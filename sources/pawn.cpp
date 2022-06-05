#include "../headers/pawn.h"

Pawn::Pawn(int i, int j, char color, string st) {
	this->tx.loadFromFile(get_path(color, 'p'));
    this->tx.setSmooth(true);
    this->sp.setTexture(this->tx);
    this->sp.setPosition(sf::Vector2f(j*120 + 10, i*120 + 10));
    this->sp.setScale(sf::Vector2f((float)100 / (float)this->tx.getSize().x, (float)100 / this->tx.getSize().y));

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

bool Pawn::validationCheck(int dst_i, int dst_j, Board& chess) {
	if (abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 0) {
		if (this->piece_color == 'w')
			if (dst_i < this->m_i) return true;
			else return false;
		else {
			if (dst_i > this->m_i) return true;
			else return false;
		}
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
