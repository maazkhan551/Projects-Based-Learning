#include <iostream>
using namespace std;
class Books{
	private:
		string names[50];
		int nameBound,idBound;
		int id[50];
	public:
		Books():nameBound(0),idBound(0){
		}
		void addBook(string name,int i){
			if(nameBound<50){
				names[nameBound++] = name;
				id[idBound++] = i;
			}
		}
		void showBooks(){
			for(int i=0;i<nameBound;i++){
				cout<<"Name: "<<names[i]<<" *** ID: "<<id[i]<<endl;
			}
			cout<<endl<<endl;
		}
		void sortedBook(){
			int i,j;
			for(int i=0;i<nameBound-1;i++){
				for(int j=i+1;j<nameBound;j++){
					if(id[i]>id[j]){
						int temp = id[i];
						string tempName = names[i];
						id[i] = id[j];
						names[i] = names[j];
						id[j] = temp;
						names[j] = tempName;
					}
				}
			}
		}
		string searchByid(int target){
			sortedBook();
			int low = 0, high = idBound-1;
			while(low<=high){
				int mid = (high+low)/2;
				if(id[mid]==target){
					cout<<"The book is present..."<<endl;
					return names[mid];
				}
				else if(id[mid]<target){
					low = mid+1;
				}
				else high = mid-1;
			}
			return "no";	
		}
		string SearchByname(string n){
			for(int i=0;i<nameBound;i++){
				if(names[i]==n){
					cout<<"The books is present.... and ID is "<<id[i]<<endl;
					break;
				}
				else cout<<"No such book is in library..."<<endl;
			}
		}
};
class Student{
	private:
		string name;
		int regNo;
		int requestID;
	public:
		Student(){
		}
		Student(string n, int rn,int id){
			name = n;
			regNo = rn;
			requestID = id;
		}
		
};
class manageStudents{
	private:
		Student que[10];
		int front,rear;
	public:
		manageStudents():front(0),rear(0){
		}
		void enqueue(Student b1){
			if(rear<10){
				que[rear++]=b1;
//				que[rear-1].showBooks();
			}
		}
		Student dequeue(){
			Student temp = que[front];
			for(int i=0;i<rear;i++){
				que[i] = que[i+1];
			}
			rear--;
			return temp;
		}
};
int main(){
	Books b1,b2;
	b1.addBook("DSA",12);
	b2.addBook("OOP",24);
	Student s1("Maaz",24,24);	
	manageStudents m1;
	m1.enqueue(s1);
	if(b2.searchByid(24)!="no"){
		cout<<"The book is present"<<endl;
	}	
	else cout<<"Book is not present..."<<endl;
}
