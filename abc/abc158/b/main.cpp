#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = unsigned long long;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans = (n / (a+b) * a) + min(a, n % (a+b));
  cout << ans << endl;
  return 0;
}