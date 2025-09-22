#include <iostream>
using namespace std;
class Queue{
	private:
		string pendings[10];
		int numbers,rear,front;
	public:
		Queue():numbers(0),rear(0),front(0){
		}
		void enqueue(string j){
			if(numbers<10){
				pendings[rear++] = j;
				rear%=10;
				numbers++;
			}
			else cout<<"too much jobs are added to pending jobs.."<<endl;
		}
		string dequeue(){
			if(front>-1){
				string temp = pendings[front++];
				front%=10;
				numbers--;
				return temp;
			}
			else{
				cout<<"No job in pending jobs..."<<endl;
				return "/0";
			}
		}
		bool isEmpty(){
			return numbers==0?true:false;
		}
		void pendingJobs(){
			cout<<"pending jobs...."<<endl;
			for(int i=0;i<numbers;i++){
				cout<<pendings[i]<<endl;
			}
		}
};
class Stack{
	string completed[10];
	int top;
	public:
		Stack():top(0){
		}
		void push(string j){
			if(top<10){
				completed[top++] = j;
			}
			else cout<<"Too much tasks are added...."<<endl;
		}
		string pop(){
			if(top>0){
				return completed[--top];
			}
			else {
				cout<<"No task......"<<endl;
				return "/0";
			}
		}
		void complete(){
			cout<<"Completed Jobs...."<<endl;
			for(int i=0;i<top;i++){
				cout<<completed[i]<<endl;
			}
		}
};
int main(){
	Queue q1;
	Stack s1;
	cout<<"Works that you would like: "<<endl;
	cout<<"1. Add job"<<endl;
	cout<<"2. Process job"<<endl;
	cout<<"3. Undo job"<<endl;
	cout<<"4. Show pending jobs"<<endl;
	cout<<"5. show completed jobs"<<endl;
	int num;
	char ch;
	do{
	cout<<"Enter your choice: ";
	cin>>num;
	switch(num){
		case 1:{
			 string job;
			cout<<"Enter job name: ";
			cin>>job;
			q1.enqueue(job);
			break;
		}
		case 2:
			s1.push(q1.dequeue());
			break;
		case 3:
			q1.enqueue(s1.pop());
			break;
		case 4:
			q1.pendingJobs();
			break;
		case 5:
			s1.complete();
			break;
		default:
			cout<<"Invalid value..."<<endl;
		}	
		cout<<"Do you want further execution(y/n): ";
		cin>>ch;
	}while(ch=='y');
	
}
