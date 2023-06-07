#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main(){
    string n,sign, m;
    deque<string> non_vaksin, vaksin;
    while(n != '#')
        cin >> n;
    while(m != EOF)
        cin >> m;

    // cek front and back
    while(!vaksin.empty())
    {
        if(non_vaksin.front() == vaksin.front())
        {
            non_vaksin.pop_front();
            vaksin.pop_front();
        }
        else
        {
            while(non_vaksin.back() == vaksin.back())
            {
                non_vaksin.pop_back();
                vaksin.pop_back();
            }
            break;
        }   
    }

    if (vaksin.empty()) cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    else cout << "Gabisa sumpah, game ini red flag banget sih" << endl;

    return 0;
}
