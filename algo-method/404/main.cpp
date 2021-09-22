#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> d(m);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    d[i] = a-b;
  }
  sort(d.rbegin(), d.rend());
  int ans = 0;
  REP(i,m-1) {
    if (d[i] < 0) ans += (-d[i]+1)/2;
  }
  cout << ans << endl;
  return 0;
}