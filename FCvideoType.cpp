#include "FCvideoType.h"


void FCvideoType::SetIdFromKB() //Ű����� ������ ID �Է� �Լ� 
{
	cout << "\tId    : ";
	cin >> v_fId;
}
void FCvideoType::SetNameFromKB() //Ű����� ������ �̸� �Է� �Լ� 
{
	cout << "\tName   : ";
	cin >> v_fName;
}

void FCvideoType::SetRecordFromKB() //Ű����� ������ ���� �Է� �Լ� 
{
	SetIdFromKB();
	SetNameFromKB();

}