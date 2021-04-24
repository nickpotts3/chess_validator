#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

using namespace std;

class Board {

private:
	map<string,char> game;
public:
	Board(map<string, char>);
	Board() {cout << "default constructor" << endl;}
	Board(const Board& b);
	~Board();
	Board& operator=(const Board& b);
	map<string,char> getGameBoard() { return game; }

};

#endif 
