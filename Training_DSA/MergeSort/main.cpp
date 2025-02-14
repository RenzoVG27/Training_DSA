#include <stdio.h>
#include <iostream>
#include <vector>

void print(int array[],int right,int left){
	if(right>left) return;

	std::cout<<"array = ";

	for(int i=right;i<=left;i++){
		std::cout<<array[i]<<" ";
	}
	std::cout<<"\n";
}

void print(int array[],int size){
	std::cout<<"array = ";
	if(size>0){
		for(int i=0;i<size;i++){
			std::cout<<array[i]<<" ";
		}
		std::cout<<"\n";
	}else{
		std::cout<<"(Empty)\n";
	}
}



void  Merge(int array[], int left , int middle, int right){

	int leftArraySize = middle - left + 1;
	int rightArraySize = right - middle;



	int arrayLeft[leftArraySize], arrayRight[rightArraySize];

	std::copy(array + left, array+left+leftArraySize, arrayLeft);
	std::copy(array + middle+1, array+middle+rightArraySize+1, arrayRight);


	int index1 = 0, index2=0;

	while(index1 + index2 < leftArraySize + rightArraySize){
		if(index1>=leftArraySize){
			array[left + index2 + index1] = arrayRight[index2];
			index2++;
		}else if(index2>=rightArraySize){
			array[left + index2 + index1] = arrayLeft[index1];
			index1++;
		}else if(arrayLeft[index1] > arrayRight[index2]){
			array[left + index2 + index1] = arrayRight[index2];
			index2++;
		}else{
			array[left + index2 + index1] = arrayLeft[index1];
			index1++;
		}
	}

}



void MergeSort(int array[], int leftIndex, int rightIndex){

	if(leftIndex >= rightIndex) return;

	int midleIndex = leftIndex + (rightIndex - leftIndex)/2;

	MergeSort(array,leftIndex, midleIndex);

	MergeSort(array,midleIndex + 1, rightIndex);

	Merge(array,leftIndex,midleIndex,rightIndex);
}


int main(){

	int test[] = {12,15,10,27,20};

	print(test,5);

	MergeSort(test,0,4);

	print(test,5);

	return 0;
}
