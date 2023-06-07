#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int i, cnt = 0, a;
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a==1) cnt++;
    }
    printf("%d %d", cnt, n-cnt);
}