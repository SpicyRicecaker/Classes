#include <iostream>
#include <cstring>

//Header guard
#ifndef MEDIA_H
#define MEDIA_H
class Media{
 public:
  //cons and destr and methods declaration
  Media(char*, int);
  ~Media();
  char* getTitle();
  int getYear();
  //Virtual allows media to be overriden
  virtual int getType();
 private:
  //Variables
  char title[48];
  int year;
};
#endif
