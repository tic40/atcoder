#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  priority_queue<int, vector<int>, less<int>> q;
  REP(i,n) q.push(a[i]);

  REP(i,m) {
    q.push(q.top()/2);
    q.pop();
  }

  ll ans = 0;
  while(q.size()) { ans += q.top(); q.pop(); }

  cout << ans << endl;
  return 0;
}