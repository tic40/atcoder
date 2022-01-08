#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()

int main() {
  string s; cin >> s;
  int n = s.size();
  vector<string> vs;

  REP(i,n) {
    rotate(s.begin(), s.begin()+1, s.end());
    cout << s << endl;
    vs.push_back(s);
  }

  sort(ALL(vs));
  cout << vs[0] << endl << vs.back() << endl;

  return 0;
}