#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int lis(const vector<int> &a) {
  int n = a.size();
  vector<int> dp(n, INF);

  REP(i,n) {
    int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    dp[pos] = a[i];
  }

  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  cout << lis(a) << endl;
  return 0;
}