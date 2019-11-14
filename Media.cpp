#include <iostream>
#include "Media.h"

Media::Media(char* newTitle, int newYear){
  strcpy(title, newTitle);
  year = newYear;
}

char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}

int Media::getType(){

}
