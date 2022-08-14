#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const string atc = "atcoder";
const int n = 7;

int main() {
  string s; cin >> s;
  int ans = 0;
  REP(i,n) {
    int ni = -1;
    for(int j = i; j < n; j++) if (atc[i] == s[j]) ni = j;

    while(i != ni) {
      swap(s[ni],s[ni-1]);
      ans++;
      ni--;
    }
  }
  cout << ans << endl;
  return 0;
}