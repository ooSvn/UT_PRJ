#pragma once
#include "./board.h"

class Board;
class Null : public Piece {
public:
	Null(int i, int j, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};