#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.rbegin(),a.rend());
  int ans = 0;
  while(a[1] > 0) {
    ans++;
    a[0]--; a[1]--;
    sort(a.rbegin(),a.rend());
  }
  cout << ans << endl;
  return 0;
}