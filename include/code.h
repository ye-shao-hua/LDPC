#pragma once 
#include <vector>

class Code{
  public:
    Code() = default;
    Code(int length, int length_information);
    Code(const std::vector<double> &code);
    void showInformation();
    Code &operator=(const Code &others) = default;
    Code operator=(const std::vector<double> &code);
    std::vector<double> code();
    Code operator+(const std::vector<double> &code);
    Code operator+(const Code &others1);
    Code operator+=(const std::vector<double> &code);
    Code operator+=(const Code &others1);
      
  private:
    std::vector<double> _code; 
    int _length{};
    int _length_information{};
    double _rate{};
};
