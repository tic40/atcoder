#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  int ans = *max_element(a.begin(),a.end()) + *max_element(b.begin(),b.end());
  cout << ans << endl;
  return 0;
}