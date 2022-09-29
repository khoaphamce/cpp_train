#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class SLinkedList {
public:
    struct Student {
        std::string name;
        float mathGrade;
        float litGrade;
        float avgGrade;
        Student* next;

        Student(std::string newName, float newMathGrade, float newLitGrade, float newAvgGrade) :
            name(newName), mathGrade(newMathGrade), litGrade(newLitGrade), avgGrade(newAvgGrade), next(NULL) {}
    };

private:
    Student* root = NULL;

    // Recursive functions
    Student * addRec(Student* rootNode, Student* newNode);
    Student * deleteRec(Student* rootNode, std::string deleteName);
    int countRec(Student* rootNode);
    void listUnder5Rec(Student* rootNode);
    int countLarger8Rec(Student* rootNode);
    void displayRec(Student* rootNode);


public:
    // Add student
    void addStudent(std::string newName, float newMathGrade, float newLitGrade, float newAvgGrade);

    // Delete student
    bool deleteStudent(std::string deleteName);

    // Count student
    int countStudent();

    // Count student math < 5
    void listUnder5Math();

    // Count student math and lit > 5
    int countLarger8LitMath();

    // Sort avg grade decrease
    bool sortAvgDec();

    // Display list
    void display();
};

namespace b824 {
    void execute();
}