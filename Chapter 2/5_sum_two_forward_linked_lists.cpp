#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	
	Node ()
	{
		data=0;
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

void add_node (Node **original_head, Node** pointer_to_the_last_node, int data)
{
	if (*original_head != nullptr) //if linked list in not empty
	{
		(*pointer_to_the_last_node)->next = new Node; //add a node to the linked list
		(*pointer_to_the_last_node) = (*pointer_to_the_last_node)->next; //increment the pointer so that the newly added node can be manipulated
	}
	else //if linked list is empty
	{
		*original_head = new Node;
		*pointer_to_the_last_node= *original_head;
	}
	
	(*pointer_to_the_last_node)->data = data;
	(*pointer_to_the_last_node)->next = nullptr;
}

void sum_forward_linked_lists(Node *h1, Node* h2, Node** ans, int* carry)
{
	static int level=0;
	int sum=0;
	level++;
	
	if (h1 == nullptr || h2 == nullptr) //if any of the linked list is empty, return. In recursion, this also ensures that both the lists have equal length
	{
		return;
	}
	
	if(h1->next == nullptr) //base case- if the last node is reached, start adding
	{
		sum = h1->data + h2->data; //sum = carry + n1 + n2
		*ans = new Node; //units digit node of the ans linked list
		(*ans)->data = sum % 10; //units digit of the 'sum' becomes the units digit of the answer
		(*ans)->next = nullptr;
		*carry= sum/10; //the new units digit i.e the previous tens digit of 'sum' becomes a carry
		level--;
		return;
	}
	
	sum_forward_linked_lists(h1->next, h2->next, ans, carry);
	Node* previous_of_ans = new Node;
	previous_of_ans->next = *ans;
	*ans = previous_of_ans;
	sum = *carry + h1->data + h2->data;
	(*ans)->data = sum % 10;
	*carry= sum/10;
	
	if (level == 1)
	{
		if (*carry != 0)
		{
			previous_of_ans= new Node;
			previous_of_ans->next = *ans;
			*ans = previous_of_ans;
			(*ans)->data = *carry;
		}
	}
	level--;
	return;
}

void sum_forward_linked_lists(Node *h1, Node* h2, Node** ans)
{
	int carry=0;
	sum_forward_linked_lists(h1, h2, ans, &carry);
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

void append_zeroes(Node ** head, int number_of_zeroes)
{
	Node* p = nullptr;
	for (int i=0; i < number_of_zeroes; i++)
	{
		p = new Node;
		p->data = 0;
		p->next = *head;
		*head = p;
	}
}

int main()
{
	int number_of_nodes1, number_of_nodes2;
    cin >> number_of_nodes1;
    cin >> number_of_nodes2;
    if (number_of_nodes1 <= 0 || number_of_nodes2 <=0 )
    {
    	return 0;
	}
	
    LinkedList linkedlist1, linkedlist2;
    create_linked_list(&(linkedlist1.head), number_of_nodes1);
    create_linked_list(&(linkedlist2.head), number_of_nodes2);
	
	if(number_of_nodes1 != number_of_nodes2)
	{
		if (number_of_nodes1 < number_of_nodes2)
		{
			append_zeroes(&(linkedlist1.head), number_of_nodes2 - number_of_nodes1);
		}
		else
		{
			append_zeroes(&(linkedlist2.head), number_of_nodes1 - number_of_nodes2);
		}
	}
	
    cout<<endl<<"Linked List1:"<<endl;
    display_linked_list(linkedlist1.head);
	
	cout<<endl<<"Linked List2:"<<endl;
    display_linked_list(linkedlist2.head);
	
	LinkedList ans;
	sum_forward_linked_lists(linkedlist1.head, linkedlist2.head, &(ans.head));
	
	cout<<endl<<endl;;
    cout<<endl<<"Answer Linked List:"<<endl;
    display_linked_list(ans.head);
	
    cout<<endl;

    return 0;
}

