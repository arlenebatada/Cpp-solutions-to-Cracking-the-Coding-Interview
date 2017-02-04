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

bool is_odd(int number)
{
	return (number%2 != 0);
}

bool is_linked_list_palindrome(Node * head, int length, Node ** compare) 
{
	static int level=0;
	level++;
	
	if (head == nullptr) //if the list is empty
	{
		return false;
	}
	
	if(level == length >> 1 )/* if level == length/2 */ 
	{
		if (is_odd(length))
		{
			*compare = head->next->next->next; //suppose the list is {1,2,3,4,5}, then we're at 5/2 i.e 2nd level. 'compare' points to 5 so that 1 can compare itself with 5
			return (head->data == head->next->next->data); //returns true if 2 equals 4 in {1,2,3,4,5}
		}
		else //the list has even number of elements
		{
			*compare = head->next->next; //suppose the list is {1,2,3,4}, then we're at 4/2 i.e 2nd level. 'compare' points to 4 so that 1 can compare itseld with 4
			return (head->data == head->next->data); //returns true if 2 equals 4 in {1,2,3,4}
		}
	}
	
	if (is_linked_list_palindrome (head->next, length, compare) && head->data == (*compare)->data) //if the inner list is a palindrome and the current element is a palindrome
	{
		*compare = (*compare)->next; //make 'compare' point to the next element in the list so that the outer element can compare itself with the respective element in the list
		return true; 
	}
	else
	{
		return false;
	}
}

bool is_linked_list_palindrome(Node * head, int length)
{
	Node *compare= nullptr; //compare is a pointer to the node to which the outer node will compare its data to determine if the list is a palindrome
	return (is_linked_list_palindrome(head, length, &compare));	
} 

void create_linked_list(Node** original_head, int number_of_nodes)
{
    *original_head= new Node;
    Node * head= *original_head;

    for(int i=0; i<number_of_nodes; i++)
    {
        cin >> (head->data);
        if(i < number_of_nodes-1)
        {
            head->next= new Node;
            head=head->next;
        }
    }

    head->next=NULL;
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
	int number_of_nodes;
    cin >> number_of_nodes;
    if (number_of_nodes <= 0)
    {
    	return 0;
	}
	
    LinkedList linkedlist;
    create_linked_list(&(linkedlist.head), number_of_nodes);
    
	cout<<endl<<"Linked List:"<<endl;
    display_linked_list(linkedlist.head);
	
	cout<<endl<<endl;
    cout<<endl<<"Is the linked list a palindrome? :  "<< is_linked_list_palindrome(linkedlist.head, number_of_nodes)<<endl;
    
    cout<<endl;

    return 0;
}

