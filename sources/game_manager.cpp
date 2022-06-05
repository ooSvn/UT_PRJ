#include "../headers/game_manager.h"

Manager::Manager(Board* b, RenderWindow* window){
    this->resume = YES;
    this->turn = WHITE;
    this->board = b;
    this->window = window;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            this->board->board[i][j]->rect.setSize(sf::Vector2f(120, 120));
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
        draw();
        this->window->display();
    }
}

int index_finder(int pxl){
    if (pxl < 960)
        return int(pxl / 120);
    else return -1;
}

void Manager::mouse_handler(const sf::Vector2i& position){
    int row = index_finder(position.y), column = index_finder(position.x);
    if (row == -1 || column == -1)
        return;
    else { //if (this->board->board[row][column]->state != "--")
        //////here should be completed;
        cout << "row: " << row << " col: " << column << '\n';
    }
}


