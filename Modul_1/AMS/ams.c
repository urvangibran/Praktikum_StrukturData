#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long

typedef struct tnode
{
    ll id, priority;
    struct tnode *next;
}pQueueNode;

typedef struct tpq
{
    pQueueNode *top;
}PriorityQueue;

bool pq_isEmpty(PriorityQueue *pq)
{
    return (pq->top == NULL);
}

void push(PriorityQueue *ipq, ll id, ll prior)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode*)malloc(sizeof(pQueueNode));
    newNode->id = id;
    newNode->priority = prior;
    newNode->next = NULL;

    if((pq_isEmpty(ipq)))
    {
        ipq->top = newNode;
    }
    else if(prior >= ipq->top->priority)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
    else
        {
            while(temp->next != NULL && prior < temp->next->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            
            temp->next = newNode;
        }
    }

void tambahScore(PriorityQueue *ipq, ll id, ll skor)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *cur = ipq->top;
    while(temp->id != id && temp->next != NULL)
    {
        if(temp->next->id == id) cur = temp;
        temp = temp -> next;
    }
    temp->priority += skor;

    if(temp == ipq->top) return;    
    else if(temp->priority >= ipq->top->priority)
    {
        cur->next = temp->next;
        temp->next = ipq->top;
        ipq->top = temp;
    }
}

void show(PriorityQueue *ipq)
{
    prllf("%d %d\n", ipq->top->id, ipq->top->priority);
}

int main()
{
    PriorityQueue pemain;
    ll q;s
    scanf("%lld", &q);

    char taken[2001] = {0};
    while(q--)
    {
        ll id, n, m, skor;
        scanf("%lld %lld %lld", &id, &n, &m);
        skor = n * 500ll - m * 200ll;
        if(taken[id] > 0) 
        {
            tambahScore(&pemain, id, skor);
        }
        taken[id]++;
        push(&pemain, id, skor);
        show(&pemain);
    }
    return 0;
}