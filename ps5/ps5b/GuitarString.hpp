/*Copyright Sam Pickell 2017*/

#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "RingBuffer.hpp"

class GuitarString {
 public:
  GuitarString();
  explicit GuitarString(double frequency);
  explicit GuitarString(std::vector<sf::Int16> init);
  ~GuitarString();
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();

 private:
  RingBuffer* data;
  int tic_tracker;
};
#endif
