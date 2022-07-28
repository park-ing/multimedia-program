#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FCphotoType
{
public:
	FCphotoType() //default constructor
	{
		p_fId = 0;
		p_fName = " ";
	}

	~FCphotoType() {}; //default destructor

	int GetId() const //������ ID ��ȯ �Լ�
	{
		return p_fId;
	}
	string GetName() const //������ �̸� ��ȯ �Լ�
	{
		return p_fName;
	}
	void SetId(int inId) //������ ID ���� �Լ� 
	{
		p_fId = inId;
	}
	void SetName(string inName) //������ �̸� ���� �Լ� 
	{
		p_fName = inName;
	}

	void setRecord(int inId, string inName) //������ ���� ���� �Լ� 
	{
		SetId(inId);
		SetName(inName);
	}
	void DisplayIdOnScreen() //������ ID ��� �Լ� 
	{
		cout << "\t���ϸ�      : " << p_fId << endl;
	}
	void DisplayNameOnScreen() //������ �̸� ��� �Լ� 
	{
		cout << "\t���� ����   : " << p_fName << endl;
	}

	void DisplayRecordOnScreen() //������ ���� ��� �Լ� 
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
	}
	void SetIdFromKB(); //Ű����� ������ ID �Է� �Լ� 

	void SetNameFromKB(); //Ű����� ������ �̸� �Է� �Լ� 

	void SetRecordFromKB(); //Ű����� ������ ���� �Է� �Լ�  

	bool operator==(const FCphotoType& _item) {
		if (p_fId == _item.GetId())
			return true;
		return false;
	}
	bool operator>(const FCphotoType& _item) {
		if (p_fId > _item.GetId())
			return true;
		return false;
	}
	bool operator<(const FCphotoType& _item) {
		if (p_fId < _item.GetId())
			return true;
		return false;
	}
	void operator=(const FCphotoType& _item) {
		p_fId = _item.GetId();
		p_fName = _item.GetName();
	}
	friend ostream& operator<<(ostream& os, const FCphotoType& _item) {
		os << "\tId      : " << _item.GetId() << endl;
		os << "\tName    : " << _item.GetName() << endl;
		return os;
	}

protected:
	int p_fId; //primary key
	string p_fName;
};

