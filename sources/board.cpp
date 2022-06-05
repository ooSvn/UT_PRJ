#include "../headers/board.h"
#include "../headers/null.h"

Board::Board(){
	for (int i = 0; i < 8; ++i) {
		vector<Piece*> row;
		for (int j = 0; j < 8; ++j){
			row.push_back(0);
		}
		this->board.push_back(row);
	}
}

bool Board::if_do_move(Piece* p, int dst_i, int dst_j) {
	bool ans;
	Piece* org_item = this->board[dst_i][dst_j];
	int org_i = p->m_i, org_j = p->m_j;
	
	Null* n = new Null(p->m_i, p->m_j, "--");

	if (p->piece_color == 'w') {
		if (this->board[dst_i][dst_j]->piece_color == 'b' || this->board[dst_i][dst_j]->piece_color == 'n') {
			
			this->board[dst_i][dst_j] = p;
			p->m_i = dst_i; p->m_j = dst_j;
			this->board[n->m_i][n->m_j] = n;

			if (!this->check(this->king_w, this->board)) {
				ans = true;
			}
			else {
				ans = false;
			}
		}
		else if (this->board[dst_i][dst_j]->piece_color == 'w') {
			ans = false;
		}
	}
	else if (p->piece_color == 'b') {
		if (this->board[dst_i][dst_j]->piece_color == 'w' || this->board[dst_i][dst_j]->piece_color == 'n') {
			
			this->board[dst_i][dst_j] = p;
			p->m_i = dst_i; p->m_j = dst_j;
			this->board[n->m_i][n->m_j] = n;
			
			if (!this->check(this->king_b, this->board)) {
				ans = true;
			}
			else {
				ans = false;
			}
		}
		else if (this->board[dst_i][dst_j]->piece_color == 'b') {
			ans = false;
		}
	}
	this->board[dst_i][dst_j] = org_item;
	this->board[org_i][org_j] = p;
	p->m_i = org_i; p->m_j = org_j;
	return ans;
}

bool Board::check(Piece* k, vector<vector<Piece*>> v) {
	if (k->piece_color == 'w') {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (v[i][j]->piece_color == 'b') {
					if (v[i][j]->validationCheck(k->m_i, k->m_j, *this)) return true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (v[i][j]->piece_color == 'w') {
					if (v[i][j]->validationCheck(k->m_i, k->m_j, *this)) return true;
				}
			}
		}
	}
	return false;
}

void Board::display() {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				cout << this->board[i][j]->state << " ";
			}
			cout << '\n';
		}
}

bool Board::mate(Piece* k) {
	// k_colored pieces will make any possible move and it will checked if the king is still checked or not.
	char mate_plyr = k->piece_color;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (this->board[i][j]->piece_color == mate_plyr) {
				for (int m = 0; m < 8; ++m) {
					for (int n = 0; n < 8; ++n) {
						if (this->board[i][j]->validationCheck(m, n, *this)) {
							if (this->board[m][n]->piece_color != this->board[i][j]->piece_color) {
								Null* nll = new Null(i, j, "--");
								Piece* org_item = this->board[m][n];
								this->board[m][n] = this->board[i][j];
								this->board[m][n]->m_i = m; this->board[m][n]->m_j = n;
								this->board[i][j] = (Piece*)nll;
								if (mate_plyr == 'w') {
									if (!this->check(this->king_w, this->board)) {
										this->board[i][j] = this->board[m][n];
										this->board[m][n] = org_item;
										this->board[i][j]->m_i = i;	this->board[i][j]->m_j = j;
										return false;
									}
								}
								else {
									if (!this->check(this->king_b, this->board)) {
										this->board[i][j] = this->board[m][n];
										this->board[m][n] = org_item;
										this->board[i][j]->m_i = i;	this->board[i][j]->m_j = j;
										return false;
									}
								}
								this->board[i][j] = this->board[m][n];
								this->board[m][n] = org_item;
								this->board[i][j]->m_i = i;	this->board[i][j]->m_j = j;
							}
						}
					}
				}
			}
		}
	}
	std::cout << "here giving false" << '\n';
	return true;
}

void Board::do_move(Piece* p, int dst_i, int dst_j){
	Null* n = new Null(p->m_i, p->m_j, "--");
	this->board[dst_i][dst_j] = p;
	p->m_i = dst_i; p->m_j = dst_j;
	this->board[n->m_i][n->m_j] = n;
}