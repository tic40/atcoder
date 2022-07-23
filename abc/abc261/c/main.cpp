#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  map<string,int> mp;

  REP(i,n) {
    string s; cin >> s;
    if (mp[s] == 0) cout << s << endl;
    else cout << s << "(" << mp[s] << ")" << endl;
    mp[s]++;
  }
  return 0;
}