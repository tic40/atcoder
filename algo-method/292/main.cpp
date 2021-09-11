#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  cout << (regex_search(s,regex(R"(algo)")) ? "Yes" : "No") << endl;
  return 0;
}