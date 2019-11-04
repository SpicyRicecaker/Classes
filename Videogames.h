#include <iostream>
#include <Media.h>

class Videogames : public Media
{
 public:
  char* getPublisher();
  float getRating();
 private:
  char* publisher[48];
  float rating;
};
