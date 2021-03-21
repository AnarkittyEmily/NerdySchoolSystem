#include "../include/class.hpp"
#include <iostream> 


int main() { 
    std::string teacher_name; 
    int choice; 

    std::cout << "What's your name?: "; 
    std::cin >> teacher_name; 

    std::cout << "Choose: 1 (Math) 2 (Technology): "; 
    std::cin >> choice; 

    if (choice == 1) { 
        Teacher teacherMath(teacher_name, "Math"); 
        teacherMath.employ_teacher();
    } else if (choice == 2) {
        Teacher teacherTechnology(teacher_name, "Technology"); 
        teacherTechnology.employ_teacher(); 
    } 
}