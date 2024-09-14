#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  char sab, sac, sbc;
  cin >> sab >> sac >> sbc;
  if (sab == '>' && sac == '>' && sbc == '>') {
    cout << "b" << endl;
  }
  else if (sab == '>' && sac == '>' && sbc == '<') {
    cout << "c" << endl;
  }
  else if (sab == '>' && sac == '<' && sbc == '>') {
    // invalid
  }
  else if (sab == '>' && sac == '<' && sbc == '<') {
    cout << "a" << endl;
  }
  else if (sab == '<' && sac == '>' && sbc == '>') {
    cout << "a" << endl;
  }
  else if (sab == '<' && sac == '>' && sbc == '<') {
    // invalid
  }
  else if (sab == '<' && sac == '<' && sbc == '>') {
    cout << "c" << endl;
  }
  else if (sab == '<' && sac == '<' && sbc == '<') {
    cout << "b" << endl;
  }

  return 0;
}