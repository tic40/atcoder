#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> t(n);
  REP(i,n) {
    int l,r; cin >> l >> r;
    t[i] = {r,l};
  }
  sort(t.begin(),t.end());

  int now = 0, ans = 0;
  REP(i,n) {
    auto [r,l] = t[i];
    if (now <= l) { ans++; now = r; }
  }

  cout << ans << endl;
  return 0;
}