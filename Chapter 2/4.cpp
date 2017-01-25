#include <iostream>

using namespace std;

struct Node
{
	public:
	int data;
	Node * next;	
};

class LinkedList
{
	public:
		Node * head;
};

void partition (Node ** head, int x)
{
	//if list is empty or if there is only one node present, return
	if ((*head)==nullptr || (*head)->next==nullptr)
	{
		return;
	}
	
	//p1 & p2 to traverse the list and shift the nodes.
	//a dummy node will be inserted in the beginning which will be the initial breakpoint between 2 groups of nodes- 1. all nodes <x and 2. all nodes >=x
	Node* p1, *p2, *dummy_node;
	dummy_node=new Node;
	dummy_node->data=x-1;
	dummy_node->next=*head;
	*head = dummy_node;
	p1= *head;
	p2= p1->next;
	
	while (p1->next->data < x)
	{
		/*make pl and p2 travese the list till the first node with value >x is encountered after p1*/
		p1= p1->next;
		if (p1 == nullptr) //if p1 reaches the end, no node with value >x is present in the list
		{
			return;
		}
		p2= p2->next;
	}
	
	*head= p1; //p1 is the new breakpoint between 2 groups of nodes- 1. all nodes <x and 2. all nodes >=x
	p2= p1->next;
	
	while (p1->next != nullptr) //traverse the list till the end and shift the nodes whenever necessary
	{
		if (p1->next->data < x) //if the next node after p is <x
		{
			//make the second next node after p1 its next one
			p1->next = p2->next;
			//make second next node after p1 be the next node after the breakpoint node
			p2->next = (*head)->next;
			(*head)->next= p2; 
			//increment the breakpoint
			(*head)= (*head)->next;
			//make p2 proceed p1
			p2= p1->next;
		}
		else
		{
			p1= p1->next;
			p2= p2->next;
		}
	}
	(*head)=dummy_node->next; //reset the head node
	delete dummy_node; //remove the dummy node
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
	int number_of_nodes, partition_value;
    cin >> number_of_nodes;
    cin >> partition_value;
    if (number_of_nodes <= 0 )
    {
    	return 0;
	}
	
    LinkedList linkedlist;
    create_linked_list(&(linkedlist.head), number_of_nodes);
	
    cout<<endl<<"Linked List:"<<endl;
    display_linked_list(linkedlist.head);
	
	partition(&(linkedlist.head), partition_value);
	
	
    cout<<endl<<endl;;
    cout<<endl<<"Modified Linked List:"<<endl;
    display_linked_list(linkedlist.head);
	
    cout<<endl;

    return 0;
}

