#include <iostream>
#include <iomanip>
double avg(const int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return double(sum) / n;
}
int* minandmax(const int* a, int n) {
    int mmin = a[0];
    int mmax = a[0];
    for (int i = 0; i < n; i++) {
        mmax = std::max(mmax, a[i]);
        mmin = std::min(mmin, a[i]);
    }
    return new int[2]{mmin, mmax};
}
int lesszero(const int* a, int n) {
    int q = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) q++;
    }
    return q;
}


int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    double first = avg(a, n);
    int* minnmax = minandmax(a, n);
    int q = lesszero(a, n);
    std::cout << std::fixed << std::setprecision(1) << first << "\n";
    std::cout << minnmax[0] << ' ' << minnmax[0] << "\n";
    std::cout << q << "\n";
    delete[] minnmax;
    delete[] a;
}
