#include <iostream>
#include <cstring>
#include "Videogames.h"

//Constructor
Videogames::Videogames(char* newTitle, int newYear, char* newPublisher, float newRating) : Media(newTitle, newYear){
  strcpy(publisher, newPublisher);
  rating = newRating;
}

//Getters
char* Videogames::getPublisher(){
  return publisher;
}

float Videogames::getRating(){
  return rating;
}

int Videogames::getType(){
  return 1;
}

//Destructor
Videogames::~Videogames(){
  delete publisher;
}
