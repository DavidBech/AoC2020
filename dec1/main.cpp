#include <iostream>
#include <stdlib.h>
#include <vector>

#define LIST_ENTRIES 1000
#define RSEED 12

int find2020(std::vector<int> inList);

int main(){
    srand(RSEED);

    std::vector<int> inList;
    int list_entries = LIST_ENTRIES;

    inList.reserve(list_entries);

    for (int i(0); i < list_entries; ++i){
        inList[i] = rand() % 2021;
    }

    std::cout << "Result: " << find2020(inList) << std::endl;
    return (0);
}


int find2020(std::vector<int> List){
    int result = -1;


    if (result = -1){
        std::cerr << "No Numbers add to 2020" << std::endl;
        std::exit(1);
    }

    return result;
}
