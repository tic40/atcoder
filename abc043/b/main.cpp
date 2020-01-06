#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s,ans;
  cin>>s;
  REP(i,s.size()) {
    if (s[i] == '0' || s[i] == '1') ans.push_back(s[i]);
    else if (ans.size() > 0) ans.pop_back();
  }
  cout << ans << endl;
}
