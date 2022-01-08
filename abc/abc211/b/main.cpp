#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  vector<string> v = { "H", "2B", "3B", "HR" };
  vector<string> s(4);
  REP(i,4) cin >> s[i];
  sort(s.begin(), s.end());
  sort(v.begin(), v.end());

  cout << (s == v ? "Yes" : "No") << endl;
  return 0;
}