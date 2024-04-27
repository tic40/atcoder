#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,d; cin >> n >> d;
  vector<P> p(n);
  REP(i,n) {
    int l,r; cin >> l >> r;
    l--; r--;
    p[i] = {r,l};
  }
  sort(p.begin(),p.end());
  int now = -1;
  int ans = 0;
  REP(i,n) {
    auto [r,l] = p[i];
    if (l <= now) continue;
    now = r+d-1;
    ans++;
  }

  cout << ans << endl;
  return 0;
}