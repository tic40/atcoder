#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n),b(n),c(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());

  priority_queue<tuple<ll,int,int,int>> q;
  set<tuple<int,int,int>> used;
  auto push = [&](int i, int j, int k) {
    if (i >= n || j >= n || k >= n) return;
    ll val = a[i]*b[j] + b[j]*c[k] + c[k]*a[i];
    q.emplace(val,i,j,k);
  };

  push(0,0,0);
  REP(_,k-1) {
    auto [val,i,j,k] = q.top(); q.pop();
    push(i+1,j,k);
    if (i==0) push(i,j+1,k);
    if (i==0 && j==0) push(i,j,k+1);
  }
  ll ans = get<0>(q.top());
  cout << ans << endl;
  return 0;
}
