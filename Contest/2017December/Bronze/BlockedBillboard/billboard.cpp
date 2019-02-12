/*
ID: jeremia11
TASK: billboard
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct pair {
	int x;
	int y;
};
struct rect {
	struct pair lowerleft;
	struct pair upperright;
};
int main(void)
{
  ofstream fout ("billboard.out");
  ifstream fin ("billboard.in");

  // process inputs
  struct rect board1, board2, truck;
  fin >> board1.lowerleft.x >> board1.lowerleft.y >> board1.upperright.x >> board1.upperleft.y;
  fin >> board2.lowerleft.x >> board2.lowerleft.y >> board2.upperright.x >> board2.upperleft.y;
  fin >> truck.lowerleft.x >> truck.lowerleft.y >> truck.upperright.x >> truck.upperleft.y;
 
 
 
  fout << << endl;


  return 0;
}

