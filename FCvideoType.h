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

	int GetId() const //콘텐츠 ID 반환 함수
	{
		return v_fId;
	}
	string GetName() const //콘텐츠 이름 반환 함수
	{
		return v_fName;
	}
	void SetId(int inId) //콘텐츠 ID 저장 함수 
	{
		v_fId = inId;
	}
	void SetName(string inName) //콘텐츠 이름 저장 함수 
	{
		v_fName = inName;
	}

	void setRecord(int inId, string inName) //콘텐츠 정보 저장 함수 
	{
		SetId(inId);
		SetName(inName);
	}
	void DisplayIdOnScreen() //콘텐츠 ID 출력 함수 
	{
		cout << "\t파일명      : " << v_fId << endl;
	}
	void DisplayNameOnScreen() //콘텐츠 이름 출력 함수 
	{
		cout << "\t파일 유형   : " << v_fName << endl;
	}

	void DisplayRecordOnScreen() //콘텐츠 정보 출력 함수 
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
	}
	void SetIdFromKB(); //키보드로 콘텐츠 ID 입력 함수 

	void SetNameFromKB(); //키보드로 콘텐츠 이름 입력 함수 

	void SetRecordFromKB(); //키보드로 콘텐츠 정보 입력 함수  

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

