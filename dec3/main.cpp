#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
std::uint32_t get_hill(std::string fileLine);
void print_hill_line(std::vector<std::uint32_t>& hill, int line);
unsigned int find_trees(const std::vector<std::uint32_t>& hill, int slope[2]);


int main(){
    std::ifstream input;//input file
    std::vector<std::uint32_t> hill; //hill

    unsigned long int result = 1;

    input.open("inputdec3.txt");

    int line_cntr = 0;
    for (std::string fline; std::getline(input, fline); ) {
        hill.push_back(get_hill(fline));
        ++line_cntr;
    }
    input.close();
    
    int slope[2] = {3, 1};
    result *= find_trees(hill, slope);
    slope[0] = 1; 
    result *= find_trees(hill, slope);
    slope[0] = 5; 
    result *= find_trees(hill, slope);
    slope[0] = 7; 
    result *= find_trees(hill, slope);
    slope[0] = 1; 
    slope[1] = 2; 
    result *= find_trees(hill, slope);



    std::cout << "Trees Hit Multi Together: " << result << std::endl; 
    return (0);
}

std::uint32_t get_hill(std::string line){
    std::uint32_t temp = 0;

    for (int i(0); i < 31; ++i) {
        if (line.at(i) == '#'){
            temp += 1 << i+1;
        }
    } 
    return temp;
}

void print_hill_line(const std::vector<std::uint32_t>& hill, int line) {
    bool temp;
    for (int i(1); i < 32; ++i){
        temp = hill[line] & (1 << i);
        std::cout << temp;
    }
    return;
}

unsigned int find_trees(const std::vector<std::uint32_t>& hill, int slope[2]) {
    int y = 0; 
    unsigned int tree_quant = 0;

    for (int i(0); i <= hill.size(); i+=slope[1]){

        if (hill[i] & (1 << (y+1))) {
            ++tree_quant; 
        }
        y += slope[0];
        y %= 31;
        
    }
    return tree_quant;
}
