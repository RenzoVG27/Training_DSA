#include <stdio.h>
#include <iostream>

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

	void deleteNode(Node *node){
		if (!node)
			return;

		if(node->left)
			deleteNode(node->left);

		if(node->right)
			deleteNode(node->right);

		delete node;
	}

	~BinaryTree(){

		deleteNode(root);
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


	return 0;
}
