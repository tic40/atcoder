#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  int m = 0;
  while((1<<m) < n) m++;
  cout << m << endl;
  REP(i,m) {
    vector<int> a;
    REP(j,n) if ((j>>i)&1) a.push_back(j);
    cout << a.size();
    for(auto v: a) cout << " " << v+1;
    cout << endl;
  }

  string s; cin >> s;
  int ans = 0;
  // reverse(s.begin(),s.end());
  // REP(i,m) ans = ans * 2 + (s[i]-'0');
  REP(i,m) if (s[i] == '1') ans |= 1<<i;
  cout << ans+1 << endl;

  return 0;
}