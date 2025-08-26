#include "./../include/channel.h"
#include <vector>
#include <random>
#include <iostream>

std::vector<double> Channel::BPSK(const std::vector<double> &code){
  std::vector<double> BPSK_code(code.size(),0);
  for(int i = 0; i < code.size(); i++){
    BPSK_code[i] = 1 - 2 * code[i];
  }
  return BPSK_code;
}
std::vector<double> Channel::hardDecision(const std::vector<double> &code){
  std::vector<double> decided_code(code.size(),0);
  for(int i = 0; i<code.size(); i++){
    if(code[i]<0){
      decided_code[i] = 1;
    }
    else{
      decided_code[i] = 0;
    }
  }
  return decided_code;
}



AWGN::AWGN(double sigma):_sigma(sigma){};

double AWGN::normalRandomGenerate(){
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::normal_distribution<double> dis(0,_sigma);
  return dis(gen);

}

void AWGN::showInformation(){
  std::cout << "该AWGN信道的标准差为：" << _sigma << std::endl << std::endl;
}

std::vector<double> AWGN::transfer(const std::vector<double> &code){
  std::vector<double> decided_code = code;
  for(auto &i:decided_code){
    i += normalRandomGenerate();
  }
  return decided_code;
}


