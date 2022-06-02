#include "../headers/king.h"

King::King(int i, int j, char color, string st) {
	this->m_i = i;
	this->m_j = j;
	this->piece_color = color;
	this->state = st;
};

bool King::validationCheck(int dst_i, int dst_j, Board& chess) {
	if ((abs(dst_i - this->m_i) == 0 && abs(dst_j - this->m_j) == 1) ||
		(abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 0) ||
		(abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 1)) {
		return true;
	}
	return false;
}

