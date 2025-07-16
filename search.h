#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

// Function to find last occurrence of target in vector
template<typename Item_Type>
int recursive_linear_search_last(const std::vector<Item_Type>& items,
    const Item_Type& target,
    int pos);

// Wrapper function
template<typename Item_Type>
int find_last_occurrence(const std::vector<Item_Type>& items,
    const Item_Type& target);



#endif
