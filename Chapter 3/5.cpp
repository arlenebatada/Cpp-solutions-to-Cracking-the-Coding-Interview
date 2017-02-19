#include <iostream>
#include <stack>
using namespace std;

template <class T>
void sortStack (stack <T> &s)
{
	if (s.empty())
	{
		throw -1;
	}
	
	stack <T> temp_stack; //temporary stack
	T temp; //temporary variable
	
	while (!s.empty())
	{
		/*push the top of the stack onto the temp_stack if it is the greater than the top of temp_stack
		(i.e. the greatest of all the elements present in the temp_stack, 
		because temp_stack is already sorted in the descending order)*/
		
		if(temp_stack.empty() || s.top() > temp_stack.top())
		{
			temp_stack.push(s.top());
			s.pop();
		}
		else //if the top of the stack is less than that of the temp_stack
		{
			temp = s.top(); //pop the top of the stack into the temp variable
			s.pop();
			
			/*shift all the elements from the temp_stack into the stack till the correct place
			for the temp is found*/
			while (!temp_stack.empty() && temp < temp_stack.top())
			{
				s.push(temp_stack.top());
				temp_stack.pop();
			}
			//after the correct position for the temp is found on the temp_stack, push it onto the same
			temp_stack.push(temp);
		}
	}
	
	/*After all the elements from the stack fall into the descending order sorted temp_stack, push them
	back into the temp stack so as to make the place ove there in the ascending order*/
	
	while (!temp_stack.empty())
	{
		s.push(temp_stack.top());
		temp_stack.pop();
	}
}

int main()
{
	stack<char> s;
	s.push('1');
	s.push('3');
	s.push('6');
	s.push('0');
	s.push('a');
	s.push('4');
	s.push('4');
	s.push('5');
	sortStack<char>(s);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
}
