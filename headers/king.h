#pragma once
#include "./board.h"

class King : public Piece {
public:
	King(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};