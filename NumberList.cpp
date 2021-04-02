#include "NumberList.h"
#include <iostream>

using namespace std;

//Function prototype
bool doItAgain(bool);

int main() {
	
	bool goAgain = true;
	//int oneMore = 0;

	//Define a NumberList
	NumberList list;

do
{
	double userInput = 0; //Variable to hold user input

	//Append nodes
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);

	cout << "Enter a double to append in the list\n";
	cin >> userInput;
	list.appendNode(userInput);

	cout << "Enter another double to append in the list\n";
	cin >> userInput;
	list.appendNode(userInput);

	//Inserting nodes
	list.insertNode(10.5);

	cout << "Enter a double to insert in the list\n";
	cin >> userInput;
	list.insertNode(userInput);

	cout << "Enter a double to insert in the list\n";
	cin >> userInput;
	list.insertNode(userInput);

	//Deleting and displaying remaining nodes
	cout << endl;
	cout << "\nDisplaying the intial set up after insertion\n";
	list.displayList();

	cout << "\nNow deleting nodes from the list\n";
	cout << "Deleting node 7.9\n";
	cout << "Here are the nodes left\n";
	list.deleteNode(7.9);
	list.displayList();

	cout << "\nDeleting node 10.5\n";
	cout << "Here are the nodes left\n";
	list.deleteNode(10.5);
	list.displayList();

	cout << "\nDeleting node 12.6\n";
	cout << "Here are the nodes left\n";
	list.deleteNode(12.6);
	list.displayList();

	cout << "\nDeleting node 2.5\n";
	cout << "Here are the nodes left\n";
	list.deleteNode(2.5);
	list.displayList();

	cout << "\nEnter node to delete next\n";
	cin >> userInput;
	cout << "Here are the nodes left\n";
	list.deleteNode(userInput);
	list.displayList();

	cout << "\nEnter node to delete next\n";
	cin >> userInput;
	cout << "Here are the nodes left\n";
	list.deleteNode(userInput);
	list.displayList();

	cout << "\nEnter node to delete next\n";
	cin >> userInput;
	cout << "Here are the nodes left\n";
	list.deleteNode(userInput);
	list.displayList();

	cout << "\nEnter node to delete next\n";
	cin >> userInput;
	cout << "Here are the nodes left\n";
	list.deleteNode(userInput);
	list.displayList();

	goAgain = doItAgain(goAgain);
} while (goAgain);

	//Destroying the list
	list.~NumberList();

	return 0;
}

bool doItAgain(bool oneMore) {

	int another;
	cout << "\nDo you want to try again?\n[0] No \n[1] Yes   ";
	cin >> another;
	if (another != 1)
	{
		oneMore = false;
	}

	cout << endl;
	return oneMore;
}

NumberList::~NumberList()
{
	ListNode* nodePtr;
	ListNode* nextNode;

	//Position nodePtr at the head of the list
	nodePtr = head;

	//while nodePtr is not at the head of the list
	while (nodePtr != nullptr)
	{	
		//Save a ptr to the next node
		nextNode = nodePtr->next;

		//Delete current node
		delete nodePtr;

		//position nodePtr at the next node
		nodePtr = nextNode;
	}
}

void NumberList::appendNode(double num)
{
	ListNode* newNode;   //To point to a new node
	ListNode* nodePtr;   //To traverse the list

	//Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//If the are no nodes in the list, make newNode the first node.
	if (!head)
		head = newNode;
	else
	{
		//Initialize nodePtr to head of list
		nodePtr = head;

		//Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		//Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

void NumberList::insertNode(double num)
{
	ListNode* newNode;     //A new node
	ListNode* nodePtr;     //The traverse the list
	ListNode* previousNode = nullptr;  //The previous node

	//Allocate new node and store
	newNode = new ListNode;
	newNode->value = num;

	//If new node is the first and only node in the list
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // otherwise, skip to desired position
	{
		nodePtr = head;

		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If new node is to be first in the list
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else //otherwise insert after the previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void NumberList::deleteNode(double num)
{
	ListNode* nodePtr;       //To traverse the list
	ListNode* previousNode = nullptr;  //Points to prev node

	//If list is empty, do nothing
	if (!head)
	{
		return;
	}
	
	//Determine if the first node is the one
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		//Initialize nodePtr to head of list
		nodePtr = head;

		//skip all nodes whose value member is not equal to num
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//Link node to end of list if it is not there yet
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
	

}

void NumberList::displayList() const
{
	ListNode* nodePtr;   //To traverse the list

	//Position nodePtr at the head of the list
	nodePtr = head;

	//Traverse
	while (nodePtr)
	{
		cout << nodePtr->value << endl;

		nodePtr = nodePtr->next; //move to the next node
	}
}
