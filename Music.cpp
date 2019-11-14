#include <iostream>
#include <cstring>
#include "Music.h"

Music::Music(char* newTitle, int newYear, char* newArtist, float newDuration, float newRating) : Media(newTitle, newYear){
  strcpy(artist, newArtist);
  duration = newDuration;
  rating = newRating;
}							   

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
  return 2;
}
