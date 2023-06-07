#include <stdio.h>
const int MAX_BITS = 30;

int main()
{
    int N, i, j;
    scanf("%d", &N);
    int A[N];
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    int Q;
    scanf("%d", &Q);
    int bitAwal[2];
    bitAwal[0] = 0;
    bitAwal[1] = 2147483647;

    while(Q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            char t[5]; int x;
            scanf("%s %d", t, &x);
            for(j=0; j<2; j++)
            {
                if(t[0] == 'X') bitAwal[j] ^= x;
                else if(t[0] == 'O') bitAwal[j] |=x;
                else bitAwal[j] &= x;
            }

            continue;
        }

        for(i=0; i<N; i++)
        {
        int elem = A[i];
        int printed = 0;
        for(j=0; j<MAX_BITS; j++)
        {
            int rightmostBit = elem & 1;
            int bit = (bitAwal[rightmostBit] >> j) & 1;
            printed |= (bit << j);
            elem >>=1;
        }
        printf("%d%c", printed, (i == N - 1 ? '\n' : ' '));
        }
    }
}