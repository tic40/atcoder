#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto m = minmax_element(a.begin(),a.end());
  int mi = m.first - a.begin();
  int mx = m.second - a.begin();
  vector<P> ans;

  // 正負の値が混在する場合は正負のどちらかに揃える
  if (a[mi] < 0 && 0 < a[mx]) {
    int add_idx =  abs(a[mi]) < abs(a[mx]) ? mx : mi;
    REP(i,n) {
      a[i] += a[add_idx];
      ans.emplace_back(add_idx,i);
    }
  }

  // 正負が揃っていれば累積和の考えで昇順に並び替えできる
  if (0 <= a[mi]) {
    REP(i,n-1) ans.emplace_back(i,i+1);
  } else {
    REP(i,n-1) ans.emplace_back(n-i-1,n-i-2);
  }

  cout << ans.size() << endl;
  for(auto v :ans) cout << v.first+1 << " " << v.second+1 << endl;
  return 0;
}