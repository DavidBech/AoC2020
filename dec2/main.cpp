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

        //if  (++total_counter == 10) {
        //   std::exit(0);
        //}
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
   
    int req_cnt = 0; 
    for (int i(0); i < pass.length(); ++i){
        if (pass.at(i) == required) {
            ++req_cnt; 
        }
    }
    valid = req_cnt >= min && req_cnt <= max ? true : false;
    
    std::cout << fileLine << std::endl;
    //std::cout << std::endl;
    std::cout << "min: " << min << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "required: " << required << std::endl;
    std::cout << "valid: " << (valid ? "true" : "false") << std::endl;
    std::cout << "pass: " << pass << std::endl;
    std::cout << std::endl;
    return valid;
}
