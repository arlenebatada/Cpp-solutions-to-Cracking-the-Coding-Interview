#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
			
		T data;
		Node* left;
		Node* right;
		Node (T data)
		{
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
};

template <class T>
Node<T>* sortedArrayToBST(T* array, int start, int end)
{
	if ((start < 0) || (end < 0))
	{
		return nullptr;
	}
	
	if(start > end)
	{
		return nullptr;
	}
	
	if (start == end)
	{
		return (new Node<T>(array[start]));
	}
	
	Node<T> * parent = new Node<T>(array [(start+end)>>1]); //(start+end)/2
	parent->left = sortedArrayToBST(array, start, (((start+end)>>1)-1));//((start+end)>>1)-1) = (start+end)/2)-1
	parent->right = sortedArrayToBST(array, (((start+end)>>1)+1), end); //(((start+end)>>1)+1) =(start+end)/2)+1
	
	return parent;
}

template <class T>
Node<T>* sortedArrayToBST(T* array, int size)
{
	return (sortedArrayToBST<T> (array, 0, size-1));
}

template <class T>
void preOrder(Node<T>* root)
{
	if (root == nullptr)
	{
		return;
	}
	preOrder(root->left);
	cout<<root->data;
	preOrder(root->right);
}

int main()
{
	char array[26];
	for(size_t i=0; i<26; i++)
	{
		array[i] = i+ 'a';
	}
	Node<char>* root=sortedArrayToBST<char> (array, 26);
	preOrder<char> (root);
	return 0;
}
