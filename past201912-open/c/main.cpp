#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  vector<int> a(6);
  REP(i,6) cin >> a[i];
  sort(ALL(a));
  cout << a[3] << endl;
  return 0;
}