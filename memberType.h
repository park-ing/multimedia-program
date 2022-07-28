#ifndef _MEMBERTYPE_H
#define _MEMBERTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "masterType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"



class MemberType {
public:

	MemberType() {
		m_name = "";
	}

	~MemberType() {}

	void SetId(int& id)
	{
		m_list.Add(id);
	}

	void GetIdlist(DoublySortedLinkedList<int>& list)
	{
		list = m_list;
	}

	int DeleteID(int& id)
	{
		if (m_list.Delete(id))
		{
			if (m_list.GetLength() == 0)
			{
				return 1;
			}
			return 0;
		}
		return -1;
	}

	string GetName() {
		return m_name;
	}

	void SetName(string inName) {
		m_name = inName;
	}

	void DisplayNameOnScreen() {
		cout << "\t함꼐한 사람 : " << m_name << endl;
	};

	void DisplayRecordOnScreen() {
		cout << "\t함께한 사람 : " << m_name << endl;
		DoublyIterator<int> iter(m_list);
		cout << "\t";
		while (iter.NotNull())
		{
			cout << iter.GetCurrentNode().data << "  ";
			iter.Next();
		}
		cout << endl;

	};

	void SetNameFromKB() {
		cout << "\t함께한 사람  : ";
		cin >> m_name;
	};

	bool operator == (const MemberType& data);
	bool operator > (const  MemberType& data);

	bool operator < (const  MemberType& data);


protected:
	string m_name;
	DoublySortedLinkedList<int> m_list;	// Contents ID list

};

#endif	// _MEMBERTYPE_H