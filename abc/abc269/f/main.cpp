#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  int n,m,q; cin >> n >> m >> q;

  auto sum2 = [&](int x, int y, mint a) {
    // 左上(最小)と右下(最大)の値を割る2すると平均値が求まる
    mint ave = (a + (a + mint(x-1) * m * 2 + (y-1) * 2) ) / 2;
    return ave * x * y; // 平均値　x　マス目の数
  };

  auto sum = [&](int x, int y) {
    mint res = 0;
    // 偶数行と奇数行それぞれのsumを取る
    res += sum2((x+1)/2, (y+1)/2, 1); // 奇数
    res += sum2(x/2, y/2, m+2); // 偶数
    return res;
  };

  REP(i,q) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; c--;

    mint ans = 0;
    ans += sum(b,d);
    ans -= sum(a,d);
    ans -= sum(b,c);
    ans += sum(a,c);
    cout << ans.val() << endl;
  }
  return 0;
}