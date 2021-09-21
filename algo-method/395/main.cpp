#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  REP(i,n-1) {
    if (s[i] != s[i+1]) {
      ans++;
      i++;
    }
  }

  cout << ans << endl;
  return 0;
}