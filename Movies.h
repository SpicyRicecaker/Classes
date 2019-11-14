#include <iostream>
#include "Media.h"

//Movies are children of Media
class Movies : public Media
{
 public:
  //constr + destr + method declaration
  Movies(char*, int, char*, float, float);
  ~Movies();
  char* getDirector();
  float getDuration();
  float getRating();
  int getType();
 private:
  //variables
  char director[48];
  float duration;
  float rating;
};
