#include "../headers/game_manager.h"

int main(){
    Board chess; string temp;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> temp;
			if (temp == "--") {
				Null* nll = new Null(i, j, "--");
				chess.board[i][j] = (Piece*)nll;
			}
			// white Pieces;
			else if (temp == "KW") {
				King* k_w = new King(i, j, 'w', "KW");
				chess.board[i][j] = (Piece*)k_w;
				chess.king_w = (Piece*)k_w;
			}
			else if (temp == "QW") {
				Queen* q_w = new Queen(i, j, 'w', "QW");
				chess.board[i][j] = (Piece*)q_w;
			}
			else if (temp == "BW") {
				Bishop* b_w = new Bishop(i, j, 'w', "BW");
				chess.board[i][j] = (Piece*)b_w;
			}
			else if (temp == "NW") {
				Knight* n_w = new Knight(i, j, 'w', "NW");
				chess.board[i][j] = (Piece*)n_w;
			}
			else if (temp == "RW") {
				Rook* r_w = new Rook(i, j, 'w', "RW");
				chess.board[i][j] = (Piece*)r_w;
			}
			else if (temp == "PW") {
				Pawn* p_w = new Pawn(i, j, 'w', "PW");
				chess.board[i][j] = p_w;
			}
			// black Pieces;
			else if (temp == "KB") {
				King* k_b = new King(i, j, 'b', "KB");
				chess.board[i][j] = (Piece*)k_b;
				chess.king_b = (Piece*)k_b;
			}
			else if (temp == "QB") {
				Queen* q_b = new Queen(i, j, 'b', "QB");
				chess.board[i][j] = (Piece*)q_b;
			}
			else if (temp == "BB") {
				Bishop* b_b = new Bishop(i, j, 'b', "BB");
				chess.board[i][j] = (Piece*)b_b;
			}
			else if (temp == "NB") {
				Knight* n_b = new Knight(i, j, 'b', "NB");
				chess.board[i][j] = (Piece*)n_b;
			}
			else if (temp == "RB") {
				Rook* r_b = new Rook(i, j, 'b', "RB");
				chess.board[i][j] = (Piece*)r_b;
			}
			else if (temp == "PB") {
				Pawn* p_b = new Pawn(i, j, 'b', "PB");
				chess.board[i][j] = (Piece*)p_b;
			}
		}
	}
	RenderWindow window(VideoMode(1080, 960), "AMD CHESS", Style::Close | Style::Titlebar);
	Manager game(&chess, &window);
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