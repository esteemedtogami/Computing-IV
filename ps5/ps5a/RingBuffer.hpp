/* Copyright 2017 Sam Pickell */
#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <stdint.h>
#include <stdexcept>
#include <iostream>
#include <vector>

class RingBuffer {
 public:
  RingBuffer();
  explicit RingBuffer(int u_capacity);
  ~RingBuffer();

  int size() { return my_size; }
  int get_capacity() { return capacity; }
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

 private:
  int my_size, capacity;
  std::vector<int16_t> data;
};
#endif
