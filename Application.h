#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

#include "masterType.h"
#include "eventType.h"
#include "placeType.h"
#include "memberType.h"
#include "SortedArrayList.h"
#include "CircularQueueList.h"
#include "DoublyIterator.h"
#include "DoublyLinkedList.h"
#include "FCphotoType.h"
#include "FCvideoType.h"


#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run(); // Program driver

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand(); // Display command on screen and get a input from keyboard.

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddItem(); // Add new record into list

	void AddEvent(string eName); // Add new event into list

	void AddMember(string mName); // Add new member into list

	void AddPlace(string pName); // Add new place into list

	void AddKeyToEvent(string eName, int key); // Add new ID into event list
	
	void AddKeyToMember(string mName, int key); // Add new ID into member list

	void AddKeyToPlace(string pName, int key); // Add new ID into place list

	int DeleteItem(); //filename으로 item을 찾아서 제거한다.

	int ReplaceItem(); //해당 filename의 item을 변경한다.

	int RetrieveByID_BinaryS(); //이진탐색 방법으로 filename과 일치하는 item을 찾아서 출력

	void DisplayAllItem(); // Display all records in the list on screen.


	/**
	*	@brief	Make empty list.
	*	@pre	none.
	*	@post	Make empty list in this member.
	*/
	void MakeEmpty();

	/**
	*	@brief	Retrieve item in the event list.
	*	@pre	none.
	*	@post	none.
	*/
	void Retrieve_Event();

	/**
	*	@brief	Retrieve item in the member list.
	*	@pre	none.
	*	@post	none.
	*/
	void Retrieve_Member();

	/**
	*	@brief	Retrieve item in the place list.
	*	@pre	none.
	*	@post	none.
	*/
	void Retrieve_Place();

	/**
	*	@brief	Retrieve item use two key -> event, member
	*	@pre	none.
	*	@post	none.
	*/
	void RetrieveByName_Event();

	/**
	*	@brief	Retrieve item use two key -> member, another member
	*	@pre	none.
	*	@post	none.
	*/
	void RetrieveByName_Member();

	/**
	*	@brief	Retrieve item use two key -> event, place
	*	@pre	none.
	*	@post	none.
	*/
	void RetrieveByName_Place();

	int login();//로그인

	void Add_FC(); //콘텐츠를 선정하여 FC_list에 추가

	void Delete_FC(); //입력된 FC를 FC_list에서 삭제

	void Display_FC_list(); //FC_list에 들어있는 정보를 화면에 출력

	void Display_Detail_FC(); //특정FC의 자세한 정보(master list에 저장된 정보)를 화면에 출력

	void Rearrange_FC(); //키보드로부터 조건을 입력받아서 FC의 보는 순서를 바꾼다.

	int OpenInFile(char* fileName); // Open a file by file descriptor as an input file.

	int OpenOutFile(char* fileName); // Open a file by file descriptor as an output file.

	int ReadDataFromFile(); // Open a file as a read mode, read all data on the file, and set list by the data.

	int WriteDataToFile(); // Open a file as a write mode, and write all data into the file,

	int start();//로그인,회원가입,종료메뉴

	int regist();//회원가입

	int play();//저장된 파일 출력


private:
	ifstream m_InFile;	//Input file descriptor
	ofstream m_OutFile;	//output file descriptor
	SortedArrayList<MasterType> m_List;	//item list
	DoublySortedLinkedList<EventType> e_List; //event list
	DoublySortedLinkedList<PlaceType> p_List; //place list
	DoublySortedLinkedList<MemberType> me_List; //member list
	CircularQueueList<FCphotoType> FCp_List;  // Favorite Photo Content list
	CircularQueueList<FCvideoType> FCv_List;  // Favorite Video Content list
	int m_Command;	//current command number
	string id;
	string pw;
};
#endif // _APPLICATION_H