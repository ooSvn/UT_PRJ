#include "../headers/knight.h"

Knight::Knight(int i, int j, char color, string st) {
    this->m_i = i;
    this->m_j = j;
    this->piece_color = color;
    this->state = st;
};

bool Knight::validationCheck(int dst_i, int dst_j, Board &chess) {
    if ((abs(dst_i - this->m_i) == 1 && abs(dst_j - this->m_j) == 2) ||
        (abs(dst_i - this->m_i) == 2 && abs(dst_j - this->m_j) == 1)) {
        return true;
    }
    else return false;
}