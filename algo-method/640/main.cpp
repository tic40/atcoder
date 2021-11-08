#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  vector<bool> s(n+1, true);
  REP(i,x+y) {
    int a; cin >> a;
    s[a] = false;
  }

  int ans = 0;
  REP(i,n) ans += s[i+1];
  cout << ans << endl;
  return 0;
}