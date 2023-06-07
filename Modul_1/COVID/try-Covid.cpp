#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main()
{
    string n,sign, m;
    deque<string> non_vaksin, vaksin;
    getline(cin, n);
    getline(cin, sign);
    getline(cin, m);
    stringstream non_vaksin_stream(n);
    stringstream vaksin_stream(m);
    string temp_non_vaksin,temp_vaksin;

    // membaca satu-satu dari string stream 
    while (non_vaksin_stream >> temp_non_vaksin) 
    {
        non_vaksin.push_back(temp_non_vaksin);
    }

    while (vaksin_stream >> temp_vaksin) 
    {
        vaksin.push_back(temp_vaksin);
    }

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
