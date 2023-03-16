#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("test.txt");
    string text;
    char lol[26];
    long double s;
    s = 1;
    fin >> text;
    char m;
    int k;

    for (size_t i = 0; i < sizeof(text); i++)
    {
        m = text[i];
        if(m == 0){
            continue;
        }
        k = m;
        s *= k;
        lol[k - 64] += 1;
    }
    
    cout << s << endl;
    cout << lol << endl;
}