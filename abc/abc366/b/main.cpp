#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  int m = 0;
  REP(i,n) {
    cin >> s[i];
    m = max(m,(int)s[i].size());
  }

  REP(i,m) {
    string t = "";
    REP(j,n) t += ((int)s[j].size() > i) ? s[j][i] : '*';
    reverse(t.begin(),t.end());
    while(t.back() == '*') t.pop_back();
    cout << t << endl;
  }
  return 0;
}