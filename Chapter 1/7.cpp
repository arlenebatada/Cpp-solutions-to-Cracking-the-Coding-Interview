#include<iostream>
using namespace std;

int ** create_matrix(int size)
{
	int **matrix= new int*[size];
	
	for(int i=0; i<size; i++)
	{
		matrix[i]=new int [size];
	}
	
	for(int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			cout<< "matrix[" << i << "][" << j << "]= ";
			cin>>matrix[i][j];
		}
	}
	
	return matrix;
}

void rotate_by_90(int ** a /*matrix*/, int n /*size*/)
{
	
	for (int i=0; i < n/2 /* i < (n<<1) is better*/; i++)
	{
		for (int j=i, temp; j< n-1-i; j++)
		{
			temp=a[i][j]; //top left element of the layer copied to temp
			a[i][j]= a[n-1-j][i];//bottom left element of the layer copied to top left of the layer
			a[n-1-j][i]=a[n-1-i][n-1-j];//bottom right element of the layer copied to bottom left of the layer
			a[n-1-i][n-1-j]=a[j][n-1-i];//top right element of the layer copied to bottom right of the layer
			a[j][n-1-i]=temp;//original top left element copied to top right of the layer
			
			/*now j will be inremented so that the next element in the first row of the layer can be swapped along with the respective elements*/
		}
		/*now i will be incremented and we will move one layer deeper in the matrix*/
	}
}

void display_matrix(int ** matrix, int size)
{
	for(int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			/*cout<< "matrix["<<i << "]["<<j << "]= "<<matrix[i][j];*/
			cout<< matrix[i][j]<<"	";
		}
		cout<<endl;
	}
}

int main()
{
	int size;
	cin>>size;
	
	int ** matrix=create_matrix(size);
	
	cout<<endl<<endl<<"Original Matrix: "<<endl<< endl;
	display_matrix(matrix, size);
	
	rotate_by_90(matrix, size);
	
	cout<<endl<<endl<<"Rotated Matrix: "<<endl<< endl;
	display_matrix(matrix, size);
	
}
