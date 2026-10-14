#include <iostream>
bool text(char (&table)[5][10], int x, int y, char word[]) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }
    if (y < 0 || y >= 5 || x < 0 || x + len > 10) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        table[y][x + i] = word[i];
    }
    return true;
}
void clear(char (&table)[5][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = ' ';
        }
    }
}
bool put(char (&table)[5][10], int x, int y, char c) {
    if (x < 0 || x >= 10 || y < 0 || y >= 5) {
        return false;
    }
    table[y][x] = c;
    return true;
}
void print(char (&board)[5][10]) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 10; x++) {
            std::cout << board[y][x];
        }
        std::cout << '\n';
    }
}
int main() {
    char table[5][10];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = ' ';
        }
    }
    while (true) {
        char a, b, c;
        std::cin >> a >> b >> c;
        if (a == 'q' && b == 'u') {
            std::cin >> c;
            break;
        } else if (a == 'c' && b == 'l') {
            std::cin >> c;
            std::cin >> c;
            clear(table);
        } else if (a == 'p' && b == 'u') {
            int x, y;
            std::cin >> x >> y >> c;
            if (!put(table, x, y, c)) {
                std::cout << "error\n";
            }
        } else if (a == 'p' && b == 'r') {
            std::cin >> c;
            std::cin >> c;
            print(table);
        } else {
            std::cin >> c;
            int x, y;
            char word[1000];
            std::cin >> x >> y >> word;
            if (!text(table, x, y, word)) {
                std::cout << "error\n";
            }
        }
    }
}
