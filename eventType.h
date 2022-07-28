#ifndef _EVENTTYPE_H
#define _EVENTTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "masterType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"



class EventType {
public:

	EventType() {
		e_name = "";
	}

	~EventType() {}

	void SetId(int& id)
	{
		e_list.Add(id);
	}

	int DeleteID(int& id)
	{
		if (e_list.Delete(id))
		{
			if (e_list.GetLength() == 0)
			{
				return 1;
			}
			return 0;
		}
		return 0;
	}

	void GetIdlist(DoublySortedLinkedList<int>& list)
	{
		list = e_list;
	}

	string GetName() {
		return e_name;
	}

	void SetName(string inName) {
		e_name = inName;
	}

	void DisplayNameOnScreen() {
		cout << "\t이벤트명  : " << e_name << endl;
	};

	void DisplayRecordOnScreen() {
		cout << "\t이벤트명  : " << e_name << endl;
		DoublyIterator<int> iter(e_list);
		cout << "\t";
		while (iter.NotNull())
		{
			cout << iter.GetCurrentNode().data << "  ";
			iter.Next();
		}
			cout << endl;
		
	};

	void SetNameFromKB() {
		cout << "\t이벤트명   : ";
		cin >> e_name;
	};

	bool operator == (const EventType& data);
	bool operator > (const  EventType& data);

	bool operator < (const  EventType& data);


protected:
	string e_name;
	DoublySortedLinkedList<int> e_list;	// Contents ID list

};

#endif	// _EVENTTYPE_H
