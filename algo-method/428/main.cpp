#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<vector<int>> f(int n, int l, int r) {
  vector<vector<int>> ans;
  if (r < l) return ans;
  if (n == 0) {
    ans.resize(1);
    return ans;
  }

  for(auto v: f(n-1,l,r)) {
    v.push_back(l);
    ans.push_back(v);
  }
  for(auto v: f(n,l+1,r)) {
    ans.push_back(v);
  }

  return ans;
}

int main() {
  int n,l,r;
  cin >> n >> l >> r;

  auto ans = f(n,l,r);
  for(auto v: ans) {
    reverse(v.begin(), v.end());
    for(int x: v) cout << x << " ";
    cout << endl;
  }
  return 0;
}