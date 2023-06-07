#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
    int tc; cin >> tc;
    map<string, int> m1;
    map<string, int> m2;
    string word;
    for (int i = 0; i < tc; i++)
    {
        cin >> word;
        if (m1[word] == 0)
        {
            m1[word]++;
            cout << word << " masuk Kamus 1!" << endl;
        }
        else if (m2[word] == 0)
        {
            m2[word]++;
            cout << word << " masuk Kamus 2!" << endl;
        }
        else
        {
            cout << "aku tidak bisa masuk Kamus!" << endl;
        }
    }
    cout << "Kamus 1 berisi " << m1.size() << " kata" << endl;
    cout << "Kamus 2 berisi " << m2.size() << " kata" << endl;
    return 0;
}