#include <bits/stdc++.h>
using namespace std;

int main(){
    string postfix;
    
    int i, j;
	int a, b;

    //while(getline(cin, postfix)){
        getline(cin, postfix);
        stringstream numop(postfix);
        stack<int> angka;
        int gagal = 0;
        string temp;
        while(numop >> temp){
            if(temp[0] >= '0' && temp[0] <= '9')
                angka.push(stod(temp));
            else{
                //if(angka.empty() || angka.size() == 1){
                if(angka.size() < 2){
                    gagal = 1;
                    break;
                }
                b = angka.top();
                angka.pop();
                a = angka.top();
                angka.pop();
                if(temp[0] == '+')
				    angka.push(a+b); else
			    if(temp[0] == '-')
				    angka.push(a-b); else
			    if(temp[0] == '*')
				    angka.push(a*b); else
			    if(temp[0] == '/')
				    angka.push(a/b);
            }
        }
        if(gagal || angka.size()>1)
		    printf("ERROR\n");
	    else
		    printf("%d\n", angka.top());
    //}

    return 0;
}