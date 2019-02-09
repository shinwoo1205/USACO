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
//Farmer John's key and Master Key
vector<int> FJkey(3);
vector<int> Mkey(3);
//Farmer John's possible value and master's possible value
int FJPossible[3][5];
int MPossible[3][5];
int N;

void determinePossible(const int keyvalue, int* possible);
int main(void)
{
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");

  fin >> N;
  for (int i  = 0; i < 3; i++)
    fin >> FJkey[i];
  for (int i  = 0; i < 3; i++)
    fin >> Mkey[i];
  for (int i = 0; i < 3; i++){
    determinePossible(FJkey[i], FJPossible[i]);
    determinePossible(Mkey[i], MPossible[i]);    
  }  

  

  // count FJ case 
  int FJcase = 1;
  for (int i = 0; i < 3; i++){
    int FJcount = 0;
    for (int j = 0; j < 5; j++){
      if (FJPossible[i][j] == 0)
        continue;
      FJcount++; 
    }
    FJcase *= FJcount; 
  }
  // count M case
  int Mcase = 1;
  for (int i = 0; i < 3; i++){
    int Mcount = 0;
    for (int j = 0; j < 5; j++){
      if (MPossible[i][j] == 0)
        continue;
      Mcount++; 
    }
    Mcase *= Mcount; 
  }

  // count duplicate case between FJkey and Master key
  int dupcase=1;
  for (int i = 0; i < 3; i++){
    int dupcount=0;
    for(int j = 0; j < 5; j++){
      if(FJPossible[i][j] == 0)
        continue;
      for(int k = 0; k < 5; k++)
        if(FJPossible[i][j] == MPossible[i][k]) 
          dupcount++; 
    } 
    dupcase *= dupcount;
  }


  int totalcase = 0;
  totalcase = FJcase + Mcase - dupcase;

  fout << totalcase << endl;

  return 0;
}
//define possible value  (value-2, value-1, value, value+1, value+2)
void determinePossible(const int keyvalue, int* possible)
{
  possible[0] = keyvalue;
  possible[1] = keyvalue + 1;
  if (possible[1] == (N+1))  
    possible[1] = 1;

  possible[2] = keyvalue + 2;
  if (possible[2] == (N+1))
    possible[2] = 1;
  if (possible[2] == (N+2))
    if (N == 1)
      possible[2] = 1;
    else
      possible[2] = 2;

  possible[3] = keyvalue - 1;
  if (possible[3] == 0) 
    possible[3] = N;

  possible[4] = keyvalue - 2; 
  if (possible[4] == 0)
    possible[4] = N;
  if (possible[4] == -1)
    possible[4] = N - 1 ;
    


  // delete duplicate value
  for(int i = 0; i < 5; i++)
    for(int j = i + 1; j < 5; j++){
      if (possible[i] == 0) 
        break;
      else
        if (possible[i] == possible[j])
          possible[j] = 0;
    }
}
