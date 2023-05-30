#include<iostream>
#include<string>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;
char* wqt()
{
	time_t now = time(0);
	char* date_time = ctime(&now);
	tm* gmtm = gmtime(&now);
	date_time = asctime(gmtm);
	//cout << "The current date and time is: " << date_time << endl;
	return date_time;
}
class Fnode
{
public:
	string name;
	string username;

	Fnode* next;
	Fnode* pre;
	Fnode(string tname = NULL, string tusername = NULL)
	{

		name = tname;
		username = tusername;
		next = NULL;
		pre = NULL;

	}
};

class Stac_F
{
public:
	Fnode* head;
	Fnode* tail;
	Stac_F()
	{
		head = NULL;
		tail = NULL;

	}
	void push(string val, string fusrnm)
	{
		Fnode* myFnode = new Fnode(val, fusrnm);
		if (head == NULL)
		{
			head = myFnode;
			tail = head;


		}
		else
		{


			while (tail->next != NULL)
			{


				tail = tail->next;
			}
			tail->next = myFnode;
			myFnode->pre = tail;

			tail = myFnode;
			//ti = wqt();

		}

	}
	Fnode* pop()
	{
		if (tail == NULL)
		{
			return tail;
		}
		else
		{
			Fnode* npop = top();
			Fnode* temp1 = tail;
			tail = temp1->pre;
			temp1->pre->next = NULL;
			temp1->pre = NULL;
			temp1 = temp1->pre;
			return npop;
		}
	}
	Fnode* top()
	{
		Fnode* tempt = tail;
		return tempt;
	}
	Fnode* gtnd(int in)
	{
		in = in - 1;
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->pre;
			}
		}
		return temp;
	}
	void del(int ind)
	{
		Fnode* temp = gtnd(ind);
		remove(temp->name);



	}
	void upd(int x)
	{
		Fnode* temp = gtnd(x);
		update(temp->name);
	}
	void remove(string val)
	{
		Fnode* temp = head;
		if (head->name == val)
		{
			if (head->next != NULL)
			{
				head->next->pre = head->pre;
				head = head->next;
			}
			else
			{
				head = NULL;
			}

		}
		else if (tail->name == val)
		{
			tail->pre->next = tail->next;
			tail = tail->pre;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;

				}
				temp = temp->next;
			}
		}
	}
	void update(string val)
	{
		Fnode* temp = head;
		string updt;
		if (head->name == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			head->name = updt;

		}
		else if (tail->name == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			tail->name = updt;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					cin.ignore();
					cout << "Update Your Post..!!!" << endl;
					getline(cin, updt);
					temp->name = updt;

				}
				temp = temp->next;
			}
		}
	}
	bool search(string val)
	{
		bool flag = false;
		Fnode* temp = head;
		if (head->name == val)
		{
			flag = true;

		}
		else if (tail->name == val)
		{
			flag = true;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{

					flag = true;

				}
				temp = temp->next;
			}

		}
		if (flag == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Display_U()
	{
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->name << endl;
				temp = temp->pre;
				i++;
			}
		}
	}

	void Display()
	{
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->name << endl;
				cout << "______" << endl;
				temp = temp->pre;
			}
		}
	}
};

class Mnode
{
public:
	string data;
	string name;
	char* tim;
	Mnode* next;
	Mnode* pre;
	Mnode(string tdata = NULL, string tname = NULL, char* ttim = NULL)
	{
		data = tdata;
		name = tname;
		tim = ttim;
		next = NULL;
		pre = NULL;

	}
};

class Queue_M
{
public:
	Mnode* head;
	Mnode* tail;
	Queue_M()
	{
		head = NULL;
		tail = NULL;

	}
	void push(string val, string nam)
	{
		Mnode* myMnode = new Mnode(val, nam, wqt());
		if (head == NULL)
		{
			head = myMnode;
			tail = head;


		}
		else
		{


			while (tail->next != NULL)
			{


				tail = tail->next;
			}
			tail->next = myMnode;
			myMnode->pre = tail;

			tail = myMnode;
			//ti = wqt();

		}

	}
	Mnode* pop()
	{
		if (tail == NULL)
		{
			return tail;
		}
		else
		{
			Mnode* npop = top();
			Mnode* temp1 = tail;
			tail = temp1->pre;
			temp1->pre->next = NULL;
			temp1->pre = NULL;
			temp1 = temp1->pre;
			return npop;
		}
	}
	Mnode* top()
	{
		Mnode* tempt = tail;
		return tempt;
	}
	Mnode* gtnd(int in)
	{
		in = in - 1;
		Mnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->pre;
			}
		}
		return temp;
	}
	void del(int ind)
	{
		Mnode* temp = gtnd(ind);
		remove(temp->data);



	}
	void upd(int x)
	{
		Mnode* temp = gtnd(x);
		update(temp->data);
	}
	void remove(string val)
	{
		Mnode* temp = head;
		if (head->data == val)
		{
			if (head->next != NULL)
			{
				head->next->pre = head->pre;
				head = head->next;
			}
			else
			{
				head = NULL;
			}

		}
		else if (tail->data == val)
		{
			tail->pre->next = tail->next;
			tail = tail->pre;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->data == val)
				{
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;

				}
				temp = temp->next;
			}
		}
	}
	void update(string val)
	{
		Mnode* temp = head;
		string updt;
		if (head->data == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			head->data = updt;

		}
		else if (tail->data == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			tail->data = updt;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->data == val)
				{
					cin.ignore();
					cout << "Update Your Post..!!!" << endl;
					getline(cin, updt);
					temp->data = updt;

				}
				temp = temp->next;
			}
		}
	}
	void Display_U()
	{
		Mnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->data << endl;
				temp = temp->pre;
				i++;
			}
		}
	}
	void Display()
	{
		Mnode* temp = head;

		if (head == NULL)
		{
			cout << "EMPTY LIST..." << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->name << " : " << endl;
				cout << "           " << temp->data << endl;
				cout << "                                                                  " << temp->tim << endl;
				cout << "___________" << endl;
				temp = temp->next;
			}
		}
	}

};
class Comments
{
public:
	Queue_M cmnt;
	Comments()
	{

	}
	void add_cmnt(string comnt, string name)
	{
		cmnt.push(comnt, name);
	}
	void display_cmnts()
	{
		cmnt.Display();
	}
};

class node
{
public:
	Comments cmt;
	string data;
	string name;
	char* tim;
	node* next;
	node* pre;
	node(string tdata = NULL, string tname = NULL, char* ttim = NULL)
	{
		data = tdata;
		name = tname;
		tim = ttim;
		next = NULL;
		pre = NULL;

	}
};


class Stack_L
{
public:
	node* head;
	node* tail;
	Stack_L()
	{
		head = NULL;
		tail = NULL;

	}
	void push(string val, string nm)
	{
		node* mynode = new node(val, nm, wqt());
		if (head == NULL)
		{
			head = mynode;
			tail = head;


		}
		else
		{


			while (tail->next != NULL)
			{


				tail = tail->next;
			}
			tail->next = mynode;
			mynode->pre = tail;

			tail = mynode;
			//ti = wqt();

		}

	}
	node* pop()
	{
		if (tail == NULL)
		{
			return tail;
		}
		else
		{
			node* npop = top();
			node* temp1 = tail;
			/*tail = temp1->pre;
			temp1->pre->next = NULL;
			temp1->pre = NULL;
			temp1 = temp1->pre;*/
			remove(tail->data);
			return npop;
		}
	}
	bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	node* top()
	{
		node* tempt = tail;
		return tempt;
	}
	node* gtnd(int in)
	{
		in = in - 1;
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->pre;
			}
		}
		return temp;
	}
	void del(int ind)
	{
		node* temp = gtnd(ind);
		remove(temp->data);



	}
	void upd(int x)
	{
		node* temp = gtnd(x);
		update(temp->data);
	}
	/*void dsingle(int t)
	{
		node* temp = gtnd(t);
		dis_single(temp->data);

	}*/
	/*void dis_single()
	{
		int a;
		string ct;*/
		//node* temp = head;
		//if (head->data == val)

/*
			cout << "---------------------------------------------------------" << endl;
			cout << head->data << endl;*/
			//			cout << "---------------------------------------------------------" << endl;
			//			cout << "------Comments------" << endl << endl << endl;
			//
			//
			//			cout << "------------------------- " << endl;
			//			cout << "1- Add New Comment " << endl;
			//			cout << "2- Display All Comments " << endl;
			//			cout << "3- Go Back " << endl;
			//			cout << "------------------------- " << endl;
			//			cout << "Enter Your Option " << endl;
			//			cin >> a;
			//			while (a < 1 || a>2)
			//			{
			//				cout << "Enter Valid Option...!!!!" << endl;
			//				cin >> a;
			//			}
			//			system("CLS");
			//			switch (a)
			//			{
			//			case 1:
			//			{
			//				//	system("CLS");
			//				cin.ignore();
			//				cout << "Enter Comment : " << endl;
			//				getline(cin, ct);
			//				//temp->cmt.add_cmnt(ct);
			//				break;
			//
			//			}
			//			case 2:
			//			{
			//				temp->cmt.display_cmnts();
			//			}
			//			case 3:
			//			{
			//				goto l1;
			//			}
			//			default:
			//				break;
			//			}
			//		
			//		/*else if (tail->data == val)
			//		{
			//			cout << "---------------------------------------------------------" << endl;
			//			cout << tail->data << endl;
			//			cout << "---------------------------------------------------------" << endl;
			//			cout << "------Comments------" << endl;
			//			temp->cmt.display_cmnts();
			//
			//		}
			//		else
			//		{
			//			while (temp->next != NULL)
			//			{
			//				if (temp->data == val)
			//				{
			//					cout << "---------------------------------------------------------" << endl;
			//					cout << temp->data << endl;
			//					cout << "---------------------------------------------------------" << endl;
			//					cout << "------Comments------" << endl;
			//					temp->cmt.display_cmnts();
			//
			//
			//				}
			//				temp = temp->next;
			//			}
			//		}
			//*/
			//	    l1:

				//}
	node* ser(int va)
	{
		node* temp = gtnd(va);
		return search(temp->data);
	}
	node* search(string val)
	{
		bool flag = false;
		node* temp = head;
		node* stemp = head;
		if (head->name == val)
		{
			flag = true;

		}
		else if (tail->name == val)
		{
			stemp = tail;
			flag = true;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					stemp = temp;
					flag = true;

				}
				temp = temp->next;
			}

		}
		if (flag == true)
		{
			return stemp;
		}
		else
		{
			return NULL;
		}
	}
	void remove(string val)
	{
		node* temp = head;
		if (head->data == val)
		{
			if (head->next != NULL)
			{
				head->next->pre = head->pre;
				head = head->next;
			}
			else
			{
				head = NULL;
			}

		}
		else if (tail->data == val)
		{
			tail->pre->next = tail->next;
			tail = tail->pre;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->data == val)
				{
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;

				}
				temp = temp->next;
			}
		}
	}
	void update(string val)
	{
		node* temp = head;
		string updt;
		if (head->data == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			head->data = updt;

		}
		else if (tail->data == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			tail->data = updt;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->data == val)
				{
					cin.ignore();
					cout << "Update Your Post..!!!" << endl;
					getline(cin, updt);
					temp->data = updt;

				}
				temp = temp->next;
			}
		}
	}
	void Display_s()
	{
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->name << " : " << endl;
				cout << "          " << temp->data << endl;
				cout << "                                                        " << temp->tim << endl;
				temp = temp->pre;
				i++;
			}
		}
	}
	void Display_U(string nam)
	{
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->name << " : " << endl;
				cout << "          " << temp->data << endl;
				cout << "                                                        " << temp->tim << endl;
				//dis_single();
				string ct;
				int a;
				cout << "---------------------------------------------------------" << endl;
				cout << "------Comments------" << endl << endl << endl;


				cout << "------------------------- " << endl;
				cout << "1- Add New Comment " << endl;
				cout << "2- Display All Comments " << endl;
				cout << "3- Go Back To See Next Post " << endl;
				cout << "------------------------- " << endl;
				cout << "Enter Your Option " << endl;
				cin >> a;
				while (a < 1 || a>3)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> a;
				}
				system("CLS");
				switch (a)
				{
				case 1:
				{
					//	system("CLS");
					cin.ignore();
					cout << "Enter Comment : " << endl;
					getline(cin, ct);
					temp->cmt.add_cmnt(ct, nam);
					break;

				}
				case 2:
				{
					temp->cmt.display_cmnts();
				}
				case 3:
				{
					goto l1;
				}
				default:
					break;
				}

				/*else if (tail->data == val)
				{
					cout << "---------------------------------------------------------" << endl;
					cout << tail->data << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "------Comments------" << endl;
					temp->cmt.display_cmnts();

				}
				else
				{
					while (temp->next != NULL)
					{
						if (temp->data == val)
						{
							cout << "---------------------------------------------------------" << endl;
							cout << temp->data << endl;
							cout << "---------------------------------------------------------" << endl;
							cout << "------Comments------" << endl;
							temp->cmt.display_cmnts();


						}
						temp = temp->next;
					}
				}
		*/
			l1:
				temp = temp->pre;
				i++;
			}
		}
	}
	void Display()
	{
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->data << endl;
				cout << "                                                              " << temp->tim << endl;
				cout << "______" << endl;
				temp = temp->pre;
			}
		}
	}
	/*void all_frnds()
	{

	}*/
};


class Lnode
{
public:
	string data;
	Lnode* next;
	Lnode(string tdata = NULL)
	{
		data = tdata;
		next = NULL;

	}
};

class Linked_List
{
public:
	Lnode* head;
	Linked_List()
	{
		head = NULL;

	}
	void insert(string val)
	{
		Lnode* myLnode = new Lnode(val);
		Lnode* temp = head;
		if (head == NULL)
		{
			head = myLnode;


		}
		else
		{


			while (temp->next != NULL)
			{


				temp = temp->next;
			}
			temp->next = myLnode;


		}

	}

	Lnode* gtnd(int in)
	{
		in = in - 1;
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void Display_U()
	{
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->data << endl;
				temp = temp->next;
				i++;
			}
		}
	}

	void Display()
	{
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->data << endl;
				cout << "                                                              " << endl;
				cout << "______" << endl;
				temp = temp->next;
			}
		}
	}
};

class NTNode {
public:
	char ch;
	string usernam;
	bool terminal;
	NTNode* child[53];

	NTNode(char c, string un)
	{
		ch = c;
		usernam = un;
		terminal = false;
		for (int i = 0; i < 53; i++)
		{
			child[i] = NULL;
		}
	}
};

class NTries
{
public:
	NTNode* root;
	Linked_List Lfrnd;
	Stack_L all_f;
	NTries()
	{
		root = createNode('\0', "");
	}

	NTNode* createNode(char c, string usrn)
	{
		NTNode* newNTNode = new NTNode(c, usrn);
		return newNTNode;
	}
	void Insert(string word, string uname)
	{
		NTNode* temp = root;
		string usnam = "";
		char ch = '\0';
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];

			pos = ch;

			if (pos >= 97 && pos <= 122)
			{
				pos = (pos + 0) - 97;
			}
			else if (pos >= 65 && pos <= 90)
			{
				pos = (pos + 26) - 65;
			}
			else if (pos == 32)
			{
				pos = (pos + 52) - 32;
			}


			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch, usnam);

			}
			temp = temp->child[pos];

		}
		temp->usernam = uname;
		temp->terminal = true;
	}
	void Display(NTNode* temp, string word)
	{

		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->ch != '\0')
				word = word + temp->ch;
			if (temp->terminal == true)
			{
				cout << word << endl;
			}
		}



		for (int i = 0; i < 53; i++)
		{

			Display(temp->child[i], word);
		}
	}
	int in = 1;
	void Display_s(NTNode* temp1, string word)
	{

		if (temp1 == NULL)
		{
			return;
		}
		else
		{
			if (temp1->ch != '\0')
				word = word + temp1->ch;
			if (temp1->terminal == true)
			{
				cout << "-------------- (" << in << ") --------------" << endl;
				cout << word << endl;
				Lfrnd.insert(word);
				in++;
			}
		}



		for (int i = 0; i < 53; i++)
		{

			Display_s(temp1->child[i], word);
		}
	}
	NTNode* search(NTNode* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch == 32)
		{
			i = ch - ' ';
			i = i + 52;
		}


		return	search(temp->child[i], key, ++index);

	}
	NTNode* search_s(NTNode* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch == 32)
		{
			i = ch - ' ';
			i = i + 52;
		}


		return	search_s(temp->child[i], key, ++index);

	}
	string gtusrnm(int indx)
	{
		string sname;
		sname = Lfrnd.gtnd(indx)->data;
		string susrn;
		susrn = search(root, sname, 0)->usernam;
		return susrn;
	}
	void all_push(NTNode* temp, string word)
	{

		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->ch != '\0')
				word = word + temp->ch;
			if (temp->terminal == true)
			{
				all_f.push(temp->usernam, word);
			}
		}



		for (int i = 0; i < 53; i++)
		{

			all_push(temp->child[i], word);
		}
	}
};

class all_users
{
public:
	NTries all_usr;
	all_users()
	{

	}
	void insert_user(string name, string uname)
	{
		all_usr.Insert(name, uname);
	}
	void display_usr(NTNode* temp2, string word)
	{
		all_usr.Display(temp2, word);
	}
	void display_s_usr(NTNode* temp4, string word)
	{
		all_usr.Display_s(temp4, word);
	}
	NTNode* search_usr(string key)
	{
		return all_usr.search(all_usr.root, key, 0);
	}
	NTNode* search_s_usr(string key)
	{
		return all_usr.search_s(all_usr.root, key, 0);
	}
	string gtusrnm_al(int inx)
	{
		return all_usr.gtusrnm(inx);
	}

};

class frnd
{
public:
	NTries frndz;
	Stac_F Req;
	Stack_L usernm;

	frnd()
	{

	}
	void add_frnd(string name, string uname)
	{
		frndz.Insert(name, uname);
	}
	void display_frnd()
	{
		frndz.Display(frndz.root, "");
	}
	bool search_frnd(string key)
	{
		bool temp6 = frndz.search(frndz.root, key, 0);

		if (temp6 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	NTNode* search_s_frnd(string key)
	{
		return frndz.search_s(frndz.root, key, 0);
	}
	void frnd_req(string rname, string rusername)
	{
		Req.push(rname, rusername);
	}
	string req_gtusrn(int nu)
	{
		return Req.gtnd(nu)->username;
	}
	bool search_req(string name)
	{
		bool temp5 = Req.search(name);
		if (temp5 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void rmv_req(string name)
	{
		Req.remove(name);
	}
	void show_req()
	{
		Req.Display_U();
	}
	void frnd_usnm()
	{

	}
};




class Posts
{
public:
	//Comments cmt;
	Stack_L post;
	Posts()
	{

	}


	void addPost(string apost, string aname)
	{
		//char* t = wqt();
		post.push(apost, aname);
	}
	void displayMyPost(string name)
	{
		post.Display_U(name);
	}
	void display_s()
	{
		post.Display_s();
	}
	void displayHPost()
	{
		post.Display();
	}
	node* ser(int val)
	{
		return post.ser(val);
	}
	void poop()
	{
		cout << post.pop()->data;
		post.Display();
	}
	void del_Post(int ino)
	{

		post.del(ino);
	}
	void update_post(int ix)
	{
		post.upd(ix);
	}

};

class Messages
{
public:
	Queue_M convo;
	Messages()
	{

	}
	void snd_msg(string msg, string name)
	{
		convo.push(msg, name);
	}
	void chat()
	{
		convo.Display();
	}

};

class Node {
public:
	char ch;
	bool terminal;
	string name;
	string pass;
	string num;
	Posts a;
	frnd f1;
	Messages M1;
	Node* child[62];

	Node(char c, string n, string p, string no)
	{
		ch = c;
		name = n;
		pass = p;
		num = no;
		terminal = false;
		for (int i = 0; i < 62; i++)
		{
			child[i] = NULL;
		}
	}
};

class Tries
{
public:
	Node* root;

	Tries()
	{
		root = createNode('\0', "", "", "");
	}

	Node* createNode(char c, string cn, string cp, string cno)
	{
		Node* newNode = new Node(c, cn, cp, cno);
		return newNode;
	}
	void Insert(string word, string in, string ip, string ino, Node* t)
	{

		Node* temp = t;
		char ch = '\0';
		string iname = "";
		string ipass = "";
		string inum = "";
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];

			pos = ch;

			if (pos >= 97 && pos <= 122)
			{
				pos = (pos + 0) - 97;
			}
			else if (pos >= 65 && pos <= 90)
			{
				pos = (pos + 26) - 65;
			}
			else if (pos >= 48 && pos <= 57)
			{
				pos = (pos + 52) - 48;
			}


			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch, iname, ipass, inum);

			}

			temp = temp->child[pos];

		}
		temp->name = in;
		temp->pass = ip;
		temp->num = ino;
		temp->terminal = true;
	}


	void Display_t(Node* temp, string word)
	{

		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->ch != '\0')
				word = word + temp->ch;
			if (temp->terminal == true)
			{
				cout << word << endl;
				cout << temp->name << endl;
				cout << temp->num << endl;
			}
		}



		for (int i = 0; i < 62; i++)
		{

			Display_t(temp->child[i], word);
		}
	}
	Node* search(Node* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch >= 48 && ch <= 57)
		{
			i = ch - '0';
			i = i + 52;
		}


		return	search(temp->child[i], key, ++index);

	}
	Node* signin(Node* temp, string us, string pass, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = us[index];

		if (temp->terminal && index == us.size() && temp->pass == pass)
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch >= 48 && ch <= 57)
		{
			i = ch - '0';
			i = i + 52;
		}


		return	signin(temp->child[i], us, pass, ++index);

	}
};

class Hash
{
public:
	//int size ;
	Tries bucket[62];


	/*Hash(int tsize=0)
	{
		size = tsize;
	}*/


	int Hash_fun(string nam)
	{
		int index;
		index = nam[0];

		if (index >= 97 && index <= 122)
		{
			index = (index + 0) - 97;
		}
		else if (index >= 65 && index <= 90)
		{
			index = (index + 26) - 65;
		}
		else if (index >= 48 && index <= 57)
		{
			index = (index + 52) - 48;
		}
		return index;

	}
	void Insert(string username, string in1, string ip1, string ino1)
	{
		int ind = Hash_fun(username);
		Node* temp = bucket[ind].root;

		bucket[ind].Insert(username, in1, ip1, ino1, temp);
	}
	Node* search(string uname)
	{
		int in = Hash_fun(uname);
		Node* temp = bucket[in].root;
		return bucket[in].search(temp, uname, 0);
	}
	Node* sign_in(string uname, string pass)
	{
		int in = Hash_fun(uname);
		Node* temp = bucket[in].root;
		return bucket[in].signin(temp, uname, pass, 0);
	}

	void Display()
	{

		//char c;
		//cout << "Enter 1st Alphabet of series : " << endl;
		//cin >>c;
		//int indx = c-97;
		for (int indx = 0; indx < 62; indx++)
		{

			bucket[indx].Display_t(bucket[indx].root, "");

		}
	}

};

int main()
{
	string key;
	Hash h1;
	all_users a1;
	//h1.Display();





	int a;
lable:
	cout << "                                =======================FAKEBOOK==========================\n" << endl;
	cout << "                                =================(BILAL JUTT & TALHA FAREED)===============\n" << endl;
	cout << "                                   *****************************************************\n"
		<< "                                         1-SIGN UP\n"
		<< "                                         2-SIGN IN\n"
		<< "                                         3-EXIT\n"
		<< "                                   ******************************************************\n";

	cout << "Enter Your Option " << endl;
	cin >> a;

	while (a < 1 || a>3)
	{
		cout << "Enter Valid Option...!!!!" << endl;
		cin >> a;
	}

	system("CLS");
	switch (a)
	{
	case 1:
	{
		cout << "=======================NEW ACCOUNT==========================\n";

		string name;
		string username;
		string password;
		string mobile_number;
		//h1.Insert("ali123", "ali", "123", "032143");
		cin.ignore();
		cout << "Enter Your Name : " << endl;
		getline(cin, name);
		while (name == "")
		{
			cout << "Name Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, name);
		}
		//cin >> name;
		cout << "Enter Your Username : " << endl;
		getline(cin, username);
		while (username == "")
		{
			cout << "Username Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, username);
		}
		//cin >> username;
		cout << "Enter Your Password : " << endl;
		getline(cin, password);
		while (password == "")
		{
			cout << "Password Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, password);
		}
		cout << "Enter Your Mobile Number : " << endl;
		getline(cin, mobile_number);
		while (mobile_number == "")
		{
			cout << "Mobile No. Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, mobile_number);
		}

		Node* temp = h1.search(username);
		while (temp)
		{
			cout << "USERNAME ALREADY EXISTS !!!!!  " << endl;
			cout << "Try Another Username : " << endl;
			getline(cin, username);
			temp = h1.search(username);
		}
		h1.Insert(username, name, password, mobile_number);
		//frnd.Insert(name);
		a1.insert_user(name, username);
		cout << "Successfully Signed Up....!!!!" << endl;
		system("pause");
		system("CLS");
		goto lable;
		break;

	}

	case 2:
	{
		cout << "=================================================\n";

		string susername;
		string spassword;
	login:
		cin.ignore();
		cout << "Enter Your Username : " << endl;

		getline(cin, susername);
		while (susername == "")
		{
			cout << "Username Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, susername);
		}
		cout << "Enter Your Password : " << endl;
		getline(cin, spassword);
		while (spassword == "")
		{
			cout << "Password Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, spassword);
		}
		Node* temp = h1.sign_in(susername, spassword);
		if (temp)
		{
			cout << "Signed In Successfully...!!!" << endl;
			cout << "=================================================\n";



			int c;
		lable1:
			cout << "                             =======================Account==========================\n";
			cout << "\n                                **********************************\n"
				<< "                                         1-Personal Tab\n"
				<< "                                         2-Home Tab\n"
				<< "                                         3-Friends Tab\n"
				<< "                                         4-Messages\n"
				<< "                                         5-Log Out\n"
				<< "                                   ************************************\n";

			cout << "Enter Your Option " << endl;
			cin >> c;
			while (c < 1 || c>5)
			{
				cout << "Enter Valid Option...!!!!" << endl;
				cin >> c;
			}
			system("CLS");
			switch (c)
			{
			case 1:
			{
				cout << "=================================================\n";
				int b;
			lable2:
				cout << "                             ======================= PERSONAL TAB ==========================\n";
				cout << "\n                                  *******************************************\n"
					<< "                                         1-View Post\n"
					//	<< "                                         2-View Comment\n"
					<< "                                         2-Add Post\n"
					<< "                                         3-Delete Post\n"
					<< "                                         4-Update Post\n"
					<< "                                         5-GoTo Back Page\n"
					<< "                                     ********************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> b;
				while (b < 1 || b>6)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> b;
				}
				system("CLS");
				switch (b)
				{
				case 1:
				{
					int x;
					cout << "                             =======================POST TAB ==========================\n";
					cout << "\n                                  *****************************************\n"
						<< "                                         1-View Post Only\n"
						<< "                                         2-View Post With Comments\n"

						<< "                                     ******************************************\n";

					cout << "Enter Your Option " << endl;
					cin >> x;
					while (x < 1 || x>2)
					{
						cout << "Enter Valid Option...!!!!" << endl;
						cin >> x;
					}
					system("CLS");
					switch (x)
					{
					case 1:
					{
						int inxd;
						node* cnmt;
						string ct;
						int flag = 0;
						cout << "====================== POSTS ===========================\n";
						cout << "______" << endl;
						temp->a.display_s();
						break;

					}
					case 2:
					{

						int inxd;
						node* cnmt;
						string ct;
						int flag = 0;
						cout << "====================== POSTS ===========================\n";
						cout << "______" << endl;
						temp->a.displayMyPost(temp->name);

					}
					default:
						break;
					}
					system("pause");
					system("CLS");
					goto lable2;
					break;

				}
				/*case 2:
				{
					cout << "====================== COMMENTS ===========================\n";



					system("pause");
					system("CLS");
					goto lable2;
					break;
				}*/
				case 2:
				{
					cout << "====================== ADD POST ===========================\n";
					string adpost;
					cin.ignore();
					cout << "Post Your Feelings Here : " << endl;
					getline(cin, adpost);
					//char* tme = temp->a.wqt();
					temp->a.addPost(adpost, temp->name);
					system("pause");
					system("CLS");
					goto lable2;
					break;

				}
				case 3:
				{
					cout << "====================== DELETE POST ===========================\n";
					int in;
					temp->a.post.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Delete" << endl;
					cin >> in;

					temp->a.del_Post(in);
					system("pause");
					system("CLS");
					goto lable2;
					break;
				}
				case 4:
				{
					cout << "====================== UPDATE POST ===========================\n";
					int iu;
					temp->a.post.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Update" << endl;
					cin >> iu;
					temp->a.update_post(iu);
					system("pause");
					system("CLS");
					goto lable2;
					break;
				}

				case 5:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;

			}
			case 2:
			{
				cout << "=================================================\n";
				int d;
			lable3:
				cout << "                             ======================= HOME TAB ==========================\n";
				cout << "\n                                  ******************************************\n"
					<< "                                         1-View Post\n"
					//		<< "                                         2-View Comment\n"
					<< "                                         2-Add Post\n"
					<< "                                         3-Delete Post\n"
					<< "                                         4-Update Post\n"
					<< "                                         5-GoTo Back Page\n"
					<< "                                     ******************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> d;
				while (d < 1 || d>5)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> d;
				}
				system("CLS");
				switch (d)
				{
				case 1:
				{
					int y;
					cout << "                             =======================POST TAB ==========================\n";
					cout << "\n                                  *********************************************\n"
						<< "                                         1-View Post Only\n"
						<< "                                         2-View Post With Comments\n"

						<< "                                     **********************************************\n";

					cout << "Enter Your Option " << endl;
					cin >> y;
					while (y < 1 || y>2)
					{
						cout << "Enter Valid Option...!!!!" << endl;
						cin >> y;
					}
					system("CLS");
					switch (y)
					{
					case 1:
					{
						cout << "====================== POSTS ===========================\n";
						string usnem;
						cout << "______" << endl;
						temp->a.display_s();
						temp->f1.frndz.all_push(temp->f1.frndz.root, "");
						while (temp->f1.frndz.all_f.IsEmpty() == false)
						{
							usnem = temp->f1.frndz.all_f.pop()->data;
							Node* temp9 = h1.search(usnem);
							cout << "______" << endl;
							temp9->a.display_s();

							cout << "______" << endl;

						}

						break;

					}
					case 2:
					{
						cout << "====================== POSTS ===========================\n";
						string usnem;
						cout << "______" << endl;
						temp->a.displayMyPost(temp->name);
						temp->f1.frndz.all_push(temp->f1.frndz.root, "");
						while (temp->f1.frndz.all_f.IsEmpty() == false)
						{
							usnem = temp->f1.frndz.all_f.pop()->data;
							Node* temp9 = h1.search(usnem);
							cout << "______" << endl;
							temp9->a.displayMyPost(temp->name);

							cout << "______" << endl;

						}
						break;
					}
					default:
						break;
					}

					system("pause");
					system("CLS");
					goto lable3;
					break;

				}
				/*case 2:
				{
					cout << "====================== COMMENTS ===========================\n";

					system("pause");
					system("CLS");
					goto lable3;
					break;
				}*/
				case 2:
				{
					cout << "====================== ADD POST ===========================\n";
					string adpost;
					cin.ignore();
					cout << "Post Your Feelings Here : " << endl;
					getline(cin, adpost);
					//char* tme = temp->a.wqt();
					temp->a.addPost(adpost, temp->name);
					system("pause");
					system("CLS");
					goto lable3;
					break;

				}
				case 3:
				{
					cout << "====================== DELETE POST ===========================\n";
					int in;
					temp->a.post.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Delete" << endl;
					cin >> in;
					temp->a.del_Post(in);
					system("pause");
					system("CLS");
					goto lable3;
					break;
				}
				case 4:
				{
					cout << "====================== UPDATE POST ===========================\n";
					int iu;
					temp->a.post.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Update" << endl;
					cin >> iu;
					temp->a.update_post(iu);
					system("pause");
					system("CLS");
					goto lable3;
					break;
				}

				case 5:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;
			}
			case 3:
			{
				cout << "=================================================\n";
				int e;
			lable4:
				cout << "                             ======================= FRIENDS TAB ==========================\n";
				cout << "\n                                  ***********************************************\n"
					<< "                                         1-My Friends\n"
					<< "                                         2-Add Friends\n"
					<< "                                         3-Friend Requests\n"
					<< "                                         4-GoTo Back Page\n"
					<< "                                     ***********************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> e;
				while (e < 1 || e>4)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> e;
				}
				system("CLS");
				switch (e)
				{
				case 1:
				{
					cout << "====================== MY FRIENDS ===========================\n";
					int as;
					cout << "--------------------------------------------\n";
					cout << "1- Show All Friends Name " << endl;
					cout << "2- Search Friends " << endl;
					cout << "--------------------------------------------\n";
					cout << "Enter Your Option " << endl;
					cin >> as;
					while (as < 1 || as>2)
					{
						cout << "Enter Valid Option...!!!!" << endl;
						cin >> as;
					}
					system("CLS");
					if (as == 1)
					{
						temp->f1.display_frnd();



					}
					else
					{
						string kye;
						cin.ignore();

						cout << "Search New Friend Here : " << endl;
						getline(cin, kye);

						cout << "Suggesstion are...." << endl;
						NTNode* temp1 = temp->f1.search_s_frnd(kye);
						kye.erase(kye.size() - 1);
						if (temp1)
						{
							temp->f1.frndz.Display_s(temp1, kye);
						}
						else
						{
							cout << "Not Found";
							system("pause");
							system("CLS");
							goto lable4;
						}
						if (a1.all_usr.root != NULL)
						{


							int nf;
							string usrnm;
							cout << "Enter Index Of Above Mentioned User You Want To See ..." << endl;
							cin >> nf;
							usrnm = temp->f1.req_gtusrn(nf);
							Node* temp2 = h1.search(usrnm);
							if (temp2)
							{
								cout << "==================================================================" << endl;
								cout << temp2->name << endl;
								cout << "==================================================================" << endl;
								cout << "-----------------Posts---------------" << endl;
								temp2->a.displayHPost();
							}
						}

					}
					system("pause");
					system("CLS");
					goto lable4;
					break;

				}
				case 2:
				{
					cout << "====================== ADD FRIEND ===========================\n";
					//ls1:
					string ky;
					cin.ignore();

					cout << "Search New Friend Here : " << endl;
					getline(cin, ky);

					cout << "Suggesstion are...." << endl;
					NTNode* temp1 = a1.search_s_usr(ky);
					ky.erase(ky.size() - 1);
					if (temp1)
					{
						a1.display_s_usr(temp1, ky);
					}
					else
					{
						cout << "Not Found";
						system("pause");
						system("CLS");
						goto lable4;
					}
					if (a1.all_usr.root != NULL)
					{


						int nf;
						string usrnm;
						cout << "Enter Index Of Above Mentioned User You Want To See ..." << endl;
						cin >> nf;
						usrnm = a1.gtusrnm_al(nf);
						Node* temp2 = h1.search(usrnm);
						if (temp2)
						{
							cout << "==================================================================" << endl;
							cout << temp2->name << endl;

							cout << "==================================================================" << endl;
							cout << "-----------------Posts---------------" << endl;
							temp2->a.displayHPost();
						}
						int as;
						cout << "--------------------------------------------\n";
						cout << "1- Send Friend Request " << endl;
						cout << "2- GoTo Previous Page " << endl;
						cout << "--------------------------------------------\n";
						cout << "Enter Your Option " << endl;
						cin >> as;
						while (as < 1 || as>2)
						{
							cout << "Enter Valid Option...!!!!" << endl;
							cin >> as;
						}
						system("CLS");
						if (as == 1)
						{
							/*if (temp2->f1.search_req(temp->name) == true)
							{
								cout << "Friend Request Already Sent !!!!!" << endl;
							}*/
							// if (temp->f1.search_frnd(temp2->name) == true)
						   //{
						   //	cout << "You Both are Already Friends !!!!" << endl;
						   //}
							 if (temp->name == temp2->name)
							{
								cout << "Why are you Making Friend Yourself..." << endl;
								cout << "Go And Search Someone Else..." << endl;
							}
							else
							{
								temp2->f1.frnd_req(temp->name, susername);
								cout << "Friend Request Sent !!!!!! " << endl;
								//cout << "added" << endl;
							}
						}
						else
						{
							//cout << "case2" << endl;
							goto lable4;
						}
					}
					system("pause");
					system("CLS");
					goto lable4;
					break;
				}
				case 3:
				{
					cout << "====================== FRIEND REQUESTS ===========================\n";
					temp->f1.show_req();
					if (temp->f1.Req.head != NULL)
					{
						string fusr;
						int fr;
						cout << "Enter Index Of Above Mentioned Requested User You Want To See ..." << endl;
						cin >> fr;
						fusr = temp->f1.req_gtusrn(fr);
						Node* temp3 = h1.search(fusr);
						if (temp3)
						{
							cout << "==================================================================" << endl;
							cout << temp3->name << endl;
							cout << "==================================================================" << endl;
							cout << "-----------------Posts---------------" << endl;
							temp3->a.displayHPost();
						}
						cout << "======================================================================================================" << endl;
						int fs;
						cout << "--------------------------------------------\n";
						cout << "1- Accept Friend Request " << endl;
						cout << "2- Reject Friend Request " << endl;
						cout << "3- GoTo Previous Page " << endl;
						cout << "--------------------------------------------\n";
						cout << "Enter Your Option " << endl;
						cin >> fs;
						while (fs < 1 || fs>3)
						{
							cout << "Enter Valid Option...!!!!" << endl;
							cin >> fs;
						}
						system("CLS");
						if (fs == 1)
						{
							temp->f1.add_frnd(temp3->name, fusr);
							temp3->f1.add_frnd(temp->name, susername);
							temp->f1.rmv_req(temp3->name);
							cout << "You Are Now Friends !!!!!" << endl;
							//cout << "added" << endl;
						}
						else if (fs == 2)
						{
							temp->f1.rmv_req(temp3->name);
							cout << "Request Removed.!!!!" << endl;
						}
						else
						{
							//cout << "case2" << endl;
							goto lable4;
						}
					}
					system("pause");
					system("CLS");
					goto lable4;
					break;

				}

				case 4:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;

			}
			case 4:
			{
				cout << "=================================================\n";
				int f;
			lable5:
				cout << "                             ======================= MESSSAGE TAB ==========================\n";
				cout << "\n                                  *****************************************\n"
					<< "                                         1-Conversations\n"
					<< "                                         2-GoTo Back Page\n"
					<< "                                     *****************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> f;
				while (f < 1 || f>3)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> f;
				}
				system("CLS");
				switch (f)
				{
				case 1:
				{
					cout << "====================== CONVERSATIONS ===========================\n";

					string mesg;
					cout << "--------------------------------------------\n";
					cout << "Select Friend " << endl;
					cout << "--------------------------------------------\n";


					{
						if (temp->f1.frndz.root != NULL)
						{
							temp->f1.frndz.Display_s(temp->f1.frndz.root, "");
						}
						else
						{
							cout << "Not Found";
							system("pause");
							system("CLS");
							goto lable5;
						}
						if (temp->f1.frndz.root != NULL)
						{


							int nf;
							string usrnm;
							//string sname;
							cout << "Enter Index Of Above Mentioned User You Want To See ..." << endl;
							cout << "(Press '0' If Nothing Shows) " << endl;
							cin >> nf;
							if (nf == 0)
							{
								goto lable5;
							}
							else
							{
								cout << "==================================================================" << endl;
								cout << "-----------------Chats---------------" << endl;
								temp->M1.convo.Display();
								usrnm = temp->f1.frndz.gtusrnm(nf);
								Node* temp2 = h1.search(usrnm);
								if (temp2)
								{

									int y;
									cout << "*******\n"
										<< "1-Send A Message\n"
										<< "2-Go Back\n"
										<< "******\n";

									cout << "Enter Your Option " << endl;
									cin >> y;
									while (y < 1 || y>2)
									{
										cout << "Enter Valid Option...!!!!" << endl;
										cin >> y;
									}
									system("CLS");
									switch (y)
									{
									case 1:
									{
										cin.ignore();
										cout << "ENTER NEW MESSAGE ( Press Enter To Send ) " << endl;
										getline(cin, mesg);
										temp->M1.snd_msg(mesg, temp->name);
										temp2->M1.snd_msg(mesg, temp->name);
										break;

									}
									case 2:
									{

										goto lable5;
										break;
									}
									default:
										break;
									}
								}
							}

						}

					}
					system("pause");
					system("CLS");
					goto lable5;
					break;

				}
				case 2:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;
			}

			case 5:
			{
				goto lable;
			}
			default:
				break;


			}











			//cout << "Name : " << temp->name << endl;
			//cout << "Mobile No. : " << temp->num << endl;
		}
		else
		{
			cout << "Incorrect USERNAME or PASSWORD..!!!!!" << endl;
			int z;
			cout << "*******\n"
				<< "1-Go Back\n"
				<< "2-SIGN IN Again\n"
				<< "******\n";

			cout << "Enter Your Option " << endl;
			cin >> z;
			while (z < 1 || z>2)
			{
				cout << "Enter Valid Option...!!!!" << endl;
				cin >> z;
			}
			system("CLS");
			switch (z)
			{
			case 1:
			{
				system("CLS");
				goto lable;
				break;

			}
			case 2:
			{

				goto login;
			}
			default:
				break;
			}
		}
		system("pause");
		system("CLS");
		break;
	}

	case 3:
	{
		exit(0);
	}
	default:
		break;


	}











	system("pause");
}