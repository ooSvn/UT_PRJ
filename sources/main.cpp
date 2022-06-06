#include "../headers/game_manager.h"

int main(){
    Board chess1, chess2; string temp;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> temp;
			if (temp == "--") {
				Null* nll = new Null(i, j, "--");
				chess1.board[i][j] = (Piece*)nll;
				Null* nll_c = new Null(i, j, "--");
				chess2.board[i][j] = (Piece*)nll_c;
			}
			// white Pieces;
			else if (temp == "KW") {
				King* k_w = new King(i, j, 'w', "KW");
				chess1.board[i][j] = (Piece*)k_w;
				chess1.king_w = (Piece*)k_w;
				King* k_w_c = new King(i, j, 'w', "KW");
				chess2.board[i][j] = (Piece*)k_w_c;
				chess2.king_w = (Piece*)k_w_c;
			}
			else if (temp == "QW") {
				Queen* q_w = new Queen(i, j, 'w', "QW");
				chess1.board[i][j] = (Piece*)q_w;
				Queen* q_w_c = new Queen(i, j, 'w', "QW");
				chess2.board[i][j] = (Piece*)q_w_c;
			}
			else if (temp == "BW") {
				Bishop* b_w = new Bishop(i, j, 'w', "BW");
				chess1.board[i][j] = (Piece*)b_w;
				Bishop* b_w_c = new Bishop(i, j, 'w', "BW");
				chess2.board[i][j] = (Piece*)b_w_c;
			}
			else if (temp == "NW") {
				Knight* n_w = new Knight(i, j, 'w', "NW");
				chess1.board[i][j] = (Piece*)n_w;
				Knight* n_w_c = new Knight(i, j, 'w', "NW");
				chess2.board[i][j] = (Piece*)n_w_c;
			}
			else if (temp == "RW") {
				Rook* r_w = new Rook(i, j, 'w', "RW");
				chess1.board[i][j] = (Piece*)r_w;
				Rook* r_w_c = new Rook(i, j, 'w', "RW");
				chess2.board[i][j] = (Piece*)r_w_c;
			}
			else if (temp == "PW") {
				Pawn* p_w = new Pawn(i, j, 'w', "PW");
				chess1.board[i][j] = p_w;
				Pawn* p_w_c = new Pawn(i, j, 'w', "PW");
				chess2.board[i][j] = p_w_c;
			}
			// black Pieces;
			else if (temp == "KB") {
				King* k_b = new King(i, j, 'b', "KB");
				chess1.board[i][j] = (Piece*)k_b;
				chess1.king_b = (Piece*)k_b;
				King* k_b_c = new King(i, j, 'b', "KB");
				chess2.board[i][j] = (Piece*)k_b_c;
				chess2.king_b = (Piece*)k_b_c;
			}
			else if (temp == "QB") {
				Queen* q_b = new Queen(i, j, 'b', "QB");
				chess1.board[i][j] = (Piece*)q_b;
				Queen* q_b_c = new Queen(i, j, 'b', "QB");
				chess2.board[i][j] = (Piece*)q_b_c;
			}
			else if (temp == "BB") {
				Bishop* b_b = new Bishop(i, j, 'b', "BB");
				chess1.board[i][j] = (Piece*)b_b;
				Bishop* b_b_c = new Bishop(i, j, 'b', "BB");
				chess2.board[i][j] = (Piece*)b_b_c;
			}
			else if (temp == "NB") {
				Knight* n_b = new Knight(i, j, 'b', "NB");
				chess1.board[i][j] = (Piece*)n_b;
				Knight* n_b_c = new Knight(i, j, 'b', "NB");
				chess2.board[i][j] = (Piece*)n_b_c;
			}
			else if (temp == "RB") {
				Rook* r_b = new Rook(i, j, 'b', "RB");
				chess1.board[i][j] = (Piece*)r_b;
				Rook* r_b_c = new Rook(i, j, 'b', "RB");
				chess2.board[i][j] = (Piece*)r_b_c;
			}
			else if (temp == "PB") {
				Pawn* p_b = new Pawn(i, j, 'b', "PB");
				chess1.board[i][j] = (Piece*)p_b;
				Pawn* p_b_c = new Pawn(i, j, 'b', "PB");
				chess2.board[i][j] = (Piece*)p_b_c;
			}
		}
	}
	RenderWindow window(VideoMode(1080, 960), "AMD CHESS", Style::Close | Style::Titlebar);
	Manager game(&chess1, &chess2, &window);
	game.play();
    return 0;
}

// win messages should be generated(check_mate checking)
// turn expressing
// reset button with it's back process

// RB NB BB QB KB BB NB RB
// PB PB PB PB PB PB PB PB
// -- -- -- -- -- -- -- --
// -- -- -- -- -- -- -- --
// -- -- -- -- -- -- -- --
// -- -- -- -- -- -- -- --
// PW PW PW PW PW PW PW PW
// RW NW BW QW KW BW NW RW