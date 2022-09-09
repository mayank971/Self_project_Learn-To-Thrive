#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void enqueue(int x) {
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
    front = rear;
	  rear->next = front;
      rear->data = x;
      
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      rear->next = temp;
      temp->data = x;
      temp->next = front;
      rear = temp;
   }
}
void dequeue() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
   }
   else if (temp->next != front) {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temp;
      rear->next= front;
   } else {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void Display() {
   temp = front;
   if (front == NULL) {
      cout<<"Queue is empty"<<endl;
   }
   else {
   	cout<<"Queue elements are: ";
   while (temp->next!= front ) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<temp->data<<" ";
   cout<<endl;
   }
}
int main() {
   int ch,val;
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
