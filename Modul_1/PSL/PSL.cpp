#include <iostream>
#include <queue>
using namespace std;

typedef struct pas_t
{
    string nama;
    int umur, prior;
}pasien;

struct ComparePrior
{
    bool operator()(pasien const &p1, pasien const &p2)
    {   
    if(p1.prior == p2.prior)    
    {
        if(p1.umur == p2.umur)
        {
            return 3;
        }
        return p1.umur < p2.umur;
    }
        return p1.prior > p2.prior;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    int loop = n;
    priority_queue <pasien, vector<pasien>, ComparePrior> pasien_asc, temp, pasien_asc_cek;
    while(n--)
    {
        string nama; int umur, prioritas;
        cin >> nama >> umur >> prioritas;

        pasien_asc.push(pasien{nama, umur, prioritas});
    }
    int flag = 0;

    if(m == loop)
    {
        cout << "Full senyum deck" << endl;
        return 0;
    }
    pasien_asc_cek = pasien_asc;
    for(int i=0; i<loop ;i++)
    {
        temp = pasien_asc_cek;
        temp.pop();
        for(int j=i+1; j<loop
        ;j++)
        {
            if(temp.top().umur == pasien_asc_cek.top().umur && 
                temp.top().prior == pasien_asc_cek.top().prior && flag == 0)
                {
                    cout << "Kamu jodoh ya " <<
                    pasien_asc_cek.top().nama << " - " <<pasien_asc_cek.top().prior <<
                    " && "  << temp.top().nama << " - " << temp.top().prior << endl;;
                    flag = 1;
                }
            temp.pop(); 
        }
            pasien_asc_cek.pop();
    }

    if(flag != 1)
    {
    for(int i=0; i<m; i++) pasien_asc.pop();
    cout << "Pasien selanjutnya adalah: " << pasien_asc.top().nama <<
    " - " << pasien_asc.top().prior <<endl;
    }
    return 0;

    while(!pasien_asc.empty())
    {
        cout << pasien_asc.top().nama <<" - " << pasien_asc.top().umur << " " << pasien_asc.top().prior << endl;
        pasien_asc.pop();
    }
}