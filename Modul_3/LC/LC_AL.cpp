#include<bits/stdc++.h>

using namespace std;

int main(){
    map<string, int> mp;
    int n, x, m, y, minCount;
    string str, s;
    while(getline(cin, str)){
        mp[str]++;
        if(str == "#") break;
    }
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        minCount = INT_MAX;
        bool gagal = 0, visited = 0;
        map<string, int> sy;
        while(m--){
            getline(cin, s);
            getline(cin, s);
            cin >> y;
            sy[s] += y;
            minCount = min(minCount, mp[s]/y);
            if(mp[s] - x*y < 0 && !visited){
                gagal = 1;
                visited = 1;
            }
        }
        if(!gagal){
            cout << "Material Fulfilled, Crafting " << x << "!" << endl;
            for(auto j = sy.begin(); j != sy.end(); j++){
                mp[j->first] -= j->second * x;
            }
        }
        else{
            cout << "Insufficient Material, Can only craft " << minCount << "." << endl;
        }
        
    }
}