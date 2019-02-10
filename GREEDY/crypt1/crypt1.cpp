/*
ID: jeremia11
TASK: crypt1
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//a bit mask for given digits
int givendigit = 0;
int main(void)
{
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");

  // process inputs
  int N;
  fin >> N;
  for (int i = 0; i < N; i++) {
    int temp;
    fin >> temp;
    temp -= 1;
    givendigit |= (1 << temp);  
  }
  fout << endl;

  return 0;
}
