#include <iostream>

using namespace std;

class Node
{
	public:
	char data;
	Node* next;
	
	Node ()
	{
		data='0';
		next=nullptr;
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

int get_linked_list_length(Node * head)
{
	int length=0;
	
	while (head != nullptr)
	{
		length++;
		head = head->next;
	}
	
	return length;
}

Node * find_intersection_of_the_linked_lists(Node *h1, Node *h2)
{
	if (h1 == nullptr || h2 == nullptr)//lists should not be empty
	{
		return nullptr;
	}
	
	int l1 = get_linked_list_length (h1), l2 = get_linked_list_length (h2);
	
	if (l1 < l2)
	{
		swap (l1, l2);
		swap (h1, h2);
		//h1 should be the larger list
	}
	
	int difference= l1-l2;
	
	for (int i=0; i < difference; i++)
	{
		h1 = h1->next; //increment h1 until the remaining length of h1 equals that of h2
	}
	
	while (h1 != h2) //while both the lists don't include the same node, traverse both of them
	{
		if (h1 == nullptr || h2 == nullptr) //if the lists don't intersect
		{
			return nullptr;
		}
		
		h1 = h1->next;
		h2 = h2->next;
	}
	
	return h1; //while loop has terminated once memory location pointed by h1 equals to that of h2
}


void display_linked_list(Node* head)
{
    while (head!=NULL)
    {
        cout << head->data <<" -> ";
        head=head->next;
    }
    cout<< "NULL";
}

int main()
{
	LinkedList linkedlist1, linkedlist2;
    
    linkedlist1.head= new Node;
    
    Node * p1=linkedlist1.head;
    
	p1->data= '1';    
	p1->next= new Node; p1= p1->next; p1->data= '2';
    p1->next= new Node; p1= p1->next; p1->data= '3';
    p1->next= new Node; p1= p1->next; p1->data= '4';
    p1->next= new Node; p1= p1->next; p1->data= '5';
    p1->next= new Node; p1= p1->next; p1->data= '6';
    p1->next= new Node; p1= p1->next; p1->data= '7'; p1->next= nullptr;
    
    linkedlist2.head= new Node;
    
	Node * p2=linkedlist2.head;
    
	p2->data= 'a';    
	p2->next= new Node; p2= p2->next; p2->data= 'b';
    p2->next= new Node; p2= p2->next; p2->data= 'c';
    p2->next= new Node; p2= p2->next; p2->data= 'd';
    p2->next= linkedlist1.head->next->next;
    
    
	cout<<endl<<"Linked List1:"<<endl;
    display_linked_list(linkedlist1.head);
	
	cout<<endl<<"Linked List2:"<<endl;
    display_linked_list(linkedlist2.head);
	
	cout<<endl<<endl;
    cout<<endl<<"Intersecting Node :  "<< (find_intersection_of_the_linked_lists(linkedlist1.head, linkedlist2.head))->data<<endl;
    
    cout<<endl;

    return 0;
}

