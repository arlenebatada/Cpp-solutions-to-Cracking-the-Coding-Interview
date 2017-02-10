/*
There are 3 stacks- s1, s2, s3 each pushing their elements in a common array such that s1 increases from the start of the array, 
s2 from either the start of the array or immediately after s1; depending on existance of the latter,
and s3 from the end of the array.

If array is full while pushing an element in any of the stacks, an exception is thrown.
Stacks s1 and s3 have a fixed bottom at the start and the end of the array respectively. 
Stack s2 oscillates between s1 and s2 i.e between left & right in the array.
If s1 pushes an element while s2 is right after it, it shifts s2 to the right and then completes its job.
If s3 pushes an element while s2 is right after it (before it in actuality), it shifts s2 to the left and then completes its job
If s2 pushes an element while s3 is right after it, or that it is about to cross the maximum array index, 
it shifts itself to the left and then completes its job
*/

#include <iostream>
using namespace std;

template <class T>
class StackManager
{
	class Stack
	{
		public:
		int top, bottom; //top and bottom indices of the stack
		int size;
		
		Stack()
		{
			top = -1;
			bottom = -1;
			size = 0;
		}
		
		bool is_empty()
		{
			return (top == -1);
		}
	};
	
	Stack s1, s2, s3; //s1 and s2 start from the left of the array, unlike s3 which starts from the end
	T* array;
	int length;
	
	public:
	StackManager (T* array, int length)
	{
		this->array = array;
		this->length = length;
	}
	
	private:
	bool is_array_full()
	{
		return (s1.size + s2.size + s3.size == length);
	}
	
	public:
	void push (int data, int stack_number) throw (int)
	{
		try
		{
			if (stack_number > 3 || stack_number < 1)
			{
				throw -2;
			}
			
			if (is_array_full())
			{
				throw -1;
			}
			
			if (stack_number == 1) //pushing the element in the first stack
			{
				if (s1.top+1 == s2.bottom) //if the next location after the top of stack 1 is the bottom of stack 2
				{
					shift_right(s2, 2); 
				}
				
				if (s1.top == -1)
				{
					s1.bottom = 0; //setting the bottom of stack 1 so as to refer it to the start of the array
				}
				
				s1.top++;
				array[s1.top] = data;
				s1.size++;
			}
			
			if (stack_number == 2) 
			{
				if (s2.top+1 >= length) //when there is space before the bottom of s2, s3 doesn't exit, and the top of stack 2 exceeds the array length
				{
					shift_left(s2, 2);
				}
				
				if (s2.top+1 == s3.top)//when there is space before the bottom of s2 and the top of stack 2 is about to collide with s3
				//since s3, unlike s1 & s2 expands from right to left, its top is compared with the top of s2
				{
					shift_left(s2, 2);
				}
				
				if (s2.top == -1)
				{
					s2.top = s1.top;//setting the top of s2 equal to that of the s1 because it is soon going to be incremented before an element is pushed into it
					s2.bottom = s1.top+1; //setting the bottom of s2 to the index of next of the top of s1
				}
				
				s2.top++;
				array[s2.top] = data;
				s2.size++;
			}
			
			if (stack_number == 3)
			{
				if (s3.top == -1)
				{
					//NOTE: s3 grows from right to left, unlike s1 and s2
					if (s2.top == length-1) //if there is space before s2, and its top is at the position where the 1st element of s3 needs to be pushed
					{
						shift_left(s2, 2);
					}
					
					s3.top = length-1;//array ranges from 0 to length-1
					s3.bottom = length-1;
					array[s3.top] = data;
					s3.size = 1;
				}
				
				else
				{
					if (s3.top-1 == s2.top)//there is space before s2, while s3 is about to collide with s2 while pushing an element
					{
						shift_left(s2, 2);
					}
					s3.top--;
					array[s3.top] = data;
					s3.size++;
				}
			}
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
			if (stack_number > 3 || stack_number < 1)
			{
				throw -2;
			}
			
			if (stack_number ==1)
			{
				if(s1.is_empty())
				{
					throw -1;
				}
				
				T data = array[s1.top];
				
				if (s1.size ==1)//if stack 1 has only 1 element
				{
					s1.top = -1;
					s1.bottom = -1;
					s1.size = 0;
				}
				
				else
				{
					s1.top--;
					s1.size--;
				}
				return data;
			}
			
			if (stack_number ==2)
			{
				if(s2.is_empty())
				{
					throw -1;
				}
				
				T data = array[s2.top];
				
				if (s2.size ==1)//if stack 2 has only 1 element
				{
					s2.top = -1;
					s2.bottom = -1;
					s2.size = 0;
				}
				
				else
				{
					s2.top--;
					s2.size--;
				}
				return data;
			}
			
			if (stack_number == 3)
			{
				if(s3.is_empty())
				{
					throw -1;
				}
				
				T data = array[s3.top];
				
				if (s3.size ==1)//if stack 3 has only 1 element
				{
					s3.top = -1;
					s3.bottom = -1;
					s3.size = 0;
				}
				
				else
				{
					s3.top++; //equivalent to writing s3.top = s3.top+1, just that this works in circular array
					s3.size--;
				}
				return data;
			}
			
		}
		
		catch (int i)
		{
			throw i;
		}
		
	}
	
	T peek(int stack_number) throw (int)
	{
		try
		{
			if (stack_number > 3 || stack_number < 1)
			{
				throw -2;
			}
			
			if (stack_number ==1)
			{
				if(s1.is_empty())
				{
					throw -1;
				}
				
				
				return array[s1.top];
			}
			
			if (stack_number ==2)
			{
				if(s2.is_empty())
				{
					throw -1;
				}
				
				return array[s2.top];
			}
			
			if (stack_number == 3)
			{
				if(s3.is_empty())
				{
					throw -1;
				}
				
				return array[s3.top];
			}
			
		}
		
		catch (int i)
		{
			throw i;
		}
	}
	
	private:
	void shift_right(Stack &s, int stack_number)
	{
		int p = s.top;
		if (stack_number == 3)
		{
			p = s.bottom; //s3 is opposite to the other two stacks, where it needs to be shifted to the right from its bottom
		}
		
		s.top++;//increment 'top' as the stack has shifted to the right by 1
		
		for (size_t i=0; i<s.size; i++)
		{
			array[p+1] = array[p]; 
			p--; //'p' equals to the previous location in the array
		}
		s.bottom++; //increment 'bottom' as the stack has shifted by 1 to the right
	}
	
	void shift_left (Stack &s, int stack_number)
	{
		int p = s.bottom;
		if (stack_number == 3)
		{
			p = s.top; //s3 is opposite to the other two stacks, where it needs to be shifted to the left from its top
		}
		s.bottom--; //decrement 'bottom' as the stack has shifted to the left by 1
		
		for (size_t i=0; i<s.size; i++)
		{
			array[p-1] = array[p];
			p++;//'p' equals to the next location
		}
		s.top--; //decrement 'top' as the stack has shifted to the left by 1
	}
};

int main()
{
	int array[6];
	StackManager<int> stackmanager (array, 6);
	try
	{
		
		/*
		stackmanager.push(10,1);
		stackmanager.push(11,1);
		stackmanager.push(20,2);
		stackmanager.push(21,2);
		stackmanager.push(30,3);
		stackmanager.push(31,3);
		stackmanager.pop(1);
		stackmanager.push(22,2);
		*/
		/*
		stackmanager.push(10,1);
		stackmanager.push(20,2);
		stackmanager.push(30,3);
		stackmanager.push(31,3);	
		stackmanager.pop(1);
		stackmanager.push(21,2);
		stackmanager.pop(2);
		stackmanager.push(32,3);
		stackmanager.pop(2);
		stackmanager.push(10,1);
		stackmanager.pop(2);
		*/
		/*
		stackmanager.push(20, 2);
		stackmanager.push(21, 2);
		stackmanager.push(10, 1);
		stackmanager.push(11, 1);
		stackmanager.pop(1);
		stackmanager.pop(1);
		stackmanager.push(22, 2);	
		stackmanager.push(30, 3);
		*/	
	}
	catch (int i)
	{
		cout <<endl<< "Error Code: "<<i;
	}
	return 0;
}
