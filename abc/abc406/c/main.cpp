#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  vector<P> pa;
  REP(i,n-1) {
    int t = p[i] < p[i+1];
    if (pa.size() && pa.back().first == t) pa.back().second++;
    else pa.emplace_back(t,1);
  }

  ll ans = 0;
  for(int i = 1; i < (int)pa.size()-1; i++) if (pa[i].first == 0) {
    ans += (ll)pa[i-1].second * pa[i+1].second;
  }
  cout << ans << endl;
  return 0;
}