#include<string>
#include "board.h"
using namespace std;

Board::Board( map<string, char> game ) {

	boardGame = game

}

Board::Board(const Board& b) {

	cout << "Copy" << endl;

}

Board::~Board() {
	cout << "Destructor" << endl;
}

Board& Board::operator=(const Board& b) {

	if (this != &b) {
	
	}

	return *this;
}
