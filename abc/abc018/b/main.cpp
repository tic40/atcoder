#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s;
  int n,l,r;
  cin >> s >> n;
  REP(i,n) {
    cin >> l >> r;
    reverse(s.begin() + l-1, s.begin() + r);
  }
  cout << s << endl;
}
