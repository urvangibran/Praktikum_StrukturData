#include <iostream>
#include <queue>
using namespace std;

typedef struct pas_t
{
    string nama;
    int umur, prior, index;
}pasien;

struct ComparePrior
{
    bool operator()(pasien const &p1, pasien const &p2)
    {   
        if(p1.prior == p2.prior && p1.umur == p2.umur)
        {
            return p1.index > p2.index;
        }
        if(p1.prior == p2.prior)    
        {
            return p1.umur < p2.umur;
        }
        return p1.prior > p2.prior;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    priority_queue <pasien, vector<pasien>, ComparePrior> pasien_asc;
    queue<pasien>temp, pasien_asc_cek;
    for(int i = 0; i < n; i++)
    {
        string nama; int umur, prioritas;
        cin >> nama >> umur >> prioritas;

        pasien_asc.push({nama, umur, prioritas, i});
    }

    if(m == n)
    {
        cout << "Full senyum deck" << endl;
        return 0;
    }
    pasien_asc_cek = pasien_asc;
    for(int i=0; i<n ;i++)
    {
        temp = pasien_asc_cek;
        temp.pop();
        for(int j=i+1; j<n;j++)
        {
            if(temp.top().umur == pasien_asc_cek.top().umur && 
                temp.top().prior == pasien_asc_cek.top().prior)
                {
                    cout << "Kamu jodoh ya " <<
                    pasien_asc_cek.top().nama << " - " <<pasien_asc_cek.top().prior <<
                    " && "  << temp.top().nama << " - " << temp.top().prior << endl;
                    return 0;
                }
            temp.pop(); 
        }
            pasien_asc_cek.pop();
    }

    for(int i=0; i<m; i++) pasien_asc.pop();
    cout << "Pasien selanjutnya adalah: " << pasien_asc.top().nama <<
    " - " << pasien_asc.top().prior <<endl;
}
