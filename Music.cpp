#include <iostream>
#include "Music.h"

char* Music::getArtist(){
  return artist;
}

float Music::getDuration(){
  return duration;
}

float Music::getRating(){
  return rating;
}

int Music::getType(){
  return 0;
}
