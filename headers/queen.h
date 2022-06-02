#pragma once
#include <iostream>
#include <string>
#include "./board.h"
#include "./piece.h"
using namespace std;

class Queen : public Piece {
public:
	Queen(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};