#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> c(9);
  REP(i,9) cin >> c[i];

  int mn = *min_element(c.begin(),c.end());
  int len = n / mn;

  string ans = "";
  int now = n;
  REP(i,len) {
    for (int j = 8; j >= 0; j--) {
      now -= c[j];
      if (now >= 0 && now / mn == len - (i+1)) {
        ans += (char)('0' + (j+1));
        break;
      }
      now += c[j];
    }
  }
  cout << ans << endl;
  return 0;
}