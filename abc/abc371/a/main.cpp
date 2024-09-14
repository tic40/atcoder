#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector op(3,vector<char>(3));
  cin >> op[0][1] >> op[0][2] >> op[1][2];
  op[1][0] = op[0][1] == '<' ? '>' : '<';
  op[2][0] = op[0][2] == '<' ? '>' : '<';
  op[2][1] = op[1][2] == '<' ? '>' : '<';
  vector<int> s = {0,1,2};
  sort(s.begin(),s.end(),[&](int a, int b){ return op[a][b] == '<'; });
  cout << char('A' + s[1]) << endl;
  return 0;
}