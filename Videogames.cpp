#include <iostream>
#include <cstring>
#include "Videogames.h"

Videogames::Videogames(char* newTitle, int newYear, char* newPublisher, float newRating) : Media(newTitle, newYear){
  strcpy(publisher, newPublisher);
  rating = newRating;
}

char* Videogames::getPublisher(){
  return publisher;
}

float Videogames::getRating(){
  return rating;
}

int Videogames::getType(){
  return 1;
}
