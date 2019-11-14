#include <iostream>
#include <cstring>
#include "Movies.h"

Movies::Movies(char* newTitle, int newYear, char* newDirector, float newDuration, float newRating) : Media(newTitle, newYear){
  strcpy(director, newDirector);
  duration = newDuration;
  rating = newRating;
}

char* Movies::getDirector(){
  return director;
}

float Movies::getDuration(){
  return duration;
}

float Movies::getRating(){
  return rating;
}

int Movies::getType(){
  return 3;
}

Movies::~Movies(){
  delete director;
}
