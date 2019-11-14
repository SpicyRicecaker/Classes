#include <iostream>
#include "Media.h"

//Music is kid of media
class Music : public Media
{
 public:
  //constr + destr + method declarations
  Music(char*, int, char*, float, char*);
  ~Music();
  char* getArtist();
  float getDuration();
  char* getPublisher();
  int getType();
 private:
  //variables
  char artist[48];
  float duration;
  char publisher[48];
};
