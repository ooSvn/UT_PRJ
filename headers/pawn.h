#pragma once
#include "./board.h"

class Pawn : public Piece {
public:
	bool is_first_move = false;
	Pawn(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};