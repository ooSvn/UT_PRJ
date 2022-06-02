#pragma once
#include "./board.h"

class Queen : public Piece {
public:
	Queen(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};