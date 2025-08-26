#pragma once 
#include <vector>

class Channel{
  public:
    Channel()=default;
    std::vector<double> BPSK(const std::vector<double> &code);
    std::vector<double> hardDecision(const std::vector<double> &code);
    virtual std::vector<double> transfer(const std::vector<double> &code)=0;
  private:
};

class AWGN:public Channel{
  public:
    AWGN() = default;
    AWGN(double sigma);
    AWGN &operator=(const AWGN &others) = default;
    double normalRandomGenerate();
    void showInformation();
    std::vector<double> transfer(const std::vector<double> &code) override ;
  private:
    double _sigma{};
};
