#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

typedef struct pem_t
{
    ll id, skor;
}pemain;

struct ComparePrior
{
    bool operator()(pemain const &p1, pemain const &p2)
    {   
    if(p1.skor == p2.skor)    
    {
        return p1.id <= p2.id;
    }
        return p1.skor < p2.skor; 
    }
};

void tambah_skor(priority_queue <pemain, vector<pemain>, ComparePrior> &pqueue, 
                    ll id, ll n, ll m) 
{
    priority_queue <pemain, vector<pemain>, ComparePrior> temp;
    bool taken = true;
    ll score = n * 5 - m * 2;
    while (!pqueue.empty()) 
    {
        pemain top = pqueue.top();
        pqueue.pop();   
        if (top.id != id) 
        {
            temp.push(top);
            taken = true;
        } 
        else 
        {
            top.skor += score;
            temp.push(top);
            taken = false;
            break;
        }
    }
    if (taken) 
    {
        pqueue.push(pemain{id, score});
    }
    while (!temp.empty()) 
    {
        pqueue.push(temp.top());
        temp.pop();
    }
}

int main()
{
    int Q;
    cin >> Q;
    priority_queue <pemain, vector<pemain>, ComparePrior> top;

    while(Q--)
    {
        ll id, n, m;
        cin >> id >> n >> m;
        tambah_skor(top, id, n, m);
        cout << top.top().id << " " << top.top().skor * 100 << endl;
    }
}