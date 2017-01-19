#include <iostream>

using namespace std;

bool is_rotation(string s1, string s2)
{
	
	s2+=s2;
	
	/* string function find() gives inaccurate result for some strings. Eg- if s1="aa" and s2="aa"
	
	if(s2.find(s1))
	{
		return true;
	}
	
	return false;
	
	*/
	
	for (int i=0, j=0, count=0; i<s2.length(); i++)
	{
		if (s2[i] == s1[j])
		{
			count++;
			j++;
			
			if(count==s1.length())
			{
				return true;
			}
		}
		else
		{
			count=0;
			j=0;
		}
		
	}
	
	return false;
}

int main()
{
	string original_string, rotated_string;
	cin >> original_string;
	cin >> rotated_string;
	
	if ( is_rotation(original_string, rotated_string) )
	{
		cout<< "yes";
	}
	else
	{
		cout<<"no";
	}
}
