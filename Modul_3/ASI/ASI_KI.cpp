#include <iostream>
#include <map>
#define ull unsigned long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    ull angka;

    map<ull, ull> catalan_map;
    catalan_map[0] = 1;
    catalan_map[1] = 1;

    while (t--)
    {
        cin >> angka;

        // kalo gaada
        if (catalan_map.count(angka) == 0)
        {
            for (ull i = 2; i <= angka; i++)
            {
                if (catalan_map.count(i) == 0)
                {
                    catalan_map[i] = 0;
                    for (int j = 0; j < i; j++)
                    {
                        catalan_map[i] += catalan_map[j] * catalan_map[i - j - 1];
                    }
                }
            }
        }

        ull hasil = catalan_map[angka];
        cout << hasil << endl;
    }
    return 0;
}