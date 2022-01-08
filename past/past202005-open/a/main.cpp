#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  string s,t;
  cin >> s >> t;
  int n = s.size();

  if (s == t) {
    cout << "same" << endl;
  } else {
    int ok = true;
    REP(i,n) {
      if (tolower(s[i]) != tolower(t[i])) ok = false;
    }
    cout << (ok ? "case-insensitive" : "different") << endl;
  }

  return 0;
}