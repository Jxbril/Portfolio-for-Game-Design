#include "ttt_functions.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

//VARIABLES
std::vector<int>v;
std::vector<std::vector<char>>set_pos;

//METHODS

//grid position
void gridPosition() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "|" << ((i * 3) + j + 1) << "|";
        }
        std::cout << "\n";
    }
}

//User Input & space check
void userInput(int pos, char u) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    set_pos[row][col] = u;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "|" << set_pos[i][j] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}

int spaceChk(int ck) {
    if (v.size() > 0) {
        for (int i = 0; i < 100; i++) {
            std::vector<int>::iterator it;
            it = std::find(v.begin(), v.end(), ck);
            if (it != v.end()) {
                std::cout << "\nPlayer already enter value at " << ck << " position please enter another value\n";
                std::cin >> ck;
            }
            else {
                v.push_back(ck);
                return ck;
                break;
            }
        }
    }
    else {
        v.push_back(ck);
        return ck;
    }
}

//Board Reset
void resetGrid() {
    for (int i = 0; i < 3; i++) {
        std::vector<char>temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back('_');
        }
        set_pos.push_back(temp);
    }
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            std::cout << "|" << set_pos[k][l] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}


//Win check & conditions based on position (if statements)

  //Horizontal
bool winChk() {
    if (((set_pos[0][0] == set_pos[1][0]) && (set_pos[1][0] == set_pos[2][0])) && (set_pos[0][0] != '_')) {
        if (set_pos[0][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    if (((set_pos[0][1] == set_pos[1][1]) && (set_pos[1][1] == set_pos[2][1])) && (set_pos[0][1] != '_')) {
        if (set_pos[0][1] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    if (((set_pos[0][2] == set_pos[1][2]) && (set_pos[1][2] == set_pos[2][2])) && (set_pos[0][2] != '_')) {
        if (set_pos[0][2] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    //Vertical
    if (((set_pos[0][0] == set_pos[0][1]) && (set_pos[0][1] == set_pos[0][2])) && (set_pos[0][0] != '_')) {
        if (set_pos[0][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    if (((set_pos[1][0] == set_pos[1][1]) && (set_pos[1][1] == set_pos[1][2])) && (set_pos[1][0] != '_')) {
        if (set_pos[1][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    if (((set_pos[2][0] == set_pos[2][1]) && (set_pos[2][1] == set_pos[2][2])) && (set_pos[2][0] != '_')) {
        if (set_pos[2][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    //Diagonal Win Condition
    if (((set_pos[0][0] == set_pos[1][1]) && (set_pos[1][1] == set_pos[2][2])) && (set_pos[0][0] != '_')) {
        if (set_pos[0][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }

    if (((set_pos[2][0] == set_pos[1][1]) && (set_pos[1][1] == set_pos[0][2])) && (set_pos[2][0] != '_')) {
        if (set_pos[2][0] == 'x') {
            std::cout << "\nPlayer 1 wins!\n";
            return true;
        }
        else {
            std::cout << "\nPlayer 2 wins!\n";
            return true;
        }
    }
}

