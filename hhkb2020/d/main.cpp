#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int mod = 1000000007;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  int t;
  cin >> t;
  REP(i,t) {
    ll n,a,b;
    cin >> n >> a >> b;

    // N正方形内に赤と青の正方形を置く全パターンを求める
    mint ax = n-a+1; // N内にaの区間を置くパターン
    mint bx = n-b+1; // N内にbの区間を置くパターン
    mint all = ax*ax*bx*bx;

    // 赤い正方形の内部と青い正方形の内部が重なるケースを求める

    // x4: 空白マスはn-a-b.
    // (空白)(赤)(空白)(青)(空白) となるため空白+(赤と青分の+2)から2つを選ぶ組み合わせを求める
    mint x4 = a+b <= n ? (n-a-b+2)*(n-a-b+1)/2 : 0;
    mint x3 = x4*2;
    mint x2 = ax*bx-x3;
    mint x1 = x2*x2;

    // 全体から内部が重なるケースを引く
    mint ans = all-x1;
    cout << ans << endl;
  }
}