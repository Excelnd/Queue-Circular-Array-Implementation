// Queue Circular Array Implementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 101

using namespace std;

class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear;
	
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	bool isEmpty()
	{
		return (front == -1 && rear == -1);

	}

	bool isFull()
	{
		return(rear + 1) % MAX_SIZE == front ? true : false;
	}

	void Enqueue(int x)
	{
		cout << "Enqueuing" << x << "\n";
		if (isFull())
		{
			cout << "Error: Queue is Full \n";
			return;
		}
		if (isEmpty())
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
		}
		A[rear] = x;
	}

	void Dequeue()
	{
		cout << "Dequeuing \n";
		if (isEmpty())
		{
			cout << "Error: Queue is Empty\n";
			return;
		}
		else if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}
	int Front()
	{
		if (front == -1)
		{
			cout << "Error : cannot return front from emtpy queue \n";
			return -1;
		}
		return A[front];
	}

	void Print()
	{
		int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
		cout << "Queue    : ";
		for (int i = 0; i < count; i++)
		{
			int index = (front + i) % MAX_SIZE;
			cout << A[index] << " ";
		}
		cout << "\n\n";
	}


};


int main()
{
	Queue Q;
	
	Q.Enqueue(2); Q.Print();
	Q.Enqueue(4); Q.Print();
	Q.Enqueue(6); Q.Print();
	Q.Dequeue(); Q.Print();
	Q.Enqueue(8);  Q.Print();

    return 0;
}

