#include "./Header/vector.h"
#include<iostream>
using namespace std;

int main()
{
    Vector<char> number;
    cout << number.size() << endl;
    for(int i=0; i < 8; i++)
    {
        cout << i << endl;
        cout << number.size() << endl;
        number.insert(i, 'a');
    }
}