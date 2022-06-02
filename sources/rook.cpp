#include "../headers/rook.h"

Rook::Rook(int i, int j, char color, string st) {
    this->m_i = i;
    this->m_j = j;
    this->piece_color = color;
    this->state = st;
};

bool Rook::validationCheck(int dst_i, int dst_j, Board& chess) {
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
    else return false;
}