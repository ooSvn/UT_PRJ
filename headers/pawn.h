#pragma once
#include "./board.h"

class Pawn : public Piece {
public:
	Pawn(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};