#include <iostream>
#include <cstring>
#include "Media.h"

//Constructor of Media
Media::Media(char* newTitle, int newYear){
  strcpy(title, newTitle);
  year = newYear;
}
//Getters
char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}

int Media::getType(){
  //To be overriden
}
//Destructor
Media::~Media(){
  delete[] title;
}
