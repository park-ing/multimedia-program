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
	*	@post	m_CurPointer�� m_iFront ������ �ʱ�ȭ�ȴ�.
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
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
	m_pItems = new T[m_nMaxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
}

template<typename T>
CircularQueueList<T>::CircularQueueList(int max)
{
	m_nMaxQueue = max;
	m_CurPointer = -1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
	m_pItems = new T[max];	//m_pItems�� ũ�Ⱑ max�� �迭�� �����.
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
		return 1;	//m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� 1�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	return 0;	//�� ���� �ʾ����� 0�� �����Ѵ�.
}

template<typename T>
bool CircularQueueList<T>::IsEmpty() const
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� 1�� �����Ѵ�.
	return 0;	//������� ������ 0�� �����Ѵ�.
}

template<typename T>
void CircularQueueList<T>::ResetQueue()
{
	m_iFront = m_nMaxQueue - 1;
	m_CurPointer = -1;
	m_iRear = m_nMaxQueue - 1;	//�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
	delete[] m_pItems;	//�����Ҵ��ߴ� �޸𸮸� �������ش�.
	m_pItems = new T[m_nMaxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
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
		// FullQueue().print();	//�� á���� throw FullQueue
		T tmp;
		DeQueue(tmp);
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear�� 1���������ְ� item���� �־��ش�.
}

template<typename T>
void CircularQueueList<T>::DeQueue(T& item)
{
	if (IsEmpty())
		return;
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.
}

template<typename T>
int CircularQueueList<T>::GetNextItem(T& item)
{
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront���� 1 ������ index�� m_pItem�� item�� �������ش�.
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
	if (m_iFront > m_iRear)	//m_iFront�� m_iRear���� Ŭ��
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//m_iFront ���� �׸���� �迭�� ������ ����Ѵ�.
		for (int i = 0; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//�迭�� ó������ m_iRear���� ������ش�.
	}
	else	//m_iRear�� m_iFront���� Ŭ��
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << "\t-----------------" << endl;
		}	//m_iFront+1�������� m_iRear���� ���
	}
	cout << endl;
}

template <typename T>
void CircularQueueList<T>::Rearrange_By_FileName()
{
	if (IsEmpty())
		return;

	if (m_iFront > m_iRear)	//m_iFront�� m_iRear���� Ŭ��
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

		}	//m_iFront ���� �׸���� �迭�� ������
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
		}	//�迭�� ó������ m_iRear����
	}
	else	//m_iRear�� m_iFront���� Ŭ��
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
		}	//m_iFront+1�������� m_iRear����
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

