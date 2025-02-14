#include <stdio.h>
#include <iostream>

class Node{


public:
	Node(int value):value(value),next(nullptr){

	}

	int value;
	Node *next;
};


class Linkedlist{
public:
	Linkedlist (int value){
		++length;
		head = new Node(value);
		tail = head;
	}

	~Linkedlist(){
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
			tail->next = newnode;
		}else{
			head = newnode;
		}

		tail = newnode;
		++length;
	}

	void deleteLast(){
		if (length==0){
			return;
		}else if(length == 1){
			head = nullptr;
			tail = nullptr;
			--length;
		}else{
			Node *prevNode = head;

			for(int index=0;index<length-2;++index){
				prevNode = prevNode->next;
			}
			prevNode->next = nullptr;

			delete tail;
			--length;

			tail = prevNode;
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

	Linkedlist mylist(27);

	mylist.append(10);
	mylist.append(2);
	mylist.append(15);

	mylist.PrintList();


	return 0;
}
