/*
ID: jeremia11
TASK: shuffle
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<string> cownames;
//shuffle order
vector<int> s_order;
shuffle
int main(void)
{
  ofstream fout ("shuffle.out");
  ifstream fin ("shuffle.in");

  // process inputs
  int N;
  fin >> N;
  s_order.resize(N+1);
  cownames.resize(N+1);
  //process input
  for (int i = 1; i <= N; i++) 
	  fin >> s_order[i];
  for (int i = 1; i <= N; i++) 
	  fin >> cownames[i];
  

  return 0;
}

