#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>

namespace b306 {
    std::pair<int, std::vector<int>> maxSubCross(std::vector<int> arr, int left, int mid, int right) {
        std::pair<int, std::vector<int>> returnPair;
        std::vector<int> indexVector;
        std::vector<int> tempVector;
        std::vector<int> leftVector;
        std::vector<int> rightVector;
        std::vector<int> midVector;


        // scan left side
        int maxSum = 0;
        int leftSum = 0;

        for (int i = mid; i >= left; i--) {
            tempVector.push_back(i);

            maxSum += arr[i];

            if (maxSum > leftSum) {
                leftSum = maxSum;
                leftVector.insert(leftVector.end(), tempVector.begin(), tempVector.end());
                if (i != mid)
                    midVector.insert(midVector.end(), leftVector.begin(), leftVector.end());
                tempVector.clear();
            }
        }
        tempVector.clear();

        // scan right side
        maxSum = 0;
        int rightSum = INT32_MIN;

        for (int i = mid; i <= right; i++) {
            tempVector.push_back(i);

            maxSum += arr[i];

            if (maxSum > leftSum) {
                rightSum = maxSum;
                rightVector.insert(rightVector.end(), tempVector.begin(), tempVector.end());
                if (i != mid)
                    midVector.insert(midVector.end(), rightVector.begin(), rightVector.end());
                tempVector.clear();
            }
        }
        tempVector.clear();

        std::pair<int, std::vector<int>> leftPair;
        std::pair<int, std::vector<int>> midPair;
        std::pair<int, std::vector<int>> rightPair;

        leftPair.first = leftSum;
        leftPair.second = leftVector;

        rightPair.first = rightSum;
        rightPair.second = rightVector;

        midPair.first = rightSum + leftSum - arr[mid];
        midPair.second = midVector;

        if (leftPair.first >= rightPair.first && leftPair.first >= midPair.first) {
            maxSum = leftPair.first;
            indexVector = leftPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }
        else if (midPair.first >= rightPair.first && midPair.first >= leftPair.first) {
            maxSum = midPair.first;
            indexVector = midPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }
        else if (rightPair.first >= midPair.first && rightPair.first >= leftPair.first) {
            maxSum = rightPair.first;
            indexVector = rightPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }

        return returnPair;
    }



    std::pair<int, std::vector<int>> maxSub(std::vector<int> arr, int left, int right) {
        std::pair<int, std::vector<int>> returnPair;
        int maxSum;
        std::vector<int> indexVector;
        
        // Base case
        if (left == right) {
            maxSum = arr[left];
            indexVector.push_back(left);

            returnPair.first = maxSum;
            returnPair.second = indexVector;

            return returnPair;
        }

        if (left > right) {
            maxSum = INT32_MIN;
            indexVector.push_back(-1);

            returnPair.first = maxSum;
            returnPair.second = indexVector;

            return returnPair;
        }

        // recursive case
        int mid = (left + right) / 2;

        std::pair<int, std::vector<int>> leftPair = maxSub(arr, left, mid - 1);
        std::pair<int, std::vector<int>> midPair = maxSubCross(arr, left, mid, right);
        std::pair<int, std::vector<int>> rightPair = maxSub(arr, mid + 1, right);

        if (leftPair.first >= rightPair.first && leftPair.first >= midPair.first) {
            maxSum = leftPair.first;
            indexVector = leftPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }
        else if (midPair.first >= rightPair.first && midPair.first >= leftPair.first) {
            maxSum = midPair.first;
            indexVector = midPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }
        else if (rightPair.first >= midPair.first && rightPair.first >= leftPair.first) {
            maxSum = rightPair.first;
            indexVector = rightPair.second;

            returnPair.first = maxSum;
            returnPair.second = indexVector;
        }

        return returnPair;
    }


    std::pair<int, std::vector<int>> maxSubArray(std::vector<int>arr) {
        std::pair<int, std::vector<int>> result = maxSub(arr, 0, arr.size() - 1);

        std::sort(result.second.begin(), result.second.end());

        for (int i = 0; i < result.second.size(); i++) {
            while ((i + 1 < result.second.size()) && (result.second[i] == result.second[i + 1])) {
                result.second.erase(result.second.begin() + i + 1, result.second.begin() + i + 2);
            }
        }
        return result;
    }
    

    void execute() {
        std::vector<int> arr;
        int n;

        std::cout << "Type in array length: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            int newEle;
            std::cout << "array[" << i << "]: ";
            std::cin >> newEle;

            arr.push_back(newEle);
        }

        std::pair<int, std::vector<int>> result = maxSubArray(arr);

        std::cout << "\nMax sum of sub array: " << result.first << "\n";

        std::cout << "Index of sub array with maximum sum: ";
        for (int i = 0; i < result.second.size(); i++) {
            std::cout << result.second[i] << ' ';
        }
        std::cout << "\n\n\n";

        return;
    }
}