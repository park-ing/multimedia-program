#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FCvideoType
{
public:
	FCvideoType() //default constructor
	{
		v_fId = 0;
		v_fName = " ";
	}

	~FCvideoType() {}; //default destructor

	int GetId() const //������ ID ��ȯ �Լ�
	{
		return v_fId;
	}
	string GetName() const //������ �̸� ��ȯ �Լ�
	{
		return v_fName;
	}
	void SetId(int inId) //������ ID ���� �Լ� 
	{
		v_fId = inId;
	}
	void SetName(string inName) //������ �̸� ���� �Լ� 
	{
		v_fName = inName;
	}

	void setRecord(int inId, string inName) //������ ���� ���� �Լ� 
	{
		SetId(inId);
		SetName(inName);
	}
	void DisplayIdOnScreen() //������ ID ��� �Լ� 
	{
		cout << "\t���ϸ�      : " << v_fId << endl;
	}
	void DisplayNameOnScreen() //������ �̸� ��� �Լ� 
	{
		cout << "\t���� ����   : " << v_fName << endl;
	}

	void DisplayRecordOnScreen() //������ ���� ��� �Լ� 
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
	}
	void SetIdFromKB(); //Ű����� ������ ID �Է� �Լ� 

	void SetNameFromKB(); //Ű����� ������ �̸� �Է� �Լ� 

	void SetRecordFromKB(); //Ű����� ������ ���� �Է� �Լ�  

	bool operator==(const FCvideoType& _item) {
		if (v_fId == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const FCvideoType& _item) {
		if (v_fId > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const FCvideoType& _item) {
		if (v_fId < _item.GetId())
			return true;
		return false;
	}
	void operator=(const FCvideoType& _item) {
		v_fId = _item.GetId();
		v_fName = _item.GetName();
	}
	friend ostream& operator<<(ostream& os, const FCvideoType& _item) {
		os << "\tId      : " << _item.GetId() << endl;
		os << "\tName    : " << _item.GetName() << endl;
		return os;
	}

protected:
	int v_fId; //primary key
	string v_fName;
};

