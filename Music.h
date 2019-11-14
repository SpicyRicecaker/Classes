#include <iostream>
#include "Media.h"

class Music : public Media
{
 public:
  Music(char*, int, char*, float, char*);
  ~Music();
  char* getArtist();
  float getDuration();
  char* getPublisher();
  int getType();
 private:
  char artist[48];
  float duration;
  char publisher[48];
};
