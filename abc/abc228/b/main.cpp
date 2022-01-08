#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,n) a[i]--;

  x--;
  vector<bool> s(n);
  while(1) {
    if (s[x]) break;
    s[x] = true;
    x = a[x];
  }

  int ans = 0;
  REP(i,n) ans += s[i];
  cout << ans << endl;

  return 0;
}