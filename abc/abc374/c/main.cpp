#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> k(n);
  REP(i,n) cin >> k[i];

  int ans = 2e9+1;
  REP(bit,1<<n) {
    int a = 0, b = 0;
    REP(i,n) {
      if (bit >> i & 1) a += k[i];
      else b += k[i];
    }
    ans = min(ans,max(a,b));
  }
  cout << ans << endl;
  return 0;
}