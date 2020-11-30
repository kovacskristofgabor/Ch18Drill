#include <iostream>
#include <stdexcept>

// globális int array deklarálása
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int ai[], int n)
{
    int la[10] = { };
    for (int i = 0; i < n; ++i) la[i] = ai[i];

    std::cout << "Lokális másolat\n";
    for (const auto& a : la)
        std::cout << a << ' ';
    std::cout << '\n';

    int* p = new int[n];
    for (int i = 0; i < n; ++i) p[i] = ai[i];
    
    std::cout << "Free store-ra mutató pointer\n";
    for (int i = 0; i < n; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';

    delete[] p;
}

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int main()
try {

    std::cout << "Bináris array\n";
    f(ga, 10);

    int aa[10] = {};
    for (int i = 0; i < 10; ++i)
        aa[i] = fac(i + 1);

    std::cout << "Faktoriális array\n";
    f(aa, 10);
}
catch(std::exception& e) {
    std::cerr << "Kivétel: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Ismeretlen kivétel\n";
    return 2;
}