#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;


int main() {
  string s; cin >> s;
  int n = s.size();

  int cnt = 0;
  vector<string> vs;
  string t;
  REP(i,n) {
    if (isupper(s[i])) {
      t += s[i] + 'a' - 'A';
      cnt++;
      if (cnt == 2) {
        vs.push_back(t);
        t = "";
        cnt = 0;
      }
    } else {
      t += s[i];
    }
  }
  sort(ALL(vs));
  REP(i,vs.size()) {
    vs[i].front() = vs[i].front() + 'A' - 'a';
    vs[i].back() = vs[i].back() + 'A' - 'a';
    cout << vs[i];
  }
  cout << endl;
  return 0;
}