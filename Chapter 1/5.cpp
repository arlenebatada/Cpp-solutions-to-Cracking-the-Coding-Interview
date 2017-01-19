#include <iostream>

using namespace std;

bool is_replace_one_away(char* s1, char* s2, int size)
{
	int discrepancy=0;
	
	for(int i=0; i<size; i++)
	{
		if(s1[i] != s2[i])
		{
			if(++discrepancy > 1)
			{
				return false;
			}
		}
	}
	
	return discrepancy;
}

bool is_remove_or_add_one_away(char* larger_array, char* smaller_array, int size1, int size2)
{
	if(size1 < size2)
	{
		swap(larger_array, smaller_array);
		swap(size1, size2);
	}
	
	int discrepancy=0;
	
	for(int i=0, j=0; i<size1 && j<size2; i++, j++)
	{
		if(larger_array[i] != smaller_array[j])
		{
			++j;
			if (++discrepancy > 1)
			{
				return false;
			}
		}
	}
	
	return true;
}

bool is_one_away(char* s1, char* s2, int size1, int size2)
{
	if (size1==size2)
	{
		return is_replace_one_away(s1, s2, size1);
	}
	
	return is_remove_or_add_one_away(s1, s2, size1, size2);
}

int main()
{
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	cout<<is_one_away((char*)&s1[0], (char*)&s2[0], s1.length(), s2.length());
	return 0;
}
