#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  ll s,c; cin >> s >> c;
  ll a = min(s, c / 2);
  ll b = (c - (a*2)) / 4;

  cout << a+b << endl;
  return 0;
}
