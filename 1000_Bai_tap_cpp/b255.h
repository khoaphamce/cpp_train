#pragma once

#include <string>
#include <iostream>
#include <vector>

namespace b255 {
    void quickSortRec(std::vector<float>& arr, int left, int right) {
        int pivot = (left+right)/2;

        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] < arr[pivot])
                i++;
            while (arr[j] > arr[pivot])
                j--;

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quickSortRec(arr, left, j);
        if (right > i)
            quickSortRec(arr, i, right);
    }

    void quickSort(std::vector<float>& arr) {
        quickSortRec(arr, 0, arr.size() - 1);
    }

    void execute() {
        std::vector<float> arr;

        int n;

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

        quickSort(arr);

        std::cout << "Array after quick sort: ";

        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n\n";

        return;
    }
}
