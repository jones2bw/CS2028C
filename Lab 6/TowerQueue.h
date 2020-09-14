#pragma once
#include <exception>
#include <string>

using namespace std;

template<class T> class TowerQueue {
private:
	int MAX_SIZE = 5;
	T *tower;
	int back = 0;
	int front = 0;
	int size = 0;
public:
	TowerQueue() {
		tower = new T[MAX_SIZE];
	}

	TowerQueue(int arraySize)
	{
		MAX_SIZE = arraySize;
		tower = new T[MAX_SIZE];
	}

	~TowerQueue() {
		delete tower;
	}


	void Enqueue(T *inVal) {
		if (!isFull())
		{
			tower[back] = *inVal;
			back = (back + 1) % MAX_SIZE;
			size++;
		}
		else
			throw QueueOverflow();
	}

	T *Dequeue() {
		if (!isEmpty())
		{
			T retVal = tower[front];
			front = (front + 1) % MAX_SIZE;
			size--;
			return &retVal;
		}
		else
			throw QueueUnderflow();
	}

	T *Peek() {
		if (!isEmpty())
			return tower[front];
		else
			throw QueueUnderflow();
	}

	int Length() {
		return size;
	}

	bool isFull() {
		return size == MAX_SIZE;
	}

	bool isEmpty() {
		return size == 0;
	}

	void MakeEmpty() {
		for (int i = 0; i < size; i++)
			delete tower[i];
		size = 0;
		back = front;
	}

	class QueueOverflow : public exception {
	public:
		string msg = "The queue is full.";
	};

	class QueueUnderflow : public exception {
	public:
		string msg = "The queue is empty.";
	};

};
