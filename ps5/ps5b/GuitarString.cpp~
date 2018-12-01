/*Copyright Sam Pickell 2017*/
#include "GuitarString.hpp"
#include <cmath>
#include <cstdlib>
#include <vector>

GuitarString::GuitarString() {
}

GuitarString::GuitarString(double frequency) {
  int N = ceil(44100/frequency);
  data = new RingBuffer(N);
  for (int i = 0; i < N; i++) {
      data->enqueue(0);
    }
}

GuitarString::GuitarString(std::vector<sf::Int16> init) {
  data = new RingBuffer(init.size());
  for (unsigned int i = 0; i < init.size(); i++) {
      data->enqueue(init.at(i));
    }
}

GuitarString::~GuitarString() {
  delete data;
}

void GuitarString::pluck() {
  unsigned int r = 123;
  for (int i = 0; i < data->size(); i++) {
      int16_t random_var = (int16_t)(rand_r(&r) % 0xffff);
      data->dequeue();
      data->enqueue(random_var);
    }
}

void GuitarString::tic() {
  int16_t KS_update = data->peek();
  data->dequeue();
  KS_update = ((KS_update + data->peek()) / 2) * .996;
  data->enqueue(KS_update);

  tic_tracker++;
}

sf::Int16 GuitarString::sample() {
  return data->peek();
}

int GuitarString::time() {
  return tic_tracker;
}
