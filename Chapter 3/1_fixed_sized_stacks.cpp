#include <iostream>

using namespace std;

template <class T>

class StackManager
{
	class Stack
	{
		T* top, *start, *end;
		
		public:
		set_start_and_end_pointers(T* start, T* end)
		{
			this->start = start;
			this->end = end;
			top = nullptr;
		}
		
		void push (T data)
		{
			if (top == nullptr) //inserting the 1st element
			{
				top = start;
				*top = data;
				return;
			}
			
			if (top == end) //stack full
			{
				throw -1;
			}
			
			*(++top) = data; //increment top and insert the element in all the cases except- 1. inserting the 1st element and 2. stack being full
			return;
		}
		
		T pop()
		{
			if (top == start) //removing the 1st element
			{
				T data = *top;
				top = nullptr;
				return data;
			}
			
			if (top == nullptr) //if stack is empty
			{
				throw -1;
			}
			
			T data = *(top--); //take the element and decrement 'top' in all the cases except- 1. Removing the 1st element and 2. stack being empty
			return data;
		}
		
		T peek()
		{
			if (top == nullptr) //if stack is empty
			{
				throw -1;
			}
			
			return *top;
		}
	};

	T* array;
	int size;
	Stack stack_array[3];
	
	public:
	StackManager(T* array, int size)
	{
		this->array = array;
		this->size = size;
		//calling Stack class constructor below:
		stack_array[0].set_start_and_end_pointers(array, array + (size/3 - 1)); //1st stack ranges from array[0] to array[n/3 -1]
		stack_array[1].set_start_and_end_pointers(array + (size/3), array + (2*size/3 -1));//2nd stack ranges from array[n/3] to array[2n/3 -1]
		stack_array[2].set_start_and_end_pointers(array + (2*size/3), array + size);//3rd stack ranges from array[2n/3] to array[n]
	}
	
	void check_stack_number (int stack_number) throw (int)
	{
		if (stack_number > 3 || stack_number <1)
		{
			throw -2;
		}
	}
	
	void push (T data, int stack_number) throw (int)
	{	
		try
		{
			check_stack_number(stack_number);
			stack_array[stack_number-1].push(data); //stack_number-1 because array starts from 0 rather than 1
		}
		
		catch (int i)
		{
			throw i;
		}
	}
	
	T pop(int stack_number) throw (int)
	{
		try
		{
			check_stack_number(stack_number);
			return (stack_array[stack_number-1].pop()); //stack_number-1 because array starts from 0 rather than 1
		}
		
		catch (int i)
		{
			throw i;
		}
	}
	
	T peek (int stack_number) throw (int)
	{
		try
		{
			check_stack_number(stack_number);
			return (stack_array[stack_number-1].peek()); //stack_number-1 because array starts from 0 rather than 1
		}
		
		catch (int i)
		{
			throw i;
		}
		
	}
};

int main()
{
	int array[4];
	StackManager<int> stackmanager (array, 5);
	stackmanager.push(10, 1);
	stackmanager.push(11, 2);
	stackmanager.push(12, 2);
	stackmanager.push(13, 3);
	stackmanager.push(14, 3);
	cout << stackmanager.peek(1) <<endl;
	cout << stackmanager.pop(1) <<endl;
	cout << stackmanager.pop(2) <<endl;
	cout << stackmanager.pop(2) <<endl;
	cout << stackmanager.pop(3) <<endl;
	cout << stackmanager.pop(3) <<endl;
	return 0;
}
