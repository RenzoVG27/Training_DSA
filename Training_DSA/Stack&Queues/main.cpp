#include <stdio.h>
#include <iostream>

class Node{


public:
	Node(int value):value(value),next(nullptr){

	}

	int value;
	Node *next;
};


class Stack{
public:
	Stack (int value){
		height = 1;
		top = new Node(value);
	}

	~Stack(){

		Node *tmp = top;

		while(tmp){
			tmp = tmp->next;
			delete top;
			top= tmp;
		}
		height = 0;
	}

	void push(int value){
		Node *newnode = new Node(value);
		newnode->next = top;
		top = newnode;
		height++;
	}

	void pop(){

		if(height == 0)
			return;

		Node *tmpNode = top->next;
		delete top;
		top = tmpNode;
		height--;
	}



	void PrintList(){
		Node *tmp = top;

		while(tmp){
			std::cout<<tmp->value<<"\n";
			tmp = tmp->next;
		}
		std::cout<<"\n";
	}

private:

	int height{0};
	Node *top;

};

class Queue{
public:
	Queue (int value){
		Node *newNode = new Node(value);
		last = newNode;
		first = newNode;
		height = 1;
	}

	~Queue(){
		Node *tmp = first;
		while(tmp){
			first = first->next;
			delete tmp;
			tmp = first;
		}
		height = 0;
	}

	void Enqueue(int value){
		Node *newNode = new Node(value);
		if(height == 0){
			first = newNode;
		}else{
			last->next = newNode;
		}

		last = newNode;
		height++;
	}

	void Dequeue(){
		if(height == 0)
			return;

		if(height == 1){
			delete first;
			last = nullptr;
		}else{
			Node *tmp = first;
			first = first->next;
			delete tmp;
		}
		height--;
	}

	void PrintList(){
		Node *tmp = first;
		for(int i=0;i<height;i++){
			std::cout<<tmp->value;
			if(tmp->next)
				std::cout<<"->";
			tmp = tmp->next;
		}
		std::cout<<"\n";
	}


private:
	Node* last{nullptr};
	Node* first{nullptr};
	int height{0};
};

int main(){

	Stack mystack(27);

	mystack.push(10);
	mystack.push(02);
	mystack.push(15);

	mystack.PrintList();

	mystack.pop();

	mystack.PrintList();

	std::cout<<"---------------------------\n";

	Queue myqueue(10);

	myqueue.Enqueue(27);
	myqueue.Enqueue(2);
	myqueue.Enqueue(15);

	myqueue.PrintList();

	myqueue.Dequeue();

	myqueue.PrintList();

	myqueue.Enqueue(28);


	myqueue.PrintList();

	return 0;
}
