// modified codeground's skel code
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//s: at most s feets of snow that FJ can step 
//d: the maximum distance that FJ can step once
struct boot {
  int s;
  int d;
}
vector<int> feets;
vector<boot> boots;

int main(void)
{
  ofstream fout ("snowboots.out");
  ifstream fin ("snowboots.in");
  // N: the number of tiles
  // B: the number of boots
  int N, B;

  fin >> N >> B;
  feets.resize(N);
  boots.resize(B);
  // initialize tiles
  for (int i = 0; i < N; i++)
    fin >> feets[i]
  // initialize boots
  for (int i = 0; i < B; i++_
    fin >> boots[i].s >> boots[i].d;
  
  fout << endl;

  return 0;
}
