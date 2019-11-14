/*
  Author: Andy Li
  Date: 11/13/2019
  Classes: A program that takes in information about 3 different types of media: Videogames, Music, and Movies defined by classes and header files stored in vector arrays that can add, delete, search for media and information. Destructors are also used.
*/
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

//The add function prompts the user for a type of media and sends them to a corresponding function that asks about the corresponding values
void add(vector <Media*>* medListP){
  char mediaTypeInput[12] = "";
  
  cout << "Please choose the type of media to add. (Videogames, Music, or Movies)" << endl;
  //Input validation
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

//Delete uses much of search's methods and uses delete and erase to remove corresponding media types
//(refer to search for search portion)
void del(vector <Media*>* medListP){
  char input [7] = "";
  cout << "Would you like to delete by title or by year?" << endl;
  while(true){
    cin.get(input, 7);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(input); a++){
      input[a] = toupper(input[a]);
    }

    if(strcmp(input, "TITLE") == 0 || strcmp(input, "YEAR") == 0){
      break;
    }

    cout << "Please choose either title or year" << endl;
  }

  vector <Media*>::iterator medListIt;

  if(strcmp(input, "TITLE") == 0){
    char inTitle [48] = "";
    cout << "Please enter the title" << endl;
    cin.get(inTitle, 48);
    cin.clear();
    cin.ignore(999, '\n');
    
    for(medListIt = medListP->begin(); medListIt != medListP->end(); ){
      if(strcmp((*medListIt)->getTitle(), inTitle) == 0){
	int trans = (*medListIt)->getType();
	//Videogame
	if(trans == 1){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Videogames*)(*medListIt))->getPublisher() << ", " << ((Videogames*)(*medListIt))->getRating() << endl;
	}else if(trans == 2){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Music*)(*medListIt))->getArtist() << ", " << ((Music*)(*medListIt))->getDuration() << ", "<< ((Music*)(*medListIt))->getPublisher() << endl;
	}else if(trans == 3){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Movies*)(*medListIt))->getDirector() << ", " << ((Movies*)(*medListIt))->getDuration() << ", " << ((Movies*)(*medListIt))->getRating() << endl;
	}

	//Asks for user confirmation of deletion

	cout << "Are you sure you want to delete this? (y/n)" << endl;

	char chooseDel = '\n';
	cin >> chooseDel;
	cin.clear();
	cin.ignore(999, '\n');

	if(chooseDel == 'y'){
	  //Deletes contents of iterator then the iterator
	  delete *medListIt;
	  medListIt = medListP->erase(medListIt);  
	}else{
	  //Only count up if iterator wasn't deleted
	  cout << "Deletion cancelled" << endl;
	  ++medListIt;
	}
      }
    }
  }else {
    int inYear = 0;
    cout << "Please enter the year" << endl;
    cin >> inYear;
    cin.clear();
    cin.ignore(999, '\n');
    
    for(medListIt = medListP->begin(); medListIt != medListP->end(); ){
      if((*medListIt)->getYear() == inYear){
	int trans = (*medListIt)->getType();
	//Videogame
	if(trans == 1){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Videogames*)(*medListIt))->getPublisher() << ", " << ((Videogames*)(*medListIt))->getRating() << endl;
	}else if(trans == 2){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Music*)(*medListIt))->getArtist() << ", " << ((Music*)(*medListIt))->getDuration() << ", "<< ((Music*)(*medListIt))->getPublisher() << endl;
	}else if(trans == 3){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Movies*)(*medListIt))->getDirector() << ", " << ((Movies*)(*medListIt))->getDuration() << ", " << ((Movies*)(*medListIt))->getRating() << endl;
	}
	
	cout << "Are you sure you want to delete this? (y/n)" << endl;

	char chooseDel = '\n';
	cin >> chooseDel;
	cin.clear();
	cin.ignore(999, '\n');

	if(chooseDel == 'y'){
	  delete *medListIt;
	  medListIt = medListP->erase(medListIt);
	  
	}else{
	  cout << "Deletion cancelled" << endl;
	  ++medListIt;
	}
      }
    }
  }
}

//Search prompts the user for title or year search, a title or year, then uses an iterator that loops through the vector to find media types with matching titles or years and prints them out
void search(vector <Media*>* medListP){
  //Asks for title or year
  char input [7] = "";
  cout << "Would you like to search by title or by year?" << endl;
  while(true){
    cin.get(input, 7);
    cin.clear();
    cin.ignore(999, '\n');

    for(int a = 0; a < strlen(input); a++){
      input[a] = toupper(input[a]);
    }

    if(strcmp(input, "TITLE") == 0 || strcmp(input, "YEAR") == 0){
      break;
    }

    cout << "Please enter title or year" << endl;
  }

  //Makes iterator
  vector <Media*>::iterator medListIt;

  //Asks for title 
  if(strcmp(input, "TITLE") == 0){
    char inTitle [48] = "";
    cout << "Please enter the title" << endl;
    cin.get(inTitle, 48);
    cin.clear();
    cin.ignore(999, '\n');

    //Loops through the media list
    for(medListIt = medListP->begin(); medListIt != medListP->end(); ++medListIt){
      //Until corresponding title is found
      if(strcmp((*medListIt)->getTitle(), inTitle) == 0){
	int trans = (*medListIt)->getType();
	//Casts type to methods and displays info
	if(trans == 1){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Videogames*)(*medListIt))->getPublisher() << ", " << ((Videogames*)(*medListIt))->getRating() << endl;
	}else if(trans == 2){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Music*)(*medListIt))->getArtist() << ", " << ((Music*)(*medListIt))->getDuration() << ", "<< ((Music*)(*medListIt))->getPublisher() << endl;
	}else if(trans == 3){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Movies*)(*medListIt))->getDirector() << ", " << ((Movies*)(*medListIt))->getDuration() << ", " << ((Movies*)(*medListIt))->getRating() << endl;
	} 
      }
    }
    //Same principles for year
  }else {
    int inYear = 0;
    cout << "Please enter the year" << endl;
    cin >> inYear;
    cin.clear();
    cin.ignore(999, '\n');
    
    for(medListIt = medListP->begin(); medListIt != medListP->end(); ++medListIt){
      if((*medListIt)->getYear() == inYear){
	int trans = (*medListIt)->getType();
	//Videogame
	if(trans == 1){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Videogames*)(*medListIt))->getPublisher() << ", " << ((Videogames*)(*medListIt))->getRating() << endl;
	}else if(trans == 2){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Music*)(*medListIt))->getArtist() << ", " << ((Music*)(*medListIt))->getDuration() << ", "<< ((Music*)(*medListIt))->getPublisher() << endl;
	}else if(trans == 3){
	  cout << (*medListIt)->getTitle() << ", " << (*medListIt)->getYear() << ", " << ((Movies*)(*medListIt))->getDirector() << ", " << ((Movies*)(*medListIt))->getDuration() << ", " << ((Movies*)(*medListIt))->getRating() << endl;
	} 
      }
    }
  }
}

//Add videogames prompts the user for information pertaining to videogames
void addVideogames(vector <Media*>* medListP){
  //Title (char), Year (int), Publisher (char), Rating (float)
  char tempTitle[48] = "";
  int tempYear = 0;
  char tempPublisher[48] = "";
  float tempRating = 0.0;
  
  cout << "Please enter the title" << endl;
  cin.get(tempTitle, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Year" << endl;
  cin >> tempYear;
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Publisher" << endl;
  cin.get(tempPublisher, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Rating" << endl;
  cin >> tempRating;
  cin.clear();
  cin.ignore(999, '\n');

  //Constructs a new Videogame with the gathered information
  medListP->push_back(new Videogames(tempTitle, tempYear, tempPublisher, tempRating));
  
  cout << "Successfully added new Videogame." << endl;
}

//Asks the user for information pertaining to music
void addMusic(vector <Media*>* medListP){
  //Title (char), Year (int), newArtist (char), new Duration (float), new Publisher (char)

  char tempTitle[48] = "";
  int tempYear = 0;
  char tempArtist[48] = "";
  float tempDuration = 0.0;
  char tempPublisher[48] = "";
  
  cout << "Please enter the title" << endl;
  cin.get(tempTitle, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Year" << endl;
  cin >> tempYear;
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Artist" << endl;
  cin.get(tempArtist, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Duration" << endl;
  cin >> tempDuration;
  cin.clear();
  cin.ignore(999, '\n');
  
  cout << "Please enter the Publisher" << endl;
  cin >> tempPublisher;
  cin.clear();
  cin.ignore(999, '\n');

  //Constructs new Music with the input values
  medListP->push_back(new Music(tempTitle, tempYear, tempArtist, tempDuration, tempPublisher));
  
  cout << "Successfully added new Music." << endl;
}

//Asks the user for information pertaining to movies
void addMovies(vector <Media*>* medListP){
  //Title (char), Year (int), Director (char), Duration (float), Rating (float)
  char tempTitle[48] = "";
  int tempYear = 0;
  char tempDirector[48] = "";
  float tempDuration = 0.0;
  float tempRating = 0.0;
  
  cout << "Please enter the title" << endl;
  cin.get(tempTitle, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Year" << endl;
  cin >> tempYear;
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Director" << endl;
  cin.get(tempDirector, 48);
  cin.clear();
  cin.ignore(999, '\n');

  cout << "Please enter the Duration" << endl;
  cin >> tempDuration;
  cin.clear();
  cin.ignore(999, '\n');
  
  cout << "Please enter the Rating" << endl;
  cin >> tempRating;
  cin.clear();
  cin.ignore(999, '\n');

  //Constructs a new Movie with the input values
  medListP->push_back(new Movies(tempTitle, tempYear, tempDirector, tempDuration, tempRating));
  
  cout << "Successfully added new Movie." << endl;
}

//Exits the program
void quit(){
  exit(0);
}

//The main method of Classes
int main(){
  char input[8] = "";
  
  bool running = true;

  //Vectors that store media
  vector <Media*> medList;
  vector <Media*>* medListP = &medList; 

  //Program loop to ask user for command
  while(running){

    cout << "Please enter a command. Type \"HELP\" for help." << endl;
    
    while(true){
      cin.get(input, 8);
      cin.clear();
      cin.ignore(999,'\n');

      for(int a = 0; a < strlen(input); a++){
	input[a] = toupper(input[a]);
      }
      
      if(strcmp(input, "ADD") == 0 || strcmp(input, "SEARCH") == 0 || strcmp(input, "DELETE") == 0 || strcmp(input, "QUIT") == 0 || strcmp(input, "HELP") == 0){
	break;
      }

      cout << "Please enter a valid command. Type \"Help\" for a list of commands." << endl;
    }

    if(strcmp(input, "ADD") == 0){
      add(medListP);
    }else if(strcmp(input, "SEARCH") == 0){
      search(medListP);
    }else if(strcmp(input, "DELETE") == 0){
      del(medListP);
    }else if(strcmp(input, "QUIT") == 0){
      quit();
    }else if (strcmp(input, "HELP") == 0){
      cout << "Type \"ADD\" to add media. Type \"SEARCH\" to search for media. Type \"DELETE\" to delete media. Type \"QUIT\" to quit." << endl;
    }
  }
}
