#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue
{
	private:
		stack <T> s1, s2;
		void emptyOneStackIntoOther(stack <T> &source, stack <T> &destination)
		{
			while (!source.empty())//while source is not empty, transfer all its contents to the destination
			{
				destination.push(source.top());
				source.pop();
			}
		}
		
	public:
		void enqueue(T data)
		{
			try
			{
				if (s1.empty())
				{
					/*if a dequeue operation has taken prior to the current enqueue*/
					if (!s2.empty())
					{
						emptyOneStackIntoOther(s2, s1); //shift all the contents of s2 to s1
					}
				}
					s1.push(data);
			}
			catch (...)
			{
				throw;
			}
		}
		
		T dequeue()
		{
			try
			{
				if (s1.empty() && s2.empty())
				{
					throw -1;
				}
				
				
				emptyOneStackIntoOther(s1, s2);//while s1 is not empty, transfer all its contents to s2
				T data = s2.top();
				s2.pop();
				return data;
			}
			catch (int i)
			{
				throw i;
			}
		}
		
		T top()
		{
			try
			{
				if (s1.empty() && s2.empty())
				{
					throw -1;
				}
				
				emptyOneStackIntoOther(s1, s2);//while s1 is not empty, transfer all its contents to s2
				return (s2.top());
			}
			catch (int i)
			{
				throw i;
			}
		}
};

int main()
{
	MyQueue <char> queue;
	queue.enqueue('1');
	queue.enqueue('2');
	queue.enqueue('3');
	queue.enqueue('4');
	queue.enqueue('5');
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	queue.enqueue('a');
	queue.enqueue('b');
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	return 0;
}
