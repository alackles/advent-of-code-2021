#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

#define BITLEN 5


// bitset parser function
// I like reading things into memory before working with them
// Sue me
std::vector<std::bitset<BITLEN>> parse_bitset(const std::string & fname) {
  
  std::vector<std::bitset<BITLEN>> vec;
  std::ifstream datafile(fname);
  std::string line;
  
  while (getline(datafile, line)) {
    std::bitset<BITLEN> bit_line(line);
    vec.push_back(bit_line);
  }
  
  return vec;
} 

// find the most common bit at an index 
// given a vector of bitsets and an index
bool mcb(const std::vector<std::bitset<BITLEN>> & vec, const size_t & index) {
  int common_bit = 0;
  for (auto entry : vec) {
    if (entry[index] == 0) {
      common_bit--;
    } else {
      common_bit++;
    }
  }
  return common_bit >= 0;
}  


int main() {
}