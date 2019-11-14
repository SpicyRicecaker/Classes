#include <iostream>
#include "Media.h"

//videogames is child of media
class Videogames : public Media
{
 public:
  //constr + destr + method declaration
  Videogames(char*, int, char*, float);
  ~Videogames();
  char* getPublisher();
  float getRating();
  int getType();
 private:
  //Variables
  char publisher[48];
  float rating;
};
