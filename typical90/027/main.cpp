#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;

  map<string,int> mp;
  REP(i,n) {
    string s; cin >> s;
    if (mp[s] == 1) continue;
    mp[s] = 1;
    cout << i+1 << endl;
  }

  return 0;
}