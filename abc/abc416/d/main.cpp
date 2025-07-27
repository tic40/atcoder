#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  auto solve = []() {
    int n,m; cin >> n >> m;
    multiset<int> ms;
    REP(i,n) { int a; cin >> a; ms.insert(a); }
    vector<int> b(n);
    REP(i,n) cin >> b[i];
    sort(b.rbegin(),b.rend());

    ll ans = 0;
    REP(i,n) {
      auto it = ms.lower_bound(m-b[i]);
      if (it == ms.end()) it--;
      ans += (*it + b[i]) % m;
      ms.erase(it);
    }
    return ans;
  };

  int t; cin >> t;
  REP(_,t) cout << solve() << endl;
  return 0;
}