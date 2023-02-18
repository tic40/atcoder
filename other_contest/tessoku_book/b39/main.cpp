#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,d; cin >> n >> d;

  vector g(d,vector<int>());
  REP(i,n) {
    int x,y; cin >> x >> y;
    x--;
    g[x].push_back(y);
  }

  priority_queue<int, vector<int>, less<int>> q;
  ll ans = 0;
  REP(i,d) {
    for(int v: g[i]) q.push(v);
    if (q.size()) { ans += q.top(); q.pop(); }
  }

  cout << ans << endl;
  return 0;
}