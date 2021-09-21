#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  string s;
  cin >> n >> s;

  REP(i,n-2) {
    if (s.substr(i,3) == "joi") {
      s[i] = 'J';
      s[i+1] = 'O';
      s[i+2] = 'I';
    }
  }
  cout << s << endl;
  return 0;
}