#include <unordered_map>
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

void remove_duplicates(Node *ptr)
{
    //if Linked List has 0 or 1 node, no need to progress
    if (ptr==NULL || ptr->next==NULL)
    {
        return;
    }

    //We need two pointers for deletion of a node in a Linked List.
    Node * ahead_ptr= ptr->next;
    unordered_map <int, int> hashtable;
    hash <int> int_hash;
    //inserting the first node entry in the hash table since it has appeared the first time
    hashtable.insert(make_pair(int_hash(ptr->data),ptr->data));

    while (ahead_ptr !=NULL)
    {
        /*
        If node is already present in the linked list, delete it.
        Else add it to the hash table
        */

        unordered_map<int, int> :: const_iterator iterator_to_the_entry= hashtable.find(int_hash(ahead_ptr->data));
        if (iterator_to_the_entry != hashtable.end())
        {
            ptr->next= ahead_ptr->next;
            delete ahead_ptr;
            ahead_ptr= ptr->next;
        }
        else
        {
            hashtable.insert(make_pair(int_hash(ptr->data), ptr->data));
            ptr=ptr->next;
            ahead_ptr=ptr->next;
        }
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

    remove_duplicates(linkedlist.head);

    cout<<endl<<endl;;
    cout<<"New Linked List:"<<endl;
    display_linked_list(linkedlist.head);
    cout<<endl;

    return 0;
}
