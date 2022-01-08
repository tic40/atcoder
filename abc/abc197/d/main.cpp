#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

const double PI = 2 * acos(0.0);
using C = complex<double>;
namespace std {
  C operator / (const C& a, const double& b) { return C(real(a) / b, imag(a) / b); }
  C operator * (const C& a, const double& b) { return C(real(a) * b, imag(a) * b); }
}

// 複素数 complex<double> を ラジアン分回転させる
// 角度からラジアン = 角度*PI/180
C rotate(C vec, double rad) {
  double x = real(vec), y = imag(vec);
  return C(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
}

int main() {
  int n; cin >> n;
  int x, y;

  cin >> x >> y; C p0 = C(x, y);
  cin >> x >> y; C p2 = C(x, y);

  C center = (p0 + p2) / 2;
  C ans = rotate(p0 - center, 360.0 / n * PI / 180.0) + center;

  printf("%0.9f %0.9f\n", real(ans), imag(ans));
  return 0;
}