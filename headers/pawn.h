#pragma once
#include <iostream>
#include <string>
#include "./board.h"
#include "./piece.h"

class Pawn : public Piece {
public:
	bool is_first_move = false;
	Pawn(int i, int j, char color, std::string st) {
		this->m_i = i;
		this->m_j = j;
		this->piece_color = color;
		this->state = st;
		if (color == 'w') {
			if (i == 6)
				this->is_first_move = true;
		}
		else if (color == 'b')
			if (i == 1)
				this->is_first_move = true;
	};

	bool validationCheck(int dst_i, int dst_j, Board& chess) {
		if (abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 0) {
			if (dst_i > this->m_i) return true;
			else return false;
		}
		else if ((abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 1)) {
			if (this->piece_color == 'w') {
				if (chess.board[dst_i][dst_j]->piece_color != 'b') return false;
			}
			else
				if (chess.board[dst_i][dst_j]->piece_color != 'w') return false;
			return true;
		}
		else if (abs(dst_i - this->m_i) == 2 && abs(dst_j - this->m_j) == 0) {
			if (this->is_first_move) return true;
		}
		return false;
	}
};