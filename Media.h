#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H
class Media{
 public:
  char* getTitle();
  int getYear();
  int getType();
 private:
  char* title[48];
  int year;
};
#endif
