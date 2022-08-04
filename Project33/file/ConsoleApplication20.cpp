#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"STACK.h"
#include"linklist.h"
#include"queue.h"
#include"bst.h"
#include"waqt.h"
#include <time.h>   
#include <stdio.h>

using namespace std;


class mobile_directory
{
  private:
	string name;
	string number;
	singlelink_list <string>l;
	singlelink_list <string>Sec_l;
	node bye;
	Queue f;
	tree t;
	stack <node1*> a;
	node1* alpha;
	int count=0;
	int count1 = 0;
	waqt w;

  public:
	void setinfo()
	{
		cin.ignore();
		cout << "ENTER NAME:";
		getline(cin,name,'\n');
		cout << endl;
		cout << "ENTER NUMBER:";
		getline( cin,number);
		cout << endl;

	}

	string getname()
	{
		return name;
	}
	string getnum()
	{
		return number;
	}

	void create_new_contact()
	{
		system("CLS");
		setinfo();
		l.insert_beig(name, number);
		t.make_tree(name,number);
		count++;
		
		cout <<endl<<" New Contact Created!" << endl;

		cout << "\nDO YOU WANT TO SAVE THIS  CONTACT AS FAVOURITE \nPRESS Y TO SAVE OR N TO CONTINUE:";
		char op;
		cout << "ENTER OPTION: ";
		cin >> op;
		if (op == 'Y' || op == 'y')
		{
			node *p = Sec_l.insert_beig(name, number);
			
			f.Insert(p);
		}
	}
	
	void display_favourite_c()
	{
		while (!f.IsEmpty())
		{
			f.Remove();
		}
	}
	

	void displaycontacts()
	{
		system("CLS");
		cout << "Total cotacts are " << count << endl;
		cout << "NAME:" << "\t     " << "NUMBER" << endl;
		t.show();
		//t.search();
	}
	
	void makecall()
	{
		system("CLS");
		string n;
		int opt;
		cout << endl<<"How do you want to call? ";
		cout << "\n1.By name\n2.By nmber\n";
		cin >> opt;
	
		switch (opt)
		{
		case 1:
			cin.ignore();
			cout << "Enter Name: "; getline(cin, n);
			
			alpha = t.search(n, opt);
			a.Push(alpha);
			count1++;
			break;
		case 2:
			cin.ignore();
			cout << "Enter Number: "; 
			getline(cin, n);
			//search_by_number()
			alpha = t.search(n, opt);
			a.Push(alpha);
			count1++;

			break;
		default:
			break;
		}
	
	}

	void search() {
		system("CLS");
		string s1;
		cout << "Enter name or Number to search: ";
		cin >> s1;
		l.search(s1);



	}

	void recents_contacted() {
		system("CLS");
		cout <<endl<< " Recently contacted list" << endl << endl;
		node1* b = NULL;
		cout << "NAME:" << "\t     " << "NUMBER" << "    TIME" << endl;
		for (int i = 0; i < count1; i++) {

			a.Pop(b);
			cout << b->name << "         " << b->num << endl;
		}

	}
	
	void update() {

		system("CLS");
		cout << endl;
		cout << "Enter contact name to modify: ";
		cin.ignore();
		string s;
		getline(cin, s);
		t.modify_func(s);
		cout << endl << "Conatct Modified!" << endl;
	

	}

	void delete_contact(){
		system("CLS");
		string s;
		cout << "Enter contact name to delete: " << endl;
		cin >> s;
		t.delete_contact(s);
		cout << "The information of contact " << s << "has been deleted successfully!" << endl << endl;


	}
	
	void  del_link()
	{
		t.delete_all();
		count = 0;
	}

};



int main()
{
	system("CLS");
	cout << "--------------------------------- Phone Directory ---------------------------------\n\n" << endl << endl;
	int ch;
	char op;
	mobile_directory m;
	while (1) {

		cout <<endl<<endl<< " SELECT AN OPTION: ";
		cout << endl << "1. Create New Contact" << endl;
		cout << "2. Modify a Contact" << endl;
		cout << "3. Delete a Contact" << endl;
		cout << "4. Display All Contacts" << endl;
		cout << "5. Make a Call" << endl;
		cout << "6. Display Recently Contatcted List" << endl;
		cout << "7. Search Contact" << endl;
		cout << "8. To Display favourite Contact:" << endl;
		cout << "9. To delete all  contacts:" << endl;
		cout << "10.Exit" << endl << endl;
		cout<<"Enter Your Option: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			do {
				m.create_new_contact();
				system("CLS");
				cout << "Do you want to create another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 2:
			do {
				m.update();
				cout << "Do you want to modify another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 3:
			do {
				m.delete_contact();
				cout << "Do you want to delete another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 4:
			m.displaycontacts();
			break;
		case 5:
			do {
				m.makecall();
				cout << "Do you want to make another call?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 6:
			m.recents_contacted();
			break;
		case 7:
			m.search();
			break;
		case 8:
			m.display_favourite_c();
			break;
		case 9:
			m.del_link();
			break;
		case 10:
			cout << "              Made by:" << endl;
			cout << "    HAIDER AKBAR ZUBAIRI (X1-X342XX-XXX)" << endl;
			exit(0);
			break;
		default:
			break;
		}





	}
	
	

	_getch();
	return 0;
}

