#include <stdio.h>
#include <iostream>

void Sort(int array[], int size){

	if(size<2)
		return;

	for(int i=1;i<size;i++){
		for(int j=i-1;j>=0;j--){
			if(array[j+1]<array[j]){
				int tmp = array[j+1];
				array[j+1] = array[j];
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
