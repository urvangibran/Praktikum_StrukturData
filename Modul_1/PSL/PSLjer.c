#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int flag = 1;
char n1[1001];
char n2[1001];
int pr1, pr2;

typedef struct node
{
    char nama[1001];
    int umur, priority;
    struct node *next;
} PQNode;

typedef struct pq
{
    int size;
    PQNode *top;
} PQ;

void masuk(PQ *inp, char nama[], int umur, int pr)
{
    PQNode *temp = inp->top;
    PQNode *newNode = (PQNode *)malloc(sizeof(PQNode));
    strcpy(newNode->nama, nama);
    newNode->umur = umur;
    newNode->priority = pr;
    newNode->next = NULL;

    if (inp->top == NULL)
    {
        inp->top = newNode;
        return;
    }

    if (pr < inp->top->priority || ((umur >= inp->top->umur) && (pr == inp->top->priority)))
    {   
        // puts("ho");
        if ((umur == inp->top->umur) && (pr == inp->top->priority))
        {
            flag = 0;
            strcpy(n1, inp->top->nama);
            strcpy(n2, nama);
            pr1 = inp->top->priority;
            pr2 = pr;
            return;
        }

        else
        {
            newNode->next = inp->top;
            inp->top = newNode;
        }
    }

    else
    {
        while ((temp->next != NULL && temp->next->priority < pr) || (temp->next != NULL && temp->next->priority == pr && umur <= temp->next->umur))
        {
            if ((umur == temp->next->umur) && (pr == temp->next->priority))
            {
                flag = 0;
                strcpy(n1, temp->next->nama);
                strcpy(n2, nama);
                pr1 = temp->next->priority;
                pr2 = pr;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    inp->size++;
}

void layani(PQ *inp)
{
    if (inp->top != NULL)
    {
        PQNode *temp = inp->top;
        inp->top = inp->top->next;
        free(temp);
    }
}

int main()
{
    int t, n, skip = 1;
    scanf("%d %d", &t, &n);
    if (n >= t)
        skip = 0;
    PQ stat;
    stat.size = 0;
    stat.top = NULL;
    while (t--)
    {
        int umur, pr;
        char nama[1001];
        scanf("%s %d %d", nama, &umur, &pr);
        if (skip && flag)
            masuk(&stat, nama, umur, pr);
    }

    if (skip == 0)
    {
        puts("Full senyum deck");
        return 0;
    }

    if (flag == 0)
    {
        printf("Kamu jodoh ya %s - %d && %s - %d\n", n1, pr1, n2, pr2);
        return 0;
    }

    // while (stat.size != 0)
    // {
    //     printf("%s %d %d\n", stat.top->nama, stat.top->umur, stat.top->priority);
    //     layani(&stat);
    // }

    while (n--)
    {
        layani(&stat);
    }
    printf("Pasien selanjutnya adalah: %s - %d\n", stat.top->nama, stat.top->priority);
}