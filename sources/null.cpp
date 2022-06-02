#include <iostream>
#include "../headers/piece.h"
#include "../headers/null.h"
using namespace std;

Null::Null(int i, int j, string st) {
    this->m_i = i;
    this->m_j = j;
    this->state = st;
    this->piece_color = 'n';
}

bool Null::validationCheck(int dst_i, int dst_j, Board& chess) {
    return false;
}