#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> d(n);
  REP(i,n) cin >> d[i];

  int ans = 0;
  REP(i,n) {
    vector<int> t(10);
    int y = i+1;
    while(y) {
      t[y%10] = 1;
      y/=10;
    }

    for(int j = 1; j <= d[i]; j++) {
      auto s = t;
      int x = j;
      while(x) {
        s[x%10] = 1;
        x /= 10;
      }
      int sum = accumulate(s.begin(),s.end(),0);
      if (sum == 1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}