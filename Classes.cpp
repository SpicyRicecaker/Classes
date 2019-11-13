#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Videogames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

void add(vector <Media*>* medListP);

void del(vector <Media*>* medListP);

void search(vector <Media*>* medListP);

void addVideogames(vector <Media*>* medListP);

void addMusic(vector <Media*>* medListP);

void addMovies(vector <Media*>* medListP);

void quit();

void add(vector <Media*>* medListP){
  char mediaTypeInput[12] = "";
  
  cout << "Please choose the type of media to add. (Videogames, Music, or Movies)" << endl;
  while(true){
    cin.get(mediaTypeInput, 12);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(mediaTypeInput); a++){
      mediaTypeInput[a] = toupper(mediaTypeInput[a]);
    }
    if(strcmp(mediaTypeInput, "VIDEOGAMES") == 0 || strcmp(mediaTypeInput, "MUSIC") == 0 || strcmp(mediaTypeInput, "MOVIES")==0) {
      break;
    }
    cout << "Please choose Videogames, Music, or Movies" << endl;
  }

  if(strcmp(mediaTypeInput, "MOVIES") == 0){
    addMovies(medListP);
  }else if(strcmp(mediaTypeInput, "MUSIC") == 0){
    addMusic(medListP);
  }else {
    addVideogames(medListP);
  }
}

void del(vector <Media*>* medListP){

}

void search(vector <Media*>* medListP){

}

void addVideogames(vector <Media*>* medListP){
  //Title (char), Year (int), Publisher (char), Rating (float)
  
  medListP->push_back(new Videogames());

  vector<Media*>::iterator medListIt = medListP->end();
  
  cout << "Please enter the title" << endl;
  cin.get((*medListIt)->title, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Year" << endl;
  cin.get((*medListIt)->year, 5);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Publisher" << endl;
  cin.get((*medListIt)->publisher, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Rating" << endl;
  cin.get((*medListIt)->rating, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Successfully added new Videogame." << endl;
}

void addMusic(vector <Media*>* medListP){

}

void addMovies(vector <Media*>* medListP){

}

void quit(){
  exit(0);
}

int main(){
  char input[8] = "";
  
  bool running = true;

  vector <Media*> medList;
  vector <Media*>* medListP = &medList; 

  while(running){

    cout << "Please enter a command. Type \"HELP\" for help." << endl;
    
    while(true){
      cin.get(input, 8);
      cin.clear();
      cin.ignore(999,'\n');

      for(int a = 0; a < strlen(input); a++){
	input[a] = toupper(input[a]);
      }
      
      if(strcmp(input, "ADD") == 0 || strcmp(input, "SEARCH") == 0 || strcmp(input, "DEL") == 0 || strcmp(input, "QUIT") == 0 || strcmp(input, "HELP") == 0){
	break;
      }

      cout << "Please enter a valid command. Type \"Help\" for a list of commands." << endl;
    }

    if(strcmp(input, "ADD") == 0){
      add(medListP);
    }else if(strcmp(input, "SEARCH") == 0){
      search(medListP);
    }else if(strcmp(input, "DEL") == 0){
      del(medListP);
    }else if(strcmp(input, "QUIT") == 0){
      quit();
    }else if (strcmp(input, "HELP") == 0){
      cout << "Type \"ADD\" to add media. Type \"SEARCH\" to search for media. Type \"DELETE\" to delete media. Type \"QUIT\" to quit." << endl;
    }
  }
}

