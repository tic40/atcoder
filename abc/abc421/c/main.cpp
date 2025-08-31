#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;
  n *= 2;
  vector<int> a;
  REP(i,n) if (s[i] == 'A') a.push_back(i);

  auto f = [&](int m) {
    ll cnt = 0;
    REP(i,n) if (i % 2 == m) cnt += abs(a[i/2] - i);
    return cnt;
  };
  cout << min(f(0),f(1)) << endl;
  return 0;
}