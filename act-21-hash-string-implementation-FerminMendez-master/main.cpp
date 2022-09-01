// =========================================================
// File: main.cpp
// Authors:
//  Fermín Méndez García - A01703366
// Date: 18/08/2022
// =========================================================
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;


string num_to_hex(int x,char &arr[]){
    x=x%256;
    int a=x/16;
16;    return arr[a]+arr[x%16];
}

int main()
{
  const char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    return 0;
}
