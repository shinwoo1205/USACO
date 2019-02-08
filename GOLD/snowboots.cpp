// modified codeground's skel code
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int Answer;
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
  // N: the number of tiles
  // B: the number of boots
  int N, B;
  freopen ("input.txt", "r", stdin);

  cin >> N >> B;
  feets.resize(N);
  boots.resize(B);
  Answer = 0;
  // initialize tiles
  for (int i = 0; i < N; i++)
    cin >> feets[i]
  // initialize boots
  for (int i = 0; i < B; i++_
    cin >> boots[i].s >> boots[i].d;
  
  cout << Answer << endl;

  return 0;
}
