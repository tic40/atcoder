#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> p(n),q(m);
  REP(i,n) cin >> p[i].first;
  REP(i,n) cin >> p[i].second;
  REP(i,m) cin >> q[i].first;
  REP(i,m) cin >> q[i].second;

  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());

  int qi = 0;
  multiset<int> s;
  for(auto [x,y]: p) {
    while(qi < m) {
      auto [qx,qy] = q[qi];
      if (qx < x) break;
      s.insert(qy);
      qi++;
    }

    auto it = s.lower_bound(y);
    if (it == s.end()) {
      cout << "No" << endl;
      return 0;
    }
    s.erase(it);
  }

  cout << "Yes" << endl;
  return 0;
}