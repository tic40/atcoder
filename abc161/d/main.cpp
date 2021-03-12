#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int k;
vector<ll> r;

void bfs() {
  queue<ll> q;

  for(int i = 1; i < 10; i++) q.push(i);

  auto push = [&](ll x) {
    ll nx = x*10 + x%10;
    if (0 < nx%10) q.push(nx-1);
    q.push(nx);
    if (nx%10 < 9) q.push(nx+1);
  };

  while(!q.empty()) {
    if (k < r.size()) break;
    ll x = q.front(); q.pop();
    r.push_back(x);
    push(x);
  }
  return;
}

int main() {
  cin >> k;
  bfs();
  cout << r[k-1] << endl;
  return 0;
}