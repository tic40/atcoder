#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<char> v;
  for(auto c: s) {
    bool ok = false;
    if (v.size()) {
      if (v.back() == '[' && c == ']') ok = true;
      if (v.back() == '(' && c == ')') ok = true;
      if (v.back() == '<' && c == '>') ok = true;
    }
    if (ok) v.pop_back();
    else v.push_back(c);
  }

  cout << (v.size() ? "No" : "Yes") << endl;
  return 0;
}
