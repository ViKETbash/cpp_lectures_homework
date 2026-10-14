#include <iostream>
int main() {
    //Задача сводится к такому: В стране Нигстане есть казино
    // каждое казино описываеться двумерным полем, из 0 и 1, где 0
    // означает что в точке нет автомата, а 1 что есть, для хранения
    // и их типов я буду использовать void** а int*** использую для
    //массива всех двумерных полей Казика из Нигстана
    //Причем т.к. Нигстан не прям образованная страна, входные данные
    //там у всех свои, поэтому нужно использовать void*
    const int n = 3;
    int hs[n] = { 2, 3, 1 };
    int ws[n] = { 3, 2, 4 };
    int*** cs = new int**[n];
    for (int c = 0; c < n; c++) {
        cs[c] = new int*[hs[c]];
        for (int i = 0; i < hs[c]; i++) {
            cs[c][i] = new int[ws[c]];
        }
    }
    // Казино 1: 2x3
    int q0[2][3] = { {1,0,1}, {0,1,1} };
    // Казино 2: 3x2
    int q1[3][2] = { {1,1}, {0,0}, {1,0} };
    // Казино 3: 1x4
    int q2[1][4] = { {1,0,1,1} };
    for (int i = 0; i < hs[0]; i++) {
        for (int j = 0; j < ws[0]; j++) {
            cs[0][i][j] = q0[i][j];
        }
    }
    for (int i = 0; i < hs[1]; i++) {
        for (int j = 0; j < ws[1]; j++) {
            cs[1][i][j] = q1[i][j];
        }
    }
    for (int i = 0; i < hs[2]; i++) {
        for (int j = 0; j < ws[2]; j++) {
            cs[2][i][j] = q2[i][j];
        }
    }
    void** ai = new void*[n];
    int ik[n];
    ai[0] = new int(1);
    ik[0] = 0;
    char* nm = new char[20];
    nm[0] = 'a';
    nm[1] = 'b';
    ai[1] = nm;
    ik[1] = 1;
    ai[2] = new int(3);
    ik[2] = 0;
    int t = 0;
    for (int c = 0; c < n; c++) {
        int k = 0;
        for (int i = 0; i < hs[c]; i++) {
            for (int j = 0; j < ws[c]; j++) {
                if (cs[c][i][j] == 1) {
                    k++;
                }
            }
        }
        std::cout << "Казино #" << c
                  << " (" << hs[c] << "x" << ws[c] << ")"
                  << ": автоматов = " << k << ", ";
        if (ik[c] == 0) {
            int cd = *(int*)ai[c];
            std::cout << "тип-код = " << cd;
        } else {
            char b = *(char*)ai[c];
            std::cout << "имя = \"" << b << "\"";
        }
        std::cout << "\n";
        t += k;
    }
    std::cout << "Всего автоматов в Нигстане: " << t << "\n";
    //недодеструктор
    for (int c = 0; c < n; c++) {
        if (ik[c] == 0) {
            delete (int*)ai[c];
        } else {
            delete[] (char*)ai[c];
        }
        for (int i = 0; i < hs[c]; i++) {
            delete[] cs[c][i];
        }
        delete[] cs[c];
    }
    delete[] ai;
    delete[] cs;
}
