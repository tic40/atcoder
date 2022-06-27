#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<bool> ng(1e6+1), used(1e6+1);

  for(int i: a) {
    if (used[i]) ng[i] = true;
    if (ng[i]) continue;

    used[i] = true;
    for(int j = i*2; j <= 1e6; j+=i) ng[j] = true;
  }

  int ans = 0;
  for(int v: a) if (!ng[v]) ans++;

  cout << ans << endl;
  return 0;
}