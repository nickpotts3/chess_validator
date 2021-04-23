#include <iostream>
#include <fstream>
using namespace std;


int main() {
    string line;
    ifstream boardFile;
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	while(getline(boardFile, line)) {
	  
	  if(line.length() == 0) {
	    cout << "New board" << endl << endl;
	  } else {
	    cout << line << endl; 
	  }
	}
    } else {
	cout << "Closed";
    }
    boardFile.close();
    
    return(0);
}
