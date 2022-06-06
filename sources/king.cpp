#include "../headers/king.h"

King::King(int i, int j, char color, string st) {
	this->m_i = i;
	this->m_j = j;
	this->piece_color = color;
	this->state = st;
	this->tx.loadFromFile(get_path(color, 'k'));
    this->tx.setSmooth(true);
    this->sp.setTexture(this->tx);
    this->sp.setPosition(sf::Vector2f(this->m_i*120 + 10, this->m_j*120 + 10));
    this->sp.setScale(sf::Vector2f((float)100 / (float)this->tx.getSize().x, (float)100 / this->tx.getSize().y));
	if (this->piece_color == 'w')
		this->win_msg.setString("White WINS!");
	else
		this->win_msg.setString("Black WINS!");
	this->win_msg.setCharacterSize(50);
	this->win_msg.setStyle(sf::Text::Regular);
	this->win_msg.setFillColor(sf::Color::Green);
	this->win_msg.setPosition(Vector2f(420, 480));
};

bool King::validationCheck(int dst_i, int dst_j, Board& chess) {
	if ((abs(dst_i - this->m_i) == 0 && abs(dst_j - this->m_j) == 1) ||
		(abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 0) ||
		(abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 1)) {
		return true;
	}
	return false;
}

