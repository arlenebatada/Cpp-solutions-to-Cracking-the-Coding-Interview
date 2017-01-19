#include <iostream>

using namespace std;

int ** create_array(int row_size, int column_size)
{
	int **array= new int* [row_size];
	
	for (int i=0; i< row_size; i++)
	{
		array[i]= new int[column_size];
	}
	
	for(int i=0; i<row_size; i++)
	{
		for (int j=0; j<column_size; j++)
		{
			cout<< "array[" << i << "][" << j << "]= ";
			cin>>array[i][j];
		}
	}
	
	return array;
}

void display_array(int **array, int row_size, int column_size)
{
	for(int i=0; i<row_size; i++)
	{
		for (int j=0; j<column_size; j++)
		{
			cout<< array[i][j]<<"	";
		}
		cout<<endl;
	}
}

bool check_zeroes_in_row(int ** array, int row_number, int column_size)
{
	for (int j=0; j< column_size; j++)
	{
		if (array[row_number][j] == 0)
		{
			return true;
		}
	}
	
	return false;
}

bool check_zeroes_in_column(int ** array, int column_number, int row_size)
{
	for (int i=0; i< row_size; i++)
	{
		if (array[i][column_number] == 0)
		{
			return true;
		}
	}
	
	return false;
}

void nullify_row(int ** array, int column_size, int row_number)
{
	for (int j=0; j<column_size; j++)
	{
		array[row_number][j]=0;
	}
}

void nullify_column(int ** array, int row_size, int column_number)
{
	for (int i=0; i<row_size; i++)
	{
		array[i][column_number]=0;
	}
}

void set_zero(int ** array, int row_size, int column_size)
{
	bool zeroes_in_the_zeroth_row= check_zeroes_in_row(array, 0, column_size);
	bool zeroes_in_the_zeroth_column= check_zeroes_in_column(array, 0, row_size);
	
	//for each zero in the remaining matrix set the corresponding row & column bit to zero
	for (int i=1; i<row_size; i++)
	{
		for (int j=1; j<column_size; j++)
		{
			if (array[i][j] == 0)
			{
				array[0][j]=0; //set the corresponding row bit to zero
				array[i][0]=0; //set the corresponding column bit to zero
			}
		}
	}
	
	//nullify all columns who's array[0][j] is 0
	for (int j=1; j<column_size; j++)
	{
		if (array[0][j] == 0)
		{
			nullify_column(array, row_size, j);
		}
	}
	
	//nullify all rows who's array[i][0] is 0
	for (int i=1; i<row_size; i++)
	{
		if (array[i][0] == 0)
		{
			nullify_row(array, column_size, i);
		}
	}
	
	if (zeroes_in_the_zeroth_row)
	{
		nullify_row(array, column_size, 0);
	}
	
	if (zeroes_in_the_zeroth_column)
	{
		nullify_column(array, row_size, 0);
	}
}




int main()
{
	int row_size, column_size, ** array;
	cin >> row_size;
	cin >> column_size;
	
	array=create_array(row_size, column_size);
	cout<<endl<<"Original Array: "<<endl;
	display_array(array, row_size, column_size);
	
	set_zero(array, row_size, column_size);
	cout<<endl<<"Zeroed Array: "<<endl;
	display_array(array, row_size, column_size);
	
}
