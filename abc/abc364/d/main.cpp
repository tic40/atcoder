#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  REP(qi,q) {
    int b,k; cin >> b >> k;

    auto f = [&](int x) -> bool {
      // l: 左方向, r: 右方向
      int l = b-x;
      int r = b+x;
      // l 以上が初めて出てくる位置
      int li = lower_bound(a.begin(),a.end(),l) - a.begin();
      // 初めて r+1 を越える位置
      int ri = lower_bound(a.begin(),a.end(),r+1) - a.begin();
      return ri-li >= k;
    };

    // 二分探索
    int ok = 2e8, ng = -1;
    while(ok-ng > 1) {
      int mid = (ok+ng) / 2;
      if (f(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }
  return 0;
}