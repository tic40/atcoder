#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  REP(i,s.size()) {
    int d = s[i] - '0';
    if (10 <= d) {
      cout << "error" << endl;
      return 0;
    }
    ans*=10;
    ans+=d;
  }
  cout << ans*2 << endl;
  return 0;
}