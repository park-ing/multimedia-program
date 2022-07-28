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
		cout << "\tȯ���մϴ�!" << endl;
		cout << "\t(�ʱ� ���̵� : 1234 / �ʱ� ��й�ȣ : 1234)" << endl;
		cout << "\t ���̵�->";
		cin >> ID;
		cout << "\t ��й�ȣ->";
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
			cout << "\n\t***�α��� ����!!***" << endl;
			cout << "\t���� " << count << " �� ����...(3�� ���н� ����)" << endl;
		}
		system("pause");
	}

}


int Application::start()
{
	system("cls");
	int command;
	cout << endl << endl;
	cout << "\t====���� ���� �ý���====\n";
	cout << "\t|                      |" << endl;
	cout << "\t|  1. �α���           |" << endl;
	cout << "\t|  2. ȸ������         |" << endl;
	cout << "\t|  3. ����             |" << endl;
	cout << "\t|                      |" << endl;
	cout << "\t========================" << endl;
	cout << endl << "\t�Է�-->";
	cin >> command;
	cout << endl;
	return command;
}

int Application::regist()
{
	system("cls");
	cout << endl << endl;
	cout << "\t========ȸ������========\n";
	cout << "\t   ���ο� ���̵� : ";
	cin >> id;
	cout << "\t   ���ο� ��й�ȣ : ";
	cin >> pw;
	cout << "\t=====ȸ������ �Ϸ�======" << endl;
	return 1;
}

//Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl << endl;
	cout << "\t======================���� ���� �ý���====================== " << endl;
	cout << "\t   1 : ���� �߰�" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ����" << endl;
	cout << "\t   4 : ���� �˻�" << endl;
	cout << "\t   5 : ���� ����Ʈ ���" << endl;
	cout << "\t   6 : ����� ����Ʈ ����" << endl;
	cout << "\t ---------------------�� �˻� �޴�---------------------" << endl;
	cout << "\t   7 : �̺�Ʈ �̸����� �˻�" << endl;
	cout << "\t   8 : �Բ��� �ι��� �˻�" << endl;
	cout << "\t   9 : �̺�Ʈ ��Ҹ����� �˻�" << endl;
	cout << "\t  10 : �̺�Ʈ �̸� & �Բ��� �ι��� �˻�" << endl;
	cout << "\t  11 : �Բ��� �ι� & �� �ٸ� �Բ��� �ι��� �˻�" << endl;
	cout << "\t  12 : �̺�Ʈ ��� & �Բ��� �ι��� �˻�" << endl;
	cout << "\t --------------------------------------------------------" << endl;
	cout << "\t ---------------------���ã�� �޴�----------------------" << endl;
	cout << "\t  13 : ���ã�⿡ ���� �߰�" << endl;
	cout << "\t  14 : ���ã���� ���� ����" << endl;
	cout << "\t  15 : ���ã�� ���� ��� ���" << endl;
	cout << "\t  16 : ���ã�� ���� �˻�" << endl;
	cout << "\t  17 : �޴� ���� ���� ����" << endl;
	cout << "\t --------------------------------------------------------" << endl;
	cout << "\t  18 : �ܺο��� �ҷ�����" << endl;
	cout << "\t  19 : Text���Ϸ� �����ϱ�" << endl;
	cout << "\t  20 : @@����� ���� ���@@" << endl;
	cout << "\t   0 : ����" << endl;

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
	m_List.Add(item); // master list�� �ڷ� �߰�
	
	eitem.SetName(item.GetEvent()); // event list�� �ڷ� �߰�
	if (e_List.GetLength() == 0)
	{
		AddEvent(item.GetEvent());
		AddKeyToEvent(item.GetEvent(), item.GetId());
	}
	else
	{
		if (e_List.Get(eitem)) //event�� ���� ���
		{
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
		else
		{
			AddEvent(item.GetEvent());
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
	}
	pitem.SetName(item.GetPlace());// place list�� �ڷ� �߰�
	if (p_List.Get(pitem)) //place�� ���� ���
	{
		AddKeyToPlace(item.GetPlace(), item.GetId()); 
	}
	else 
	{
		AddPlace(item.GetPlace());
		AddKeyToPlace(item.GetPlace(), item.GetId());
	}
	
	string name;			// memberlist�� �ڷ� �߰�
	int index_rear = item.GetMember().find(",");
	int index_front = -1;
	while (1) { // member list�� ������� �з��ؼ� ������ ���� �� ��ü���� ����
		name = item.GetMember().substr(index_front + 1, index_rear - index_front -1);
		mitem.SetName(name);
		if (me_List.Get(mitem))//member�� ���� ���
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
	cout << "\t *����� ���� ����Ʈ*" << endl << endl;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
		cout << "\t--------------------" << endl;
	}

	cout << "\n\t �̺�Ʈ�� ���\n";
	// event list�� ȭ�鿡 ���
	while (e_iter.NotNull()) {
		e_iter.GetCurrentNodePtr()->data.DisplayRecordOnScreen();
		e_iter.Next();
		cout << "\t--------------------" << endl;
	}


	cout << "\n\t �Բ��� ����� ���\n";
	// member list�� ȭ�鿡 ���
	while (m_iter.NotNull()) {
		m_iter.GetCurrentNodePtr()->data.DisplayRecordOnScreen();
		m_iter.Next();
		cout << "\t--------------------" << endl;
	}


	cout << "\n\t ��ġ ���\n";
	// place list�� ȭ�鿡 ���
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
		//master list ����
		m_List.Delete(item);
		int id = item.GetId();

		
		//event list ����
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
		

		
		//place list ����
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

		
		//member list ����
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
		
	

 } //filename���� item�� ã�Ƽ� �����Ѵ�.

int  Application::ReplaceItem() //�ش� filename�� item�� �����Ѵ�.
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
		//master list ����
		m_List.Delete(item);
		int id = item.GetId();


		//event list ����
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



		//place list ����
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


		//member list ����
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
	
	
	m_List.Add(data); // master list�� �ڷ� �߰�

	eitem.SetName(data.GetEvent()); // event list�� �ڷ� �߰�
	if (e_List.GetLength() == 0)
	{
		AddEvent(data.GetEvent());
		AddKeyToEvent(data.GetEvent(), data.GetId());
	}
	else
	{
		if (e_List.Get(eitem)) //event�� ���� ���
		{
			AddKeyToEvent(data.GetEvent(), data.GetId());
		}
		else
		{
			AddEvent(data.GetEvent());
			AddKeyToEvent(data.GetEvent(), data.GetId());
		}
	}
	pitem.SetName(data.GetPlace());// place list�� �ڷ� �߰�
	if (p_List.Get(pitem)) //place�� ���� ���
	{
		AddKeyToPlace(data.GetPlace(), data.GetId());
	}
	else
	{
		AddPlace(data.GetPlace());
		AddKeyToPlace(data.GetPlace(), data.GetId());
	}

	string name;			// memberlist�� �ڷ� �߰�
	int index_rear = data.GetMember().find(",");
	int index_front = -1;
	while (1) { // member list�� ������� �з��ؼ� ������ ���� �� ��ü���� ����
		name = data.GetMember().substr(index_front + 1, index_rear - index_front - 1);
		mitem.SetName(name);
		if (me_List.Get(mitem))//member�� ���� ���
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

int  Application::RetrieveByID_BinaryS() //����Ž�� ������� filename�� ��ġ�ϴ� item�� ã�Ƽ� ���
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

void  Application::Add_FC() //�������� �����Ͽ� FC_list�� �߰�
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

void  Application::Delete_FC() //�Էµ� FC�� FC_list���� ����
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

void  Application::Display_FC_list() //FC_list�� ����ִ� ������ ȭ�鿡 ���
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

void  Application::Display_Detail_FC() //Ư��FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���
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

void  Application::Rearrange_FC() //Ű����κ��� ������ �Է¹޾Ƽ� FC�� ���� ������ �ٲ۴�.
{
	int check;
	cout << "\t1. Rearrange Favorite Photo List\n";
	cout << "\t2. Rearrange Favorite video List\n";
	cout << "\t  Command --> ";
	cin >> check;

	if (check == 1)
	{
		int cond;
		cout << "\t1 : ���� ��   2 : �̸� ��   " << endl;
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
		cout << "\t1 : ���� ��   2 : �̸� ��   " << endl;
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
		
		eitem.SetName(item.GetEvent()); // event list�� �ڷ� �߰�
		if (e_List.GetLength() == 0)
		{
			AddEvent(item.GetEvent());
			AddKeyToEvent(item.GetEvent(), item.GetId());
		}
		else
		{
			if (e_List.Get(eitem)) //event�� ���� ���
			{
				AddKeyToEvent(item.GetEvent(), item.GetId());
			}
			else
			{
				AddEvent(item.GetEvent());
				AddKeyToEvent(item.GetEvent(), item.GetId());
			}
		}
		pitem.SetName(item.GetPlace());// place list�� �ڷ� �߰�
		if (p_List.Get(pitem)) //place�� ���� ���
		{
			AddKeyToPlace(item.GetPlace(), item.GetId());
		}
		else
		{
			AddPlace(item.GetPlace());
			AddKeyToPlace(item.GetPlace(), item.GetId());
		}

		string name;			// memberlist�� �ڷ� �߰�
		int index_rear = item.GetMember().find(",");
		int index_front = -1;
		while (1) { // member list�� ������� �з��ؼ� ������ ���� �� ��ü���� ����
			name = item.GetMember().substr(index_front + 1, index_rear - index_front - 1);
			mitem.SetName(name);
			if (me_List.Get(mitem))//member�� ���� ���
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
	cout << "\t����ϰ� ���� ������ �̸��� �Է��ϼ���.\n";
	tmp.SetIdFromKB();
	m_List.Retrieve_BinaryS(tmp);

	if (tmp.GetName() == "����")
	{
		Mat image;
		string str = to_string(tmp.GetId());
		str = str + ".jpg";
		image = imread(str);
		if (image.empty()) {
			cout << "cannot open file";
			return -1;
		}

		namedWindow("���� ���� �ý���", WINDOW_AUTOSIZE);
		imshow("���� ���� �ý���", image);

		waitKey(0);
	}
	else if (tmp.GetName() == "����")
	{
		cout << "\t ������ �����Ϸ��� esc�� ��������!" << endl;
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
				namedWindow("���� ���� �ý���", WINDOW_AUTOSIZE);
				imshow("���� ���� �ý���", frameMat);
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