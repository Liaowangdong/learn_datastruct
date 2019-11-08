#include "./Header/vector.h"
#include<iostream>
using namespace std;

int main()
{
    Vector<int> number;
//    for(int i=0; i < 5; i++)
//    {
//        number.insert(i);
//    }
    number.insert(5);
    number.insert(2);
    number.insert(4);
    number.insert(3);
    number.insert(1);

    for(int i=0; i < 5; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
    number.sort(0, number.size());
    for(int i=0; i < 5; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
    cout << number.binSearchVc(6) << endl;
}