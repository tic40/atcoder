#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;

  int ans = 0, cnt = 0;
  bool ok = false;
  for(auto c: s) {
    if (c == '-') { cnt = 0; ok = true; }
    else cnt++;
    ans = max(ans,cnt);
  }

  if (ans == 0 || !ok) ans = -1;
  cout << ans << endl;
  return 0;
}