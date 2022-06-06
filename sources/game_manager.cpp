#include "../headers/game_manager.h"

Manager::Manager(Board* b, Board* b_c, RenderWindow* window){
    this->resume = YES;
    this->turn = WHITE;
    this->board = b;
    this->board_copy = b_c;
    this->window = window;
    this->window->setFramerateLimit(60);
    this->selected = 0;
    this->font.loadFromFile("font/KaushanScript-Regular.otf");
    this->menu.setFillColor(sf::Color(102, 178, 255));
    this->reset_txt.loadFromFile("images/reset.png");
    this->reset_txt.setSmooth(true);
    this->reset_sp.setScale(Vector2f(0.8, 0.8));
    this->reset_sp.setTexture(reset_txt);
    this->reset_sp.setPosition(Vector2f(970, 430));

    this->white_turn.setString("WHITE");
    this->black_turn.setString("BLACK");
    set_draw();
}

void Manager::set_draw(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->board->board[i][j]->rect.setSize(sf::Vector2f(120, 120));
            if (this->selected == 0){
                if (this->board->check(this->board->king_b, this->board->board)){
                    this->board->board[this->board->king_b->m_i][this->board->king_b->m_j]->rect.setFillColor(sf::Color(255, 0, 0));
                }
                else if (this->board->check(this->board->king_w, this->board->board)){
                    this->board->board[this->board->king_w->m_i][this->board->king_w->m_j]->rect.setFillColor(sf::Color(255, 0, 0));
                }
                if (i % 2 == 0){
                    if (j % 2 == 0){
                        this->board->board[i][j]->rect.setFillColor(sf::Color(255, 200, 255));
                    }
                    else {
                        this->board->board[i][j]->rect.setFillColor(sf::Color(35, 10, 75));
                    }
                }
                else {
                    if (j % 2 == 0){
                        this->board->board[i][j]->rect.setFillColor(sf::Color(35, 10, 75));
                    }
                    else{
                        this->board->board[i][j]->rect.setFillColor(sf::Color(255, 200, 255));
                    }
                }
            }
            else {
                if (this->selected->m_i == i && this->selected->m_j == j){
                    this->board->board[i][j]->rect.setFillColor(sf::Color(255, 255, 153));
                }
                else if (this->selected->validationCheck(i, j, *this->board))
                    if (this->board->if_do_move(this->selected, i, j)){
                        if ((this->board->board[i][j]->piece_color == 'w' && this->selected->piece_color == 'b') ||
                            (this->board->board[i][j]->piece_color == 'b' && this->selected->piece_color == 'w')){
                            this->board->board[i][j]->rect.setFillColor(sf::Color(255, 153, 51));
                        }
                        else this->board->board[i][j]->rect.setFillColor(sf::Color(0, 255, 128));
                }
            }
            this->board->board[i][j]->rect.setPosition(sf::Vector2f(j*120, i*120));
        }
    }
    this->reset_rect.setSize(sf::Vector2f(120, 120));
    this->reset_rect.setFillColor(sf::Color(201, 246, 176));
    this->reset_rect.setOutlineThickness(-5);
    this->reset_rect.setOutlineColor(sf::Color(97, 124, 84));
    this->reset_rect.setPosition(sf::Vector2f(960, 420));
    update_turn_txt();
}

void Manager::update_turn_txt(){
    if (this->turn == WHITE){
        this->white_turn.setFont(font); this->black_turn.setFont(font);
        this->white_turn.setCharacterSize(30); this->black_turn.setCharacterSize(20);
        this->white_turn.setStyle(sf::Text::Regular); this->black_turn.setStyle(sf::Text::Regular);
        this->white_turn.setFillColor(sf::Color::Red); this->black_turn.setFillColor(sf::Color::White);
        this->white_turn.setPosition(Vector2f(970, 700)); this->black_turn.setPosition(Vector2f(970, 220));
    }
    else {
        this->white_turn.setFont(font); this->black_turn.setFont(font);
        this->white_turn.setCharacterSize(20); this->black_turn.setCharacterSize(30);
        this->white_turn.setStyle(sf::Text::Regular); this->black_turn.setStyle(sf::Text::Regular);
        this->white_turn.setFillColor(sf::Color::White); this->black_turn.setFillColor(sf::Color::Red);
        this->white_turn.setPosition(Vector2f(970, 700)); this->black_turn.setPosition(Vector2f(970, 220));
    }
}

void Manager::draw(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->board->board[i][j]->rect.setOutlineThickness(-1);
            this->board->board[i][j]->rect.setOutlineColor(sf::Color::Red);
            this->window->draw(this->board->board[i][j]->rect);
        }
    }
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->board->board[i][j]->update_sp();
            this->window->draw(this->board->board[i][j]->sp);
        }
    }
    this->window->draw(this->white_turn);
    this->window->draw(this->black_turn);
    this->window->draw(reset_rect);
    this->window->draw(reset_sp);
}

void Manager::play(){
    this->window->display();
    while (this->window->isOpen()){
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
            if (resume == YES && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mouse_handler(Mouse::getPosition(*(this->window)));
            }
        }
        this->window->clear(sf::Color(0, 0, 0));
        set_draw();
        draw();
        this->window->display();
    }
}

void Manager::mouse_handler(const sf::Vector2i& position){
    int row, column;
    if (position.y < 960)
        row = int(position.y / 120);
    else row = -1;

    if (position.x < 960)
        column = int(position.x / 120);
    else column = -1;
    
    if (position.y < 540 && position.y > 420 && position.x < 1080 && position.x > 960){
        reset_board();
    }
    else if (row == -1 || column == -1)
        return;
    else {
        select_Or_unselect_piece(row, column);
    }
}

void Manager::select_Or_unselect_piece(int row, int column){
    if (this->selected == 0){
        if ((board->board[row][column]->piece_color == 'w' && this->turn == WHITE) ||
        (board->board[row][column]->piece_color == 'b' && this->turn == BLACK))
            this->selected = board->board[row][column]; //selection
    }
    else if (this->selected->m_i == row && this->selected->m_j == column){
        this->selected = 0; // unselection
    }
    else { // when some piece is selected and another cell is clicked in order to move that selected p
        if (this->selected->validationCheck(row, column, *this->board) &&
            this->board->if_do_move(this->selected, row, column)){
            move(row, column);
            this->selected = 0;
            if (this->turn == WHITE)
                this->turn = BLACK;
            else this->turn = WHITE;
            this->board->display();
            }
    }
}

void Manager::move(int row, int column){
    this->board->do_move(this->selected, row, column);
}

void Manager::reset_board(){
    this->resume = YES;
    this->turn = WHITE;
    this->selected = 0;
    this->board = (this->make_board_copy());
    set_draw();
}

Board* Manager::make_board_copy(){
	for (int i = 0; i < 8; ++i){
		for (int j = 0;j < 8; ++j){
			if (this->board_copy->board[i][j]->state == "--") {
				Null* nll = new Null(i, j, "--");
				sec_board.board[i][j] = (Piece*)nll;
			}
			// white Pieces;
			else if (this->board_copy->board[i][j]->state == "KW") {
				King* k_w = new King(i, j, 'w', "KW");
				sec_board.board[i][j] = (Piece*)k_w;
				sec_board.king_w = (Piece*)k_w;
			}
			else if (this->board_copy->board[i][j]->state == "QW") {
				Queen* q_w = new Queen(i, j, 'w', "QW");
				sec_board.board[i][j] = (Piece*)q_w;
			}
			else if (this->board_copy->board[i][j]->state == "BW") {
				Bishop* b_w = new Bishop(i, j, 'w', "BW");
				sec_board.board[i][j] = (Piece*)b_w;
			}
			else if (this->board_copy->board[i][j]->state == "NW") {
				Knight* n_w = new Knight(i, j, 'w', "NW");
				sec_board.board[i][j] = (Piece*)n_w;
			}
			else if (this->board_copy->board[i][j]->state == "RW") {
				Rook* r_w = new Rook(i, j, 'w', "RW");
				sec_board.board[i][j] = (Piece*)r_w;
			}
			else if (this->board_copy->board[i][j]->state == "PW") {
				Pawn* p_w = new Pawn(i, j, 'w', "PW");
				sec_board.board[i][j] = p_w;
			}
			// black Pieces;
			else if (this->board_copy->board[i][j]->state == "KB") {
				King* k_b = new King(i, j, 'b', "KB");
				sec_board.board[i][j] = (Piece*)k_b;
				sec_board.king_b = (Piece*)k_b;
			}
			else if (this->board_copy->board[i][j]->state == "QB") {
				Queen* q_b = new Queen(i, j, 'b', "QB");
				sec_board.board[i][j] = (Piece*)q_b;
			}
			else if (this->board_copy->board[i][j]->state == "BB") {
				Bishop* b_b = new Bishop(i, j, 'b', "BB");
				sec_board.board[i][j] = (Piece*)b_b;
			}
			else if (this->board_copy->board[i][j]->state == "NB") {
				Knight* n_b = new Knight(i, j, 'b', "NB");
				sec_board.board[i][j] = (Piece*)n_b;
			}
			else if (this->board_copy->board[i][j]->state == "RB") {
				Rook* r_b = new Rook(i, j, 'b', "RB");
				sec_board.board[i][j] = (Piece*)r_b;
			}
			else if (this->board_copy->board[i][j]->state == "PB") {
				Pawn* p_b = new Pawn(i, j, 'b', "PB");
				sec_board.board[i][j] = (Piece*)p_b;
			}
		}
	}
	return &sec_board;
}