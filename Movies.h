#include <iostream>
#include "Media.h"

class Movies : public Media
{
 public:
  char* getDirector();
  float getDuration();
  float getRating();
  int getType();
 private:
  char* director[48];
  float duration;
  float rating;
};
