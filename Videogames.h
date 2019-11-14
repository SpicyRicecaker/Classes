#include <iostream>
#include "Media.h"

class Videogames : public Media
{
 public:
  Videogames(char*, int, char*, float);
  char* getPublisher();
  float getRating();
  int getType();
 private:
  char publisher[48];
  float rating;
};
