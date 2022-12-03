#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> s(n);
  REP(i,n) cin >> s[i];

  cout << s[0] << " ";
  REP(i,n-1) cout << s[i+1] - s[i] << " ";
  cout << endl;
  return 0;
}