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
	int GetId() const //������ ID ��ȯ �Լ�
	{
		return m_Id;
	}

	/**
	*	@brief	Get contents name.
	*	@pre	contents name is set.
	*	@post	none.
	*	@return	contents name.
	*/
	string GetName() const //������ �̸� ��ȯ �Լ�
	{
		return m_Name;
	}

	/**
*	@brief	Get event name.
*	@pre	event name is set.
*	@post	none.
*	@return	event name.
*/
	string GetEvent() const // ������ �̺�Ʈ�� ��ȯ �Լ�
	{
		return m_Event;
	}

	/**
*	@brief	Get Member name.
*	@pre	Member name is set.
*	@post	none.
*	@return	Member name.
*/
	string GetMember() const // �������� ���Ե� ����� ��ȯ �Լ�
	{
		return m_Member;
	}

	/**
*	@brief	Get place name.
*	@pre	place name is set.
*	@post	none.
*	@return	place name.
*/
	string GetPlace() const // ������ ��� ��ȯ �Լ�
	{
		return m_Place;
	}

	/**
*	@brief	Get contents explain.
*	@pre	contents explain is set.
*	@post	none.
*	@return	contents explain.
*/
	string GetExplain() const // ������ ���� ��ȯ �Լ�
	{
		return m_Explain;
	}

	/**
	*	@brief	Set content id.
	*	@pre	none.
	*	@post	content id is set.
	*	@param	inId	content id.
	*/
	void SetId(int inId) //������ ID ���� �Լ� 
	{
		m_Id = inId;
	}

	/**
	*	@brief	Set content name.
	*	@pre	none.
	*	@post	content name is set.
	*	@param	inName	content name.
	*/
	void SetName(string inName) //������ ���� �̸� ���� �Լ� 
	{
		m_Name = inName;
	}

	/**
	*	@brief	Set event name.
	*	@pre	none.
	*	@post	event name is set.
	*	@param	inEvent	event name.
	*/
	void SetEvent(string inEvent) // �̺�Ʈ�̸� ���� �Լ� 
	{
		m_Event = inEvent;
	}

	/**
	*	@brief	Set member name.
	*	@pre	none.
	*	@post	member name is set.
	*	@param	inMember	Member name.
	*/
	void SetMember(string inMember) //������ ��� ���� �Լ� 
	{
		m_Member = inMember;
	}

	/**
	*	@brief	Set place name.
	*	@pre	none.
	*	@post	place name is set.
	*	@param	inPlace	place name.
	*/
	void SetPlace(string inPlace) //������ ��� ���� �Լ� 
	{
		m_Place = inPlace;
	}

	/**
	*	@brief	Set content explain.
	*	@pre	none.
	*	@post	content explain is set.
	*	@param	inExplain	content explain.
	*/
	void SetExplain(string inExplain) //������ ���� ���� �Լ� 
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
	void setRecord(int inId, string inName, string inEvent, string inMember, string inPlace, string inExplain) //������ ���� ���� �Լ� 
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
	void DisplayIdOnScreen() // ������ ���ϸ� ��� �Լ� 
	{
		cout << "\t���ϸ�        : " << m_Id << endl;
	}

	/**
	*	@brief	Display content name on screen.
	*	@pre	content name is set.
	*	@post	content name is on screen.
	*/
	void DisplayNameOnScreen() // ������ �̸� ��� �Լ� 
	{
		cout << "\t���� ����     : " << m_Name << endl;
	}

	/**
	*	@brief	Display event name on screen.
	*	@pre	event name is set.
	*	@post	event name is on screen.
	*/
	void DisplayEventOnScreen() // ������¥ ��� �Լ� 
	{
		cout << "\t�̺�Ʈ��      : " << m_Event << endl;
	}

	/**
	*	@brief	Display content member on screen.
	*	@pre	content member is set.
	*	@post	content member is on screen.
	*/
	void DisplayMemberOnScreen() // �������� ���Ե� ��� ��� �Լ� 
	{
		cout << "\t�Բ��� ����� : " << m_Member << endl;
	}

	/**
	*	@brief	Display place name on screen.
	*	@pre	place name is set.
	*	@post	place name is on screen.
	*/
	void DisplayPlaceOnScreen() // ������ ��� ��� �Լ� 
	{
		cout << "\t��ġ          : " << m_Place << endl;
	}

	/**
	*	@brief	Display content explain on screen.
	*	@pre	content explain is set.
	*	@post	content explain is on screen.
	*/
	void DisplayExplainOnScreen() //������ ���� ��� �Լ� 
	{
		cout << "\t����          : " << m_Explain << endl;
	}

	/**
*	@brief	Display an content record on screen.
*	@pre	content record is set.
*	@post	content record is on screen.
*/
	void DisplayRecordOnScreen() //������ ���� ��� �Լ� 
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
	void SetIdFromKB(); //Ű����� ������ ID �Է� �Լ� 

		/**
	*	@brief	Set content name from keyboard.
	*	@pre	none.
	*	@post	content name is set.
	*/
	void SetNameFromKB(); //Ű����� ������ �̸� �Է� �Լ� 

		/**
	*	@brief	Set event name from keyboard.
	*	@pre	none.
	*	@post	event name is set.
	*/
	void SetEventFromKB(); //Ű����� �̺�Ʈ�̸� �Է� �Լ� 

		/**
	*	@brief	Set content member from keyboard.
	*	@pre	none.
	*	@post	content member is set.
	*/
	void SetMemberFromKB(); //Ű����� ������ ���� ��� �Է� �Լ� 

		/**
	*	@brief	Set place name from keyboard.
	*	@pre	none.
	*	@post	place name is set.
	*/
	void SetPlaceFromKB(); //Ű����� ������ ��� �Է� �Լ� 

		/**
	*	@brief	Set content explain from keyboard.
	*	@pre	none.
	*	@post	content explain is set.
	*/
	void SetExplainFromKB(); //Ű����� ������ ���� �Է� �Լ� 

		/**
	*	@brief	Set content record from keyboard.
	*	@pre	none.
	*	@post	content record is set.
	*/
	void SetRecordFromKB(); //Ű����� ������ ���� �Է� �Լ� 

		/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	content record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin); //������ ������ ���Ͽ��� �д� �Լ� 

		/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new content record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout); //�л� ������ ���Ϸ� ����ϴ� �Լ� 

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
	RelationType CompareByID(const MasterType& data); //primary key(ID)�� �������� �л� ������ ���ϴ� �Լ� 

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