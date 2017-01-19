#include <iostream>

using namespace std;

int compress_string(char* str, char* compressed_string, int length)
{
	if(compressed_string[0] != '0')
	{
		char* ptr1=str, *ptr2=compressed_string;
		int count=1;
		*ptr2=*ptr1;
		int length_of_compressed_string=1;
		
		for (int i=0; i<length; i++)
		{
			ptr1++;
			
			if (*ptr2== *ptr1)
			{
				count++;
			}
			else
			{
				if (count>1)
				{
					*(++ptr2) = '0' + count;
					length_of_compressed_string++;
					count=1;
				}
				
				*(++ptr2)= *ptr1;
				length_of_compressed_string++;
			}
			
		}
		
		return (length_of_compressed_string-1);
	}
	
	return 0;
}

int main()
{
	string str;
	getline(cin, str);
	
	char compressed_string[str.length()];
	
	
	
	if(compress_string((char*) &str[0], compressed_string, str.length()) == str.length())
	{
		cout<< str;
	}
	else
	{
		cout<< compressed_string;
	}
	
	return 0;
}
