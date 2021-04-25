#include <iostream>
#include <fstream>
#include <map>
//#include "board.h"
using namespace std;

//enum piece {i, j, k, l, m, n, o, p, q, r, s, t, u};
enum color {White, Black};

class Piece {
public:
	Piece() {};
	Piece(const Piece& p);
	~Piece() {}
	string currentPos;
	string color;
	virtual bool move(string)=0;
};


Piece::Piece(const Piece& p) {
	color = p.color;
}

class Rook : public Piece {
public:
	Rook() {};
	bool move(string pos) {
		cout << "Rook move called" << endl;
		return true;
	}

};

class Pawn : public Piece {
	bool move(string pos) {
		return true;
	}
};

class Bishop : public Piece {
	bool move(string pos) {
		return true;
	};
};

class Knight : public Piece {
	bool move(string pos) {

	}

};

class King : public Piece {
	bool move(string pos) {
	
	}

};

class Queen : public Piece {
	bool move(string pos) {

	}
};

class Empty : public Piece {

};

class Board {

private:
	map<string, char> game;

public:
	Board();
	Board(const Board& b);
	Board(map<string, char>);
	Board& operator=(const Board& b);
	map<string, char> getGameBoard();
	void print();
	void setGameBoard(map<string, char> board);

};

Board::Board() {
	cout << "default" << endl;
}

Board::Board(map<string, char> b) {
	game = b;
}

Board::Board(const Board& b) {
	game = b.game;

}

void Board::print() {
	for(auto b : game) {
		cout << b.first << " : " << b.second << endl;
	}
}

Board& Board::operator=(const Board& b) {
	if( this != &b) {
		game = b.game;
	}
	return *this;
}

map<string, char> Board::getGameBoard() {
	return game;
}


string determinePiece(char piece, string pos) {
//	auto chessP;
//	cout << "entered determinePiece at pos: " << pos << endl; 
	if(piece == 'p' || piece == 'i') {
		return "Rook";
//		Rook r;
//		return r;
	} else if (piece == 'j' || piece == 'q') {
		return "knight";
	} else if (piece == 'k' || piece == 'r') {
		return "Bishop";
	} else if (piece == 'l' || piece == 's') {
		return "Queen";
	} else if (piece == 'm' || piece == 't') {
		return "King";
	} else if (piece == 'o' || piece == 'u') {
		return "pawn";
	} else {
		return "piece";
	}	
}

int main() {
    Rook r;
    cout << r.move("foo");   
    string line;
    map<string, char> boardGame;    
    Board boards[4];
    int count = 0;
    int rank = 8; // to store the row name in the key for the map
    char file[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; // to store the column name in the key for the boardGame map
    map<string, char>::iterator it = boardGame.begin();
    ifstream boardFile;
    ifstream moveFile ("move_sets.txt");
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	while(getline(boardFile, line)) {
       	  
	  if(line.length() == 0) {
	    Board tmp(boardGame);
	    boards[count] = tmp;
	    ++count;
	    cout << count << endl;
            cout << "---------------------------- NEW BOARD ------------------------" << endl;
            rank = 8;
            boardGame.clear(); 
	  } else {
	    for(int i = 0; i < line.length(); i++) {
                string pos = file[i] + to_string(rank);
		cout << determinePiece(line[i], pos);
                pair<string, char> location (pos, line[i]);
		boardGame.insert(location);
	    }
	    --rank;
	    if(rank < 0) {rank = 8;}
	     
	  }
	} // end while loop

	cout << "Line ended" << endl;
    } else {
	cout << "Closed";
    }
    cout << "See me" << endl;
    //moveFile.open("move_sets.txt");
    string moves;
    if(moveFile.is_open()) {
	cout << "Open" << endl;
	while(getline(moveFile, moves)) {
	  cout << moves;
	  cout << endl;
	}
    } else {
	cout << "Closed";
    }

	    
    return(0);
}

