#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board;
class Piece {
public:
	char piece_color;
	int m_i, m_j;
	string state;
	virtual bool validationCheck(int dst_i, int dst_j, Board &) = 0;
};