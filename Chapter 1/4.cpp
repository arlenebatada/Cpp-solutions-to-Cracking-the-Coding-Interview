#include <iostream>

using namespace std;

int count_odd_bits (bool* array, int size)
{
	int count=0;
	
	for(int i=0; i<size; i++)
	{
		if (array[i])
		{
			++count;
		}
	}
	
	return count;
}

bool is_palindrome_permutation(char* input, int size)
{
	bool bool_array[26];
	
	for(int i=0; i<26; i++)
	{
		bool_array[i]=false;
	}
	
	for (int i=0; i< size; i++)
	{
		if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') )
		{
			if (input[i] >='a' && input [i] <= 'z')
			{
				bool_array[input[i]-'a']= !bool_array[input[i]-'a'];
			}
			else
			{
				bool_array[input[i]-'A']= !bool_array[input[i]-'A'];
			}
		}
	}
	
	int number_of_odd_counts=count_odd_bits(bool_array, 26);
	
	if(number_of_odd_counts==0 || number_of_odd_counts==1)
	{
		return true;
	}
	
	return false;
}



int main()
{
	string s;
	getline(cin, s);
	

	
	cout<< is_palindrome_permutation(&s[0], s.length());
}
