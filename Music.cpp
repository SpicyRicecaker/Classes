#include <iostream>
#include <cstring>
#include "Music.h"

//Constructor
Music::Music(char* newTitle, int newYear, char* newArtist, float newDuration, char* newPublisher) : Media(newTitle, newYear){
  strcpy(artist, newArtist);
  duration = newDuration;
  strcpy(publisher, newPublisher);
}							   

//Getters
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

//Deconstructor
Music::~Music(){
  delete artist;
  delete publisher;
}
