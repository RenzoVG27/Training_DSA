#include <stdio.h>
#include <iostream>

class Node{


public:
	Node(int value):value(value),next(nullptr),prev(nullptr){

	}

	int value;
	Node *next;
	Node *prev;
};


class DoubleLinkedlist{
public:
	DoubleLinkedlist (int value){
		++length;
		head = new Node(value);
		tail = head;
	}

	~DoubleLinkedlist(){
		Node *tmp = head;
		while(head){
			head = head->next;
			delete tmp;
			tmp = head;
		}
		tail = nullptr;
		length = 0;
	}

	void append(int value){
		Node *newnode = new Node(value);
		if(length>0){
			newnode->prev = tail;
			tail->next = newnode;
		}else{
			head = newnode;
		}
		tail = newnode;
		++length;
	}

	void deleteLast(){
		if (length==0)
			return;

		Node *temp = tail;

		if(length == 1){
			head = nullptr;
			tail = nullptr;
		}else{
			tail = tail->prev;
			tail->next = nullptr;
		}

		--length;
		delete temp;
	}

	void prepend(int value){
		Node *newnode = new Node(value);

		if(length == 0){
			tail = newnode;
		}else{
			newnode->next = head;
			head->prev = newnode;
		}
		head = newnode;
		length++;
	}

	void DeleteFirst(){


		if(length == 0)
			return;

		Node *tmp = head;

		if(length==1){
			head = nullptr;
			tail = nullptr;
		}else{
			head = head->next;
			head->prev = nullptr;
		}
		--length;
		delete tmp;

	}

	Node *getNode(int index){
		if(index<0 || index>=length)
			return nullptr;

		Node *curr;

		if(index<length/2){
			 curr = head;
			for(int i=0;i<index;i++){
				curr = curr->next;
			}
		}else{
			curr = tail;
			for(int i=length-1;i>index;i--){
				curr = curr->prev;
			}
		}

		return curr;
	}

	bool setNode(int index, int value){


		Node *curr = getNode(index);

		if(curr){
			curr->value = value;
			return true;
		}

		return false;
	}

	void insert(int index, int value){

		if(index<0 || index>length)
			return;

		if(index==0){
			prepend(value);
		}else if(index==length){
			append(value);
		}else{
			Node *newNode = new Node(value);
			Node *current = getNode(index);
			Node *previous = current->prev;

			newNode->prev = previous;
			newNode->next = current;

			previous->next = newNode;
			current->prev = newNode;

			length++;
		}

	}

	void DeleteNode(int index){

		if(index<0 || index>=length)
			return;

		if(index == 0){
			DeleteFirst();
		}else if(index==length-1){
			deleteLast();
		}else{

			Node *tmp = getNode(index);
			Node *before = tmp->prev;
			Node *after = tmp->next;

			before->next = after;
			after->prev = before;

			length--;
			delete tmp;
		}

	}

	void PrintList(){
		Node *tmp = head;

		while(tmp){
			std::cout<<tmp->value;
			if(tmp->next){
				std::cout<<"->";
			}
			tmp = tmp->next;
		}
		std::cout<<"\n";
	}

private:

	int length{0};
	Node *head,*tail;

};


int main(){

	DoubleLinkedlist mylist(27);

	mylist.append(2);
	mylist.append(15);

	mylist.PrintList();

	mylist.prepend(10);
	mylist.PrintList();

	Node *curr = mylist.getNode(2);
	std::cout<<"Current node: "<<curr->value<<"\n";

	mylist.setNode(1,11);
	mylist.PrintList();

	mylist.deleteLast();
	mylist.PrintList();

	mylist.insert(2,29);
	mylist.PrintList();

	mylist.DeleteFirst();
	mylist.PrintList();

	mylist.insert(0,34);
	mylist.PrintList();

	mylist.insert(3,1);
	mylist.PrintList();

	mylist.deleteLast();
	mylist.PrintList();

	mylist.DeleteNode(1);
	mylist.PrintList();



	return 0;
}
