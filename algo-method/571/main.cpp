#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  REP(i,m) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> ans(n);

  REP(i,m) {
    int target = a[i];
    int sum = 0;
    REP(j,n) {
      int b; cin >> b;
      b--;
      if (b == target) {
        ans[j]++;
      } else {
        sum++;
      }
    }
    ans[target] += sum;
  }

  REP(i,n) cout << ans[i] << endl;
  return 0;
}