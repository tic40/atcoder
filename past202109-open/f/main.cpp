#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; string s;
  cin >> n >> s;

  vector<int> m;
  REP(i,n) if (s[i] == '0') m.push_back(i+1);

  if ((int)m.size() == 1) {
    cout << -1 << endl;
    return 0;
  }

  int cur = 1;
  REP(i,n) {
    if (s[i] == '1') {
      cout << i+1 << " ";
    } else {
      cout << m[ cur % m.size() ] << " ";
      cur++;
    }
  }
  cout << endl;

  return 0;
}