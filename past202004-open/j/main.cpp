#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

string s;
int idx = 0;

string parse() {
  string res = "";

  if (s[idx] == '(') {
    idx++;
    res += parse();

    string ser = res;
    reverse(ser.begin(),ser.end());
    idx++;

    return res + ser + parse();
  }

  if ('a' <= s[idx] && s[idx] <= 'z') {
    res += s.substr(idx,1);
    idx++;
    res += parse();
    return res;
  }

  return res;
}

int main() {
  cin >> s;

  cout << parse() << endl;
  return 0;
}