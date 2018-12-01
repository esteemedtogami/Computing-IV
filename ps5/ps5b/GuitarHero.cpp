/*Copyright Sam Pickell 2017*/
#include <limits.h>
#include <cmath>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "GuitarString.hpp"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamplesFromString(GuitarString& gs);

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;
  std::vector< std::vector<sf::Int16> > my_samples;
  std::vector<sf::SoundBuffer*> my_buffers;
  std::vector<sf::Sound> my_sounds;


  for (int i = 0; i < 37; i++) {
      // Step 1
      double freq = CONCERT_A * pow(2, (static_cast<double>(i - 24.0) / 12.0));
      GuitarString gs = GuitarString(freq);
      my_samples.push_back(makeSamplesFromString(gs));

      // Step 2
      sf::SoundBuffer* my_buf = new sf::SoundBuffer;
      if (!my_buf->loadFromSamples(
        &(my_samples.at(i))[0], my_samples.at(i).size(), 2, SAMPLES_PER_SEC)) {
          throw std::runtime_error(
        "sf::SoundBuffer: failed to load from samples.");
        }
      my_buffers.push_back(my_buf);

      // Step 3
      sf::Sound my_sound;
      my_sound.setBuffer(*my_buf);
      my_sounds.push_back(my_sound);
    }

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Q:
          my_sounds.at(0).play();
          break;
          case sf::Keyboard::Num2:
          my_sounds.at(1).play();
          break;
          case sf::Keyboard::W:
          my_sounds.at(2).play();
          break;
          case sf::Keyboard::E:
          my_sounds.at(3).play();
          break;
          case sf::Keyboard::Num4:
          my_sounds.at(4).play();
          break;
          case sf::Keyboard::R:
          my_sounds.at(5).play();
          break;
          case sf::Keyboard::Num5:
          my_sounds.at(6).play();
          break;
          case sf::Keyboard::T:
          my_sounds.at(7).play();
          break;
          case sf::Keyboard::Y:
          my_sounds.at(8).play();
          break;
          case sf::Keyboard::Num7:
          my_sounds.at(9).play();
          break;
          case sf::Keyboard::U:
          my_sounds.at(10).play();
          break;
          case sf::Keyboard::Num8:
          my_sounds.at(11).play();
          break;
          case sf::Keyboard::I:
          my_sounds.at(12).play();
          break;
          case sf::Keyboard::Num9:
          my_sounds.at(13).play();
          break;
          case sf::Keyboard::O:
          my_sounds.at(14).play();
          break;
          case sf::Keyboard::P:
          my_sounds.at(15).play();
          break;
          case sf::Keyboard::Dash:
          my_sounds.at(16).play();
          break;
          case sf::Keyboard::LBracket:
          my_sounds.at(17).play();
          break;
          case sf::Keyboard::Equal:
          my_sounds.at(18).play();
          break;
          case sf::Keyboard::Z:
          my_sounds.at(19).play();
          break;
          case sf::Keyboard::X:
          my_sounds.at(20).play();
          break;
          case sf::Keyboard::D:
          my_sounds.at(21).play();
          break;
          case sf::Keyboard::C:
          my_sounds.at(22).play();
          break;
          case sf::Keyboard::F:
          my_sounds.at(23).play();
          break;
          case sf::Keyboard::V:
          my_sounds.at(24).play();
          break;
          case sf::Keyboard::G:
          my_sounds.at(25).play();
          break;
          case sf::Keyboard::B:
          my_sounds.at(26).play();
          break;
          case sf::Keyboard::N:
          my_sounds.at(27).play();
          break;
          case sf::Keyboard::J:
          my_sounds.at(28).play();
          break;
          case sf::Keyboard::M:
          my_sounds.at(29).play();
          break;
          case sf::Keyboard::K:
          my_sounds.at(30).play();
          break;
          case sf::Keyboard::Comma:
          my_sounds.at(31).play();
          break;
          case sf::Keyboard::Period:
          my_sounds.at(32).play();
          break;
          case sf::Keyboard::SemiColon:
          my_sounds.at(33).play();
          break;
          case sf::Keyboard::Slash:
          my_sounds.at(34).play();
          break;
          case sf::Keyboard::Quote:
          my_sounds.at(35).play();
          break;
          case sf::Keyboard::Space:
          my_sounds.at(36).play();
          break;
        default:
          break;
        }

      default:
        break;
      }

      window.clear();
      window.display();
    }
  }

  // Clean up after the vector of pointers
  for (unsigned int i = 0; i < my_buffers.size(); i++) {
      delete my_buffers.at(i);
    }
  return 0;
}

std::vector<sf::Int16> makeSamplesFromString(GuitarString& gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}
