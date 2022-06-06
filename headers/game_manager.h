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
    Board* board_copy;
    Board sec_board;

    RES resume;
	TURN turn;
    RenderWindow* window;
    Piece* selected;
    RectangleShape menu;
    RectangleShape reset_rect;
    Sprite reset_sp;
    Texture reset_txt;
    Text white_turn, black_turn;
    Font font;
	Manager(Board*, Board*, RenderWindow*); // fills the cells;
	void set_draw();
    void play();
    void out_put();
    void draw();
    void mouse_handler(const sf::Vector2i&);
    void select_Or_unselect_piece(int, int);
    void move(int, int);
    void update_turn_txt();
    void reset_board();
    Board* make_board_copy();
};