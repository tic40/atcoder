#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int mx = 0;
  int mxidx = 0;
  REP(i,n) {
    if (mx < a[i]) { mx = a[i]; mxidx = i; }
  }
  int left = 0, right = 0;
  REP(i,n) {
    if (i < mxidx) left += a[i];
    else if (mxidx < i) right += a[i];
  }

  cout << left << endl << right << endl;
  return 0;
}