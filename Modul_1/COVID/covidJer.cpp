#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int main()
{
    deque<string> rumah;
    char inp[1001];
    while (1)
    {
        scanf("%s", inp);
        if (inp[0] == '#')
            break;
        rumah.push_back(inp);
    }

    char temp[1001];
    deque<string> vaksin;
    while (scanf("%s", temp) != EOF)
    {
        vaksin.push_back(temp);
        if (temp == rumah.back())break;
    }

    while (1)
    {
        puts("Hi");
        printf("%c %c %c %c\n", rumah.front(), rumah.back(), vaksin.front(), vaksin.back());
    //     if (vaksin.size() == 0)
    //     {
    //         puts("Bisa menang ini mah, gas mainin aja masbro");
    //         return 0;
    //     }

    //     else if (rumah.front() == vaksin.front())
    //     {
    //         // puts("depan");
    //         rumah.pop_front();
    //         vaksin.pop_front();
    //     }
    //     else if (rumah.back() == vaksin.back())
    //     {
    //         // puts("belakang");
    //         rumah.pop_back();
    //         vaksin.pop_back();
    //     }

    //     else
    //     {
    //         puts("Gabisa sumpah, game ini red flag banget sih");
    //         return 0;
    //     }
    // }
    // puts("Gabisa sumpah, game ini red flag banget sih");
}
}