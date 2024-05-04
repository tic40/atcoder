#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = s.size();
  int now = 0;
  REP(i,(int)t.size()) {
    if (now < n && s[now] == t[i]) { cout << i+1 << " "; now++; }
  }
  return 0;
}