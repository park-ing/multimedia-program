#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

/**
*	item information class.
*/
class MasterType
{
public:
	/**
	*	default constructor.
	*/
	MasterType() //default constructor
	{
		m_Id = 0;
		m_Name = " ";
		m_Event = " ";
		m_Member = " ";
		m_Place = " ";
		m_Explain = " ";
	}
	/**
	*	destructor.
	*/
	~MasterType() {}; //default destructor

		/**
	*	@brief	Get contents id.
	*	@pre	contents id is set.
	*	@post	none.
	*	@return	contents id.
	*/
	int GetId() const //콘텐츠 ID 반환 함수
	{
		return m_Id;
	}

	/**
	*	@brief	Get contents name.
	*	@pre	contents name is set.
	*	@post	none.
	*	@return	contents name.
	*/
	string GetName() const //콘텐츠 이름 반환 함수
	{
		return m_Name;
	}

	/**
*	@brief	Get event name.
*	@pre	event name is set.
*	@post	none.
*	@return	event name.
*/
	string GetEvent() const // 콘텐츠 이벤트명 반환 함수
	{
		return m_Event;
	}

	/**
*	@brief	Get Member name.
*	@pre	Member name is set.
*	@post	none.
*	@return	Member name.
*/
	string GetMember() const // 콘텐츠에 포함된 사람들 반환 함수
	{
		return m_Member;
	}

	/**
*	@brief	Get place name.
*	@pre	place name is set.
*	@post	none.
*	@return	place name.
*/
	string GetPlace() const // 콘텐츠 장소 반환 함수
	{
		return m_Place;
	}

	/**
*	@brief	Get contents explain.
*	@pre	contents explain is set.
*	@post	none.
*	@return	contents explain.
*/
	string GetExplain() const // 콘텐츠 내용 반환 함수
	{
		return m_Explain;
	}

	/**
	*	@brief	Set content id.
	*	@pre	none.
	*	@post	content id is set.
	*	@param	inId	content id.
	*/
	void SetId(int inId) //콘텐츠 ID 저장 함수 
	{
		m_Id = inId;
	}

	/**
	*	@brief	Set content name.
	*	@pre	none.
	*	@post	content name is set.
	*	@param	inName	content name.
	*/
	void SetName(string inName) //콘텐츠 파일 이름 저장 함수 
	{
		m_Name = inName;
	}

	/**
	*	@brief	Set event name.
	*	@pre	none.
	*	@post	event name is set.
	*	@param	inEvent	event name.
	*/
	void SetEvent(string inEvent) // 이벤트이름 저장 함수 
	{
		m_Event = inEvent;
	}

	/**
	*	@brief	Set member name.
	*	@pre	none.
	*	@post	member name is set.
	*	@param	inMember	Member name.
	*/
	void SetMember(string inMember) //콘텐츠 멤버 저장 함수 
	{
		m_Member = inMember;
	}

	/**
	*	@brief	Set place name.
	*	@pre	none.
	*	@post	place name is set.
	*	@param	inPlace	place name.
	*/
	void SetPlace(string inPlace) //콘텐츠 장소 저장 함수 
	{
		m_Place = inPlace;
	}

	/**
	*	@brief	Set content explain.
	*	@pre	none.
	*	@post	content explain is set.
	*	@param	inExplain	content explain.
	*/
	void SetExplain(string inExplain) //콘텐츠 내용 저장 함수 
	{
		m_Explain = inExplain;
	}

	/**
	*	@brief	Set content record.
	*	@pre	none.
	*	@post	content record is set.
	*	@param	inId	content id.
	*	@param	inName	content name.
	*	@param	inEvent	event name.
	* 	@param	inMember	Member name.
	*	@param	inPlace	place name.
	*	@param	inExplain	contents explain.
	*/
	void setRecord(int inId, string inName, string inEvent, string inMember, string inPlace, string inExplain) //콘텐츠 정보 저장 함수 
	{
		SetId(inId);
		SetName(inName);
		SetEvent(inEvent);
		SetMember(inMember);
		SetPlace(inPlace);
		SetExplain(inExplain);
	}

	/**
	*	@brief	Display content id on screen.
	*	@pre	content id is set.
	*	@post	content id is on screen.
	*/
	void DisplayIdOnScreen() // 콘텐츠 파일명 출력 함수 
	{
		cout << "\t파일명        : " << m_Id << endl;
	}

	/**
	*	@brief	Display content name on screen.
	*	@pre	content name is set.
	*	@post	content name is on screen.
	*/
	void DisplayNameOnScreen() // 콘텐츠 이름 출력 함수 
	{
		cout << "\t파일 유형     : " << m_Name << endl;
	}

	/**
	*	@brief	Display event name on screen.
	*	@pre	event name is set.
	*	@post	event name is on screen.
	*/
	void DisplayEventOnScreen() // 생성날짜 출력 함수 
	{
		cout << "\t이벤트명      : " << m_Event << endl;
	}

	/**
	*	@brief	Display content member on screen.
	*	@pre	content member is set.
	*	@post	content member is on screen.
	*/
	void DisplayMemberOnScreen() // 콘텐츠에 포함된 사람 출력 함수 
	{
		cout << "\t함께한 사람들 : " << m_Member << endl;
	}

	/**
	*	@brief	Display place name on screen.
	*	@pre	place name is set.
	*	@post	place name is on screen.
	*/
	void DisplayPlaceOnScreen() // 콘텐츠 장소 출력 함수 
	{
		cout << "\t위치          : " << m_Place << endl;
	}

	/**
	*	@brief	Display content explain on screen.
	*	@pre	content explain is set.
	*	@post	content explain is on screen.
	*/
	void DisplayExplainOnScreen() //콘텐츠 내용 출력 함수 
	{
		cout << "\t설명          : " << m_Explain << endl;
	}

	/**
*	@brief	Display an content record on screen.
*	@pre	content record is set.
*	@post	content record is on screen.
*/
	void DisplayRecordOnScreen() //콘텐츠 정보 출력 함수 
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
		DisplayEventOnScreen();
		DisplayMemberOnScreen();
		DisplayPlaceOnScreen();
		DisplayExplainOnScreen();
	}

	/**
*	@brief	Set content id from keyboard.
*	@pre	none.
*	@post	content id is set.
*/
	void SetIdFromKB(); //키보드로 콘텐츠 ID 입력 함수 

		/**
	*	@brief	Set content name from keyboard.
	*	@pre	none.
	*	@post	content name is set.
	*/
	void SetNameFromKB(); //키보드로 콘텐츠 이름 입력 함수 

		/**
	*	@brief	Set event name from keyboard.
	*	@pre	none.
	*	@post	event name is set.
	*/
	void SetEventFromKB(); //키보드로 이벤트이름 입력 함수 

		/**
	*	@brief	Set content member from keyboard.
	*	@pre	none.
	*	@post	content member is set.
	*/
	void SetMemberFromKB(); //키보드로 콘텐츠 포함 멤버 입력 함수 

		/**
	*	@brief	Set place name from keyboard.
	*	@pre	none.
	*	@post	place name is set.
	*/
	void SetPlaceFromKB(); //키보드로 콘텐츠 장소 입력 함수 

		/**
	*	@brief	Set content explain from keyboard.
	*	@pre	none.
	*	@post	content explain is set.
	*/
	void SetExplainFromKB(); //키보드로 콘텐츠 설명 입력 함수 

		/**
	*	@brief	Set content record from keyboard.
	*	@pre	none.
	*	@post	content record is set.
	*/
	void SetRecordFromKB(); //키보드로 콘텐츠 정보 입력 함수 

		/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	content record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin); //콘텐츠 정보를 파일에서 읽는 함수 

		/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new content record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout); //학생 정보를 파일로 출력하는 함수 

		/**
	*	Compare two content types.
	*	@brief	Compare two content types by item id.
	*	@pre	two content types should be initialized.
	*	@post	the target file is included the new content record.
	*	@param	data	target content for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const MasterType& data); //primary key(ID)를 기준으로 학생 정보를 비교하는 함수 

	bool operator==(const MasterType& A) {
		if (m_Id == A.GetId())
			return true;
		return false;
	}
	void operator=(const MasterType& _item) {
		m_Id = _item.GetId();
		m_Name = _item.GetName();
		m_Event = _item.GetEvent();
		m_Member = _item.GetMember();
		m_Place = _item.GetPlace();
		m_Explain = _item.GetExplain();
	}

protected:
	int m_Id; //primary key
	string m_Name;
	string m_Event;
	string m_Member;
	string m_Place;
	string m_Explain;
};

#endif