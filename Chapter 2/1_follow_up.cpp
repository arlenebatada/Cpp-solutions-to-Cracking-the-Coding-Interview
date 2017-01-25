#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    public:
    Node *head;
};

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

void remove_duplicates_without_temp(Node * head)
{
	if (head==NULL || head->next==NULL)
	{
		return;
	}
	
	Node * p1=head, *p2=p1->next;
	
	/* 
	For each node, search all the nodes after that, till the end of the list. 
	Remove all the duplicate nodes while performing this.
	*/
	
	while (head!=NULL)
	{
		p1=head;
		p2=p1->next;
			
		while (p1->next != nullptr)
		{	
			if (p1->next->data==head->data)
			{
				p1->next = p2->next;
				delete p2;
				p2 = p1->next;
			}
			
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		
		head = head->next;
	}
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
	
    cout<<endl<<"Original Linked List:"<<endl;
    display_linked_list(linkedlist.head);

    remove_duplicates_without_temp(linkedlist.head);

    cout<<endl<<endl;;
    cout<<"New Linked List:"<<endl;
    display_linked_list(linkedlist.head);
    cout<<endl;

    return 0;
}
