Programmer: Sam Pickell
Date: 3/6/2017
Time Spent: 3 hours and 9 minutes

I tested my ring buffer implementation using the boost test functions provided
in the starter code as well as some boost tests that I wrote based on the
provided code (see the commented portions of test.cpp).

I implemented some basic exception handling in RingBuffer.cpp. Exceptions
are thrown if the capacity is set to something lower than 1, if the user
tries to enqueue a full queue, and if the user tries to dequeue or peek into
an empty queue.

I'm not entirely sure what is meant by "time and space performance" of my
program, however I will say a little more about it. The RingBuffer class
stores its data in a vector of 16 bit integers, an implementation I based
on what I learned in Computing II. Its private data consists of two integers
size and capacity, as well as the vector mentioned earlier. On top of the
functions I was assigned to include, I also included an accessor for capacity.
My program meets cpplint standards and completely works.
