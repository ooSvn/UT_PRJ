#pragma once

class Piece {
public:
	char piece_color;
	int m_i, m_j;
	string state;
	virtual bool validationCheck(int dst_i, int dst_j, Board &) = 0;
	friend ostream& operator<<(ostream& os, const Piece &obj);
};