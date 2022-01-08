#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;

  vector<bool> m(1001);

  for(int a = 1; a <= 400; a++) {
    for (int b = 1; b <= 400; b++) {
      int s = 4*a*b + 3*a + 3*b;
      if (1000 < s) break;
      m[s] = true;
    }
  }

  int ans = 0;
  REP(i,n) {
    int x; cin >> x;
    if (!m[x]) ans++;
  }

  cout << ans << endl;
  return 0;
}