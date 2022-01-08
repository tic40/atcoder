#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; string s;
  cin >> n >> s;

  int sumB = 0, sumW = 0;
  REP(i,n) if (s[i] == '.') sumW++;

  int ans = sumW;
  for (int i = 1; i <= n; i++) {
    s[i-1] == '#' ? sumB++ : sumW--;
    ans = min(ans, sumB+sumW);
  }

  cout << ans << endl;
  return 0;
}