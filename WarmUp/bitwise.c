#include <stdio.h>
#include <string.h>

int main()
{
    int n, q, i;
    scanf("%d", &n);
    long long opr[200001];
    for(i = 0; i < n; i++)
    {
        scanf("%lld",&opr[i]);
    }
    scanf("%d",&q);
    while(q--)
    {
        int num_order;
        scanf("%d", &num_order);
        if(num_order == 2)
        {
            for(i = 0;i < n; i++)
            {
                printf("%lld", opr[i]);
                if(i >= n-1) printf("\n");
                else printf(" ");
            }
        }
        else if(num_order == 1)
        {
            char t[3];
            int x;
            scanf("%s%d", t, &x); 
            if(!strcmp(t, "XOR"))
            {
                for(i = 0; i < n; i++)
                {
                    opr[i] = opr[i] ^ x;
                }
            }
            else if(!strcmp(t, "OR"))
            {
                 for(i = 0; i < n; i++)
                {
                    opr[i] = opr[i] | x;
                }
            }
            else if(!strcmp(t, "AND"))
            {
                 for(i = 0; i < n; i++)
                {
                    opr[i] = opr[i] & x;
                }
            }
        }
    }
    return 0;   
}