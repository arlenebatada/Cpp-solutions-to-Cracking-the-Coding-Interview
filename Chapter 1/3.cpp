#include <iostream>

using namespace std;

int calculate_spaces(char* input, int size)
{
	int spaces= 0;
	
	for(int i=0; i<size; i++)
	{
		if(input[i]==' ')
		{
			spaces++;
		}
	}
	
	return spaces;
}

void shifter(char* input, int size, int spaces)
{
	int no_of_shifts=spaces<<1;
	char* ptr= input+size+1;
	
	for (int i=size+no_of_shifts+1; i>=0; i--)
	{
		if(ptr==&input[i])
		{
			return;
		}
		
		if (*ptr != ' ')
		{
			input[i]= *(ptr--);
		}
		else
		{
			*ptr='0';
			input[i--]= *(ptr--);
			input[i--]= '2';
			input[i]= '%';
		}
	}
}

int main()
{
	//string input;
	//getline(cin, input);
	char input[1000]= {' ','h', 'i', ' ', 'h', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', ' ', '?', ' '};
	
	//int size=input.length();
	int size=18;
	int spaces= calculate_spaces(&input[0], size);
	shifter(&input[0], size, spaces);
	cout<<input;
	return 0;
}
