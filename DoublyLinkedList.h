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
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; //< DoublyIterator�� ģ�� Ŭ����.
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
	*	@brief	Primary key(�й�)�� �������� �˻��Ͽ� �ش��ϴ� ������ ������.
	*	@pre	����Ʈ�� ����/�ʱ�ȭ �Ϸ�Ǿ��ִ� ���¿��� ��.
	*	@post	��ġ�ϴ� �����Ͱ� ����Ʈ�� ���� ��� ������.
	*	@param	data	primary key�� �ݵ�� ���ԵǾ� �ִ� ItemType ��ü.
	*	@return ������ ��ġ�ϴ� �����Ͱ� ������ ���� �� 1, ������ 0�� ����.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key(�й�)�� �������� �˻��Ͽ� �ش��ϴ� ������ ���� ä������.
	*	@pre	����Ʈ�� ����/�ʱ�ȭ �Ϸ�Ǿ��ִ� ���¿��� ��.
	*	@post	��ġ�ϴ� �����Ͱ� ����Ʈ�� ���� ��� ���ο� �����ͷ� ��ü��.
	*	@param	data	primary key�� �ݵ�� ���ԵǾ� �ִ� ItemType ��ü.
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
// ���������� ������, ���� �޸𸮰� ���� ���� �� �̻� �Ҵ��� �Ұ����� ��� �ý��� ���� ó��
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
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ

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

		// ����ִ� ���
		if (m_pFirst == nullptr) {
			m_pFirst = node;
			m_pLast = m_pFirst;
		}
		// 1�� �̻�
		else {
			DoublyNodeType<T>* pNode;	// iterator���� ������ ������ ��ü
			while (iter.NotNull()) {
				// GetCurrentNode�� return by value�̹Ƿ� ���� �� �� �޸� ���� �Ұ��ؼ� ��� ����
				pNode = iter.m_pCurPointer;

				if (node->data < pNode->data) { // �������� �ϴ°� �� ����
					node->next = pNode;
					if (m_nLength == 1) {	// �� ��
						m_pFirst = node;
					}
					else {	// �߰�
						node->prev = pNode->prev;
						node->prev->next = node;
					}
					pNode->prev = node;
					break;
				}
				else {
					if (!iter.NextNotNull()) {	// �� ��
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
	int count = 0;	// �� ��°�� ��ġ�ϰ� �ִ��� ���� (������ 0)
				// iterator�� ����ϸ鼭 curPointer�� ������ �� �����Ƿ� return value�� �ǹ̸� ����
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


// Ư�� ��Ҹ� ã�� �����ϴ� �Լ�
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item) {
	bool moreToSearch, found;
	DoublyNodeType<T>* pNode = nullptr;
	DoublyNodeType<T>* curNode = nullptr;
	
	curNode = m_pFirst;
	found = false;
	moreToSearch = (curNode != nullptr);   //���� �ʱ�ȭ

	while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == curNode->data)   //���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;   //ã�����Ƿ� found �� ����
			if (pNode == nullptr)
				m_pFirst = curNode->next;   //�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pNode->next = curNode->next;
				curNode->prev = pNode;

				delete curNode;
			}   //������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;   //����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pNode = curNode;
			curNode = curNode->next;
			moreToSearch = (curNode != NULL);
		}   //��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;   //������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}


// Ư�� ��Ҹ� ã�� ���ο� �������� ��ġ��Ű�� �Լ�
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& item) {

	bool moreToSearch, found;
	DoublyNodeType<T>* location;   //���� ����

	location = m_pFirst;
	found = false;
	moreToSearch = (location != NULL);   //���� �ʱ�ȭ

	while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}   //��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}   //ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;   //������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

#endif	// LINKED_LIST