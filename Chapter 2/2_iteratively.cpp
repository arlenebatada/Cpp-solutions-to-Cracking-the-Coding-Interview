#include <iostream>

using namespace std;

struct Node
{
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

Node* kth_to_the_last_iteratively(Node* head, int k)
{
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}
	
	Node * p1= head, *p2= head;
	int counter = 1;
	
	//increment p2 till counter equals k so that we can then have the distance between p1 and p2 equal to k
	while (++counter <= k)
	{
		p2 = p2->next;
		
		if (p2 == nullptr)
		{
			return nullptr;
		}
	}
	
	if (p2->next == nullptr) //i.e p2 is at the last node and p1 is at the first node and the distance between them is euqal to k
	{
		return p1;
	}
	
	while (p2->next != nullptr)
	{
		p1 = p1->next;
		p2= p2->next;
	}
	
	return p1;
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

    Node * node=kth_to_the_last_iteratively(linkedlist.head, k);

    cout<<endl<<endl;;
    cout<<"Node data:"<<endl;
    cout << node->data;
    cout<<endl;

    return 0;
}

