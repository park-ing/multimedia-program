#include "FCphotoType.h"


void FCphotoType::SetIdFromKB() //Ű����� ������ ID �Է� �Լ� 
{
	cout << "\tId    : ";
	cin >> p_fId;
}
void FCphotoType::SetNameFromKB() //Ű����� ������ �̸� �Է� �Լ� 
{
	cout << "\tName   : ";
	cin >> p_fName;
}

void FCphotoType::SetRecordFromKB() //Ű����� ������ ���� �Է� �Լ� 
{
	SetIdFromKB();
	SetNameFromKB();

}