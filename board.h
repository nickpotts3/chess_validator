#ifndef BOARD_H
#define BOARD_H

class Board {

private:
	map<string,char> game;
public:
Board(map<string, char>);

map<string, char> getGameBoard() { return game; }

};

#endif 
