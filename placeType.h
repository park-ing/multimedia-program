#ifndef _PLACETYPE_H
#define _PLACETYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "masterType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"



class PlaceType {
public:

	PlaceType() {
		p_name = "";
	}

	~PlaceType() {}

	void SetId(int& id)
	{
		p_list.Add(id);
	}

	void GetIdlist(DoublySortedLinkedList<int>& list)
	{
		list = p_list;
	}

	int DeleteID(int& id)
	{
		if (p_list.Delete(id))
		{
			if (p_list.GetLength() == 0)
			{
				return 1;
			}
			return 0;
		}
		return -1;
	}

	string GetName() {
		return p_name;
	}

	void SetName(string inName) {
		p_name = inName;
	}

	void DisplayNameOnScreen() {
		cout << "\t위치 : " << p_name << endl;
	};

	void DisplayRecordOnScreen() {
		cout << "\t위치 : " << p_name << endl;
		DoublyIterator<int> iter(p_list);
		cout << "\t";
		while (iter.NotNull())
		{
			cout << iter.GetCurrentNode().data << "  ";
			iter.Next();
		}
		cout << endl;

	};

	void SetNameFromKB() {
		cout << "\t위치 : ";
		cin >> p_name;
	};

	bool operator == (const PlaceType& data);
	bool operator > (const  PlaceType& data);

	bool operator < (const  PlaceType& data);


protected:
	string p_name;
	DoublySortedLinkedList<int> p_list;	// Contents ID list

};

#endif	// _PLACETYPE_H