#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> ev;
  REP(i,n) {
    int l,r; cin >> l >> r;
    ev.emplace_back(l,0);
    ev.emplace_back(r,1);
  }
  sort(ev.begin(),ev.end());
  ll ans = 0;
  int now = 0;
  for(auto [k,v]: ev) {
    if (v == 0) {
      ans += now++;
    } else {
      now--;
    }
  }
  cout << ans << endl;
  return 0;
}