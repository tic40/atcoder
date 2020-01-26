#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

ll a,b,x;

ll f(ll n) {
  if (n >= 0) return n / x + 1;
  return 0;
}

int main() {
  cin >> a >> b >> x;
  cout << f(b) << endl;
  cout << f(a-1) << endl;
  cout << f(b) - f(a-1) << endl;
}