#include <iostream>
#include <cstring>
#include "Music.h"

Music::Music(char* newTitle, int newYear, char* newArtist, float newDuration, char* newPublisher) : Media(newTitle, newYear){
  strcpy(artist, newArtist);
  duration = newDuration;
  strcpy(publisher, newPublisher);
}							   

char* Music::getArtist(){
  return artist;
}

float Music::getDuration(){
  return duration;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getType(){
  return 2;
}
