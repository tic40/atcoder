#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x; cin >> n >> x;
  string a; cin >> a;
  x--;
  queue<int> q;
  q.push(x);

  while(q.size()) {
    int pos = q.front(); q.pop();
    a[pos] = '@';
    if (pos-1 >= 0 && a[pos-1] == '.') q.push(pos-1);
    if (pos+1 < n && a[pos+1] == '.') q.push(pos+1);
  }
  cout << a << endl;
  return 0;
}