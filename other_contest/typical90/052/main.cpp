#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> s(n);
  REP(i,n) REP(j,6) {
    int a; cin >> a;
    s[i] += a;
  }

  mint now = 1;
  REP(i,n) now *= s[i];
  cout << now.val() << endl;
  return 0;
}