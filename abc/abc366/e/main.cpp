#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

const int M = 1e6;

// ∑(|x-xi|) を求める
vector<ll> f(vector<int> x) {
  int n = x.size();

  // 下駄を履かせてすべて正の数にする
  REP(i,n) x[i] += M*2;
  sort(x.begin(), x.end());
  // s := 初期値として、0 からの合計を求める
  ll s = accumulate(x.begin(),x.end(),0LL);
  // res[i] := 座標 i から見たときの合計
  vector<ll> res(M*4+1);
  res[0] = s;

  // 尺取法
  // k := x[k] >= i となる x の 個数
  int k = 0;
  for (int i = 1; i <= M*4; i++) {
    while (k < n && x[k] < i) k++;
    // x が正に一つ動くのでその分 -n(全て x より右側にあると仮定している)
    s -= n;
    // x より左側にある分は + されるのでその分 +1 と上で引いた分を +1 で *2
    s += k*2;
    res[i] = s;
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  int n, d; cin >> n >> d;
  vector<int> x(n), y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector<ll> a = f(x);
  vector<ll> b = f(y);

  ll ans = 0;
  // 尺取法
  int j = b.size()-1;
  REP(i,(int)a.size()) {
    while (j >= 0 && a[i]+b[j] > d) j--;
    ans += j+1;
  }
  cout << ans << endl;
  return 0;
}