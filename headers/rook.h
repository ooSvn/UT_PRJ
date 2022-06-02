#pragma once
#include "./board.h"

class Rook : public Piece {
public:
	Rook(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};