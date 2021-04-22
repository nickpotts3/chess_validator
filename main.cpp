#include <iostream>
#include <fstream>
using namespace std;


int main() {
    string line;
    ifstream boardFile;
    boardFile.open("board_states.txt");
    if(boardFile.is_open()) {
	boardFile >> line;
	cout << line;
    } else {
	cout << "Closed";
    }
    boardFile.close();
    cout << "Hello world" << endl;
    return(0);
}
