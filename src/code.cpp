#include "./../include/code.h"
#include <iostream>
#include <vector>

Code::Code(int length, int length_information):_length(length),\
        _length_information(length_information){
  _rate = (double)_length_information/(double)_length;
  _code = std::vector<double>(_length,0); 
}

Code::Code(const std::vector<double> &code){
    *this = code;
}

void Code::showInformation(){
  std::cout << "序列长度为："<< _length << std::endl;
  std::cout << "信息位长度为："<< _length_information << std::endl;
  std::cout << "码率为："<< _rate << std::endl;
  std::cout << "序列为：";
  for(auto i:_code){
    std::cout << i <<" ";
  }
  std::cout << std::endl << std::endl;
}

/*
Code Code::operator=(const Code &others){
  this->_length = others._length;
  this->_length_information = others._length_information;
  this->_rate = others._rate;
  this->_code = others._code;
  return *this;
}
*/

Code Code::operator=(const std::vector<double> &code){
  this->_code = code;
  return *this;
}

std::vector<double> Code::code(){
  return _code;
}


Code Code::operator+(const std::vector<double> &code){
  if(code.size()!=this->_code.size()){
    std::cout << "序列长度不同，无法做加操作\n";
      return *this;
  }
  for(int i = 0;i<code.size();i++){
    this->_code[i] += code[i];
  }
  return *this;
}

Code Code::operator+(const Code &others1){
  *this = *this + others1._code;
  return *this;
}


Code Code::operator+=(const std::vector<double> &code){
  *this = *this + code;
  return *this;
}

Code Code::operator+=(const Code &others1){
  *this = *this + others1;
  return *this;
}
