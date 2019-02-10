/*
ID: jeremia11
TASK: crypt1
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int crypt (int i, int j, int k, int l, int m);

//a bit mask for given digits
unsigned int givendigit = 0;
int total = 0;
int main(void)
{
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");

  // process inputs
  int N;
  fin >> N;
  vector<int> digits(N);
  for (int i = 0; i < N; i++) {
    fin >> digits[i];
    givendigit |= (1 << (digits[i] -1));  
  }
  
  // iterate all possible case 
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        for (int l = 0; l < N; l++)
          for (int m = 0; m < N; m++)
            crypt(digits[i], digits[j], digits[k], digits[l], digits[m]);

  fout << total << endl;


  return 0;
}
int crypt (int i, int j, int k, int l, int m)
{
  int multiplicand = 100*i + 10*j + k;
  int partialProduct1 = multiplicand * l;

  // parial product that is lager than 999, which is occupying 4 position, is eliminated 
  if (partialProduct1 >= 1000) return 1;
  int partialProduct2 = multiplicand * m;
  if (partialProduct2 >= 1000) return 2;


  int product = 0; 
  // if each digit in the position of partial product is not included in given digit input, it is eliminated 
  (givendigit & (1 << ((partialProduct1 / 100) - 1))) ? 
  (givendigit & (1 << (((partialProduct1 / 10)% 10) - 1))) ?  
  (givendigit & (1 << (((partialProduct1 % 100)% 10) - 1))) ?  
  (givendigit & (1 << ((partialProduct2 / 100) - 1))) ? 
  (givendigit & (1 << (((partialProduct2 / 10)% 10) - 1))) ?  
  (givendigit & (1 << (((partialProduct2 % 100)% 10) - 1))) ?  
  product = partialProduct1 + partialProduct2*10 : 0 : 0: 0: 0: 0: 0;
 
  // if final product is larger than 10000, it is eliminated.
  if (product >= 10000) return 8;

  // if each digit in the position of final product is not included in given digit input, it is eliminated.
  (givendigit & (1 << ((product / 1000) - 1))) ?
  (givendigit & (1 << (((product / 100) % 10) - 1))) ?
  (givendigit & (1 << (((product % 100) / 10) - 1))) ?
  (givendigit & (1 << (((product % 100) % 10) - 1))) ? 
  total++ : 0 : 0: 0: 0;

  return 0;
}
