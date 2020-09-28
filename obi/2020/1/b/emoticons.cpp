// Emoticons

#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int sentimento;
string m;

int count(string a, string b) {
  string::size_type pos = 0;
  int res = 0;

  while ((pos = a.find(b, pos)) != string::npos) {
    res++;
    pos += b.length();
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, m);
  sentimento = count(m, ":-)") - count(m, ":-(");
  
  if      (sentimento  > 0) cout << "divertido" ;
  else if (sentimento == 0) cout << "neutro"    ;
  else if (sentimento  < 0) cout << "chateado"  ;

  cout << endl;
}
