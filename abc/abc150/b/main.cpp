#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n,ans=0;
  string s;
  cin >> n >> s;
  REP(i,n-2) {
    string abc;
    REP(j, 3) {
      abc.push_back(s[i+j]);
    }
    ans += (abc == "ABC");
  }
  cout << ans << endl;
}
