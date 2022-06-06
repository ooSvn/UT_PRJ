#include "../headers/bishop.h"

Bishop::Bishop(int i, int j, char color, string st) {
	this->tx.loadFromFile(get_path(color, 'b'));
    this->tx.setSmooth(true);
    // cout << this->tx.getSize().x << '\n';
    this->sp.setTexture(this->tx);
    this->sp.setPosition(sf::Vector2f(j*120 + 10, i*120 + 10));
    this->sp.setScale(sf::Vector2f((float)100 / (float)this->tx.getSize().x, (float)100 / this->tx.getSize().y));
    this->m_i = i;
    this->m_j = j;
    this->piece_color = color;
    this->state = st;
};

bool Bishop::validationCheck(int dst_i, int dst_j, Board& chess) {
    if (abs(dst_i - this->m_i) == abs(dst_j - this->m_j)) {
        int dir_i = (dst_i - this->m_i) / abs(dst_i - this->m_i);
        int dir_j = (dst_j - this->m_j) / abs(dst_j - this->m_j);
        int x = this->m_i + dir_i, y = this->m_j + dir_j;
        while (x != dst_i) {
            if (chess.board[x][y]->piece_color != 'n') return false;
            x += dir_i; y += dir_j;
        }
        return true;
    }
    return false;
}