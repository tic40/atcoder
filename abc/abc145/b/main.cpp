#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {

  int n;
  string s;
  cin >> n >> s;
  string sa = s.substr(0, s.size()/2);
  string ans = (sa + sa) == s ? "Yes" : "No";
  cout << ans << endl;
}