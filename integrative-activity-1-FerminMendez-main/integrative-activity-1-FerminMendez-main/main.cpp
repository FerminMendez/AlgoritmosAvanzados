// =========================================================
// File: main.cpp
// Authors:
//  Fermín Méndez García - A01703366
//  Ricardo Núñez Alánis - A01703259
// Date: 18/08/2022
// =========================================================

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

int linear(int m, int x, int y)
{
    return y * (m + 1) + x;
}

void printArray(int *arr, int m, int n)
{
    cout << "Array" << endl;
    for (int j = 0; j < n + 1; j++)
    {
        for (int i = 0; i < m + 1; i++)
        {
            // arr[linear(m, i, j)]=linear(m, i, j);
            cout << arr[linear(m, i, j)] << " ";
        }
        cout << endl;
        ;
    }
}

int DParray(int *arr, int m, int n, string s1, string s2)
{
    int sol = 0;
    // Inizializar el array
    for (int i = 0; i < m + 1; i++)
    {
        arr[linear(m, i, 0)] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        arr[linear(m, 0, i)] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int x = arr[linear(m, i - 1, j - 1)] + 1;
                arr[linear(m, i, j)] = x;
                if (x > arr[sol])
                {
                    sol = linear(m, i, j);
                }
            }
            else{
                  arr[linear(m, i, j)] = 0;
            }
        }
    }

    return sol;
}

string longestSubstring(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int size = (m + 1) * (n + 1);
    cout << "m " << m << endl;
    cout << "n " << n << endl;
    int *array = new int[size];
    //fill(array, array + (m + 1) * (n + 1), 0);
    int index = DParray(array, m, n, s1, s2);

    string longsubs;
    while (array[index] != 0)
    {
        longsubs = s1[index % (m + 1)] + longsubs;
        index = index - 2 - m;
    }
    //printArray(array, m, n);

    delete[] array;
    return longsubs;
}

int main()
{
    string s1 = "I I Im got this feeling yeah you know";
    string s2 = "Ropompompom feeling";

    cout << "Longest Substring" << endl;
    cout << longestSubstring(s1, s2) << endl;
    return 0;
}