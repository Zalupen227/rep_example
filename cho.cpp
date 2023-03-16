#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("test.txt");
    string text;
    long double s;
    s = 1;
    fin >> text;
    int m;
    for (int i = 0; i < sizeof(text); i++)
    {
        m = text[i];
        if (m == 0)
        {
            continue;
        }
        
        s *= m;
    }
    cout << s;
}