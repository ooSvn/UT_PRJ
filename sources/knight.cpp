#include "../headers/knight.h"

Knight::Knight(int i, int j, char color, string st) {
	this->tx.loadFromFile(get_path(color, 'n'));
    this->tx.setSmooth(true);
    this->sp.setTexture(this->tx);
    this->sp.setPosition(sf::Vector2f(j*120 + 10, i*120 + 10));
    this->sp.setScale(sf::Vector2f((float)100 / (float)this->tx.getSize().x, (float)100 / this->tx.getSize().y));
    this->m_i = i;
    this->m_j = j;
    this->piece_color = color;
    this->state = st;
};

bool Knight::validationCheck(int dst_i, int dst_j, Board &chess) {
    if ((abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 2) ||
        (abs(dst_i - this->m_i) == 2 && abs(dst_j - this->m_j) == 1)) {
        return true;
    }
    else return false;
}