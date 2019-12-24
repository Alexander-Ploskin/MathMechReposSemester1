#include <stdio.h>
#include "PriorityQueue.h"

int main()
{
	PriorityQueue* queue = createQueue();

	enqueue(queue, 4, 3);
	enqueue(queue, 3, 4);
	enqueue(queue, 2, 7);
	enqueue(queue, 1, 10);
	enqueue(queue, 5, 0);

	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));

	deleteQueue(queue);

	return 0;
}