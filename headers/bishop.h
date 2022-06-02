#pragma once
#include "./board.h"

class Bishop : public Piece {
public:
	Bishop(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};