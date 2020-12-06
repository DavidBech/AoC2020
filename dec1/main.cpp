#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <fstream>
#include <string>

#define ADDER_COUNT 3

#define FILE_IN
#ifdef RAND_IN
  #undef FILE_IN

  #ifndef LIST_ENTRIES 
    #define LIST_ENTRIES 10000000
  #endif
  
  #ifndef RSEED
    #define RSEED 16
  #endif
#endif //RAND_IN

int find_product(const std::vector<unsigned int>& inList, unsigned int query_num, unsigned int num_quant);

int main(){

    std::vector<unsigned int> inList;

#ifdef FILE_IN
    std::ifstream input;
    input.open("inputDec1");
    for (std::string line; std::getline(input, line); ) {
        inList.push_back(std::stoi(line));
    }
    input.close();
#endif //RAND_IN

#ifdef RAND_IN
    srand(RSEED);
    int list_entries = LIST_ENTRIES;

    inList.reserve(list_entries);

    for (int i(0); i < list_entries; ++i){
        inList.push_back(rand() % 2020);
    }
#endif //RAND_IN

    unsigned int result = (unsigned int)find_product(inList, 2020, ADDER_COUNT);
    std::cout << std::endl << "Result: " << result << std::endl;
    return (0);
}


int find_product(const std::vector<unsigned int>& List, unsigned int query_num, unsigned int num_quant){
    long int result = -1;
    std::set<unsigned int> needed;

    if (num_quant == 1){
        std::cerr << "Cannot find product with one input" << std::endl;
        std::exit(1);
    }
        
    for (std::vector<unsigned int>::const_iterator i = List.begin(); i != List.end(); ++i) {
        if (*i >= query_num){
            continue;
        }
        
        if (num_quant > 2) {
            int sub_prod = find_product(List, (query_num-*i), num_quant-1); 
    
            if (sub_prod == -1){
                needed.insert(query_num - *i);
                continue; 
            }
            
            //std::cout << " + " << *i;
            result = (sub_prod * *i);
            break;
        } else if (needed.find(*i) == needed.end()){
            needed.insert(query_num - *i);
        } else { 
            //std::cout << " " << *i << " + " << query_num - *i;
            result = *i * (query_num - *i);
            break;
        }
    }
    return result;
}
