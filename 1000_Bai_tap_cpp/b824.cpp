#include "b824.h"

// Recursive functions
SLinkedList::Student * SLinkedList::addRec(Student* rootNode, Student* newNode)
{
    if (rootNode == NULL) {
        rootNode = newNode;
    }
    else {
        rootNode->next= addRec(rootNode->next, newNode);
    }
    return rootNode;
}

SLinkedList::Student* SLinkedList::deleteRec(Student* rootNode, std::string deleteName)
{
    if (!deleteName.compare(rootNode->name)) {
        Student* toDelete = rootNode;
        rootNode = rootNode->next;
        delete toDelete;
    }
    else {
        rootNode->next = deleteRec(rootNode->next, deleteName);
    }

    return rootNode;
}

int SLinkedList::countRec(Student* rootNode)
{
    if (rootNode == NULL)
        return 0;
    else
        return 1 + countRec(rootNode->next);

    return 0;
}

void SLinkedList::listUnder5Rec(Student* rootNode)
{
    if (rootNode == NULL)
        return;
    else if (rootNode->mathGrade < 5) {
        std::cout << rootNode->name << std::endl;
        std::cout << "Math grade: " << rootNode->mathGrade << "\n\n";
    }
    listUnder5Rec(rootNode->next);
}

int SLinkedList::countLarger8Rec(Student* rootNode)
{
    if (rootNode == NULL)
        return 0;
    else if (rootNode->mathGrade > 8 && rootNode->litGrade > 8)
        return 1 + countLarger8Rec(rootNode->next);
    else
        return countLarger8Rec(rootNode->next);

    return 0;
}

void SLinkedList::displayRec(Student * rootNode) {
    if (rootNode == NULL) {
        std::cout << "\n\n";
        return;
    }

    int setwValue = 24;

    std::cout << "-------------------------" << std::endl;
    std::cout << "|" << std::setw(setwValue) << "|" << std::endl;
    std::cout << "|" << " Name: " << rootNode->name << std::endl;
    std::cout << "|" << " Math grade: " << rootNode->mathGrade << std::endl;
    
    std::cout << "|" << " Literature grade: " << rootNode->litGrade << std::endl;
    std::cout << "|" << " Avergrade grade: " << rootNode->avgGrade << std::endl;
    std::cout << "|" << std::setw(setwValue) << "|" << std::endl;
    std::cout << "-------------------------" << std::endl;
   

    if (rootNode->next != NULL) {
        std::cout << std::setw((setwValue / 2) + 1) << "|" << std::endl << std::setw((setwValue / 2) + 1) << "V" << std::endl;
    }
    /*else {
        std::cout << "|" << std::setw(setwValue) << "|" << std::endl;
    }*/

    displayRec(rootNode->next);
}



// Add student
void SLinkedList::addStudent(std::string newName, float newMathGrade, float newLitGrade, float newAvgGrade)
{
    Student* newStudent = new Student(newName, newMathGrade, newLitGrade, newAvgGrade);
    
    root = addRec(root, newStudent);
   
}

// Delete student
bool SLinkedList::deleteStudent(std::string deleteName)
{
    root = deleteRec(root, deleteName);

    return true;
}

// Count student
int SLinkedList::countStudent()
{
    return countRec(root);

    return 0;
}

// Count student math < 5
void SLinkedList::listUnder5Math()
{
    listUnder5Rec(root);
}

// Count student math and lit > 5
int SLinkedList::countLarger8LitMath()
{
    return countLarger8Rec(root);

    return 0;
}

// Sort avg grade decrease
bool SLinkedList::sortAvgDec()
{
    Student* baseNode = this->root;
    Student* itterNode = this->root;
    Student* prevNode = this->root;
    Student* prevItterNode = this->root;
    Student* nextBaseNode = this->root;

    if (baseNode == NULL || baseNode->next == NULL) return 1;

    while (baseNode->next != NULL) {
        nextBaseNode = baseNode->next;
        itterNode = baseNode->next;
        prevItterNode = baseNode;
        bool nodeChanged = 0;

        while (itterNode != NULL) {
            if (itterNode->avgGrade < baseNode->avgGrade) {
                Student* baseNext = baseNode->next;
                Student* itterNext = itterNode->next;

                if (baseNode == prevItterNode) {
                    // if base node is next to itter node

                    if (baseNode != this->root)
                        prevNode->next = itterNode;

                    prevItterNode->next = itterNext;
                    itterNode->next = baseNode;

                    if (baseNode == this->root)
                        this->root = itterNode;
                }
                else {
                    // if base node is NOT next to itter node

                    if (baseNode != this->root)
                        prevNode->next = itterNode;

                    prevItterNode->next = baseNode;
                    baseNode->next = itterNext;
                    itterNode->next = baseNext;

                    if (baseNode == this->root)
                        this->root = itterNode;
                }
                
                Student* tempNode = baseNode;
                baseNode = itterNode;
                itterNode = tempNode;
                prevItterNode = itterNode;
                itterNode = itterNode->next;
            }
            else {
                prevItterNode = itterNode;
                itterNode = itterNode->next;
            }
            
        }
        prevNode = baseNode;

        this->display();

        if (baseNode->next != NULL)
            baseNode = baseNode->next;
        else
            break;
        
    }

    baseNode = NULL;
    itterNode = NULL;
    prevItterNode = NULL;
    prevNode = NULL;

    delete baseNode;
    delete itterNode;
    delete prevItterNode;
    delete prevNode;

    return true;
}


// display
void SLinkedList::display() {
    std::cout << "\n\n";
    displayRec(root);
}


void b824::execute() {
    SLinkedList studentList;

    std::cout << "\n\n" << "-------- SINGLY LINKED LIST VISUALIZE -------- \n\n";
    while (1) {
        std::string choice = "0";

        std::cout << "Press 1 to add student \n";
        std::cout << "Press 2 to delete student \n";
        std::cout << "Press 3 to list all students that have math grade < 5\n";
        std::cout << "Press 4 to count all students that have math and literature grade > 8 \n";
        std::cout << "Press 5 to count all students \n";
        std::cout << "Press 6 to sort student list according to average grade \n";
        std::cout << "Press 7 to view list \n";
        std::cout << "Press 8 to exit \n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        std::cout << "\n\n";

        if (choice.compare("1") == 0) {
            std::string name;
            float mathGrade;
            float litGrade;
            float avgGrade;

            std::cout << "--- Adding student ---\n\n";

            std::cout << "Student name: ";
            std::cin >> name;

            std::cout << "Math grade: ";
            std::cin >> mathGrade;

            std::cout << "Literature grade: ";
            std::cin >> litGrade;

            std::cout << "Average grade: ";
            std::cin >> avgGrade;

            studentList.addStudent(name, mathGrade, litGrade, avgGrade);

            studentList.display();
        }
        else if (choice.compare("2") == 0) {
            std::string name;
            
            std::cout << "--- Removing student ---\n\n";

            std::cout << "Student name: ";
            std::cin >> name;

            studentList.deleteStudent(name);

            studentList.display();
        }
        else if (choice.compare("3") == 0) {
            std::string name;

            std::cout << "--- List students that have math grade < 5 ---\n\n";

            studentList.listUnder5Math();
        }
        else if (choice.compare("4") == 0) {
            std::cout << "--- Count all students that have math and literature grade > 8 ---\n\n";
            std::cout << "Result: " << studentList.countLarger8LitMath() << "\n\n";
        }
        else if (choice.compare("5") == 0) {
            std::cout << "--- Count all students ---\n\n";
            std::cout << "Result: " << studentList.countStudent() << "\n\n";
        }
        else if (choice.compare("6") == 0) {
            std::cout << "--- Sort student list according to average grade ---\n\n";
            studentList.sortAvgDec();
            studentList.display();
        }
        else if (choice.compare("7") == 0) {
            studentList.display();
        }
        else if (choice.compare("8") == 0) {
            break;
        }
    }
}

