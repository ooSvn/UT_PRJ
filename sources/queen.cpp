#include "../headers/queen.h"

Queen::Queen(int i, int j, char color, string st) {
	this->tx.loadFromFile(get_path(color, 'q'));
    this->tx.setSmooth(true);
    this->sp.setTexture(this->tx);
    this->sp.setPosition(sf::Vector2f(j*120 + 10, i*120 + 10));
    this->sp.setScale(sf::Vector2f((float)100 / (float)this->tx.getSize().x, (float)100 / this->tx.getSize().y));
    this->m_i = i;
    this->m_j = j;
    this->piece_color = color;
    this->state = st;
};

bool Queen::validationCheck(int dst_i, int dst_j, Board& chess) {
    if ((abs(dst_i - this->m_i) != 0 && abs(dst_j - this->m_j) == 0) ||
        (abs(dst_i - this->m_i) == 0 && abs(dst_j - this->m_j) != 0)) {
        if (dst_i == this->m_i) {
            int dir_j = (dst_j - this->m_j) / abs(dst_j - this->m_j);
            int y = this->m_j + dir_j;
            while (y != dst_j) {
                if (chess.board[dst_i][y]->piece_color != 'n') return false;
                y += dir_j;
            }
        }
        else if (dst_j == this->m_j) {
            int dir_i = (dst_i - this->m_i) / abs(dst_i - this->m_i);
            int x = this->m_i + dir_i;
            while (x != dst_i) {
                if (chess.board[x][dst_j]->piece_color != 'n') return false;
                x += dir_i;
            }
        }
        return true;
    }
    else if (abs(dst_i - this->m_i) == abs(dst_j - this->m_j)) {
        int dir_i = (dst_i - this->m_i) / abs(dst_i - this->m_i);
        int dir_j = (dst_j - this->m_j) / abs(dst_j - this->m_j);
        int x = this->m_i + dir_i, y = this->m_j + dir_j;
        while (x != dst_i) {
            if (chess.board[x][y]->piece_color != 'n') {
                return false;
            }
            x += dir_i; y += dir_j;
        }
        return true;
    }
    else return false;
}