#include <iostream>
using namespace std;
int main()
{
  int result = 0;
  for(int i = 0;i < 50;++i){
    for(int j = i + 1;j < 50; ++j){
      if(i < 7 && j < 7) continue;
      result++;
      }
  }
  cout << result;
  return 0;
}