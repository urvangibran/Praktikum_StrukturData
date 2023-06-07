#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    string n,m;
    string pagar;
    vector<string> X;
    vector<string> Y;
    getline(cin, n);
    getline(cin, pagar);
    getline(cin, m);
    int counter = 0, counter_nonvaksin=0;
    stringstream nn(n);
    stringstream mm(m);
    string tmp,TMP;

    while (nn >> tmp) {
        X.push_back(tmp);
    }

    while (mm >> TMP) {
        Y.push_back(TMP);
    }

    vector<int> sudahvaksin;
    for (int i=0; i<X.size(); i++) {
        int tervaksinasi=0;
        for (int j=0; j<Y.size(); j++){
            if (Y[j] == X[i]) {
                tervaksinasi=1;
                sudahvaksin.push_back(tervaksinasi);
            }
        }
        if (tervaksinasi == 0) {
            counter_nonvaksin++;
            sudahvaksin.push_back(tervaksinasi);
        }
    }

    int counter_menang=0, max=0;
    for (int i=0; i<sudahvaksin.size(); i++) {
        if (sudahvaksin[i] == 1) {
            counter_menang = 0;
        } else if (sudahvaksin[i] == 0) {
            if (counter_menang >= max) {
                counter_menang++;
                max = counter_menang;
            } else {
                counter_menang++;
            }
        }
    }
    
    cout<<endl;
    for (int i=0; i<sudahvaksin.size(); i++) {
        cout<<sudahvaksin[i]<<" ";
    }
    cout<<endl;

    if (max == counter_nonvaksin) {
        cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    } else {
        cout << "Gabisa sumpah, game ini red flag banget sih" << endl;
    }

    return 0;
}