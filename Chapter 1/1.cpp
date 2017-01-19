#include<iostream>

int main()
{
	std::string input;
	//scanf("%[/n]", input);
	getline(std::cin, input);
	int input_length=input.length();
	printf("%d",input_length);
	
	if(input_length > 91)
	{
		printf("not unique");
		return false;
	}
	
	else
	{
		bool ascii_bool_array[91];
		
		for(int i=0; i<91; i++)
		{
			ascii_bool_array[i]=false;
		}
		
		for(int i=0; i<input_length; i++)
		{
			int index_of_bool_array= (int)input[i]-31;
			
			if(ascii_bool_array[index_of_bool_array] == true)
			{
				printf("not unique");
				return false;
			}
			
			else
			{
				if(input[i] != ' ')
				ascii_bool_array[index_of_bool_array]=true;
			}
		}
		
		printf("unique");
		return true;
	}
}
