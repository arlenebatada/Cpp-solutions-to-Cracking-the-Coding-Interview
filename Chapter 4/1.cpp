#include <iostream>
#include <queue>

using namespace std;

class Graph
{
	private:
		int** node_array;
		int size;
		
		void checkRange(int node)
		{
			if ((node > this->size-1) || (node <0 ))
			{
				throw -1;
			}
		}
		
	public:
		Graph(int size)
		{
			if (size < 1)
			{
				throw -1;
			}
			this->size = size;
			node_array = new int* [size];
			for (size_t i=0; i<size; i++)
			{
				node_array[i] = new int [size];
			}
			
			for (size_t i=0; i<size; i++)
			{
				for (size_t j=0; j<size; j++)
				{
					node_array[i][j] = 0;
				}
			}
		}
		
		void addConnection(int node1, int node2)
		{
			checkRange(node1);
			checkRange(node2);
			
			node_array[node1][node2] = 1;
		}
		
		void removeConnection(int node1, int node2)
		{
			checkRange(node1);
			checkRange(node2);
			
			node_array[node1][node2] = 0;
		}
		
		bool isConnection(int source, int destination)
		{
			checkRange(source);
			checkRange(destination);
			
			queue<int> q; //BFS queue
			bool visited[size]; //visited array to keep track of the nodes which have already been explored
			for (size_t i=0; i<size; i++)
			{
				visited[i] = false; //initialisation of the array to false
			}
			
			q.push(source);
			
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				
				if (node == destination)
				{
					return true;
				}
				
				if (visited[node] == false)
				{
					for (size_t i=0; i<size; i++)
					{
						if (node_array[node][i] != 0)
						{
							q.push(i);
						}
					}
				}
				visited[node] = true;
			}
			
			return false;
		}
		
		~Graph()
		{
			for (size_t i=0; i<size; i++)
			{
				free(node_array[i]);
			}
			free (node_array);
		}
};

int main()
{
	Graph g(9999);
	g.addConnection(0, 2);
	g.addConnection(3, 4);
	g.addConnection(4, 10);
	g.addConnection(2, 3);
	g.addConnection(4, 1);
	g.addConnection(1, 0);
	g.addConnection(4, 30);
	cout<<g.isConnection(1,30);
	return 0;
}
