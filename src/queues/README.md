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

