#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Board;
class Piece {
public:
	Texture tx;
	Sprite sp;
	char piece_color;
	int m_i, m_j;
	string state;
	RectangleShape rect;
	Text win_msg;
	virtual bool validationCheck(int dst_i, int dst_j, Board &) = 0;
	string get_path(char color, char p){
		string path = "images/";
		path += color; path += p; path += ".png";
		return path;
	}
	void update_sp(){
		this->sp.setPosition(sf::Vector2f(this->m_j*120 + 10, this->m_i*120 + 10));
	}
};