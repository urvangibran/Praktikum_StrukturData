#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tnode_t
{
    char nama[30];
    int umur, priority;
    struct tnode_t *next;
}pQueueNode;

typedef struct priorQueue
{
    pQueueNode *top;
}PriorityQueue;

int top=0;
void init(PriorityQueue *ipq)
{
    ipq->top = 0;
}

bool pq_isEmpty(PriorityQueue *ipq)
{
    if(ipq->top == 0) return true;
    return false;
}

void pq_push(PriorityQueue *ipq, char nama[], int umur, int prior)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode*)malloc(sizeof(pQueueNode));

    strcpy(newNode->nama, nama);
    newNode->umur = umur;
    newNode->priority = prior;
    newNode->next = NULL;
    
    if(pq_isEmpty(ipq))
    {
        ipq->top = newNode;
    }
    else
    {
        if(prior == ipq->top->priority)
        {
            if(umur > ipq->top->umur)
            {
                newNode->next = ipq->top;
                ipq->top = newNode;
            }
            else
            {
                newNode->next = ipq->top->next;
                ipq->top->next = newNode;
            }
        }
        else if(prior < ipq->top->priority)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
        else
        {
            while(temp->next != NULL && prior >= temp->next->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void pq_pop(PriorityQueue *ipq)
{
    if(!pq_isEmpty(ipq))
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

int main()
{
    PriorityQueue pq, pqCek, temp;
    init(&pq);
    init(&pqCek);
    init(&temp);
    int n, m; 
    scanf("%d %d", &n, &m);
    int i, j;
    for(i = 0; i < n; i++)
    {
        char nama[31]; 
        int umur, skala;
        scanf("%s %d %d", nama, &umur, &skala);
        pq_push(&pq, nama, umur, skala);
    }

    if(n == m) 
    {   
        printf("Full senyum deck");
        return 0;
    }

    pqCek = pq;
    for(i = 0; i < n; i++)
    {
        temp = pqCek; 
        pq_pop(&temp);
        for(j = i + 1; j < n; j++)
        {
            printf("AHA %d %d\n", i, j);
            if(pqCek.top->priority == temp.top->priority && 
            pqCek.top->umur == temp.top->umur)
            {
                printf("Kamu jodoh ya %s - %d && %s - %d", pqCek.top->nama,
                pqCek.top->priority, temp.top->nama, temp.top->priority);
            }
            pq_pop(&temp);
        }
        pq_pop(&pqCek);
    }

    for(i=0; i<m; i++) pq_pop(&pq);
        printf("Pasien selanjutnya adalah: %s - %d", pq.top->nama, pq.top->priority);

    //print queue
    while(!pq_isEmpty(&pq))
    {
        printf("%s %d %d\n", pqCek.top->nama, pqCek.top->umur, pqCek.top->priority);
        pq_pop(&pqCek);
    }
}