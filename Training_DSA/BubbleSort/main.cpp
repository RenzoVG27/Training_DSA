#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

void Sort(int array[], int size){

	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]>array[j]){
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

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



int main(){

	int array[5] = {5,3,1,6,4};

	print(array,5);

	Sort(array,5);

	print(array,5);

	return 0;
}
