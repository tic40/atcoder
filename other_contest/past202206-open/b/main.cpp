#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  map<string,int> mp;
  REP(i,n-1) {
    string ns = "";
    ns += s[i];
    ns += s[i+1];
    mp[ns]++;
  }

  int mx = 0;
  string ans = "";
  for(auto [a,b]: mp) if (b > mx) { ans = a; mx = b; }
  cout << ans << endl;
  return 0;
}