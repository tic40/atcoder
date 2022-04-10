#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<string> s(n),t(n);
  REP(i,n) cin >> s[i] >> t[i];
  map<string,int> ms,mt;
  REP(i,n) { ms[s[i]]++; mt[t[i]]++; }

  REP(i,n) {
    ms[s[i]]--; mt[t[i]]--;
    int ok = 2;
    if (ms[s[i]] || mt[s[i]]) ok--;
    if (ms[t[i]] || mt[t[i]]) ok--;
    ms[s[i]]++; mt[t[i]]++;
    if (ok) { cout << "No" << endl; return 0; }
  }

  cout << "Yes" << endl;
  return 0;
}