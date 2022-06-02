#pragma once
#include <iostream>
#include <string>
#include "./board.h"
#include "./piece.h"
using namespace std;

class Null : public Piece {
public:
	Null(int i, int j, string st);
	bool validationCheck(int dst_i, int dst_j, Board& chess);
};