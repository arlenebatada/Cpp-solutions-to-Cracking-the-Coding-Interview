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


Node* kth_to_the_last_if_size_is_known(Node* head, int length, int k)
{
	if (head== nullptr || length < k)
	{
		return nullptr;
	}
	
	int length_minus_k= length-k;
	
	int counter=0;
	
	while (head != nullptr)
	{
		if (counter == length_minus_k)
		{
			return head;
		}
		
		head = head->next;
		
		
		counter++;
		
	}
	
	return nullptr;
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

    Node * node=kth_to_the_last_if_size_is_known(linkedlist.head, number_of_nodes, k);

    cout<<endl<<endl;;
    cout<<"Node data:"<<endl;
    cout << node->data;
    cout<<endl;

    return 0;
}

