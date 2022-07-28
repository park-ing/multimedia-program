#include "Application.h"


void Application::Run()
{
	int A = start();
	while (1) 
	{
		if (A == 1)
		{
			if (login() == 1)
			{
				while (1) {
					system("cls");
					m_Command = GetCommand();
					switch (m_Command)
					{
					case 1:
						AddItem();
						break;
					case 2:
						DeleteItem();
						break;
					case 3:
						ReplaceItem();
						break;
					case 4:
						RetrieveByID_BinaryS();
						break;
					case 5:
						DisplayAllItem();
						break;
					case 6:
						MakeEmpty();
						break;
					case 7:
						Retrieve_Event();
						break;
					case 8:
						Retrieve_Member();
						break;
					case 9:
						Retrieve_Place();
						break;
					case 10:
						RetrieveByName_Event();
						break;
					case 11:
						RetrieveByName_Member();
						break;
					case 12:
						RetrieveByName_Place();
						break;
					case 13:
						Add_FC();
						break;
					case 14:
						Delete_FC();
						break;
					case 15:
						Display_FC_list();
						break;
					case 16:
						Display_Detail_FC();
						break;
					case 17:
						Rearrange_FC();
						break;
					case 18:
						ReadDataFromFile();
						break;
					case 19:
						WriteDataToFile();
						break;
					case 20:
						play();
						break;
					case 0:
						return;
					default:
						cout << "\tIllegal selection...\n";
						break;
					}
					system("pause");
				}
			}
			else break;
		}
		else if (A == 2)
		{
			regist();
			A = start();
		}
		else break;

	}
	
	
}

int Application::login()
{
	string ID, PW;
	int count = 0;
	while (1) {
		system("cls");
		cout << endl << endl;
		cout << "\t환영합니다!" << endl;
		cout << "\t(초기 아이디 : 1234 / 초기 비밀번호 : 1234)" << endl;
		cout << "\t 아이디->";
		cin >> ID;
		cout << "\t 비밀번호->";
		cin >> PW;

		if (ID == id && PW == pw)
			count = 100;
		
		else if (ID == "1234" && PW == "1234")
			count = 100;
		
		else
			count++;

		if (count == 100)
		{
			return 1;
			break;
		}
		else if (count == 3)
		{
			return 0;
			break;
		}
		else
		{
			cout << "\n\t***로그인 실패!!***" << endl;
			cout << "\t현재 " << count << " 번 실패...(3번 실패시 종료)" << endl;
		}
		system("pause");
	}

}


int Application::start()
{
	system("cls");
	int command;
	cout << endl << endl;
	cout << "\t====파일 관리 시스템====\n";
	cout << "\t|                      |" << endl;
	cout << "\t|  1. 로그인           |" << endl;
	cout << "\t|  2. 회원가입         |" << endl;
	cout << "\t|  3. 종료             |" << endl;
	cout << "\t|                      |" << endl;
	cout << "\t========================" << endl;
	cout << endl << "\t입력-->";
	cin >> command;
	cout << endl;
	return command;
}

int Application::regist()
{
	system("cls");
	cout << endl << endl;
	cout << "\t========회원가입========\n";
	cout << "\t   새로운 아이디 : ";
	cin >> id;
	cout << "\t   새로운 비밀번호 : ";
	cin >> pw;
	cout << "\t=====회원가입 완료======" << endl;
	return 1;
}

//Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl << endl;
	cout << "\t======================파일 관리 시스템====================== " << endl;
	cout << "\t   1 : 파일 추가" << endl;
	cout << "\t   2 : 파일 삭제" << endl;
	cout << "\t   3 : 파일 수정" << endl;
	cout << "\t   4 : 파일 검색" << endl;
	cout << "\t   5 : 파일 리스트 출력" << endl;
	cout << "\t   6 : 저장된 리스트 포맷" << endl;
	cout << "\t ---------------------상세 검색 메뉴---------------------" << endl;
	cout << "\t   7 : 이벤트 이름으로 검색" << endl;
	cout << "\t   8 : 함께한 인물로 검색" << endl;
	cout << "\t   9 : 이벤트 장소명으로 검색" << endl;
	cout << "\t  10 : 이벤트 이름 & 함께한 인물로 검색" << endl;
	cout << "\t  11 : 함께한 인물 & 또 다른 함께한 인물로 검색" << endl;
	cout << "\t  12 : 이벤트 장소 & 함께한 인물로 검색" << endl;
	cout << "\t --------------------------------------------------------" << endl;
	cout << "\t ---------------------즐겨찾기 메뉴----------------------" << endl;
	cout << "\t  13 : 즐겨찾기에 파일 추가" << endl;
	cout << "\t  14 : 즐겨찾기의 파일 삭제" << endl;
	cout << "\t  15 : 즐겨찾기 파일 모두 출력" << endl;
	cout << "\t  16 : 즐겨찾기 파일 검색" << endl;
	cout << "\t  17 : 메뉴 보는 순서 변경" << endl;
	cout << "\t --------------------------------------------------------" << endl;
	cout << "\t  18 : 외부에서 불러오기" << endl;
	cout << "\t  19 : Text파일로 저장하기" << endl;
	cout << "\t  20 : @@저장된 파일 출력@@" << endl;
	cout << "\t   0 : 종료" << endl;

	cout << endl << "\tChoose a Command-->";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddItem()
{
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}
	MasterType item;
	EventType eitem;
	MemberType mitem;
	PlaceType pitem;
	item.SetRecordFromKB();
	m_List.Add(item); // master list에 자료 추가
	
	eitem.SetName(item.GetEvent()); // event list에 자료 추가
	if (e_List.GetLength() == 0)
	{
		AddEvent(item.GetEvent());
		AddKeyToEvent(item.GetEvent(), item.GetId());
	}
	else
	{
		if (e_List.Get(eitem)) //event가 있을 경우
		{
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
		else
		{
			AddEvent(item.GetEvent());
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
	}
	pitem.SetName(item.GetPlace());// place list에 자료 추가
	if (p_List.Get(pitem)) //place가 있을 경우
	{
		AddKeyToPlace(item.GetPlace(), item.GetId()); 
	}
	else 
	{
		AddPlace(item.GetPlace());
		AddKeyToPlace(item.GetPlace(), item.GetId());
	}
	
	string name;			// memberlist에 자료 추가
	int index_rear = item.GetMember().find(",");
	int index_front = -1;
	while (1) { // member list에 사람별로 분류해서 변수에 저장 후 객체별로 저장
		name = item.GetMember().substr(index_front + 1, index_rear - index_front -1);
		mitem.SetName(name);
		if (me_List.Get(mitem))//member가 있을 경우
		{
			AddKeyToMember(name, item.GetId());
		}
		else
		{
			AddMember(name);
			AddKeyToMember(name, item.GetId());
		}
		if (index_rear == -1)
			break;
		index_front = index_rear;
		index_rear = item.GetMember().find(",", index_front + 1);
	}
	
	DisplayAllItem();
	return 1;
}

void Application::AddEvent(string eName) {
	EventType data;
	data.SetName(eName);
	e_List.Add(data);
}

void Application::AddKeyToEvent(string eName, int key)
{
	EventType data;
	data.SetName(eName);
	EventType* temp = new EventType;

	temp = e_List.GetPtr(data);
	temp->SetName(eName);
	temp->SetId(key);
	e_List.Replace(*temp);
}

void Application::AddMember(string mName) {
	MemberType data;
	data.SetName(mName);
	me_List.Add(data);
}

void Application::AddKeyToMember(string mName, int key)
{
	MemberType data;
	data.SetName(mName);
	MemberType* temp = new MemberType;

	temp = me_List.GetPtr(data);
	temp->SetName(mName);
	temp->SetId(key);
	me_List.Replace(*temp);
}

void Application::AddPlace(string pName) {
	PlaceType data;
	data.SetName(pName);
	p_List.Add(data);
}

void Application::AddKeyToPlace(string pName, int key)
{
	PlaceType data;
	data.SetName(pName);
	PlaceType* temp = new PlaceType;

	temp = p_List.GetPtr(data);
	temp->SetName(pName);
	temp->SetId(key);
	p_List.Replace(*temp);
}

void Application::DisplayAllItem()
{
	MasterType data;
	DoublyIterator<EventType> e_iter(e_List);
	DoublyIterator<MemberType> m_iter(me_List);
	DoublyIterator<PlaceType> p_iter(p_List);
	cout << "<====================================>" << endl;
	cout << "\t *저장된 파일 리스트*" << endl << endl;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
		cout << "\t--------------------" << endl;
	}

	cout << "\n\t 이벤트명 목록\n";
	// event list를 화면에 출력
	while (e_iter.NotNull()) {
		e_iter.GetCurrentNodePtr()->data.DisplayRecordOnScreen();
		e_iter.Next();
		cout << "\t--------------------" << endl;
	}


	cout << "\n\t 함께한 사람들 목록\n";
	// member list를 화면에 출력
	while (m_iter.NotNull()) {
		m_iter.GetCurrentNodePtr()->data.DisplayRecordOnScreen();
		m_iter.Next();
		cout << "\t--------------------" << endl;
	}


	cout << "\n\t 위치 목록\n";
	// place list를 화면에 출력
	while (p_iter.NotNull()) {
		p_iter.GetCurrentNodePtr()->data.DisplayRecordOnScreen();
		p_iter.Next();
		cout << "\t--------------------" << endl;
	}
	cout << "<====================================>" << endl;
}

int Application::DeleteItem() 
{ 
	if (m_List.IsEmpty()) {
		cout << "List is empty" << endl;
		return 0;
	}

	MasterType item;
	item.SetIdFromKB();
	if (m_List.Retrieve_BinaryS(item) == 1)
	{
		//master list 제거
		m_List.Delete(item);
		int id = item.GetId();

		
		//event list 제거
		EventType data;
		DoublyIterator<EventType> e_iter(e_List);
		data.SetName(item.GetEvent());
		
		while (e_iter.NotNull())
		{
			if (e_iter.GetCurrentNodePtr()->data.GetName() == data.GetName())
			{
				if (e_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
				{
					e_List.Delete(data);
					break;
				}
				break;
			}
			e_iter.Next();
		}
		

		
		//place list 제거
		PlaceType data1;
		DoublyIterator<PlaceType> p_iter(p_List);
		data1.SetName(item.GetPlace());
		while (p_iter.NotNull())
		{
			if (p_iter.GetCurrentNodePtr()->data.GetName() == data1.GetName())
			{
				if (p_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
				{
					p_List.Delete(data1);
					break;
				}
			}
			p_iter.Next();
		}

		
		//member list 제거
		MemberType mitem;
		DoublyIterator<MemberType> m_iter(me_List);
		string name;
		int index_rear = item.GetMember().find(",");
		int index_front = -1;
	
		while (1) {
			name = item.GetMember().substr(index_front + 1, index_rear - index_front - 1);
			mitem.SetName(name);
			m_iter.First();
			while (m_iter.NotNull())
			{
				if (m_iter.GetCurrentNodePtr()->data.GetName() == mitem.GetName())
				{
					if (m_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
					{
						me_List.Delete(mitem);
						break;
					}
				}
				m_iter.Next();
			}
			if (index_rear == -1)
				break;
			index_front = index_rear;
			index_rear = item.GetMember().find(",", index_front + 1);
		}
		
		cout << "<========DELETE SUCCESS !===========>" << endl;
	}
	else cout << "<========DELETE FALL !===========>" << endl;
		
	

 } //filename으로 item을 찾아서 제거한다.

int  Application::ReplaceItem() //해당 filename의 item을 변경한다.
{ 
	MasterType data;
	MasterType item;

	EventType eitem;
	MemberType mitem;
	PlaceType pitem;
	data.SetRecordFromKB();
	item.SetId(data.GetId());
	
	if (m_List.Retrieve_BinaryS(item) == 1)
	{
		//master list 제거
		m_List.Delete(item);
		int id = item.GetId();


		//event list 제거
		EventType data;
		DoublyIterator<EventType> e_iter(e_List);
		data.SetName(item.GetEvent());

		while (e_iter.NotNull())
		{
			if (e_iter.GetCurrentNodePtr()->data.GetName() == data.GetName())
			{
				if (e_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
				{
					e_List.Delete(data);
					break;
				}
				break;
			}
			e_iter.Next();
		}



		//place list 제거
		PlaceType data1;
		DoublyIterator<PlaceType> p_iter(p_List);
		data1.SetName(item.GetPlace());
		while (p_iter.NotNull())
		{
			if (p_iter.GetCurrentNodePtr()->data.GetName() == data1.GetName())
			{
				if (p_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
				{
					p_List.Delete(data1);
					break;
				}
			}
			p_iter.Next();
		}


		//member list 제거
		MemberType mitem;
		DoublyIterator<MemberType> m_iter(me_List);
		string name;
		int index_rear = item.GetMember().find(",");
		int index_front = -1;

		while (1) {
			name = item.GetMember().substr(index_front + 1, index_rear - index_front - 1);
			mitem.SetName(name);
			m_iter.First();
			while (m_iter.NotNull())
			{
				if (m_iter.GetCurrentNodePtr()->data.GetName() == mitem.GetName())
				{
					if (m_iter.GetCurrentNodePtr()->data.DeleteID(id) == 1)
					{
						me_List.Delete(mitem);
						break;
					}
				}
				m_iter.Next();
			}
			if (index_rear == -1)
				break;
			index_front = index_rear;
			index_rear = item.GetMember().find(",", index_front + 1);
		}
	}
	
	
	m_List.Add(data); // master list에 자료 추가

	eitem.SetName(data.GetEvent()); // event list에 자료 추가
	if (e_List.GetLength() == 0)
	{
		AddEvent(data.GetEvent());
		AddKeyToEvent(data.GetEvent(), data.GetId());
	}
	else
	{
		if (e_List.Get(eitem)) //event가 있을 경우
		{
			AddKeyToEvent(data.GetEvent(), data.GetId());
		}
		else
		{
			AddEvent(data.GetEvent());
			AddKeyToEvent(data.GetEvent(), data.GetId());
		}
	}
	pitem.SetName(data.GetPlace());// place list에 자료 추가
	if (p_List.Get(pitem)) //place가 있을 경우
	{
		AddKeyToPlace(data.GetPlace(), data.GetId());
	}
	else
	{
		AddPlace(data.GetPlace());
		AddKeyToPlace(data.GetPlace(), data.GetId());
	}

	string name;			// memberlist에 자료 추가
	int index_rear = data.GetMember().find(",");
	int index_front = -1;
	while (1) { // member list에 사람별로 분류해서 변수에 저장 후 객체별로 저장
		name = data.GetMember().substr(index_front + 1, index_rear - index_front - 1);
		mitem.SetName(name);
		if (me_List.Get(mitem))//member가 있을 경우
		{
			AddKeyToMember(name, data.GetId());
		}
		else
		{
			AddMember(name);
			AddKeyToMember(name, data.GetId());
		}
		if (index_rear == -1)
			break;
		index_front = index_rear;
		index_rear = data.GetMember().find(",", index_front + 1);
	}
	
	DisplayAllItem();

	return 1;
}

int  Application::RetrieveByID_BinaryS() //이진탐색 방법으로 filename과 일치하는 item을 찾아서 출력
{ 
	MasterType item;

	item.SetIdFromKB();
	if (m_List.Retrieve_BinaryS(item))
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;


 } 

void  Application::MakeEmpty()
{
	m_List.MakeEmpty();
	e_List.MakeEmpty();
	me_List.MakeEmpty();
	p_List.MakeEmpty();
}

void  Application::Retrieve_Event()
{
	EventType eitem;
	MasterType temp;
	DoublyIterator<EventType> iter(e_List);
	DoublySortedLinkedList<int> id_List;
	eitem.SetNameFromKB();
	int result = 0;
	int check;
	if (e_List.Get(eitem))
	{
		eitem.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{	
				if(result == 0)
					cout << "<============I FOUND ITEM !==========>" << endl;
				temp.DisplayRecordOnScreen();
				cout << "\t-----------------" << endl;
				result = 1;
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
}

void  Application::Retrieve_Member() 
{
	MemberType item;
	MasterType temp;
	DoublyIterator<MemberType> iter(me_List);
	DoublySortedLinkedList<int> id_List;
	item.SetNameFromKB();
	int result = 0;
	int check;
	if (me_List.Get(item))
	{
		item.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{
				if (result == 0)
					cout << "<============I FOUND ITEM !==========>" << endl;
				temp.DisplayRecordOnScreen();
				cout << "\t-----------------" << endl;
				result = 1;
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
}

void  Application::Retrieve_Place()
{
	PlaceType item;
	MasterType temp;
	DoublyIterator<PlaceType> iter(p_List);
	DoublySortedLinkedList<int> id_List;
	item.SetNameFromKB();
	int result = 0;
	int check;
	if (p_List.Get(item))
	{
		item.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{
				if (result == 0)
					cout << "<============I FOUND ITEM !==========>" << endl;
				temp.DisplayRecordOnScreen();
				cout << "\t-----------------" << endl;
				result = 1;
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
}

void  Application::RetrieveByName_Event() 
{
	EventType Event;
	MasterType tmp;
	MasterType temp;
	DoublyIterator<EventType> e_iter(e_List);
	DoublySortedLinkedList<int> id_List;
	Event.SetNameFromKB();
	tmp.SetMemberFromKB();
	int result = 0;
	int check;
	if (e_List.Get(Event))
	{
		Event.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{
				if (temp.GetMember().find(tmp.GetMember()) != -1)
				{
					if (result == 0)
						cout << "<============I FOUND ITEM !==========>" << endl;
					temp.DisplayRecordOnScreen();
					cout << "\t-----------------" << endl;
					result = 1;
				}
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
}

void  Application::RetrieveByName_Member() 
{
	MemberType Mem;
	MasterType tmp;
	MasterType temp;
	DoublyIterator<MemberType> m_iter(me_List);
	DoublySortedLinkedList<int> id_List;
	Mem.SetNameFromKB();
	cout << "Another";
	tmp.SetMemberFromKB();
	int result = 0;
	int check;
	if (me_List.Get(Mem))
	{
		Mem.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{
				if (temp.GetMember().find(tmp.GetMember()) != -1)
				{
					if (result == 0)
						cout << "<============I FOUND ITEM !==========>" << endl;
					temp.DisplayRecordOnScreen();
					cout << "\t-----------------" << endl;
					result = 1;
				}
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
}

void  Application::RetrieveByName_Place() 
{
	PlaceType item;
	MasterType tmp;
	MasterType temp;
	DoublyIterator<PlaceType> p_iter(p_List);
	DoublySortedLinkedList<int> id_List;
	item.SetNameFromKB();
	cout << "Another";
	tmp.SetMemberFromKB();
	int result = 0;
	int check;
	if (p_List.Get(item))
	{
		item.GetIdlist(id_List);
		m_List.ResetList();
		while (m_List.GetNextItem(temp) != -1)
		{
			check = temp.GetId();
			if (id_List.Get(check))
			{
				if (temp.GetMember().find(tmp.GetMember()) != -1)
				{
					if (result == 0)
						cout << "<============I FOUND ITEM !==========>" << endl;
					temp.DisplayRecordOnScreen();
					cout << "\t-----------------" << endl;
					result = 1;
				}
			}
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
		
}

void  Application::Add_FC() //콘텐츠를 선정하여 FC_list에 추가
{
	int check;
	cout << "\t1. Add Favorite Photo List\n";
	cout << "\t2. Add Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;
	if (check == 1)
	{
		FCphotoType item1;
		MasterType tmpitem;

		item1.SetRecordFromKB();
		tmpitem.SetId(item1.GetId());
		if (!m_List.Retrieve_BinaryS(tmpitem))
		{
			cout << "<============I NOT FOUND ITEM !==========>" << endl;
			return;
		}
		FCp_List.EnQueue(item1);
		FCp_List.Display_All();
	}
	else if (check == 2)
	{
		FCvideoType item2;
		MasterType tmpitem;

		item2.SetRecordFromKB();
		tmpitem.SetId(item2.GetId());
		if (!m_List.Retrieve_BinaryS(tmpitem))
		{
			cout << "<============I NOT FOUND ITEM !==========>" << endl;
			return;
		}
		FCv_List.EnQueue(item2);
		FCv_List.Display_All();
	}
	else
		cout << "\tBye Bye" << endl;

	return;
} 

void  Application::Delete_FC() //입력된 FC를 FC_list에서 삭제
{
	int check;
	cout << "\t1. Delete Favorite Photo List\n";
	cout << "\t2. Delete Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;
	if (check == 1)
	{
		FCphotoType item;
		item.SetIdFromKB();
		if (FCp_List.Delete(item))
		{
			cout << "<========DELETE SUCCESS !===========>" << endl;
			return;
		}
		cout << "<========DELETE FAIL !=======>" << endl;
		return;
	}
	else if (check == 2)
	{
		FCvideoType item;
		item.SetIdFromKB();
		if (FCv_List.Delete(item))
		{
			cout << "<========DELETE SUCCESS !===========>" << endl;
			return;
		}
		cout << "<========DELETE FAIL !=======>" << endl;
		return;
	}
	else
		cout << "\tBye Bye" << endl;
} 

void  Application::Display_FC_list() //FC_list에 들어있는 정보를 화면에 출력
{
	int check;
	cout << "\t1. Display Favorite Photo List\n";
	cout << "\t2. Display Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;
	if (check == 1)
	{
		FCp_List.Display_All();
	}
	else if (check == 2)
		FCv_List.Display_All();
	else
		cout << "\tBye Bye" << endl;
} 

void  Application::Display_Detail_FC() //특정FC의 자세한 정보(master list에 저장된 정보)를 화면에 출력
{
	int check;
	MasterType m_item;
	cout << "\t1. Display Detail Favorite Photo List\n";
	cout << "\t2. Display Detail Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;
	if (check == 1)
	{
		FCphotoType item;
		item.SetIdFromKB();
		if (FCp_List.Retrieve_Q(item))
		{
			m_item.SetId(item.GetId());
			m_List.Retrieve_BinaryS(m_item);
			cout << "<============I FOUND ITEM !==========>" << endl;
			m_item.DisplayRecordOnScreen();
			cout << "<====================================>" << endl;
			return;
		}
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
		return;
	}
	else if (check == 2)
	{

		FCvideoType item;
		item.SetIdFromKB();
		if (FCv_List.Retrieve_Q(item))
		{
			m_item.SetId(item.GetId());
			m_List.Retrieve_BinaryS(m_item);
			cout << "<============I FOUND ITEM !==========>" << endl;
			m_item.DisplayRecordOnScreen();
			cout << "<====================================>" << endl;
			return;
		}
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
		return;
	}
	else
		cout << "\tBye Bye" << endl;
} 

void  Application::Rearrange_FC() //키보드로부터 조건을 입력받아서 FC의 보는 순서를 바꾼다.
{
	int check;
	cout << "\t1. Rearrange Favorite Photo List\n";
	cout << "\t2. Rearrange Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;

	if (check == 1)
	{
		int cond;
		cout << "\t1 : 들어온 순   2 : 이름 순   " << endl;
		cout << "\tCondition : ";
		cin >> cond;

		if (cond == 1) {
			FCp_List.Display_All();
			return;
		}
		else if (cond == 2) {

			FCp_List.Rearrange_By_FileName();
			FCp_List.Display_All();
			return;
		}
		else {
			cout << "\tFail" << endl;
			return;
		}
		return;
	}
	else if (check == 2)
	{
		int cond;
		cout << "\t1 : 들어온 순   2 : 이름 순   " << endl;
		cout << "\tCondition : ";
		cin >> cond;

		if (cond == 1) {
			FCv_List.Display_All();
			return;
		}
		else if (cond == 2) {

			FCv_List.Rearrange_By_FileName();
			FCv_List.Display_All();
			return;
		}
		else {
			cout << "\tFail" << endl;
			return;
		}
		return;
	}
	else
		cout << "\tBye Bye" << endl;

	} 

int  Application::OpenInFile(char* fileName) // Open a file by file descriptor as an input file.
{ 
	m_InFile.open(fileName);
	if (!m_InFile)
		return 0;
	else
		return 1;
} 

int  Application::OpenOutFile(char* fileName) // Open a file by file descriptor as an output file.
{
	m_OutFile.open(fileName);
	if (!m_OutFile)
		return 0;
	else
		return 1;
} 

int  Application::ReadDataFromFile() // Open a file as a read mode, read all data on the file, and set list by the data.
{
	int index = 0;
	MasterType item;
	EventType eitem;
	MemberType mitem;
	PlaceType pitem;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof()) {
		item.ReadDataFromFile(m_InFile);
		if (m_InFile.eof())
			break;
		m_List.Add(item);
		
		eitem.SetName(item.GetEvent()); // event list에 자료 추가
		if (e_List.GetLength() == 0)
		{
			AddEvent(item.GetEvent());
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
		else
		{
			if (e_List.Get(eitem)) //event가 있을 경우
			{
				AddKeyToEvent(item.GetEvent(), item.GetId());
			}
			else
			{
				AddEvent(item.GetEvent());
				AddKeyToEvent(item.GetEvent(), item.GetId());
			}
		}
		pitem.SetName(item.GetPlace());// place list에 자료 추가
		if (p_List.Get(pitem)) //place가 있을 경우
		{
			AddKeyToPlace(item.GetPlace(), item.GetId());
		}
		else
		{
			AddPlace(item.GetPlace());
			AddKeyToPlace(item.GetPlace(), item.GetId());
		}

		string name;			// memberlist에 자료 추가
		int index_rear = item.GetMember().find(",");
		int index_front = -1;
		while (1) { // member list에 사람별로 분류해서 변수에 저장 후 객체별로 저장
			name = item.GetMember().substr(index_front + 1, index_rear - index_front - 1);
			mitem.SetName(name);
			if (me_List.Get(mitem))//member가 있을 경우
			{
				AddKeyToMember(name, item.GetId());
			}
			else
			{
				AddMember(name);
				AddKeyToMember(name, item.GetId());
			}
			if (index_rear == -1)
				break;
			index_front = index_rear;
			index_rear = item.GetMember().find(",", index_front + 1);
		}
	}
	m_InFile.close();
	DisplayAllItem();

	return 1; 
} 

int  Application::WriteDataToFile() // Open a file as a write mode, and write all data into the file,
{
	MasterType data;
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}
	m_OutFile.close();

	return 1;
}
int Application::play()
{
	MasterType tmp;
	cout << "\t출력하고 싶은 파일의 이름을 입력하세요.\n";
	tmp.SetIdFromKB();
	m_List.Retrieve_BinaryS(tmp);

	if (tmp.GetName() == "사진")
	{
		Mat image;
		string str = to_string(tmp.GetId());
		str = str + ".jpg";
		image = imread(str);
		if (image.empty()) {
			cout << "cannot open file";
			return -1;
		}

		namedWindow("파일 관리 시스템", WINDOW_AUTOSIZE);
		imshow("파일 관리 시스템", image);

		waitKey(0);
	}
	else if (tmp.GetName() == "비디오")
	{
		cout << "\t 영상을 종료하려면 esc를 누르세요!" << endl;
		Mat frameMat;
		VideoCapture cap;

		string str = to_string(tmp.GetId());
		str = str + ".mp4";
		cap.open(str);

		if (!cap.isOpened())
		{
			cout << "Camera open failed!" << endl;
			return -1;
		}
		while (1)
		{
			if (cap.read(frameMat))
			{
				if (frameMat.empty())
				{
					cout << "empty frame found...\n";
					break;
				}
				namedWindow("파일 관리 시스템", WINDOW_AUTOSIZE);
				imshow("파일 관리 시스템", frameMat);
				if (waitKey(25) == 27)
					break;
			}
			else break;
		}

		destroyAllWindows();
	}
	else return 0;

	return 0;

}