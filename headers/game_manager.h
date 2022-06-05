#pragma once
#include "../headers/king.h"
#include "../headers/queen.h"
#include "../headers/knight.h"
#include "../headers/bishop.h"
#include "../headers/rook.h"
#include "../headers/pawn.h"

enum TURN {
	WHITE,
	BLACK
};

enum RES {
    YES,
    NO
};

class Manager {
public:
    Board* board;
    RES resume;
	TURN turn;
    RenderWindow* window;
	Manager(Board* b, RenderWindow* window); // fills the cells;
	void play();
    void out_put();
    void draw();
    void mouse_handler(const sf::Vector2i& position);
    // int index_finder(int pxl);
};