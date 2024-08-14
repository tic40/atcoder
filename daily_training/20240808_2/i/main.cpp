#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int M = 10;

int main() {
  int n,q; cin >> n >> q;
  vector<dsu> uf(M+1,dsu(n));
  vector<int> cnt(M+1);

  auto add = [&]() -> void {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    for(int i = c; i <= M; i++) if (!uf[i].same(a,b))  {
      cnt[i]++;
      uf[i].merge(a,b);
    }
  };

  REP(i,n-1) add();
  REP(_,q) {
    add();
    int ans = 0;
    for(int i = 1; i <= M; i++) ans += (cnt[i] - cnt[i-1]) * i;
    cout << ans << endl;
  }
  return 0;
}