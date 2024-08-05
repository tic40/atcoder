#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t; cin >> t;

  auto solve = [&]() {
    int n; cin >> n;
    vector<int> p(n);
    REP(i,n) { cin >> p[i]; p[i]--; }

    auto t = p;
    sort(t.begin(),t.end());
    if (t == p) return 0;

    int mx = -1;
    REP(i,n) {
      mx = max(mx,p[i]);
      if (p[i] == i && mx == p[i]) return 1;
    }
    if (p[0] != n-1 || p[n-1] != 0) return 2;

    return 3;
  };

  REP(_,t) cout << solve() << endl;
  return 0;
}