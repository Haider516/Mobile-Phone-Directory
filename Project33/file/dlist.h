#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class node {
public:
	int data;
	node* next;
	node* prev;
};
class dlist {
private:
	node* head;
	node* head2;
	int count;
public:
	dlist() {
		head = NULL;
		head2 = NULL;
	}
	void insert_beg(int value) {
		node* temp;
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
		}
		else {
			temp = new node;
			temp->data = value;
			temp->next = head;
			temp->prev = NULL;
			head = temp;
		}
	}
	void insert_end(int value) {
		node* temp;
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
		}
		else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			node* p = new node;
			p->data = value;
			p->next = NULL;
			temp->next = p;
			p->prev = temp;
		}
	}
	void del_beg() {
		if (head == NULL) {
			cout << "List is empty cannot delete" << endl;
		}
		else {
			node* temp = head;
			head = head->next;
			head->prev = NULL;
			temp->next = NULL;
			delete temp;
		}
	}
	void del_end() {
		if (head == NULL) {
			cout << "List is empty cannot delete" << endl;
		}
		else {
			node* temp = head;
			node* p = NULL;
			while (temp->next != NULL) {
				p = temp;
				temp = temp->next;
			}
			p->next = NULL;
			temp->prev = NULL;
			delete temp;
		}
	}
	node* getHead() {
		return head;
	}
	void merge(node* head1) {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = head1;
		head1->prev = temp;
	}
	void split(int val) {
		node* temp = head;
		node* q = NULL;
		while (temp->data != val) {
			q = temp->next;
			temp = temp->next;
		}
		q->prev = NULL;
		temp->next = NULL;
		head2 = q;
	}
	void compare(dlist b) {
		node* temp1 = head;
		node* temp2 = b.head;
		if (count > b.count)
		cout << "First Linked List has more elements than second" << endl;
		else if (count < b.count) cout << "First Linked List has more elements than second" << endl;
		else
			while (temp1 != NULL) {
				if (temp1->data > temp2->data) {
					cout << "First linked list is greater" << endl;
					break;
				}
				else if (temp1->data < temp2->data)
				{
					cout << "Second linked list is greater" << endl;
					break;
				}
				else {
					cout << "Both linked lists are equal" << endl;
					break;
				}
			}
	}
	void display() {
		node* temp = head;
		int count = 0;
		while (temp != NULL) {
			cout << "Node is " << temp->data << endl;
			temp = temp->next;
			count++;
		}
	}
};