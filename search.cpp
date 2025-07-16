#include "search.h"
#include <vector>
#include <iostream>

// Recursive function to find last occurrence (searches backwards)
template<typename Item_Type>
int recursive_linear_search_last(const std::vector<Item_Type>& items,
    const Item_Type& target,
    int pos) {
    // Base case: reached beginning of vector
    if (pos < 0) {
        return -1;  // Not found
    }

    // Base case: found target (this is the last occurrence since we search backwards)
    if (items[pos] == target) {
        return pos;
    }

    // Recursive case: check previous position
    return recursive_linear_search_last(items, target, pos - 1);
}

// Wrapper function - starts search from end of vector
template<typename Item_Type>
int find_last_occurrence(const std::vector<Item_Type>& items,
    const Item_Type& target) {
    if (items.empty()) {
        return -1;
    }

    return recursive_linear_search_last(items, target, items.size() - 1);
}

int main() {
    // Test vector
    std::vector<int> nums = { 5, 2, 8, 2, 1, 9, 2, 4 };

    std::cout << "Vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Find last occurrence of 2
    int result = find_last_occurrence(nums, 2);
    std::cout << "Last occurrence of 2 is at index: " << result << std::endl;

    return 0;
}
