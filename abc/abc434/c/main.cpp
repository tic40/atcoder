#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

void solve() {
  int n,h; cin >> n >> h;
  vector<tuple<int,int,int>> e;
  P p = {h,h};

  REP(i,n) {
    int t,l,u; cin >> t >> l >> u; 
    e.emplace_back(t,l,u);
  }
  
  int now = 0; 
  for(auto [t,l,u]: e) {
    int d = t - now;
    now = t;
    p.first -= d;
    p.second += d;
    if (p.first > u || p.second < l) {
      cout << "No" << endl;
      return;
    }
    p.first = max(p.first, l);
    p.second = min(p.second, u);
  }  
  cout << "Yes" << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}