#pragma once

#include <iostream>
#include <string>

namespace b115 {

    std::string inputName() {
        std::string inpName;
        std::cout << "Name: ";
        std::cin >> inpName;
        return inpName;
    }

    float inputMath() {
        float mathGrade;
        std::cout << "Math grade: ";
        std::cin >> mathGrade;
        return mathGrade;
    }

    float inputLiterature() {
        float litGrade;
        std::cout << "Literature grade: ";
        std::cin >> litGrade;
        return litGrade;
    }

    float averageScore(float grade1, float grade2) {
        return(grade1 + grade2) / 2;
    }

    void printInfo(std::string studentName, float avgGrade) {
        std::cout << "Student name: " << studentName << std::endl;
        std::cout << "Average grade: " << avgGrade << std::endl;
    }

    void execute() {
        std::string studentName = inputName();
        float grade1 = inputMath();
        float grade2 = inputLiterature();
        float avgGrade = averageScore(grade1, grade2);
        std::cout << std::endl;
        printInfo(studentName, avgGrade);
    }
}