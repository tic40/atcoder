#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  int f = 0;
  REP(i,n) {
    if (s[i] == '"') f ^= 1;
    if (f==0 && s[i] == ',') s[i] = '.';
  }
  cout << s << endl;
  return 0;
}