#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  sort(s.begin(),s.end());
  cout << (s == "ABC" ? "Yes" : "No") << endl;
  return 0;
}