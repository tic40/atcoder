#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;

  vector p(n,vector<int>());
  vector<int> get(n);
  vector<P> query;
  REP(i,n) {
    int t,x; cin >> t >> x; x--;
    query.emplace_back(t,x);
    if (t == 1) {
      p[x].push_back(i);
    } else {
      if (p[x].size() == 0) { cout << -1 << endl; return 0; }
      get[p[x].back()] = 1;
      p[x].pop_back();
    }
  }

  int kmin = 0;
  int now = 0;
  REP(i,n) {
    auto [t,x] = query[i];
    if (t == 1) {
      if (get[i]) now++;
    } else {
      now--;
    }
    kmin = max(kmin,now);
  }

  cout << kmin << endl;
  REP(i,n) if (query[i].first == 1) cout << get[i] << " ";
  return 0;
}