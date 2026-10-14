#include <iostream>

int deposit(int &sum, int k) {
    if (k <= 0) {
        return 0;
    }
    sum += k;
    return 1;
}
int withdraw(int &sum, int k) {
    if (k <= 0 || sum < k) {
        return 0;
    }
    sum -= k;
    return 1;
}
int balance(int &sum, int k) {
    std::cout << sum << '\n';
    return 1;
}
int reset(int &sum, int k) {
    sum = 0;
    return 1;
}
int db(int &sum, int k) {
    sum *= 2;
    return 1;
}

int check(char* a, char* b) {
    int i = 0;
    while (a[i] != '\n' && b[i] != '\n') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return a[i] == b[i];
}

int main() {
    const int len_c = 5;
    char input[len_c][10] = {
        "deposit\n",
        "withdraw\n",
        "balance\n",
        "reset\n",
        "db\n"
    };
    int (*functions[len_c])(int&, int) = {
        &deposit, &withdraw, &balance, &reset, &db
    };
    char stop[6] = "stop\n";
    const int cmax = 10000;
    int sum = 0;
    while (true) {
        char cmd[cmax];
        int ln = 0;
        char c;
        while (std::cin.get(c) && c != '\n') {
            if (ln < cmax - 1) {
                cmd[ln++] = c;
            } else {
                while (std::cin.get(c) && c != '\n') {}
                break;
            }
        }
        if (!std::cin) {
            break;
        }
        cmd[ln] = '\n';
        cmd[ln + 1] = '\0';
        if (check(stop, cmd)) {
            break;
        }
        int pos = 0;
        while (cmd[pos] != ' ' && cmd[pos] != '\n') {
            pos++;
        }
        char command[10];
        int j = 0;
        if (pos >= 9) {
            command[0] = '\0';
        } else {
            while (j < pos) {
                command[j] = cmd[j];
                j++;
            }
            command[j] = '\n';
            command[j + 1] = '\0';
        }
        int k = 0;
        if (cmd[pos] == ' ') {
            int p = pos + 1;

            while (cmd[p] == ' ') {
                p++;
            }
            while (cmd[p] >= '0' && cmd[p] <= '9') {
                k = k * 10 + (cmd[p] - '0');
                p++;
            }
        }
        int f = 0;
        for (int i = 0; i < len_c; i++) {
            if (check(input[i], command)) {
                f = functions[i](sum, k);
                break;
            }
        }
        if (f == 0) {
            std::cout << "error\n";
        }
    }
}
