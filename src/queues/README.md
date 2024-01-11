# Queues

- The queue is another Abstract Data Type that is just like a line at the store or at the bank. The first person in line is the first person out of line and served.

- This is called a FIFO data structure. FIRST IN, FIRST OUT.

- Every queue has a front and a rear. You enqueue items at the rear and dequeue from the front.

- Queue operations:

    - enqueue: inserts an item on the rear of the queue.
    - dequeue: removes and returns the top item from the front of the queue.
    - isEmpty: determines if the queue is empty.
    - size: determines the # of items in the queue.
    - getFront: gives the value of the top item on the queue without removing it like dequeue.

# Common use cases

- Optimal route navigation.

- Streaming video buffering.

- Flood-filling in paint programs.

- Searching through mazes (note: the new algorithm explores the oldest x,y location inserted into the queue first).

- Tracking calls in call centers.

# Queue implementations

## Linked list

- We can use a linked list to represent a queue.

- Every time you insert an item, add a new node to the end of the linked list.

- Every time you dequeue an item, take it from the head of the linked list and then delete the head node.

- Make sure you have both head and tail pointers or the linked list based queue will be really inefficient.

## The circular queue

- The circular queue is a clever type of array-based queue.

- We never need to shift items with the circular queue!
