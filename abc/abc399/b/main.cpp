#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  int r = 1;
  vector<int> ans(n,-1);
  while(1) {
    int mx = *max_element(p.begin(),p.end());
    if (mx == -1) break;
    int k = 0;
    REP(i,n) if (p[i] == mx) {
      p[i] = -1;
      ans[i] = r;
      k++;
    }
    r += k;
  }
  for(auto v: ans) cout << v << endl;
  return 0;
}
