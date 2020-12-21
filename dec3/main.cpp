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

int main(){
    std::ifstream input;//input file
    std::vector<std::uint32_t> hill; //hill
    int tree_quant = 0;//trees hit
    int slope[2] = {3, 1}; //right, down
    int pos = 0; //right%31, down

    input.open("inputdec3.txt");

    int line_cntr = 0;
    for (std::string fline; std::getline(input, fline); ) {
        hill.push_back(get_hill(fline));
        ++line_cntr;
    }
    input.close();


    for (int i(0); i <= line_cntr; ++i){
        if (hill[i] & (1 << (pos+1))) {
            ++tree_quant; 
        }
        pos += 3;
        pos %= 31;
    }

    std::cout << "Trees Hit: " << tree_quant << std::endl; 
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

void print_hill_line(std::vector<std::uint32_t>& hill, int line) {
    bool temp;
    for (int i(1); i < 32; ++i){
        temp = hill[line] & (1 << i);
        std::cout << temp;
    }
    return;
}
