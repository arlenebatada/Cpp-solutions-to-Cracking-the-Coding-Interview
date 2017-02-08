#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	
	Node ()
	{
		data='0';
		next=nullptr;
	}
	
	size_t hash()
	{
		return size_t (this);
	}	
};

class LinkedList
{
	public:
	Node* head;
	
	LinkedList()
	{
		head=nullptr;
	}
};


Node * loop_start (Node *head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
	{
		return nullptr;
	}
	
	cout << head->data <<"("<<head<<")" << " -> ";
	Node *fast_ptr = head->next->next, *slow_ptr= head->next;
	
	while (fast_ptr != slow_ptr) //loop until both the pointers meet
	{
		if (fast_ptr == nullptr || fast_ptr->next == nullptr || fast_ptr->next->next == nullptr || slow_ptr == nullptr || slow_ptr->next == nullptr)
		{
			return nullptr;
		}
		
		cout << slow_ptr->data <<"("<<slow_ptr<<")" << " -> ";
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next; //fast_ptr is twice as fast as slow ptr
	}
	cout << slow_ptr->data <<"("<<slow_ptr<<")" ;
	 
	slow_ptr = head;
	
	while (fast_ptr != slow_ptr)
	{
		if (fast_ptr == nullptr || slow_ptr == nullptr)
		{
			return nullptr;
		}
		
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
		cout << " -> "<< fast_ptr->data <<"("<<fast_ptr<<")" ;
	}
	
	return slow_ptr;
}

int main()
{
	LinkedList linkedlist;
	linkedlist.head= new Node;
	Node* p= linkedlist.head;
	p->data= 1;    
	p->next= new Node; p= p->next; p->data= 2;
    p->next= new Node; p= p->next; p->data= 3;
    p->next= new Node; p= p->next; p->data= 4;
    p->next= new Node; p= p->next; p->data= 5;
    p->next= new Node; p= p->next; p->data= 6;
    p->next= new Node; p= p->next; p->data= 7; 
	p->next= new Node; p= p->next; p->data= 8;
	p->next= new Node; p= p->next; p->data= 9;
	p->next= new Node; p= p->next; p->data= 10;
	p->next= new Node; p= p->next; p->data= 11;
	p->next= linkedlist.head->next->next->next;
    
    Node* pointer_to_the_loop_point = loop_start(linkedlist.head);
    cout<<endl<<endl<<"Loop starts at: "<<pointer_to_the_loop_point->data <<" ("<<pointer_to_the_loop_point<<")";
	
}
