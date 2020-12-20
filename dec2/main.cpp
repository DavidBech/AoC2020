#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

bool password_valid(std::string fileLine);

int main(){
    int total_counter = 0;
    int valid_counter = 0;

    std::ifstream input;
    input.open("inputDec2");
    for (std::string line; std::getline(input, line); ) {
        
        if (password_valid(line)) {
            ++valid_counter;
        }
        ++total_counter;
    }
    input.close();

    std::cout << "Total Counter: " << total_counter << ", Valid Counter: " << valid_counter << std::endl;

    return (0);
}

bool password_valid(std::string fileLine){
    int min = 0;
    int max = 0; 
    char required = '\0';
    bool valid = false;
    std::string pass;
 
    std::string buffer;
    std::stringstream ss(fileLine);
    std::vector<std::string> split;
    
    while(std::getline(ss, buffer, ' ')) {
        split.push_back(buffer);
    }

    //split 0, Find min and max values from string
    bool after_split = false;
    for (int i(0); i < split[0].length(); ++i){
        char curr_char = split[0].at(i);
        if (curr_char == '-') {
            //min value
            for (int j(0); j < i; ++j){
                if (i == 2 && j == 0){
                    min += 10*((int)split[0].at(j) - (int)'0');
                }else {
                    min += ((int)split[0].at(j) - (int)'0');
                }
            }
            after_split = true;
        } else if (after_split) {
            //max value
            for (int j(i); j < split[0].length(); ++j){
                if (j==split[0].length()-2) {
                    max += (10)*((int)split[0].at(j) - (int)'0');
                }else {
                    max += ((int)split[0].at(j) - (int)'0');
                }
            }
            break;
        }
    }
    //std::cout << std::endl;
    required = split[1].at(0); 
    pass = split[2]; 

    valid = pass.at(min-1) == required ^ pass.at(max-1) == required;
    return valid;
}
