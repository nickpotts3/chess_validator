#include <iostream>
#include <fstream>
#include <map>
//#include "board.h"
using namespace std;


class Board {

private:
	map<string, char> game;

public:
	Board();
	Board(const Board& b);
	Board& operator=(const Board& b);
	map<string, char> getGameBoard();
	void setGameBoard(map<string, char> board);

};

Board::Board() {
	cout << "default" << endl;
}

Board::Board(const Board& b) {
	cout << "Copy" << endl;

}

Board& Board::operator=(const Board& b) {
	if( this != &b) {
		cout << "Assignment" << endl;
	}
	return *this;
}

int main() {
    string line;
    map<string, char> boardGame;    
   // Board boards[4];
    int count = 0;
    int rank = 8; // to store the row name in the key for the map
    char file[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; // to store the column name in the key for the boardGame map
    map<string, char>::iterator it = boardGame.begin();
    ifstream boardFile;
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	while(getline(boardFile, line)) {
       	  
	  if(line.length() == 0) {
	    Board test;
	   // boards[count] = boardGame;
	    ++count;
	    cout << count << endl;
            cout << "---------------------------- NEW BOARD ------------------------" << endl;
            rank = 8;
            boardGame.clear(); 
	  } else {
	    for(int i = 0; i < line.length(); i++) {
                string pos = file[i] + to_string(rank);

                pair<string, char> location (pos, line[i]);
		boardGame.insert(location);
	    }
	    --rank;
	    if(rank < 0) {rank = 8;}
	     
	  }
	} // end while loop


    } else {
	cout << "Closed";
    }
    
    boardFile.close();
    
    return(0);
}
