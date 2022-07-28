#include "masterType.h"


void MasterType::SetIdFromKB() //Ű����� ������ ID �Է� �Լ� 
{
	cout << "\t���ϸ�        : ";
	cin >> m_Id;
}
void MasterType::SetNameFromKB() //Ű����� ������ �̸� �Է� �Լ� 
{
	cout << "\t���� ����     : ";
	cin >> m_Name;
}
void MasterType::SetEventFromKB() //Ű����� �̺�Ʈ �̸� �Է� �Լ� 
{
	cout << "\t�̺�Ʈ��      : ";
	cin >> m_Event;
}
void MasterType::SetMemberFromKB() //Ű����� ������ ��� �Է� �Լ� 
{
	cout << "\t�Բ��� ����� : ";
	cin >> m_Member;
}
void MasterType::SetPlaceFromKB() //Ű����� ������ ��� �Է� �Լ� 
{
	cout << "\t��ġ          : ";
	cin >> m_Place;
}
void MasterType::SetExplainFromKB() //Ű����� ������ ���� �Է� �Լ� 
{
	cout << "\t����          : ";
	cin >> m_Explain;
}
void MasterType::SetRecordFromKB() //Ű����� ������ ���� �Է� �Լ� 
{
	SetIdFromKB();
	SetNameFromKB();
	SetEventFromKB();
	SetMemberFromKB();
	SetPlaceFromKB();
	SetExplainFromKB();
}
int MasterType::ReadDataFromFile(ifstream& fin) //������ ������ ���Ͽ��� �д� �Լ� 
{
	fin >> m_Id;
	fin >> m_Name;
	fin >> m_Event;
	fin >> m_Member;
	fin >> m_Place;
	fin >> m_Explain;

	return 1;
}
int MasterType::WriteDataToFile(ofstream& fout) //�л� ������ ���Ϸ� ����ϴ� �Լ� 
{
	fout << m_Id << " ";
	fout << m_Name << " ";
	fout << m_Event << " ";
	fout << m_Member << " ";
	fout << m_Place << " ";
	fout << m_Explain << " ";
	fout << endl;

	return 1;
}
RelationType MasterType::CompareByID(const MasterType& data) //primary key(ID)�� �������� �л� ������ ���ϴ� �Լ� 
{
	if (this->m_Id > data.m_Id)
		return GREATER;
	else if (this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}
