/*
File name: Assignment6.cpp
Developer Name: Seonghyun Moon
Date: May.2nd.2023
circularqueue_array.cpp
* Circular Queue Array Implementation
* Spring  2023
* The program must include basics Queue operations:
* Enqueue(value) --> inset value to rear
* Dequeue() --->delete value from front
* peak() --> returns front elemet
* back() ---> returns rear element 
*/
// Time Complexity: O(n)
#include<iostream>
using namespace std;
const int SIZE = 15;

class CircularQueue
{
  private:
    int front;
    int rear;
    int arr[SIZE]{};
   public:
    CircularQueue() 
    {
 
    front = -1;
    rear = -1;
 
    }

  bool isEmpty()
  {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull()
  {
    if ((rear + 1) % SIZE == front)
      return true;
    else
      return false;
  }
  void display() 
  {
    cout << "Current Queue values are: " << endl;
   
    for (int i =front; i <= rear; i++) 
    {
      cout << arr[i] << "  ";
    }
    cout<<endl;
  }
  void enqueue(int val)
  {
    if (isFull())
    {
      cout << "Queue is full!" << endl;
      return;
    }
    else if (isEmpty())
    {
      front = 0;
      rear = 0;
    }
    else
    {
      rear = (rear + 1) % SIZE;
    }
    arr[rear] = val;
  }
  //Create a function that add integers in front of the queue if the queue is not empty.
  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty!" << endl;
      return;
    }
    else if (front == rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      front = (front + 1) % SIZE;
    }
  }
  //Create a function that erase integers in front of the queue if the queue is not empty.
  int peak()
  {
    if(isEmpty())
    {
      cout<<"Queue is empty."<<endl;
      return -1;
    }
    else
    {
      return arr[front];
    }
  }
  //Create a function that display the first element in the queue if the queue is not empty.
  int back()
  {
    if(isEmpty())
    {
      cout<<"Queue is empty."<<endl;
      return -1;
    }
    else
    {
      return arr[rear];
    }
  }
  //Create a function that display the last element in the queue if the queue is not empty.
};

int main()
{
  CircularQueue queue;
  //Make an object of class.
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);

  queue.display();
  //Add 4 numbers 1 to 4 in the queue and then display the queue.

  cout << "Remove first element" << endl;

  queue.dequeue();
  queue.display();
  //Erase first element and then display the queue.

  cout << "Front element: " << queue.peak() << endl;
  cout << "Rear element: " << queue.back() << endl;
  //Show the front and last element of the queue.
  cout << "Add 5 and 6 " << endl;
    
  queue.enqueue(5);
  queue.enqueue(6);
  queue.display();
  //Add 5 and 6 in the queue and then display the queue.

  return 0;
}
