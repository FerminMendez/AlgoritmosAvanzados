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

int linear(int m, int n, int x, int y)
{
    return y * m + x;
}

void printArray(int *arr, int n, int m)
{
    int count=0;
    cout << "Array" << endl;
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << arr[linear(m, n, i, j)] << " ";
            count++;
        }
        cout << endl;
        ;
    }
    cout<<"Count "<<count;
}

int DParray(int *arr, int m, int n, string s1, string s2)
{
    int sol = 0;
    // Inizializar el array
    for (int i = 0; i < m + 1; i++)
    {
        arr[linear(m, n, i, 0)] = 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        arr[linear(m, n, 0, i)] = 1;
    }

    return sol;
}

int main()
{
    string s1 = "I I Im got this feeling yeah you know";
    string s2 = "Ropompompom feeling, one to tri for fai";
    int m = s1.size();
    int n = s2.size();
    int size = (m + 1) * (n + 1);
    cout<<"m "<<m<<endl;
    cout<<"n "<<n<<endl;
    int *array = new int[size];
    fill(array, array + (m + 1) * (n + 1), 0);
    int index = DParray(array, m, n, s1, s2);
    printArray(array, m, n);


    delete[] array;

    return 0;
}