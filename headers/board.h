#pragma once
#include "./piece.h"
#include "./null.h"
#include "../headers/king.h"
#include "../headers/queen.h"
#include "../headers/knight.h"
#include "../headers/bishop.h"
#include "../headers/rook.h"
#include "../headers/pawn.h"

class Board {
public:
	vector<vector<Piece*>> board;
	Piece* king_w;
	Piece* king_b;
	Board();
	bool if_do_move(Piece*, int, int); // makes a copy of the chess board & checks if the change is valid or not;
	void do_move(Piece*, int, int);
	bool check(Piece*, std::vector<std::vector<Piece*>>);
	bool mate(Piece*);
	void display();
};