#pragma once
#include <iostream>

template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
	{
		return -1;
	}
	else if (firstValue > secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <>
int compara <char*>(char* firstValue, char* secondValue)
{
	return strcmp(firstValue, secondValue);
}

template <typename T>
int compara2(T firstValue, T secondValue)
{
	if (firstValue > secondValue)
	{
		return -1;
	}
	else if (firstValue < secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
struct Node
{
	T value;
	Node<T>** children;
	unsigned int nrChildren;
	Node<T>* Parinte;
};

template <class T>
class Tree
{
public:
	Node<T>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode] {};
			root->Parinte = nullptr;
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<T>;
			parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T>*[maxChildrenPerNode] {};
			parent->children[parent->nrChildren]->Parinte = parent;
			parent->nrChildren++;
		}
	}

	void sort(Node<T>* parinte, int (*comparatie)(T, T))
	{
		unsigned int i, j;
		if (comparatie == nullptr)
		{
			comparatie = compara;
		}
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					T aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}

	void printNodes(Node<T>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			std::cout << parinte->children[i]->value << " ";
		}
	}
	T get_node(Node<T>* parinte)
	{
		if (parinte == nullptr)
		return root->value;
		else
		return parinte->value;
	}
	void delete_node(Node<T>* parinte, unsigned int lvl=0)
	{
		int i, ok = 0;
		if (lvl == 0)
		{
			Node<T>** aux = parinte->Parinte->children;
			parinte->Parinte->children = nullptr;
			parinte->Parinte->nrChildren--;
			parinte->Parinte->children = new Node<T>*[parinte->Parinte->nrChildren];
			for (i = 0; i < parinte->Parinte->nrChildren + 1; i++)
			{
				if (aux[i] != parinte)
				{
					parinte->Parinte->children[i - ok] = aux[i];
				}
				else
				{
					ok = 1;
				}
			}

		}
		for (i = 0; i < parinte->nrChildren; i++)
		{
			if (parinte->children[i]->nrChildren == 0)
				delete parinte->children[i];
			else
			{
				delete_node(parinte->children[i],lvl+1);
			}
		}
		delete parinte;
	}
	Node<T> *find(T val,Node<T>* parinte)
	{
		int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			if (compara(parinte->children[i]->value, val) == 0)
				return parinte->children[i];
			else
				find(val, parinte->children[i]);
		}
		return nullptr;
	}
	void insert(unsigned int index, Node<T>* parinte)
	{
		int i;
		Node<T>** aux=parinte->children;
		parinte->children=nullptr;
		parinte->nrChildren++;
		parinte->children = new Node<T>*[parinte->nrChildren];
		for (i = 0; i <parinte->nrChildren; i++)
		{
			if (i < index)
				parinte->children[i] = aux[i];
			if (i == index)
				parinte->children[i] = new Node<T>;
			if (i > index)
				parinte->children[i] = aux[i - 1];
		}
		delete aux;
	}
	unsigned int count(Node<T>* parent)
	{
		int i;
		if (parent == nullptr)
			parent = root;
		int kids = parent->nrChildren;
		for (i = 0; i < parent->nrChildren; i++)
		{
			if (parent->children[i]->nrChildren != 0)
				kids = kids + count(parent->children[i]);
		}
		return kids;
	}
};

template <>
class Tree <char*>
{
public:
	Node<char*>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<char*>* parent, const char* value)
	{
		if (parent == nullptr)
		{
			root = new Node<char*>;
			//root->value = value;
			root->value = new char[100] {};
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*>*[maxChildrenPerNode] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<char*>;
			//parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->value = new char[100] {};
			strcpy(parent->children[parent->nrChildren]->value, value);
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<char*>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}

	void sort(Node<char*>* parinte, int (*comparatie)(char*, char*))
	{
		unsigned int i, j;
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					char* aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}

	void printNodes(Node<char*>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			std::cout << parinte->children[i]->value << " ";
		}
	}
};
