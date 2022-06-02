#pragma once
#include <iostream>
#include <string>
#include "./board.h"
#include "./piece.h"
using namespace std;

class Knight : public Piece {
public:
	Knight(int i, int j, char color, string st);
	bool validationCheck(int dst_i, int dst_j, Board &chess);
};