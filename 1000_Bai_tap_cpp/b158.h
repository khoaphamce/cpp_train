#pragma once

#include <iostream>
#include <cmath>
#include <vector>

namespace b158 {
    std::vector<float> arrayInput() {
        int n = 0;
        std::vector<float> arr;

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

    float findX(std::vector<float> arr) {
        if (arr.size() == 0)
            return 0;

        float minArr = arr[0];
        float maxArr = arr[0];

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < minArr)
                minArr = arr[i];

            if (arr[i] > maxArr)
                maxArr = arr[i];
        }

        return std::max(std::abs(maxArr), std::abs(minArr));
    }

    void execute() {
        std::vector<float> arr = arrayInput();

        std::cout << "x found for interval [-x, x] that contain all values: " << findX(arr) << std::endl;

        return;
    }
}