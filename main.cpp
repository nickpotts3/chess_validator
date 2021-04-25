#include <iostream>
#include <fstream>
#include <map>
//#include "board.h"
using namespace std;

//enum piece {i, j, k, l, m, n, o, p, q, r, s, t, u};
enum color {White, Black};
class Piece;
map<string, Piece*> boardGame;
class Piece {
public:
	Piece() {};
	Piece(const Piece& p);
	~Piece() {}
	string currentPos;
	string color;
	virtual string move(string)=0;
};


Piece::Piece(const Piece& p) {
	color = p.color;
}

class Rook : public Piece {
public:
	Rook() {cout << "Rook ctr called" << endl;};
	string move(string pos) {
		return "Rook move called";
	}

};

class Pawn : public Piece {
public:
	Pawn() {cout << "Pawn ctr called" << endl;};
	string move(string pos) {
		return "pawn move";
	}
};

class Bishop : public Piece {
public:
	Bishop() {cout << "Bishop ctr called" << endl;};
	string move(string pos) {
		return "bishop move";
	};
};

class Knight : public Piece {
public:
	Knight() {cout << "Knight ctr called" << endl;};
	string move(string pos) {
		return "knight";
	}

};

class King : public Piece {
public:
	King() {cout << "king ctr called" << endl;};
	string move(string pos) {
		return "King";
	}

};

class Queen : public Piece {
public:
	Queen() {cout << "Queen ctr called" << endl;};
	string move(string pos) {
		return "queen";
	}
};

class Empty : public Piece {
public:
	Empty(){cout << "empty ctr called" << endl;};
	string move(string pos) {
		return "Empty";
	}
};

class Board {

private:
	map<string, Piece*> game;

public:
	Board();
	Board(const Board& b);
	Board(map<string, Piece*>);
	Board& operator=(const Board& b);
	map<string, Piece*> getGameBoard();
	void print();
	void setGameBoard(map<string, Piece*> board);

};

Board::Board() {
	cout << "default" << endl;
}

Board::Board(map<string, Piece*> b) {
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

map<string, Piece*> Board::getGameBoard() {
	return game;
}


pair<string,Piece*> makePair(Piece *piece, string pos) {
	return pair<string, Piece*> (pos, piece);
}
void determinePiece(char piece, string pos) {
//	auto chessP;
	cout << "entered determinePiece at pos: " << pos << endl; 
	if(piece == 'p' || piece == 'i') {
		Rook r;
		boardGame.insert (makePair(&r , pos));
	} else if (piece == 'j' || piece == 'q') {
		Knight k;
		boardGame.insert( makePair(&k, pos));
//		return "knight";
	} else if (piece == 'k' || piece == 'r') {
		Bishop b;
		boardGame.insert(makePair(&b, pos));
//		return "Bishop";
	} else if (piece == 'l' || piece == 's') {
		Queen q;
		boardGame.insert(makePair(&q, pos));
//		return "Queen";
	} else if (piece == 'm' || piece == 't') {
		King kg;
		boardGame.insert(makePair(&kg, pos));
//		return "King";
	} else if (piece == 'o' || piece == 'u') {
//		cout << "Found pawn" << endl;
		Pawn p;
		boardGame.insert(makePair(&p, pos));
//		return "pawn";
	} else {
		Empty e;
//		boardGame.insert(makePair(&e, pos));
//		return "piece";
	}	
}

//map<string, char> boardGame;
int main() {
//    Rook r;
  //  cout << r.move("foo");   
    string line;
   // map<string, char> boardGame;    
    Board boards[4];
    int count = 0;
    int rank = 8; // to store the row name in the key for the map
    char file[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; // to store the column name in the key for the boardGame map
//    map<string, char>::iterator it = boardGame.begin();
    ifstream boardFile;
    ifstream moveFile ("move_sets.txt");
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	while(getline(boardFile, line)) {
       	  
	  if(line.length() == 0) {
	    Board tmp(boardGame);
	    boards[count] = tmp;
	    ++count;
//	    cout << count << endl;
  //          cout << "---------------------------- NEW BOARD ------------------------" << endl;
            rank = 8;
            boardGame.clear(); 
	  } else {
	    for(int i = 0; i < line.length(); i++) {
                string pos = file[i] + to_string(rank);
		determinePiece(line[i], pos);
                pair<string, char> location (pos, line[i]);
//		boardGame.insert(location);
	    }
	    --rank;
	    if(rank < 0) {rank = 8;}
	    for(auto it = boardGame.cbegin(); it != boardGame.cend(); ++it) {
		cout << (*it).first << " " << (*(*it).second).move("foo");
	    }
	  }
	} // end while loop

	cout << "Line ended" << endl;
    } else {
	cout << "Closed";
    }
    cout << "See me" << endl;
    //moveFile.open("move_sets.txt");
//    for( auto it = boardGame.cbegin(); it != boardGame.cend(); ++it) {
//	cout << (*it).first << " : " << (*it).second.move() << endl;
  //  }
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
