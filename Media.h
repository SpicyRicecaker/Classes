#include <iostream>

class Media{
 public:
  char* getTitle();
  int getYear();
  int getType();
 private:
  char* title[48];
  int year;
};
