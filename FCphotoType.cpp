#include "FCphotoType.h"


void FCphotoType::SetIdFromKB() //키보드로 콘텐츠 ID 입력 함수 
{
	cout << "\tId    : ";
	cin >> p_fId;
}
void FCphotoType::SetNameFromKB() //키보드로 콘텐츠 이름 입력 함수 
{
	cout << "\tName   : ";
	cin >> p_fName;
}

void FCphotoType::SetRecordFromKB() //키보드로 콘텐츠 정보 입력 함수 
{
	SetIdFromKB();
	SetNameFromKB();

}