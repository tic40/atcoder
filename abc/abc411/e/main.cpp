#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;

int main() {
  int n; cin >> n;
  const int m = 6;
  vector a(n,vector<int>(m));
  REP(i,n) REP(j,m) cin >> a[i][j];

  vector<P> xs;
  REP(i,n) REP(j,m) xs.emplace_back(a[i][j],i);
  sort(xs.begin(),xs.end());

  mint ans = 0;
  int pre = 0;

  mint prod = 1;
  int zero = n;
  vector<int> cnt(n);

  for(auto [x,i]: xs) {
    mint p = 0;
    if (zero == 0) p = prod / mint(m).pow(n);
    ans += (mint(1)-p) * (x-pre);
    pre = x;

    if (cnt[i] == 0) zero--;
    else prod /= cnt[i];

    cnt[i]++;
    prod *= cnt[i];
  }

  cout << ans.val() << endl;
  return 0;
}