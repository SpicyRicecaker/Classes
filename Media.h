#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
class Media{
 public:
  Media(char*, int);
  ~Media();
  char* getTitle();
  int getYear();
  virtual int getType();
 private:
  char title[48];
  int year;
};
#endif
