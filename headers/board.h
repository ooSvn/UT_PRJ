#pragma once
#include "./piece.h"
#include "./null.h"

class Board {
public:
	vector<vector<Piece*>> board;
	vector <Piece*> player_w;
	vector <Piece*> player_b;
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