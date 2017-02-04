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

void sum_reverse_linked_lists(Node *h1, Node* h2, Node** ans)
{
	//if any of the linked list is empty, return
	if(h1 == nullptr || h2 == nullptr)
	{
		return;
	}
	
	//pointer p1 for traversing linked list 1, p2 for traversing linked list2, p3 points to the last node of the answer linked list
	Node* p1= h1, *p2=h2, *p3= *ans;
	int sum=0, sum_array[2]= {0}; //sum_array[0] for holding the carry and sum_array[0] for holding the number which is a part of the answer
	
	while (p1 != nullptr && p2 != nullptr) //while loop will execute upto minimum of the length of linked list1 and that of the linked list2
	{
		sum = sum_array[0] + p1->data + p2->data; //sum = carry + n1 + n2
		sum_array[1] = sum % 10; //units digit of the 'sum' becomes a part of the answer
		sum/=10; //units digit of the 'sum'is removed
		sum_array[0] = sum; //the new units digit i.e the previous tens digit of 'sum' becomes a carry
		sum=0;
		/*
		Since the units digit (i.e. a part of the final answer) and the tens digit (i.e. carry) of the 'sum' have been extracted, it is set to 0.
		In adding any two numbers and a carry, the maximum answer which can be produced is 27 (9+9+9); where 7 will be a part of the final answer
		and 2 will be the carry.
		Also, maximum carry which can be produced is 9 and the maximum sum which can be produced by adding any two numbers is 9.
		In none of the cases, the 'sum' will exceed 99 and so an array holding only 2 digits is required
		*/
		add_node(ans, &p3, sum_array[1]);
		p1 = p1->next;
		p2 = p2->next;
	}
	
	Node * p4 = nullptr; //p4 will traverse the remaining part of the longer linked list
	if(p1 != nullptr) //if linked list1 is longer
	{
		p4 = p1;
	}
	
	if (p2 != nullptr) //if linked list2 is longer
	{
		p4 = p2;
	}
	
	while (p4 != nullptr) //traversing the remaining part of the longer linked list
	{
		sum = sum_array[0] + p4->data;
		sum_array[1] = sum % 10;
		sum/=10;
		sum_array[0] = sum;
		sum=0;
		add_node (ans, &p3, sum_array[1]);
		p4 = p4->next;
	}
	
	if (sum_array[0] != 0) //if after adding two linked lists any carry remains, make it a part of the answer
	{
		add_node (ans, &p3, sum_array[0]);
	}
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
	
    cout<<endl<<"Linked List1:"<<endl;
    display_linked_list(linkedlist1.head);
	
	cout<<endl<<"Linked List2:"<<endl;
    display_linked_list(linkedlist2.head);
	
	LinkedList ans;
	sum_reverse_linked_lists(linkedlist1.head, linkedlist2.head, &(ans.head));
	
	cout<<endl<<endl;;
    cout<<endl<<"Answer Linked List:"<<endl;
    display_linked_list(ans.head);
	
    cout<<endl;

    return 0;
}

