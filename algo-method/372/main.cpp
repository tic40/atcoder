#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  map<char,char> mp = { {'J', '0'}, {'O', '1'}, {'I', '2'} };
  string m = "JOI";
  REP(i,n) s[i] = mp[s[i]];
  sort(s.begin(),s.end());
  REP(i,n) cout << m[s[i]-'0'];
  cout << endl;
  return 0;
}