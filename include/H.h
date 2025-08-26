#pragma once
#include <vector>
#include <fstream>

class H{
public:
  H() = default;
  H(int number_of_row, int number_of_col);
  H(int number_of_row, int number_of_col, std::vector<int> rou, std::vector<int> gamma);
  void readFile(std::ifstream &ifs);
  void showInformation();

private:
  void readColAndRow(std::ifstream &ifs);
  void readGammaAndRou(std::ifstream &ifs);
  void readHcol(std::ifstream &ifs);
  void readHrow(std::ifstream &ifs);

private:

  int _number_of_row{};
  int _number_of_col{};
  std::vector<int> _rou;
  std::vector<int> _gamma;
  std::vector<std::vector<int>> _H;
  std::vector<std::vector<int>> _H_row;
  std::vector<std::vector<int>> _H_col;
};
