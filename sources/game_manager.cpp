#include "../headers/game_manager.h"

Manager::Manager(Board* b, RenderWindow* window){
    this->resume = YES;
    this->turn = WHITE;
    this->board = b;
    this->window = window;
    this->selected = 0;
    set_draw();
}

void Manager::set_draw(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->board->board[i][j]->rect.setSize(sf::Vector2f(120, 120));
            if (this->selected == 0){
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
                    board->board[i][j]->rect.setFillColor(sf::Color(255, 255, 51));
                }
                else if (this->selected->validationCheck(i, j, *this->board)){
                    if (this->selected->piece_color == 'w'){
                        if (board->board[i][j]->piece_color != 'w')
                            board->board[i][j]->rect.setFillColor(sf::Color(0, 255, 128));
                    }
                    else if (this->selected->piece_color == 'w'){
                        if (board->board[i][j]->piece_color != 'w')
                            board->board[i][j]->rect.setFillColor(sf::Color(0, 255, 128));
                    }
                }
            }
            this->board->board[i][j]->rect.setPosition(sf::Vector2f(j*120, i*120));
        }
    }
}

void Manager::draw(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->window->draw(board->board[i][j]->rect);
        }
    }
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->window->draw(board->board[i][j]->sp);
        }
    }
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
        this->window->clear(sf::Color(150, 150, 150));
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
    
    if (row == -1 || column == -1)
        return;
    else if (this->board->board[row][column]->state != "--") {
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
}


