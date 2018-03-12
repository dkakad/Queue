#include "arrayqueue.h"
#include "arrayqueue.cpp"

int main() {
	queue<int> *q = new queue<int>(5);
	q->enqueue(4);
	q->enqueue(1);
	q->enqueue(7);
	q->enqueue(3);
	q->enqueue(8);
	q->enqueue(6);
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->enqueue(10);
	q->enqueue(11);
	q->enqueue(12);
	q->enqueue(13);
	q->enqueue(14);

	q->print();
	return 0;
}