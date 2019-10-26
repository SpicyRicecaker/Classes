#include <iostream>
#include <cstring>

using namespace std;

void add();

void del();

void search();

void quit();

void add(){
  
}

void del(){

}

void search(){

}

void quit(){

}

int main(){
  char input[8] = "";
  
  bool running = true;

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
      add();
    }else if(strcmp(input, "SEARCH") == 0){
      search();
    }else if(strcmp(input, "DEL") == 0){
      del();
    }else if(strcmp(input, "QUIT") == 0){
      quit();
    }else if (strcmp(input, "HELP") == 0){
      cout << "Type \"ADD\" to add media. Type \"SEARCH\" to search for media. Type \"DELETE\" to delete media. Type \"QUIT\" to quit." << endl;
    }



    

    
  }
}
