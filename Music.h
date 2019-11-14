#include <iostream>
#include "Media.h"

class Music : public Media
{
 public:
  Music(char*, int, char*, float, float);
  char* getArtist();
  float getDuration();
  float getRating();
  int getType();
 private:
  char artist[48];
  float duration;
  float rating;
};
