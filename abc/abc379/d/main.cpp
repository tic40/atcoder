#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int q; cin >> q;
  ll now = 0;
  queue<ll> que;
  while(q--) {
    int t; cin >> t;
    if (t == 1) que.push(now);
    if (t == 2) { int x; cin >> x; now += x; }
    if (t == 3) {
      int h, ans = 0; cin >> h;
      while(que.size() && now - que.front() >= h) { que.pop(); ans++; }
      cout << ans << endl;
    }
  }
  return 0;
}