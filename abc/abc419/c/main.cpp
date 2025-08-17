#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> r(n),c(n);
  REP(i,n) cin >> r[i] >> c[i];

  auto solve = [&](vector<int>& v) {
    sort(v.begin(),v.end());
    int d = v.back()-v[0];
    return (d+1)/2;
  };

  cout << max(solve(r),solve(c)) << endl;
  return 0;
}