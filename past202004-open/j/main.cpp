#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

string s;
int n, idx = 0;

string parse() {
  if (n <= idx) return "";

  if (s[idx] == ')') {
    return "";
  }

  string res = "";
  if (s[idx] == '(') {
    idx++;
    res += parse();
    string ser = res;
    reverse(ser.begin(), ser.end());
    idx++;
    return res + ser + parse();
  }

  res += s[idx];
  idx++;
  return res + parse();
}

int main() {
  cin >> s;
  n = s.size();
  cout << parse() << endl;
  return 0;
}