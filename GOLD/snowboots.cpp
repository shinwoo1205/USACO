// modified codeground's skel code
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//s: at most s feets of snow that FJ can step 
//d: the maximum distance that FJ can step once
struct boot {
  int s;
  int d;
};
vector<int> feets;
vector<boot> boots;

int step (const int current, const int deep, const int distance);
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
    fin >> feets[i];
  // initialize boots
  for (int i = 0; i < B; i++)
    fin >> boots[i].s >> boots[i].d;
 
  for (int i = 0; i< B; i++)
    fout << step(0, boots[i].s, boots[i].d) << endl; 

  return 0;
}
int step (const int current, const int deep, const int distance)
{
  // if current is equal the end of the path, to step over the snowpath succeeed
  //cout << "current is " << current << endl;
  //cout << "boots[i].s is " << deep << endl;
  //cout << "boots[i].d is " << distance << endl;
  if (current >= (feets.size() -2))
    return 1;
  int stepsize = distance; 
  int stepto = 0;
  ((current + stepsize) >= feets.size()) ? stepto = feets.size()-1 : stepto = current + stepsize;
  //cout << "stepto is " << stepto << endl;
  while (stepsize != 0){
    if (feets[stepto] > deep) {
   //   cout << " feets[" << stepto << "] : " << feets[stepto] << "deep is " << deep << endl;
      stepsize -= 1;
      stepto = current + stepsize;
      continue;
    }        
    else
      return step(stepto, deep, distance);
  }
  // to this, it is impossilbe to step further 
  return 0;
}


