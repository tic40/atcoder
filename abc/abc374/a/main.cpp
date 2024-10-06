#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  if (s.substr(s.size()-3,3) == "san") cout << "Yes";
  else cout << "No" << endl;
  return 0;
}