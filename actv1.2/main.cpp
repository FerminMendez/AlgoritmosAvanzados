// =========================================================
// File: main.cpp
// Authors:
//  Fermín Méndez García - A01703366
// Date: 18/08/2022
// =========================================================

//              Entrada
// 4 Numero de monedas
// 1 16 2 13 Valores de las monedas
// 9 Numero de Casos prueba
// 74 79 67 68 35 93 72 29 85 Casos prueba

#include <iostream>
#include <vector>
using namespace std;

// g++ -std=c++11 main.cpp -o app
//   ./app < inputX.txt > mysolutionX.txt
//    diff mysolutionX.txt outputX.txt

string print(int n, int *coins, int q, vector<int> &cases)
{
    string s;
    s += "n: ";
    s += n + "\n";
    s += "Coins: ";
    for (int i = n; i >= 0; i--)
    {
        s += coins[i];
        s += " ";
    }
    s += "\n";
    s += "q: ";
    s += q + "\n";
    for (auto i : cases)
    {
        s += i;
        s += " ";
    }
    s += "\n";
    return s;
}

int main(int argc, char *argv[])
{
    int *coins;
    int n, q;
    vector<int> cases;
    cin >> n;
    coins = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
    }
    cin >> q;
    for (int i; i < q; i++)
    {
        int x;
        cin >> x;
        cases.push_back(x);
    }

    cout << print(n, coins, q, cases);
    return 0;
}