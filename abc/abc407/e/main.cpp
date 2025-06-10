#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  auto solve = []() -> void {
    int n; cin >> n;
    int n2 = n*2;
    vector<int> a(n2);
    REP(i,n2) cin >> a[i];

    ll ans = a[0];
    priority_queue<int> q;
    for(int i = 1; i < n2-1; i += 2) {
      q.push(a[i]);
      q.push(a[i+1]);
      ans += q.top(); q.pop();
    }
    cout << ans << endl;
  };

  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}