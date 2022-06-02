#pragma once
#include <iostream>
#include <string>
#include "./board.h"
#include "./piece.h"
using namespace std;

class King : public Piece {
public:
	King(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};