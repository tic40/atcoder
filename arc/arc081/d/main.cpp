#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  string s1,s2;
  cin >> n >> s1 >> s2;

  ll ans = 0;
  bool now=false, prev=false; // true: 縦置き, false: 横置き

  REP(i,n) {
    prev = now;
    now = s1[i] == s2[i];

    if (i==0) ans = now ? 3 : 6;
    else {
      if (now) ans *= prev ? 2 : 1;
      else ans *= prev ? 2 : 3;
    }

    if (!now) i++;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}