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

	int DeleteItem(); //filename���� item�� ã�Ƽ� �����Ѵ�.

	int ReplaceItem(); //�ش� filename�� item�� �����Ѵ�.

	int RetrieveByID_BinaryS(); //����Ž�� ������� filename�� ��ġ�ϴ� item�� ã�Ƽ� ���

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

	int login();//�α���

	void Add_FC(); //�������� �����Ͽ� FC_list�� �߰�

	void Delete_FC(); //�Էµ� FC�� FC_list���� ����

	void Display_FC_list(); //FC_list�� ����ִ� ������ ȭ�鿡 ���

	void Display_Detail_FC(); //Ư��FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���

	void Rearrange_FC(); //Ű����κ��� ������ �Է¹޾Ƽ� FC�� ���� ������ �ٲ۴�.

	int OpenInFile(char* fileName); // Open a file by file descriptor as an input file.

	int OpenOutFile(char* fileName); // Open a file by file descriptor as an output file.

	int ReadDataFromFile(); // Open a file as a read mode, read all data on the file, and set list by the data.

	int WriteDataToFile(); // Open a file as a write mode, and write all data into the file,

	int start();//�α���,ȸ������,����޴�

	int regist();//ȸ������

	int play();//����� ���� ���


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