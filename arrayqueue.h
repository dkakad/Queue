#pragma once
#include <stdio.h>

template <typename T>
class queue {
	T* data;
	int head;
	int tail;
	int capacity;
	int filled;
public:
	queue();
	queue(int cap);
	T getData(int pos);
	int getHead();
	void setHead(int newHead);
	int getTail();
	void setTail(int newTail);
	int getCapacity();
	void setCapacity(int newCap);
	void enqueue(T entry);
	T dequeue();
	T peek();
	bool isEmpty();
	void print();
};