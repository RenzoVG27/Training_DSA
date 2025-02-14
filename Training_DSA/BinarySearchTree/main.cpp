#include <stdio.h>
#include <iostream>
#include <limits.h>

class Node{


public:
	Node(int value):value(value),left(nullptr),right(nullptr){

	}

	int value;
	Node *left;
	Node *right;
};


class BinaryTree{
	Node *root;
	int height;
public:
	BinaryTree (int value){
		height = 1;
		root = new Node(value);
	}

	void deleteNodeAndChilds(Node *node){
		if (!node)
			return;

		if(node->left)
			deleteNodeAndChilds(node->left);

		if(node->right)
			deleteNodeAndChilds(node->right);

		delete node;
	}

	~BinaryTree(){

		deleteNodeAndChilds(root);
	}

	bool insert(int value){

		if (!root){
			Node *newNode = new Node (value);
			root = newNode;
			return true;
		}

		Node *tmp = root;

		while(tmp){
			if(tmp->value == value) return false;

			if(tmp->value < value){
				if(tmp->right){
					tmp = tmp->right;
				}else{
					Node *newNode = new Node (value);
					tmp->right = newNode;
					return true;
				}
			}else{
				if(tmp->left){
					tmp = tmp->left;
				}else{
					Node *newNode = new Node (value);
					tmp->left = newNode;
					return true;
				}
			}
		}

		return false;

	}

	void printNode(const Node* node, int level = 0){
		if (node == nullptr)
			return;

		level++;

		if(node->left)
			printNode(node->left,level);

		if (node->right)
			printNode(node->right,level);

		std::cout<<node->value<<"("<<level<<")"<<std::endl;

	}

	void PrintList(){
		std::cout<<"Imprime Binary Tree\n";
		printNode(root);
	}

	bool rContains (Node* node, int value){
		if(node==nullptr)
			return false;

		if(node->value==value)
			return true;

		if(node->value < value){
			return rContains(node->right,value);
		}else{
			return rContains(node->left,value);
		}
	}

	bool contains(int value){

		return rContains(root,value);
	}

	void rInsert(Node* &node, int value){


		if(node==nullptr){
			node = new Node(value);
			return;
		}

		if (node->value < value){
			rInsert(node->right,value);
		}else if(node->value > value){
			rInsert(node->left,value);
		}
	}

	void rInsert(int value){
		rInsert(root,value);
	}

	int GetMinValue(Node *node){
		if (node == nullptr){
			return INT_MIN;
		}

		if(node->left){
			return GetMinValue(node->left);
		}else{
			return node->value;
		}

	}

	void deleteNode(Node *&node, int value){
		if(node == nullptr){
			return;
		}

		if(node->value < value){
			deleteNode(node->right,value);
		}else if(node->value > value){
			deleteNode(node->left,value);
		}else{
			if(node->left == nullptr && node->right == nullptr){
				delete node;
				node = nullptr;
			}else if(node->left && node->right == nullptr){
				Node *tmp = node->left;
				delete node;
				node = tmp;
			}else if(node->right && node->left == nullptr){
				Node *tmp = node->right;
				delete node;
				node = tmp;
			}else{
				int minsubtree = GetMinValue(node->right);
				std::cout<<"delete subtree min : "<< minsubtree<<"\n";
				node->value = minsubtree;
				std::cout<<"delete subtree node va;lue : "<< node->value<<"\n";
				deleteNode(node->right,minsubtree);
			}
		}
	}

	void deleteNode(int value){
		deleteNode(root,value);
	}

};



int main(){

	BinaryTree binaryTree(10);

	binaryTree.PrintList();

	binaryTree.insert(15);
	binaryTree.insert(5);

	binaryTree.PrintList();

	binaryTree.insert(7);
	binaryTree.insert(43);
	binaryTree.insert(32);
	binaryTree.insert(12);

	binaryTree.PrintList();

	binaryTree.deleteNode(15);

	binaryTree.PrintList();

	std::cout << std::boolalpha;

	std::cout<<binaryTree.contains(5)<<std::endl;

	std::cout << std::noboolalpha;

	BinaryTree binaryTree2(10);

	binaryTree2.PrintList();

	binaryTree2.rInsert(15);
	binaryTree2.rInsert(5);

	binaryTree2.PrintList();

	return 0;
}
