#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  cout << (s.size() >= 3 && s.substr(s.size()-3) == "tea" ? "Yes" : "No") << endl;
  return 0;
}