#pragma once
#include "masterType.h"
#include "FCphotoType.h"
#include "FCvideoType.h"
#include "SortedArrayList.h"

#define MAXQUEUE 31

template <typename T>
class CircularQueueList
{
private:
	int m_iFront;		///< index of one infront of the first element.
	int m_iRear;		///< index of the last element.
	int m_nMaxQueue;	///< max size of the queue.
	int m_CurPointer;	///< iterator pointer.
	T* m_pItems;		///< pointer for dynamic allocation.

public:
	CircularQueueList();
	CircularQueueList(int max);
	~CircularQueueList();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront, m_CurPointer, and m_iRear are set same value as Constructer.
	*/
	void ResetQueue();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T& item);

	/**
*	@brief	move list iterator to the next item in list and get that item.
*	@pre	list and list iterator should not be initialized.
*	@post	iterator is moved to next item.
*	@param	data	get current iterator's item. it does not need to be initialized.
*	@return	index of current iterator's item if is not end of list, oterwise return -1.
*/
	int GetNextItem(T& item);

	/**
*	@brief	Print all the items in the queue on screen
*	@pre	Queue has been initialized.
*	@post	None.
*/
	void Display_All();

	void Rearrange_By_FileName();

	int Retrieve_Q(T& data);

	int Delete(T data);
};

template<typename T>
CircularQueueList<T>::CircularQueueList()
{
	m_nMaxQueue = MAXQUEUE;
	m_CurPointer = -1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.
	m_pItems = new T[m_nMaxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
}

template<typename T>
CircularQueueList<T>::CircularQueueList(int max)
{
	m_nMaxQueue = max;
	m_CurPointer = -1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.
	m_pItems = new T[max];	//m_pItems에 크기가 max인 배열을 만든다.
}

template<typename T>
CircularQueueList<T>::~CircularQueueList()
{
	delete[] m_pItems;
}

template<typename T>
bool CircularQueueList<T>::IsFull() const
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 1을 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	return 0;	//꽉 차지 않았으면 0을 리턴한다.
}

template<typename T>
bool CircularQueueList<T>::IsEmpty() const
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 1을 리턴한다.
	return 0;	//비어있지 않으면 0을 리턴한다.
}

template<typename T>
void CircularQueueList<T>::ResetQueue()
{
	m_iFront = m_nMaxQueue - 1;
	m_CurPointer = -1;
	m_iRear = m_nMaxQueue - 1;	//생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
	delete[] m_pItems;	//동적할당했던 메모리를 해제해준다.
	m_pItems = new T[m_nMaxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
}

template<typename T>
void CircularQueueList<T>::ResetCurrentPointer()
{
	m_CurPointer = m_iFront;
}

template<typename T>
void CircularQueueList<T>::EnQueue(T item)
{
	if (IsFull()) {
		// FullQueue().print();	//꽉 찼을땐 throw FullQueue
		T tmp;
		DeQueue(tmp);
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear를 1증가시켜주고 item값을 넣어준다.
}

template<typename T>
void CircularQueueList<T>::DeQueue(T& item)
{
	if (IsEmpty())
		return;
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
}

template<typename T>
int CircularQueueList<T>::GetNextItem(T& item)
{
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront에서 1 증가된 index의 m_pItem을 item에 복사해준다.
	/*
	if (m_CurPointer == m_iRear) {
		this->ResetCurrentPointer();
		return 0;
	}
	*/
	return 1;
}

template<typename T>
void CircularQueueList<T>::Display_All()
{
	if (IsEmpty())
		return;

	cout << "\n\t-----------------" << endl;
	cout << "\t *Current list*" << endl;
	if (m_iFront > m_iRear)	//m_iFront가 m_iRear보다 클때
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//m_iFront 다음 항목부터 배열의 끝까지 출력한다.
		for (int i = 0; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//배열의 처음부터 m_iRear까지 출력해준다.
	}
	else	//m_iRear가 m_iFront보다 클때
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//m_iFront+1에서부터 m_iRear까지 출력
	}
	cout << endl;
}

template <typename T>
void CircularQueueList<T>::Rearrange_By_FileName()
{
	if (IsEmpty())
		return;

	if (m_iFront > m_iRear)	//m_iFront가 m_iRear보다 클때
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			for (int j = i; j < m_nMaxQueue - 1; j++) {
				if (m_pItems[j].GetId() > m_pItems[j + 1].GetId())
				{
					T tmp;
					tmp = m_pItems[j];
					m_pItems[j] = m_pItems[j + 1];
					m_pItems[j + 1] = tmp;

				}
			}

		}	//m_iFront 다음 항목부터 배열의 끝까지
		for (int i = 0; i <= m_iRear; i++)
		{
			for (int j = i; j <= m_iRear - 1; j++) {
				if (m_pItems[j].GetId() > m_pItems[j + 1].GetId())
				{
					T tmp;
					tmp = m_pItems[j];
					m_pItems[j] = m_pItems[j + 1];
					m_pItems[j + 1] = tmp;

				}
			}
		}	//배열의 처음부터 m_iRear까지
	}
	else	//m_iRear가 m_iFront보다 클때
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			for (int j = i; j <= m_iRear - 1; j++) {
				if (m_pItems[j].GetId() > m_pItems[j + 1].GetId())
				{
					T tmp;
					tmp = m_pItems[j];
					m_pItems[j] = m_pItems[j + 1];
					m_pItems[j + 1] = tmp;

				}
			}
		}	//m_iFront+1에서부터 m_iRear까지
	}

	return;
}


template<typename T>
int CircularQueueList<T>::Retrieve_Q(T& data)
{
	if (m_iRear == m_nMaxQueue - 1) {
		return 0;
	}
	T CurItem;
	ResetCurrentPointer();
	GetNextItem(CurItem);
	while (1)
	{
		if (m_CurPointer == m_iRear + 1) {
			return 0;
			break;
		}

		if (CurItem == data) {
			data = CurItem;
			return 1;
			break;
		}
		else if (CurItem > data) {
			return 0;
			break;
		}
		else {
			GetNextItem(CurItem);
		}
	}
	return 0;
}

template<typename T>
int CircularQueueList<T>::Delete(T data)
{
	if (Retrieve_Q(data))
	{
		if (m_iRear > m_iFront)
		{
			for (int i = m_CurPointer; i < m_iRear + 1; i++)
			{
				m_pItems[i] = m_pItems[i + 1];
			}
			m_iRear--;
			return 1;
		}
		else
		{
			int Rear = m_nMaxQueue + m_iRear;
			int Pointer = m_CurPointer + m_nMaxQueue;
			for (int i = Pointer; i < Rear + 1; i++)
				m_pItems[i - m_nMaxQueue] = m_pItems[i - m_nMaxQueue + 1];
			Rear--;
			m_iRear = Rear % m_nMaxQueue;
			m_CurPointer = Pointer - m_nMaxQueue;
			return 1;
		}
	}
	return 0;
}

