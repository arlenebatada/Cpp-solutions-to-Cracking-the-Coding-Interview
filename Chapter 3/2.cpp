#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Stack
{
	stack<T> data_stack, min_stack;
	
	public:
	void push (int data)
	{
		try 
		{
			if (data_stack.empty())
			{
				data_stack.push(data);
				min_stack.push(data);
				return;
			}
			
			if (data < min_stack.top())
			{
				min_stack.push(data);
			}
			
			data_stack.push(data);
			return;
		}
		catch (...)
		{
			throw;
		}
	}
	
	T pop() throw (int)
	{
		try 
		{
			if (data_stack.empty())
			{
				throw -1;
			}
			if (data_stack.top() == min_stack.top())
			{
				min_stack.pop();
			}
			T data = data_stack.top();
			data_stack.pop();
			return data;
		}
		catch (int i)
		{
			throw i;
		}
	}
	
	T min() throw (int)
	{
		try
		{
			if (min_stack.empty())
			{
				throw -2;
			}
			
			return (min_stack.top());
		}
		catch (int i)
		{
			throw i;
		}
	}
	
	T top() throw (int)
	{
		try 
		{
			if (data_stack.empty())
			{
				throw -1;
			}
			
			return (data_stack.top());
		}
		catch (int i)
		{
			throw i;
		}
	}
};

int main()
{
	Stack<int> s;
	try
	{
		s.push(1);
		s.push(3);
		cout<<s.min();
		s.push(-6);
		s.push(7);
		cout<<endl<<s.min();
		s.pop();
		cout<<endl<<s.min();
		s.pop();
		cout<<endl<<s.min();
		cout<<endl<<s.top();
	}
	catch (int i)
	{
		cout <<i;
	}
	return 0;
}
