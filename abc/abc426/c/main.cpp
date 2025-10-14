#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> cnt(n,1);
  int mn = 0;

  REP(_,q) {
    int x,y; cin >> x >> y; x--; y--;

    int ans = 0;
    for(int j = mn; j <= x; j++) {
      ans += cnt[j];
      cnt[y] += cnt[j];
    }
    mn = max(mn,x+1);
    cout << ans << endl;
  }
  return 0;
}