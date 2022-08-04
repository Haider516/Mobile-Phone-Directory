
#include "bst.h"
#include<iostream>
using namespace std;
class node
{
public:
    string data;
    string num;
    node* next;
};

template <class itemtype>
class singlelink_list
{
    node* head;
	tree  tr;
public:
    singlelink_list()
    {
        head = NULL;
    }
    node* insert_beig(itemtype value, itemtype num1)
    {
        node* temp;
        if (head == NULL)
        {
            temp = new node;
            temp->data = value;
            temp->num = num1;
            temp->next = NULL;
            head = temp;
        }
        else {
            temp = new node;
            temp->data = value;
            temp->num = num1;
            temp->next = head;
            head = temp;
        }
      return temp;

    }
    /*void insert_end(itemtype value)
    {
        node* temp = head;
        node* p;
        if (head == NULL)
        {
            temp = new node;
            temp->data = value;
            temp->next = NULL;
            head = temp;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            p = new node;
            p->data = value;
            p->next = NULL;
            temp->next = p;
        }
        cout << " We insert a new element" << value << " in the node " << endl;
    }
    void del_begin()
    {
        if (head == NULL)
        {
            cout << "NO NODES IN THE LINK";
        }
        else
        {
            node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void del_end()
    {
        if (head == NULL)
        {
            cout << " No nodes in the link list ." << endl;
        }
        else
        {
            node* temp = head;
            node* q = NULL;
            while (temp->next != NULL)
            {
                q = temp;
                temp = temp->next;
            }
            q->next = NULL;
            delete temp;
        }
    }
    void insert_mid(itemtype value, itemtype num)
    {
        node* temp = head;
        node* temp1;
        node* temp2 = NULL;
        if (head == NULL)
        {
            temp = new node;
            temp->data = value;
            temp->next = NULL;
            head = temp;
        }
        else
        {

            while (temp->data != num)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp1 = new node;
            temp1->data = value;
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
    }*/

   
	void search(string val) {


		bool flag1 = false;
		node* temp = head;
		
		string ab;
		string abcd;
		while (temp != NULL)
		{

			if ((temp->data == val) || (temp->num == val))
			{
				flag1 = true;
				cout << "CONTACT Found!\n";
				cout << "CONTACT Detalis: \n";

				cout <<"Name:"<< temp->data << "\n";
				cout << "Number" << temp->num << endl;
				
			}


			temp = temp->next;


		}
		if (flag1 == false) {

			cout << "Your Contact is not in the list!" << endl;
		}








	}
	void modify(string val) {

		bool flag2 = false;
		node* temp = head;
		int charlie;
		string ab;
		string abcd;
		while (temp != NULL)
		{
			
			if ((temp->data == val) || (temp->num == val))
			{
				flag2 = true;
				cout << "CONTACT DETAILS:\n";
				cout << temp->data << "\n";
				cout << temp->num;
				cout << endl;
				cout << "CHOOSE OPTION TO EDIT:" << endl;
				cout << "1.NAME \n 2.CONTACT NUMBER \n";
				cin >> charlie;
				switch (charlie)
				{
				case 1:

					cin.ignore();
					cout << "Enter New Name :";
					getline(cin, ab);
					temp->data = ab;
					break;
				case 2:
					cin.ignore();
					cout << "Enter New Number:";
					getline(cin, abcd);
					temp->num= abcd;
					break;
				default:
					break;

				}

				
				/*q->data = temp->data;
				q->num = temp->num;*/
				

			}
			
			
			temp = temp->next;

			
		}
		if (flag2 == false) {

			cout << "Your COntact is not in the list!" << endl;
		}
		


	}

    //search by function
    node *search_by_number(string val) {


        bool flag1 = false;
        node* temp = head;
        while (temp != NULL)
        {
            if ( (temp->num == val))
            {
                flag1 = true;
                cout << "CONTACT Found!\n";
                cout << "CONTACT Detalis: \n";
                cout << "Name:" << temp->data << "\n";
                cout << "Number" << temp->num << endl;
            }
            temp = temp->next;
        }
        if (flag1 == false) {

            cout << "Your Contact is not in the list!" << endl;
        }
        return temp;
    }
    void del_begin()
    {
        if (head == NULL)
        {
            cout << "NO NODES IN THE LINK";
        }
        else
        {
            node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void delete_all()
    {
        cout << endl;
        node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "   " << temp->num << endl<<"deleted";
            del_begin();
            temp = temp->next;
        }
    }

    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
			cout << temp->data << "   " << temp->num << endl;
            
            temp = temp->next;
        }
    }
};