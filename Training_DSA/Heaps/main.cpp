#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

class Heap{
public :
	Heap(){
	}

	void swap(int &left,int &right){
		int tmp = left;
		left = right;
		right = tmp;
	}

	int leftChild(int index){
		return index*2 + 1;
	}

	int rightChild(int index){
		return index*2 + 2;
	}

	int parent(int index){
		return index/2;
	}

	void sinkDown(int index){

		int currentIndex = index;

		while(true){

			int leftChildIndex = leftChild(currentIndex);
			int rightChildIndex = rightChild(currentIndex);

			int maxValue = values[currentIndex];
			int changeLoR = 0;

			if(leftChildIndex < values.size()){

				if(values[leftChildIndex] > maxValue){
					maxValue = values[leftChildIndex];
					changeLoR = 1;
				}

				if(rightChildIndex < values.size()){

					if(values[rightChildIndex] > maxValue){
						maxValue = values[rightChildIndex];
						changeLoR = 2;
					}
				}
			}

			if(changeLoR == 1){
				swap(values[leftChildIndex],values[currentIndex]);
				currentIndex = leftChildIndex;
			}else if(changeLoR == 2){
				swap(values[rightChildIndex],values[currentIndex]);
				currentIndex = rightChildIndex;
			}else{
				break;
			}
		}
	}

	void insert (int value){
		values.push_back(value);
		int current = values.size() - 1;
		while ( current > 0 && values.at(current) > values.at(parent(current))){
			swap(values.at(current),values.at(parent(current)));
			current = parent(current);
		};
	}

	int remove(){
		if(values.empty()){
			return INT_MIN;
		}

		int maxValue = values.front();

		if(values.size() == 1){
			values.pop_back();
		}else{
			values[0] = values.back();
			values.pop_back();
			sinkDown(0);
		}

		return maxValue;
	}

	void print(){

		std::cout<<"Printing Heap\n";
		int level = 0;
		int counter = 0;
		for(unsigned int i=0;i<values.size();i++){
			std::cout<<values.at(i)<<" ";
			if (++counter==std::pow(2,level)){
				std::cout<<"\n";
				level++;
				counter = 0;
			}

		}
		std::cout<<"\n";

	}

private:

	std::vector<int> values;


};


int main(){

	Heap myheap;

	myheap.insert(10);
	myheap.insert(15);
	myheap.insert(20);

	myheap.print();

	myheap.insert(50);
	myheap.insert(30);
	myheap.insert(28);

	myheap.print();

	myheap.remove();
	myheap.print();

	return 0;
}
