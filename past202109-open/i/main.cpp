#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

int n;
vector<ll> a;

void solve() {
  int cnt_div2 = 0;
  REP(i,n) {
    while(a[i] % 2 == 0) {
      a[i] /= 2;
      cnt_div2++;
    }
  }

  priority_queue<ll, vector<ll>, greater<ll>> q;
  REP(i,n) q.push(a[i]);
  REP(i,cnt_div2) {
    ll cur = q.top(); q.pop();
    cur *= 3;
    q.push(cur);
  }

  cout << q.top() << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}