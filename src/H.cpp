#include "./../include/H.h"
#include <iostream>
#include <vector>
#include <fstream>

H::H(int number_of_row, int number_of_col):_number_of_col(number_of_col), _number_of_row(number_of_row){
}


H::H(int number_of_row, int number_of_col, std::vector<int> rou, std::vector<int> gamma):_number_of_col(number_of_col),\
                        _number_of_row(number_of_row), _rou(rou), _gamma(gamma){
}

void H::readFile(std::ifstream &ifs){
  readColAndRow(ifs);
  readGammaAndRou(ifs);
  readHcol(ifs);
  readHrow(ifs);

  for(int i=0; i< _number_of_row; i++)
    _H.push_back(std::vector<int>(_number_of_col,0));
  int index_row = 0;

  for(auto i:_H_row){
    for(auto j:i){
      _H[index_row][j-1] = 1;       //注意c++的索引是从零开始，而这个数据是从1开始的
    }
    index_row ++;
  }
}

void H::showInformation(){
  std::cout << "该校验矩阵的行数为：" << _number_of_row << std::endl;
  std::cout << "该校验矩阵的列数为：" << _number_of_col << std::endl;
  std::cout << "该校验矩阵的行重为：";
    for(auto i:_rou){
      std::cout << i << " ";
    }
  std::cout << "\n";
  std::cout << "该校验矩阵的列重为：";
    for(auto i:_gamma){
      std::cout << i << " ";
    }
  std::cout << "\n";

  std::cout <<"该矩阵的列矩阵形式为：\n";
  for(auto i:_H_col){
    for(auto j:i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  std::cout <<"该矩阵的行矩阵形式为：\n";
  for(auto i:_H_row){
    for(auto j:i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  std::cout <<"该矩阵的完整矩阵形式为：\n";
  for(auto i:_H){
    for(auto j:i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

}


void H::readColAndRow(std::ifstream &ifs){
  if(!ifs.is_open())
    std::cout << "文件打开失败\n";
  ifs >> _number_of_col;
  ifs >> _number_of_row;
}

void H::readGammaAndRou(std::ifstream &ifs){
  int max_gamma, max_rou;
  int buffer;
  ifs >> max_gamma;
  ifs >> max_rou;
  for(int i =0; i < _number_of_col; i++){
    ifs >> buffer;
    _gamma.push_back(buffer);
  }
  for(int i =0; i < _number_of_row; i++){
    ifs >> buffer;
    _rou.push_back(buffer);
  }
}

void H::readHcol(std::ifstream &ifs){
  int buffer;
  std::vector<int> one_col; 
  for(int i=0; i<_number_of_col; i++){
    for(int j=0; j<_gamma[i]; j++){
      ifs >> buffer;
      one_col.push_back(buffer);
    }
    _H_col.push_back(one_col);
    one_col.clear();
  }
}

void H::readHrow(std::ifstream &ifs){
  int buffer;
  std::vector<int> one_row; 
  for(int i=0; i<_number_of_row; i++){
    for(int j=0; j<_rou[i]; j++){
      ifs >> buffer;
      one_row.push_back(buffer);
    }
    _H_row.push_back(one_row);
    one_row.clear();
  }
}
