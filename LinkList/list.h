#pragma once
#include <iostream>

typedef struct linked
{
	int data;
	struct linked* next;
}node;

node* head = NULL;
node* tail = NULL;

void init();
void insert(node* ptr);
void printlist(node* ptr);
void modify(node* ptr);
void insertData(node* ptr);
void del(node* ptr);

void init()
{
	head = new node;
	head->data = 0;
	head->next = NULL;
	tail = head;

	return;
}

void insert(node* ptr)
{
	node* newnode = new node;
	int num = 0;

	std::cout << "input number: ";
	std::cin >> num;
	
	newnode->data = num;
	newnode->next = NULL;

	ptr->next = newnode;
	tail = newnode;

	return;
}

void printlist(node* ptr)
{
	node* view = ptr->next;

	while (view != NULL)
	{
		std::cout << view->data;
		view = view->next;
	}
	std::cout << std::endl;

	return;
}

void modify(node* ptr)
{
	int index = 0;
	int num = 0;
	int i;

	std::cout << "input modify index: ";
	std::cin >> index;

	std::cout << "input modify data: ";
	std::cin >> num;

	for (i = 0; i < index; ++i)
	{
		ptr = ptr->next;
	}
	ptr->data = num;
	return;
}

void insertData(node* ptr)
{
	node* newnode = new node;

	int index = 0;
	int num = 0;
	int i;

	std::cout << "input insertData index: ";
	std::cin >> index;
	
	std::cout << "input data: ";
	std::cin >> num;

	for (i = 0; i < index; ++i)
	{
		ptr = ptr->next;
	}

	newnode->data = num;
	newnode->next = NULL;

	if (ptr->next == NULL)
	{
		ptr->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = ptr->next;
		ptr->next = newnode;
	}
	return;
}

void del(node* ptr)
{
	node* temp = 0;
	int i;
	int index;

	if (head == tail)
	{
		std::cout << "no data found." << std::endl;
		return;
	}

	std::cout << "input delete index" << std::endl;
	std::cin >> index;

	for (int i = 0; i < index - 1; ++i)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;

	if (temp->next == NULL)
	{
		ptr->next = NULL;
		tail = ptr;
	}
	else
	{
		ptr->next = temp->next;
	}
	delete(temp);
	return;
}