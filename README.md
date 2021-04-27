# chess_validator
The approach I was taking utilizes polymorphesim and an abstract class Piece with a pure virtual function move(string). Each specific chess piece inherits from
base class Piece and defines their own move(string) function. This function validates that the move from startPos = endPos.

I originally was going to create a Board class that manages the gameboard. To save space and time I decided to use a map with the key being the rank/file and the value
being the piece at the corresponding rank/file location. My plan was to read an entire board then read the moveset and validate the moves. Upon validating all moves, I
was going to deallocate the memory locations in the board map and reuse it for the next board.

Each piece contains certain rules that must be followed for the move to be valid.

Rook - The rank must stay the same and the file changes or vice versa. Otherwise, invalid move

King - The number must be the same or +- 1 of the current number where number is the file. Otherwise invalid move

Bishop - The rank AND file of the end position must be plus or minus 1 of the starting position

Queen - Combines bishop and rook

Knight - New rank must be a difference of 2 AND file a difference of 1 OR new rank must be a difference of 1 AND file a difference of 2
else invalid move

Pawns - Rank is a difference of one

Before going into the validator for each piece we must validate the the beginning spot has a piece and the ending spot is empty. We also must check to ensure
the moves are actual locations on the board and do not go out of range. 

I ran into a memory issue I believe with my pointers and references in the map object boardGame.
