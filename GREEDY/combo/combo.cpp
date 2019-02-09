/*
ID: jeremia11
TASK: combo
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> FJkey(3);
vector<int> master(3);

int main(void)
{
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");

  int N;
  fin >> N;
  for (int i  = 0; i < 3; i++)
    fin >> FJkey[i];
  for (int i  = 0; i < 3; i++)
    fin >> master[i];
  
  fout << endl;

  return 0;
}
