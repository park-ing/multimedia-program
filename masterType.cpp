#include "masterType.h"


void MasterType::SetIdFromKB() //키보드로 콘텐츠 ID 입력 함수 
{
	cout << "\t파일명        : ";
	cin >> m_Id;
}
void MasterType::SetNameFromKB() //키보드로 콘텐츠 이름 입력 함수 
{
	cout << "\t파일 유형     : ";
	cin >> m_Name;
}
void MasterType::SetEventFromKB() //키보드로 이벤트 이름 입력 함수 
{
	cout << "\t이벤트명      : ";
	cin >> m_Event;
}
void MasterType::SetMemberFromKB() //키보드로 콘텐츠 멤버 입력 함수 
{
	cout << "\t함께한 사람들 : ";
	cin >> m_Member;
}
void MasterType::SetPlaceFromKB() //키보드로 콘텐츠 장소 입력 함수 
{
	cout << "\t위치          : ";
	cin >> m_Place;
}
void MasterType::SetExplainFromKB() //키보드로 콘텐츠 내용 입력 함수 
{
	cout << "\t설명          : ";
	cin >> m_Explain;
}
void MasterType::SetRecordFromKB() //키보드로 콘텐츠 정보 입력 함수 
{
	SetIdFromKB();
	SetNameFromKB();
	SetEventFromKB();
	SetMemberFromKB();
	SetPlaceFromKB();
	SetExplainFromKB();
}
int MasterType::ReadDataFromFile(ifstream& fin) //콘텐츠 정보를 파일에서 읽는 함수 
{
	fin >> m_Id;
	fin >> m_Name;
	fin >> m_Event;
	fin >> m_Member;
	fin >> m_Place;
	fin >> m_Explain;

	return 1;
}
int MasterType::WriteDataToFile(ofstream& fout) //학생 정보를 파일로 출력하는 함수 
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
RelationType MasterType::CompareByID(const MasterType& data) //primary key(ID)를 기준으로 학생 정보를 비교하는 함수 
{
	if (this->m_Id > data.m_Id)
		return GREATER;
	else if (this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}
