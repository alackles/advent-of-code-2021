#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

// parser function
std::vector<std::string> col_parser(const std::string & fname) {
  std::vector<std::string> vec;
  std::string line;
  std::ifstream datafile(fname);
  while (getline(datafile, line)) {
    vec.resize(line.size());
    for (size_t i = 0; i < line.size(); ++i) {
        vec[i].push_back(line[i]);
    }   
  }
  return vec;
}

int main() {
  std::vector<std::string> power = col_parser("data/03.txt");
  size_t midpt = power[0].size()/2;
  std::string gamma;
  std::string epsilon;
  for (auto col : power) {
      size_t ct = std::count(col.begin(), col.end(), '1');
      gamma.push_back((ct > midpt) ? '1' : '0');
      epsilon.push_back((ct < midpt) ? '1' : '0');
  }
  int gamma_int = std::stoi(gamma, 0, 2);
  int epsilon_int = std::stoi(epsilon, 0, 2);
  std::cout << "Gamma: " << gamma_int << std::endl;
  std::cout << "Epsilon: " << epsilon_int << std::endl;
  std::cout << "Power: " << gamma_int * epsilon_int << std::endl;
}