#pragma once

#include <iostream>
#include <cmath>
#include <vector>

namespace b166 {
    std::vector<int> arrayInput() {
        int n = 0;
        std::vector<int> arr;

        std::cout << "Type in array length: ";
        std::cin >> n;

        while (n <= 0) {
            std::cout << "Array length must be >= 0, please type again: ";
            std::cin >> n;
        }

        std::cout << "Type in array: " << std::endl;
        for (int i = 0; i < n; i++) {
            float newValue;

            std::cout << "Array[" << i << "]: ";

            std::cin >> newValue;
            arr.push_back(newValue);
        }
        return arr;
    }

    int findVal(std::vector<int> arr) {
        if (arr.size() == 0)
            return 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1)
                return 1;
            else if ((arr[i] & (arr[i] - 1)) == 0)
                return arr[i];
        }

        return 0;
    }

    void execute() {
        std::vector<int> arr = arrayInput();

        std::cout << "First value that has 2^k form: " << findVal(arr) << std::endl;

        return;
    }
}