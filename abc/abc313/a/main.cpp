#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  int mx = *max_element(p.begin()+1,p.end());
  int ans = max(0, mx - p[0] + 1);
  cout << ans << endl;
  return 0;
}