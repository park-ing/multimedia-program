#include "FCvideoType.h"


void FCvideoType::SetIdFromKB() //키보드로 콘텐츠 ID 입력 함수 
{
	cout << "\tId    : ";
	cin >> v_fId;
}
void FCvideoType::SetNameFromKB() //키보드로 콘텐츠 이름 입력 함수 
{
	cout << "\tName   : ";
	cin >> v_fName;
}

void FCvideoType::SetRecordFromKB() //키보드로 콘텐츠 정보 입력 함수 
{
	SetIdFromKB();
	SetNameFromKB();

}