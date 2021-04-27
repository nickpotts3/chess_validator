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
	Piece(string);
	Piece(const Piece& p);
	~Piece() {}
	string currentPos;
	string color;
	friend ostream& operator<<(ostream& os, const Piece& p);
	virtual string move(string)=0;
};

Piece::Piece(string pos) { currentPos = pos; }

ostream& operator<<(ostream& os, const Piece& p) {
	os << p.color << " : " << p.currentPos << endl;
	return os;
}


Piece::Piece(const Piece& p) {
	color = p.color;
}

class Rook : public Piece {
public:
	Rook(string){};
	Rook() {cout << "Rook ctr called" << endl;};
	string move(string pos) {
		//board validation is done before this is executed
			return "MOVE ROOK TO" + pos;
	}
	void validMove(string);

};

class Pawn : public Piece {
public:
	Pawn(string){};
	Pawn() {cout << "Pawn ctr called" << endl;};
	string move(string pos) {
		return "MOVE PAWN TO " + pos;
	}
	void validMove(string);
};

class Bishop : public Piece {
public:
	Bishop(string){};
	Bishop() {cout << "Bishop ctr called" << endl;};
	string move(string pos) {
		return "bishop move to " + pos ;
	}
	void validMove(string);
};

class Knight : public Piece {
public:
	Knight(string){};
	Knight() {cout << "Knight ctr called" << endl;};
	string move(string pos) {
		return "knight move to " + pos;
	}
	void validMove(string);
};

class King : public Piece {
public:
	King(string){};
	King() {cout << "king ctr called" << endl;};
	string move(string pos) {
		return "King move to " + pos;
	}
	void validMove(string);

};

class Queen : public Piece {
public:
	Queen(string){};
	Queen() {cout << "Queen ctr called" << endl;};
	string move(string pos) {
		return "queen";
	}
	void validMove(string);
};

class Empty : public Piece {
public:
	Empty(string){};
	Empty(){cout << "empty ctr called" << endl;};
	string move(string pos) {
		return "Empty";
	}
	void validMove(string);
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


pair<string,Piece*> makePair(Piece &piece, string pos) {
//	cout << "INSIDE MAKE PAIR" << " pos is " << pos << endl; // " " << piece.move("pos") <<  endl;
	return (pair<string, Piece*> (pos, &piece));
}
void determinePiece(char piece, string pos) {
//	cout << "PIECE IS : " << piece << " AT POS: " << pos << endl;
//	cout << "entered determinePiece at pos: " << pos << endl; 
	if(piece == 'p' || piece == 'i') {
		Rook* r = new Rook(pos);
//		cout << r.move(pos) << endl;
		boardGame.insert(makePair(*r, pos));
		cout << "AFTER INSERT ROOK" << endl;
	} else if (piece == 'j' || piece == 'q') {
		Knight k(pos);
//		cout << k.move(pos) << endl;
		boardGame.insert(makePair(k, pos));
	} else if (piece == 'k' || piece == 'r') {
		Bishop b(pos);
//		cout << b.move(pos) << endl;
		boardGame.insert(makePair(b, pos));
	} else if (piece == 'l' || piece == 's') {
		Queen q(pos);
//		cout << q.move(pos) << endl;
		boardGame.insert(makePair(q, pos));
	} else if (piece == 'm' || piece == 't') {
		King kg(pos);
//		cout << kg.move(pos) << endl;
		boardGame.insert(makePair(kg, pos));
	} else if (piece == 'o' || piece == 'u') {
		Pawn p(pos);
//		cout << p.move(pos) << endl;
		boardGame.insert(makePair(p, pos));
	} else {
		Empty e(pos);
//		cout << e.move(pos) << endl;
		boardGame.insert(makePair(e,pos));
	}
//	cout << "---leaving determinePiece---" << endl;	
}

void validateMoveSet(string moveSet) {
	cout << "Move Set called: " << moveSet << endl;
	string move = moveSet.substr(0, 2);
	cout << move << endl;
	auto chessP = boardGame.find(move)->second;
	cout << (*chessP).move("Foo") << endl;
//	cout << boardGame.find(move)->second*->move(move); // << "   :MOVE" << endl;
//	cout << (*chessP).move(move);
}


int main() {   
    string line;
    string moveSet;       
    Board boards[4];
    int count = 0;
    int rank = 8; // to store the row name in the key for the map
    char file[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // to store the column name in the key for the boardGame map
    ifstream boardFile;
    ifstream moveFile ("move_sets.txt");
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	while(getline(boardFile, line)) {
       	  
	  if(line.length() == 0) {
	    Board tmp(boardGame);
	    boards[count] = tmp;
	    getline(moveFile, moveSet);
	    validateMoveSet(moveSet);
            string move = moveSet.substr(0, 4);
	    cout << move << endl;
	    cout << moveSet << endl;
	    ++count;
            rank = 8;
            boardGame.clear(); 
	  } else {
	    for(int i = 0; i < line.length() - 1; i++) {
                string pos = file[i] + to_string(rank);
		determinePiece(line[i], pos);
	    }
	    --rank;
	    if(rank == 0) {rank = 8;}
	    for(auto it = boardGame.cbegin(); it != boardGame.cend(); ++it) {
	//	cout << (*it).first << endl; // " " << (*(*it).second).move("foo");
	    }
	  }
	} // end while loop

	cout << "Line ended" << endl;
    } else {
	cout << "Closed";
    }
    string moves;
   // if(moveFile.is_open()) {
//	cout << "Open" << endl;
//	while(getline(moveFile, moves)) {
//	  cout << moves;
//	  cout << endl;
//	}
  //  } else {
//	cout << "Closed";
  //  }

	    
    return(0);
}
