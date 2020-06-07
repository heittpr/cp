#include <iostream>
#include <algorithm>
using namespace std;

struct horario { int inicio, fim; };
bool compara(horario a, horario b) { return a.fim < b.fim; }
int N, livre, resposta;

int main() {
  cin >> N;
  horario consultas[N];

  for ( int i = 0; i < N; i++ )
    cin >> consultas[i].inicio >> consultas[i].fim;

  sort(consultas, consultas+N, compara);

  for ( auto consulta : consultas ) {
    if ( consulta.inicio >= livre ) {
      resposta++;
      livre = consulta.fim;
    }
  }

  cout << resposta << endl;
  return 0;
}
