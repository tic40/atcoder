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
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  for(int i = 1; i <= m; i++) {
    REP(j,n-1) {
      if ( (a[j] % i) > (a[j+1] % i) ) {
        swap(a[j],a[j+1]);
      }
    }
  }

  REP(i,n) cout << a[i] << endl;
  return 0;
}