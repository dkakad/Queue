#include "arrayqueue.h"

template class queue<int>;

template <typename T>
queue<T>::queue() {
	data = new T[1];
	data[0] = 0;
	head = 0;
	tail = 0;
	capacity = 1;
	filled = 0;
}

template <typename T>
queue<T>::queue(int cap) {
	data = new T[cap];
	for (int i = 0; i < cap; i++) {
		data[i] = 0;
	}
	head = 0;
	tail = 0;
	capacity = cap;
	filled = 0;
}

template <typename T>
T queue<T>::getData(int pos) {
	return data[pos];
}

template <typename T>
int queue<T>::getHead() {
	return head;
}

template <typename T>
void queue<T>::setHead(int newHead) {
	head = newHead;
}

template <typename T>
int queue<T>::getTail() {
	return tail;
}

template <typename T>
void queue<T>::setTail(int newTail) {
	tail = newTail;
}

template <typename T>
int queue<T>::getCapacity() {
	return capacity;
}

template <typename T>
void queue<T>::setCapacity(int newCap) {
	capacity = newCap;
}

template <typename T>
void queue<T>::enqueue(T entry) {
	if (capacity == filled) {
		T *new_array = new T[2 * capacity];
		for (int i = 0; i < 2 * capacity; i++) {
			new_array[i] = 0;
		}

		for (int i = 0; i < capacity; i++) {
			new_array[i] = data[head];
			head = (head + 1) % capacity;
		}
		head = 0;
		tail = filled;
		capacity = 2 * capacity;
		new_array[tail] = entry;
		tail = (tail + 1) % capacity;
		filled = filled + 1;
		delete[] data;
		data = new_array;
	}
	else {
		data[tail] = entry;
		filled = filled + 1;
		tail = (tail + 1) % capacity;
		
	}
}

template <typename T>
T queue<T>::dequeue() {
	T ret = data[head];
	data[head] = NULL;
	head = (head + 1) % capacity;
	filled = filled - 1;
	return ret;
}

template <typename T>
T queue<T>::peek() {
	T ret = data[head];
	return ret;
}

template <typename T>
bool queue<T>::isEmpty() {
	if (filled == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
void queue<T>::print() {
	for (int i = 0; i < capacity; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}