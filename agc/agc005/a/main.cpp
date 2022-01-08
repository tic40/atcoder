#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s; cin >> s;

  int cnt = 0, res = 0;
  for (char c: s) {
    if (c == 'S') {
      cnt++;
    } else {
      if (cnt == 0) res++;
      else cnt--;
    }
  }

  int ans = res + cnt;
  cout << ans << endl;

  return 0;
}