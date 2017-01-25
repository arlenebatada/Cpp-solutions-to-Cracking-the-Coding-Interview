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

void delete_node (Node * node)
{
	while (node != nullptr)
	{
		if (node->next == nullptr)
		{
			node->data= -4096;
			return;
		}
		
		node->data= node->next->data;
		node = node->next;
	}
	
}

Node * required_node_address (Node * head, int position)
{
	if (position == 1)
	{
		return head;
	}
	for (int i=1; i <position; i++)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		head = head->next;
	}
	
	return head;
}

int main()
{
	int number_of_nodes;
    cin >> number_of_nodes;
    
    if (number_of_nodes <= 0 )
    {
    	return 0;
	}
	
    LinkedList linkedlist;
    create_linked_list(&(linkedlist.head), number_of_nodes);
	
    cout<<endl<<"Linked List:"<<endl;
    display_linked_list(linkedlist.head);
	
	int position;
	cout<<endl<<endl;
	cin >> position;
	
    Node * node = required_node_address(linkedlist.head, position);
	
	if (node == nullptr)
	{
		return 0;
	}
	
	delete_node (node);
	
    cout<<endl<<endl;;
    cout<<endl<<"Modified Linked List:"<<endl;
    display_linked_list(linkedlist.head);
	
    cout<<endl;

    return 0;
}

