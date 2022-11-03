#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> cnt(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    if (a > b) cnt[a]++;
    else cnt[b]++;
  }
  int ans = 0;
  REP(i,n) if (cnt[i] == 1) ans++;
  cout << ans << endl;

  return 0;
}