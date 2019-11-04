#include <iostream>

class Media{
 public:
  char* getTitle();
  int getYear();
 private:
  char* title[48];
  int year;
};
