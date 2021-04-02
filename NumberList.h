#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
public:
	NumberList()    //Constructor
	{
		head = nullptr;
	}

	~NumberList();  //Destructor

	//Link list operations
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;

private:
	//Declasre a structure
	struct ListNode
	{
		double value;            //The value in the node
		struct ListNode* next;   //ptr to the next node
	};

	ListNode* head;    //list head ptr
};


#endif // !NUMBERLIST_H

