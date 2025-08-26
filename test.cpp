#include <iostream>
#include <H.h>
#include <code.h>
#include <vector>
#include <channel.h>
#include <fstream>

int main(){
  std::ifstream ifs{"./etc/H_96_48.txt"};
  H h1;
  
  h1.showInformation();

  

  h1.readFile(ifs);
  h1.showInformation();
  //h1.showInformation();

  return 0;
}
