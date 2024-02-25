/*
Задание 2.5. Шахматы. Пользователь вводит расположение шахматной фигуры
игрока, затем вводит расположение шахматной фигуры соперника. Программа
определяет и выводит информацию о том, бьет ли фигура игрока, фигуру
соперника. Перечень фигур: ладья, слон, ферзь, конь.
*/

#include <iostream>
#include <cmath>

bool is_valid(int x) {
    return 0 < x < 9;
}


bool can_take(char* your, char* opponent, char piece) {
    int your_row, your_col;
    int opp_row, opp_col;

    your_col = your[0] - 'a' + 1;
    your_row = your[1] - '0';

    opp_col = opponent[0] - 'a' + 1;
    opp_row = opponent[1] - '0';

    // if(!is_valid(your_col))
    //     std::cout << "Coordinates are not valid\n";
    //     return false;
    // if(!is_valid(your_row))
    //     std::cout << "Coordinates are not valid\n";
    //     return false;
    // if(!is_valid(opp_col))
    //     std::cout << "Coordinates are not valid\n";
    //     return false;
    // if(!is_valid(opp_row))
    //     std::cout << "Coordinates are not valid\n";
    //     return false;


    switch (piece)
    {
    case 'R':
        if (your_col == opp_col || your_row == opp_row) {
            return true;
        }
        return false;
    case 'B':
        if (fabs(your_col - opp_col) == fabs(your_row - opp_row)) {
            return true;
        }
        return false;
    case 'Q':
        if ((your_col == opp_col || your_row == opp_row) || 
            (fabs(your_col - opp_col) == fabs(your_row - opp_row))) {
            return true;
        }
        return false;
    case 'N':
        if (fabs(your_col - opp_col) == 2 && fabs(your_row - opp_row) == 1 ||
            fabs(your_col - opp_col) == 1 && fabs(your_row - opp_row) == 2) {
            return true;
            }
        return false;
    
    default:
        std::cout << "Unknown figure\n";
        return false;
    }
}

// R - rook, B - bishop, N - knight, Q - queen

int main() {
    char* your_coordinate = new char[2];
    char* opponent_coordinate = new char[2];
    char piece;
    std::cout << "Write coordinate for your piece: ";
    std::cin >> your_coordinate;
    std::cout << "Write coordinate for your opponent's piece: ";
    std::cin >> opponent_coordinate;
    std::cout << "What piece you want to check? (R - rook, B - bishop, N - knight, Q - queen)\n";
    std::cin >> piece;
    if (can_take(your_coordinate, opponent_coordinate, piece)) {
        std::cout << "You can take your opponent's piece!\n";
    } else {
        std::cout << "You can't take your opponent's piece :(\n";
    }

    delete[] your_coordinate;
    delete[] opponent_coordinate;
    return 0;
}