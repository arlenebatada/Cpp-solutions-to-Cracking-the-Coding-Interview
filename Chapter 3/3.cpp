#include <iostream>
#include <vector>
using namespace std;

template <class T>
class StackManager
{
	//eventough 'vector' class can render the number of elements present using size() function, a pair is used so as to perfrom the task manually
	vector < pair <vector <T> /*stack storage*/, int /*size*/> > stacks_with_number_of_elements; 
	size_t stack_capacity;
	
	void shift_left(vector <T> &v)
	{
		for (size_t i=0; i < v.size()-1; i++)
		{
			v[i] = v[i+1];
		}
	}
	
	public:
	StackManager(size_t stack_capacity)
	{
		this->stack_capacity = stack_capacity;
	}
	
	void push (T data)
	{
		try
		{
			//if inserting the first element in the StackManager OR if the last stack in the StackManager is full
			if (stacks_with_number_of_elements.empty() || stacks_with_number_of_elements.back().second == stack_capacity) 
			{
				vector <T> v; //create a new vector which acts as a storage for our 'abstract' stack
				stacks_with_number_of_elements.push_back(make_pair(v, 0));//add a new stack to the StackManager
			}
			
			stacks_with_number_of_elements.back().first.push_back(data); //add the data to the last stack
			stacks_with_number_of_elements.back().second++;//increment the int indicating the size of the stack
			return;
		}
		catch (...)
		{
			throw;
		}
	}
	
	T pop()
	{
		try
		{
			if (stacks_with_number_of_elements.empty()) //if there is no stack present, return
			{
				throw -1;
			}
			
			T data = stacks_with_number_of_elements.back().first.back(); //copy the last element in the last stack/vector to 'data'
			stacks_with_number_of_elements.back().first.pop_back();//pop the last element from the last stack/vector
			stacks_with_number_of_elements.back().second--;//decrement the size of the stack
			
			if (stacks_with_number_of_elements.back().second == 0)//if the last stack has emptied
			{
				stacks_with_number_of_elements.pop_back();//pop the last stack/vector from the stack vector
			}
			
			return data;
		}
		catch (int i)
		{
			throw i;
		}
	}
		
	T peek()
	{
		try
		{
			if (stacks_with_number_of_elements.empty()) //if there is no stack present, return
			{
				throw -1;
			}
			
			return (stacks_with_number_of_elements.back().first.back());
		}
		
		catch (int i)
		{
			throw i;
		}
	}
	
	T pop_at (int stack_number)
	{
		try
		{
			if (stack_number-- > stacks_with_number_of_elements.size()) //if input stack_number is greater than the number of stacks present, return
			{
				throw -2;
			}
			
			T data = stacks_with_number_of_elements.at(stack_number).first.back();//copy the last element from the respective stack to 'data
			
			//iterate from the vector/stack from which the element is to be popped, to the last vector/stack in the stack array
			//so as to shift all the elements in the stacks towards the bottom by 1, such that the last element of the next stack 
			//becomes the first element of the previous one
			for (int i = stack_number; i < stacks_with_number_of_elements.size()-1; i++)
			{
				//bottom of stack i equals front of the stack i+1
				stacks_with_number_of_elements.at(i).first.back() = stacks_with_number_of_elements.at(i+1).first.front();
				
				shift_left(stacks_with_number_of_elements.at(i+1).first);
			}
			
			pop();
			return data;
			
		}
		
		catch (int i)
		{
			throw i;
		}
	}
};

int main()
{
	int stack_capacity = 3;
	stack_capacity;
	
	StackManager<char> stackmanager (stack_capacity);
	
	try
	{
		stackmanager.push('a');
		stackmanager.push('b');
		stackmanager.push('c');
		stackmanager.push('d');
		stackmanager.push('e');
		stackmanager.push('f');
		cout <<endl <<stackmanager.peek();
		stackmanager.pop_at(1);
		cout <<endl <<stackmanager.peek();
		
	}
	catch(int i)
	{
		cout<<endl<<i;
	}
	
	return 0;
}
