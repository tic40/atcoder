#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector<string>s(2);
  REP(i,2) cin >> s[i];

  int i = 0;
  mint ans = 1;
  int pre = -1;
  while(i < n) {
    // 縦置き
    if (s[0][i] == s[1][i]) {
      if (pre == -1) ans = 3;
      else if (pre == 0) ans *= 2;
      pre = 0;
      i++;
    // 横置き
    } else {
      if (pre == -1) ans = 6;
      else if (pre == 0) ans *= 2;
      else ans *= 3;
      pre = 1;
      i+=2;
    }
  }

  cout << ans.val() << endl;

  return 0;
}
