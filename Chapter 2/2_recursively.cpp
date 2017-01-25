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

Node * kth_to_the_last_recursively (Node * head, int &counter, int k)
{
	if (head == nullptr)
	{
		return nullptr;
	}
	
	Node * node = kth_to_the_last_recursively (head->next, counter, k);
	
	if (++counter == k)
	{
		return head;
	}
	
	return node;
}

Node * kth_to_the_last_recursively (Node * head, int k)
{
	int counter = 0;
	Node * node = kth_to_the_last_recursively (head, counter, k);
	return node;
}


int main()
{
	int number_of_nodes, k;
    cin >> number_of_nodes;
    cin >> k;
    
    if (number_of_nodes <= 0 || number_of_nodes < k || k <= 0)
    {
    	return 0;
	}
	
    LinkedList linkedlist;
    create_linked_list(&(linkedlist.head), number_of_nodes);
	
    cout<<endl<<"Linked List:"<<endl;
    display_linked_list(linkedlist.head);

    Node * node=kth_to_the_last_recursively(linkedlist.head, k);

    cout<<endl<<endl;;
    cout<<"Node data:"<<endl;
    cout << node->data;
    cout<<endl;

    return 0;
}

