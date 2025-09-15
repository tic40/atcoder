#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,r; cin >> n >> r; r--;
  vector<int> l(n);
  REP(i,n) cin >> l[i];

  int mn = 1e9, mx = -1;
  REP(i,n) if (l[i] == 0) {
    mx = max(mx,i);
    mn = min(mn,i);
  }

  int ans = 0;
  for(int i = r+1; i <= mx; i++) ans += l[i]+1;
  for(int i = r; i >= mn; i--) ans += l[i]+1;
  cout << ans << endl;
  return 0;
}