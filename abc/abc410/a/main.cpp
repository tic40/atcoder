#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int k; cin >> k;
  int ans = 0;
  REP(i,n) if (k <= a[i]) ans++;
  cout << ans << endl;
  return 0;
}