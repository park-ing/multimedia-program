#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/**
*	Structure for NodeType to use in Linked structure.
*/



template <typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType
{
	T data;	///< A data for each node.
	DoublyNodeType* prev;	///< A node pointer of previous node.
	DoublyNodeType* next;	///< A node pointer of next node.

};


/**
*	정렬된 더블연결리스트 클래스
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; //< DoublyIterator와 친구 클래스.
public:
	/**
	*	default constructor.
	*/
	DoublySortedLinkedList();

	/**
	*	destructor.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	Determines whether the list is full.
	*	@pre	List has been initialized.
	*	@post	None.
	*	@return	If there is not memory left, throws bad_alloc exception and return true, otherwise false.
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the list is empty.
	*	@pre	List has been initialized.
	*	@post	None.
	*	@return	Return true if the list is empty, otherwise false.
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);



	/**
*	@brief	Retrieve list element whose key matches item's key (if present).
*	@pre	Key member of item is initialized.
*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
*	@return	pinter of the record matched with with item's, otherwise NULL.
*/
	T* GetPtr(T& item);



	/**
	*	@brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 삭제함.
	*	@pre	리스트가 존재/초기화 완료되어있는 상태여야 함.
	*	@post	일치하는 데이터가 리스트에 있을 경우 삭제됨.
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*	@return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 리턴.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 새로 채워넣음.
	*	@pre	리스트가 존재/초기화 완료되어있는 상태여야 함.
	*	@post	일치하는 데이터가 리스트에 있을 경우 새로운 데이터로 교체됨.
	*	@param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	*/
	int Replace(T& item);


private:
	DoublyNodeType<T>* m_pFirst;	///< Pointer for pointing a first node.
	DoublyNodeType<T>* m_pLast; ///< Last node.
	int m_nLength;	///< Number of node in the list.
};


// Retrieve list element whose key matches item's key (if present).
template <typename T>
T* DoublySortedLinkedList<T>::GetPtr(T& item)
{
	T* itemPtr = NULL;
	DoublyIterator<T> iter(*this);
	bool found = false;

	while (iter.NotNull()) {
		itemPtr = &iter.GetCurrentNodePtr()->data;
		if (item == *itemPtr)
			return itemPtr;
		else if (item < iter.GetCurrentNode().data)
			return NULL;
		else 	iter.Next();
	}
	return NULL;
}


// Class constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_nLength = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
	
}


// Class destructor
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	//MakeEmpty();
	//delete m_pFirst;
	//delete m_pLast;
}


// Determines whether the list is full.
// 개수제한은 없지만, 실제 메모리가 가득 차서 더 이상 할당이 불가능한 경우 시스템 예외 처리
template <typename T>
bool DoublySortedLinkedList<T>::IsFull() const {
	
	try {
		DoublyNodeType<T>* temp = nullptr;	// if there is not memory left, temp would not be initialized as NULL and
		delete temp;					// deleting temp(pointer) could not be executed.
		return false;
	}
	catch (bad_alloc& e_ba) {
		cerr << "bad_alloc exception caught : " << e_ba.what() << endl;
		return true;
	}
}


// Determines whether the list is empty.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() const {
	
	if (m_pFirst == nullptr) {
		return true;
	}
	else return false;
}


// Initialize list to empty state.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화

	DoublyNodeType<T>* tempPtr;

	while (m_pFirst != nullptr)
	{
		tempPtr = m_pFirst;
		m_pFirst = m_pFirst->next;
		delete tempPtr;
	}

	m_nLength = 0;
}

// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	if (!IsFull()) {
		DoublyNodeType<T>* node = new DoublyNodeType<T>;
		DoublyIterator<T> iter(*this);

		node->data = item;
		node->prev = nullptr;
		node->next = nullptr;

		// 비어있는 경우
		if (m_pFirst == nullptr) {
			m_pFirst = node;
			m_pLast = m_pFirst;
		}
		// 1개 이상
		else {
			DoublyNodeType<T>* pNode;	// iterator에서 나오는 데이터 객체
			while (iter.NotNull()) {
				// GetCurrentNode는 return by value이므로 수정 및 실 메모리 접근 불가해서 사용 못함
				pNode = iter.m_pCurPointer;

				if (node->data < pNode->data) { // 넣으려고 하는게 더 작음
					node->next = pNode;
					if (m_nLength == 1) {	// 맨 앞
						m_pFirst = node;
					}
					else {	// 중간
						node->prev = pNode->prev;
						node->prev->next = node;
					}
					pNode->prev = node;
					break;
				}
				else {
					if (!iter.NextNotNull()) {	// 맨 뒤
						pNode->next = node;
						node->prev = pNode;
						m_pLast = node;
						break;
					}
					else iter.Next();
				}
			}
		}

		m_nLength++;
		return 1;
	}
	else return 0;

}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> iter(*this);
	int count = 0;	// 몇 번째에 위치하고 있는지 리턴 (없으면 0)
				// iterator를 사용하면서 curPointer를 재사용할 수 없으므로 return value의 의미를 변경
	bool found = false;
	while (iter.NotNull()) {
		count++;
		if (item == iter.GetCurrentNode().data) {
			found = true;
			item = iter.GetCurrentNode().data;
			break;
		}
		else if (item < iter.GetCurrentNode().data) {
			break;
		}
		else {
			iter.Next();
		}
	}

	if (found) {
		return count;
	}
	else return 0;

}


// 특정 요소를 찾아 삭제하는 함수
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item) {
	bool moreToSearch, found;
	DoublyNodeType<T>* pNode = nullptr;
	DoublyNodeType<T>* curNode = nullptr;
	
	curNode = m_pFirst;
	found = false;
	moreToSearch = (curNode != nullptr);   //변수 초기화

	while (moreToSearch && !found)   //리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == curNode->data)   //현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;   //찾았으므로 found 값 변경
			if (pNode == nullptr)
				m_pFirst = curNode->next;   //항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pNode->next = curNode->next;
				curNode->prev = pNode;

				delete curNode;
			}   //이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;   //리스트의 길이를 1 줄여준다.
		}
		else
		{
			pNode = curNode;
			curNode = curNode->next;
			moreToSearch = (curNode != NULL);
		}   //일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;   //삭제가 성공하면 1, 아니면 0을 리턴한다.
}


// 특정 요소를 찾아 새로운 내용으로 대치시키는 함수
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& item) {

	bool moreToSearch, found;
	DoublyNodeType<T>* location;   //변수 선언

	location = m_pFirst;
	found = false;
	moreToSearch = (location != NULL);   //변수 초기화

	while (moreToSearch && !found)   //리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}   //일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}   //찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;   //수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

#endif	// LINKED_LIST