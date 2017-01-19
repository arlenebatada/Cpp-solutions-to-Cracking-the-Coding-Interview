#include<iostream>

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	
	int s1_length=s1.length();
	
	if (s1_length != s2.length())
	{
		cout<< "not permutation";
		return false;
	}
	
	int ascii_array[256];
	for(int i=0; i< 256; i++)
	{
		ascii_array[i]=0;
	}
	
	for (int i=0; i < s1_length; i++)
	{
		ascii_array[(int)s1[i]]++;
	}
	
	for (int i=0; i< s1_length; i++)
	{
		if(--ascii_array[(int)s2[i]] < 0)
		{
			cout<< "not permutation";
			return false;
		}
	}
	
	cout<< "permutation";
	return true;
}
