#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<string> s(n), t(n);
  REP(i,n) cin >> s[i] >> t[i];
  map<string,int> ms, mt;
  REP(i,n) { ms[s[i]]++; mt[t[i]]++; }

  REP(i,n) {
    ms[s[i]]--; mt[t[i]]--;
    bool sok = true, tok = true;
    if (ms[s[i]] > 0 || mt[s[i]] > 0) sok = false;
    if (ms[t[i]] > 0 || mt[t[i]] > 0) tok = false;
    ms[s[i]]++; mt[t[i]]++;

    if (!tok && !sok) { cout << "No" << endl; return 0; }
  }

  cout << "Yes" << endl;
  return 0;
}