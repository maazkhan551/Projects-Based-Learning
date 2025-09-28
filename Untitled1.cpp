#include <iostream>
using namespace std;
int main(){
	
	int array[5]={3,5,1,4,2};
	
	int first;
	int second;
	
	first = array[0];
	
	for(int i=0 ; i<5 ; i++){
		if(array[i]<first){
			second = first ;
			first = array[i];
		}
		else if(array[i]<second && array[i]!=first){
			second = array[i];
		}
	}
	
	cout<<"2nd largest : "<<second<<endl;
	cout<<"1st : "<<first<<endl;
	
	
	
	
	return 0;
}
