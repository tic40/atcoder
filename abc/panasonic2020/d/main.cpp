#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
void dfs(string s, char mx) {
  if ((int)s.size() == n) {
    cout << s << endl;
    return;
  }

  // 追加するのに使えるのは'a'～今まで使われた文字の次の文字」
  // というのを満たす文字列の全列挙
  for(int i = 0; i <= mx-'a'+1; i++) {
    char c = char('a'+i);
    dfs(s+c, max(mx,c));
  }
}

int main() {
  cin >> n;
  dfs("", 'a'-1);

  return 0;
}