// =========================================================
// File: main.cpp
// Authors:
//  Fermín Méndez García - A01703366
//  Ricardo Núñez Alánis - A01703259
// Date: 18/08/2022
// =========================================================

//              Entrada
// 4 Numero de monedas
// 1 16 2 13 Valores de las monedas
// 9 Numero de Casos prueba
// 74 79 67 68 35 93 72 29 85 Casos prueba

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <string>

using namespace std;

string greddyCoins(vector<int> coins, int target)
{
    string s;
    string aux = "GREEDY SOLUTION, TOTAL COINS = ";
    int sol = 0;
    int i = coins.size() - 1;
    int count = 0;
    while (i >= 0)
    {
        if (coins[i] <= target)
        {
            target -= coins[i];
            sol++;
            count++;
        }
        else
        {
            if (count)
            {
                s = "CURRENCY = " + to_string(coins[i]) + " AMOUNT = " + to_string(count) + "\n" + s;
            }
            i--;
            count = 0;
        }
    }
    aux += to_string(sol) + "\n";
    return {aux + s};
}

// Aqui empieza la sol de DP
// Se genera el memozation para el mayor caso que tendremos. Aqui estan los resultado.
void DParray(int *arr, int max, vector<int> coins)
{
    for (auto it : coins)
    {
        for (int i = 0; i <= max; i++)
        {
            if (i == it)
            {

                arr[i] = 1;
            }

            else if (i > it)
            {
                if (arr[i - it] != INT_MAX)
                {
                    arr[i] = min(1 + arr[i - it], arr[i]);
                }
            }
        }
    }
}

string sol_dp(int *array, int target, vector<int> coins)
{
    int steps = array[target];
    string result = "DP SOLUTION, TOTAL COINS = " + to_string(steps) + "\n";

    map<int, int> mymap;
    while (steps > 0)
    {
        for (auto it : coins)
        {
            if (target == it)
            {
                mymap[it]++;
                steps--;
                target -= it;
                break;
            }
            else if (array[target - it] == steps - 1)
            {
                mymap[it]++;
                steps--;
                target -= it;
                break;
            }
        }
    }

    for (auto i = mymap.begin(); i != mymap.end(); i++)
    {
        result += "CURRENCY = " + to_string(i->first) + " AMOUNT = " + to_string(i->second) + "\n";
    }

    return result;
}

// g++ -std=c++11 main.cpp -o app
//   ./app < inputX.txt > mysolutionX.txt
//    diff mysolutionX.txt outputX.txt

// Función auxiliar que regresa el máximo valor en un vector no vacio
int max_vec(vector<int> vec)
{
    int sol = vec[0];
    for (auto it : vec)
    {
        sol = max(it, sol);
    }
    return sol;
}

int main(int argc, char *argv[])
{
    for (int k = 0; k < argc; k++)
    {

        const int LINE_TO_FIND_COINS = 2;
        const int LINE_TO_FIND_CASES = 4;
        int n;
        /// cin >> n;

        string fileName;

        // cout << "Enter file name : \n";
        // cin >> fileName;

        fileName = argv[k];

        string coinsLine;
        ifstream f(fileName);
        for (int i = 0; i < LINE_TO_FIND_COINS; i++)
        {
            getline(f, coinsLine);
        }

        f.close();

        string casesLine;
        ifstream f2(fileName);
        for (int i = 0; i < LINE_TO_FIND_CASES; i++)
        {
            getline(f2, casesLine);
        }

        f2.close();

        stringstream ssCoins(coinsLine);
        int intCoins;
        vector<int> coins;

        while (ssCoins >> intCoins)
        {
            coins.push_back(intCoins);
        }

        stringstream ssCases(casesLine);
        int intCases;
        vector<int> cases;

        while (ssCases >> intCases)
        {
            cases.push_back(intCases);
        }

        sort(coins.begin(), coins.end());

        /*for(int elem: cases){
            cout<< elem<< endl;
        }
        return 0;*/

        // De alguna manera llenar el vector con lo valores de las monedas
        // vector<int> coins = {1, 2, 13, 16};
        // LLenar los casos de prueba en un vector
        // vector<int> cases = {74, 79, 67, 68, 35, 93, 72, 29, 85};

        int max = max_vec(cases); // Valor mas grande de cases
        // Generamos el array de soluciones para DP
        int *array = new int[max + 1];
        fill(array, array + max + 1, INT_MAX);
        DParray(array, max, coins);

        string outputfile;
        // Imprime los casos
        int i = 1;
        for (auto it : cases)
        {
            outputfile += "QUERY #" + to_string(i) + ", CHANGE = " + to_string(it) + "\n";
            outputfile += greddyCoins(coins, it) + "\n";
            outputfile += sol_dp(array, it, coins) + "\n";
            outputfile += "---------\n";
            i++;
        }

        cout << outputfile;

        ofstream solution;
        cout << fileName << endl;
        cout << fileName[5];
        string files;
        files = fileName[5];

        solution.open("mysolution" + files + ".txt");
        solution << outputfile;
        solution.close();

        delete[] array;
    }
    return 0;
}
