#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int q;
vector<ll> x;
vector<int> p;

void solve() {
  priority_queue<ll, vector<ll>, greater<ll>> que;
  ll add = 0;
  REP(i,q) {
    if (p[i] == 1) {
      que.push(x[i] - add);
    } else if (p[i] == 2) {
      add += x[i];
    } else {
      cout << que.top() + add << endl;
      que.pop();
    }
  }
  return;
}

int main() {
  cin >> q;
  p.resize(q);
  x.resize(q);

  REP(i,q) {
    cin >> p[i];
    if (p[i] == 1 || p[i] == 2) cin >> x[i];
  }

  solve();
  return 0;
}