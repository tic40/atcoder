#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

bool isMM(int num) {
  return num >= 1 && num <= 12 ? true : false;
}

int main() {
  string s;
  cin >> s;
  int s1 = atoi(s.substr(0, 2).c_str());
  int s2 = atoi(s.substr(2, 2).c_str());
  bool isMMS1 = isMM(s1);
  bool isMMS2 = isMM(s2);
  if (!isMMS1 && isMMS2) {
    cout << "YYMM" << "\n";
  } else if (isMMS1 && !isMMS2) {
    cout << "MMYY" << "\n";
  } else if (isMMS1 && isMMS2) {
    cout << "AMBIGUOUS" << "\n";
  } else {
    cout << "NA" << "\n";
  }
}