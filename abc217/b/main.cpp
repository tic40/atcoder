#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  map<string,int> mp;
  REP(i,3) {
    string s; cin >> s;
    mp[s] = 1;
  }
  vector<string> vs = { "ABC", "ARC", "AGC", "AHC" };
  for(string v: vs) {
    if (mp[v] == 0) {
      cout << v << endl;
      return 0;
    }
  }

  return 0;
}