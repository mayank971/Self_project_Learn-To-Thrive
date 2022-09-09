#include <iostream>
using namespace std;
#define n 5
int queue[5],front = - 1, rear = - 1;

void enqueue(int x) {
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   
   else if(front == - 1 && rear == -1){
   	front = rear = 0;
   	queue[rear]=x;
   }
   
   else {
      rear++;
      queue[rear]=x;
   }
}
void dequeue() {
   if (front == - 1 && rear == -1) {
      cout<<"Queue Underflow ";
   } 
   else if(front == rear){
   	front = rear = -1;
   }
   
   else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}
void Display() {
   if (front == - 1 && rear == -1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int ch, val;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: 
		 cout<<"Insert the element in queue : "<<endl;
      cin>>val;
		 enqueue(val);
         break;
         case 2: dequeue();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}
