#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Player;

// Fungsi untuk menambahkan skor pemain ke dalam priority queue
void tambah_skor(priority_queue<Player>& pqueue, ll id, ll n, ll m) {
    priority_queue<Player> tmp;
    bool kosong = true;
    ll score = n * 500LL - 200LL * m;
    while (!pqueue.empty()) {
        Player player = pqueue.top();
        pqueue.pop();
        if (player.second != id) {
            tmp.push(player);
            kosong = true;
        } else {
            player.first += score;
            tmp.push(player);
            kosong = false;
            break;
        }
    }
    if (kosong) {
        pqueue.push({score, id});
    }
    while (!tmp.empty()) {
        pqueue.push(tmp.top());
        tmp.pop();
    }
}

int main() {
    priority_queue<Player> pqueue;
    ll q, id, n, m;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> id >> n >> m;
        tambah_skor(pqueue, id, n, m);
        cout << pqueue.top().second << " " << pqueue.top().first << "\n";
    }
    return 0;
}