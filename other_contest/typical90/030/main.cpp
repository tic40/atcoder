#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> c(n+1);
  for(int i = 2; i <= n; i++) {
    if (c[i] != 0) continue;
    for(int j = i; j <= n; j+=i) c[j]++;
  }

  int ans = 0;
  REP(i,n+1) if (c[i] >= k) ans++;
  cout << ans << endl;
  return 0;
}