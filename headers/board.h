#pragma once
#include <iostream>
#include <vector>
#include "./piece.h"

class Board {
public:
	std::vector<std::vector<Piece*>> board;
	std::vector <Piece*> player_w;
	std::vector <Piece*> player_b;
	Piece* king_w;
	Piece* king_b;
	//vector <vector<int, Piece>> moves;
	// int last_move[4] = { 0 };
	Board();
	bool do_move(Piece*, int, int); // makes a copy of the chess board & checks if the change is valid or not;
	bool check(Piece*, std::vector<std::vector<Piece*>> v);
	bool mate(Piece*);
	void display();
};