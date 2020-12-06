#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>

#ifndef LIST_ENTRIES 
  #define LIST_ENTRIES 10000000
#endif

#ifndef RSEED
  #define RSEED 16
#endif

int find2020(const std::vector<unsigned int>& inList);

int main(){
    srand(RSEED);

    std::vector<unsigned int> inList;
    int list_entries = LIST_ENTRIES;

    inList.reserve(list_entries);

    for (int i(0); i < list_entries; ++i){
        inList.push_back(rand() % 2020);
    }
    int result = find2020(inList);
    std::cout << "Result: " << result << std::endl;
    return (0);
}


int find2020(const std::vector<unsigned int>& List){
    int result = -1;
    unsigned int query_num = 2020;
    std::set<unsigned int> needed;

    for (std::vector<unsigned int>::const_iterator i = List.begin(); i != List.end(); ++i) {
        if (*i >= query_num){
            continue;
        }
        if (needed.find(*i) == needed.end()){
            needed.insert(query_num - *i);
        } else { 
            std::cout << "Found: " << *i << "+" << query_num - *i << std::endl;
            result = *i * (query_num - *i);
            break;
        }
    }
    

    if (result == -1){
        std::cerr << "No Numbers add to 2020" << std::endl;
        std::exit(1);
    }

    return result;
}
