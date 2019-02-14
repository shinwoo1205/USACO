/*
ID: jeremia11
TASK: hayfeast
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
  ofstream fout ("hayfeast.out");
  ifstream fin ("hayfeast.in");

  // process inputs
  int N, M;
  fin >> N >> M;
  // first : spiceness, second: flavor 
  vector<pair<int, int>> hays(N);
  for (int i = 0; i <N; i++)
	  fin >> hays.second >> hays.first;
	  
 
  fout << endl;


  return 0;
}

