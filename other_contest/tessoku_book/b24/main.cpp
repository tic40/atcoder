#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
using P = pair<int,int>;

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
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector<P> t;
  REP(i,n) t.emplace_back(x[i],-y[i]);
  sort(t.begin(),t.end());

  vector<int> a;
  for(auto v: t) a.push_back(-v.second);

  cout << lis(a) << endl;
  return 0;
}