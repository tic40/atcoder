#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
void dfs(string s, int mx) {
  if ((int)s.size() == n) {
    cout << s << endl;
    return;
  }

 // 追加するのに使えるのは'a'～今まで使われた文字の次の文字
 // というのを満たす文字列の全列挙
  for(int i = 0; i <= mx+1; i++) {
    char c = char('a' + i);
    dfs(s+c, max(mx, c-'a'));
  }

  return;
}

int main() {
  cin >> n;
  dfs("", -1);
  return 0;
}