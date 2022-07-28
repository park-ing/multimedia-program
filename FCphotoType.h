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

	int GetId() const //콘텐츠 ID 반환 함수
	{
		return p_fId;
	}
	string GetName() const //콘텐츠 이름 반환 함수
	{
		return p_fName;
	}
	void SetId(int inId) //콘텐츠 ID 저장 함수 
	{
		p_fId = inId;
	}
	void SetName(string inName) //콘텐츠 이름 저장 함수 
	{
		p_fName = inName;
	}

	void setRecord(int inId, string inName) //콘텐츠 정보 저장 함수 
	{
		SetId(inId);
		SetName(inName);
	}
	void DisplayIdOnScreen() //콘텐츠 ID 출력 함수 
	{
		cout << "\t파일명      : " << p_fId << endl;
	}
	void DisplayNameOnScreen() //콘텐츠 이름 출력 함수 
	{
		cout << "\t파일 유형   : " << p_fName << endl;
	}

	void DisplayRecordOnScreen() //콘텐츠 정보 출력 함수 
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
	}
	void SetIdFromKB(); //키보드로 콘텐츠 ID 입력 함수 

	void SetNameFromKB(); //키보드로 콘텐츠 이름 입력 함수 

	void SetRecordFromKB(); //키보드로 콘텐츠 정보 입력 함수  

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

