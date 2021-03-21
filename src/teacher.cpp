#include <iostream>
#include <filesystem>
#include <array>
#include <fstream>
#include "../include/class.hpp"


Teacher::Teacher(std::string teacherName, std::string job) { 
    this->teacherName = teacherName; 
    this->job = job; 
}


void Teacher::employ_teacher() {
    std::string homeDir = getenv("HOME");
    homeDir.append("/.config/school_system/"); 
    if (!std::filesystem::exists(homeDir)) { 
        std::filesystem::create_directory(homeDir); 
    }
    std::string teacherEmploymentFile = homeDir;
    teacherEmploymentFile.append("teachersEmploying.txt");  

    std::fstream teacherEmploymentOut;

    if (!std::filesystem::exists(teacherEmploymentFile)) { 
        teacherEmploymentOut.open(teacherEmploymentFile, std::fstream::out); 
    } else { 
        teacherEmploymentOut.open(teacherEmploymentFile); 
    }
    teacherEmploymentOut << this->teacherName << ": " << this->job << "\n"; 

    if (Teacher::job == "Math") { 
        Teacher::math_challenges();    
    } else if (Teacher::job == "Technology") { 
        Teacher::tech_challenges(); 
    }
}


bool Teacher::tech_challenges() { 
    std::string teacherEmploymentFile = getenv("HOME");
    teacherEmploymentFile.append("/.config/school_system/teachersEmploying.txt"); 
    if (!std::filesystem::exists(teacherEmploymentFile)) { 
        std::cout << "Config file does not exist.\n"; 
        return false;
    }
    std::array<std::string, 5> correctAnswers { 
        "Binary", "C", "Python", "C++", "Array"
    }; 
    std::array<std::string, 5> answers; 

    std::cout << "What do computers read?: "; 
    std::cin >> answers[0];

    std::cout << "What is the programming language used to program operating systems?: ";
    std::cin >> answers[1];  

    std::cout << "What is the most popular programming language on Stack Overflow?: "; 
    std::cin >> answers[2]; 

    std::cout << "What is this program written in?: "; 
    std::cin >> answers[3]; 
    
    std::cout << "What's a collection of a type called?: "; 
    std::cin >> answers[4]; 
    std::uint8_t incorrect; 
    for (int i = 0; i < answers.size(); i++) { 
        if (islower(answers[i][0])) {
            answers[i][0] = toupper(answers[i][0]); 
            if (answers[i] != correctAnswers[i]) { 
                incorrect++; 
            }
        } else { 
            if (answers[i] != correctAnswers[i]) { 
                incorrect++; 
            }
        }
    }
    if (incorrect > 2) {
        std::cout << false << "\n"; 
        return false; 
    }
    teacherEmploymentFile.clear(); 
    teacherEmploymentFile = getenv("HOME") + teacherEmploymentFile.append("/.config/school_system/teachersEmployed.txt");
    std::fstream teacherEmploymentOut; 
    if (!std::filesystem::exists(teacherEmploymentFile)) {
        teacherEmploymentOut.open(teacherEmploymentFile, std::fstream::out);                                      
    } else {
        teacherEmploymentOut.open(teacherEmploymentFile); 
    }
    teacherEmploymentOut << this->teacherName << ": " << this->job << "\n"; 
    
    std::cout << true << "\n";     
    return true; 
}


bool Teacher::math_challenges()
{  
    std::string teacherEmploymentFile = getenv("HOME");
    teacherEmploymentFile.append("/.config/school_system/teachersEmploying.txt"); 
    if (!std::filesystem::exists(teacherEmploymentFile)) { 
        std::cout << "Config file does not exist.\n"; 
        return false;
    }
    std::ifstream teacherEmploymentIn;
    teacherEmploymentIn.open(teacherEmploymentFile); 
    std::string contents; 
    while (getline(teacherEmploymentIn, contents)) { 
        if (contents.find(this->teacherName) != std::string::npos) { 
            break; 
        } else { 
            std::cout << "You aren't being hired!\n"; 
            return false; 
        }
    } 
    teacherEmploymentIn.close(); 
    int answers[5];
    int correct_answers[5] = { 
        25, 5, 144, 12, 16
    }; 
    int incorrect = 0; 
    std::cout << "What is 5 ^ 2?: "; 
    std::cin >> answers[0]; 
    std::cout << "What is the square root of 25?: "; 
    std::cin >> answers[1]; 
    std::cout << "What is 12^12?: "; 
    std::cin >> answers[2]; 
    std::cout << "What is the square root of 144?: ";
    std::cin >> answers[3]; 
    std::cout << "A square's side is 4cm, what's its area?: "; 
    std::cin >> answers[4];

    for (int i = 0; i < 5; i++) { 
        if (answers[i] != correct_answers[i]) {
            incorrect++; 
        }
    }

    if (incorrect > 2) {
        std::cout << "You didn't pass!\n"; 
        return false; 
    }
    std::cout << "You passed!\n"; 
    teacherEmploymentFile.clear(); 
    teacherEmploymentFile = getenv("HOME") + teacherEmploymentFile.append("/.config/school_system/teachersEmployed.txt");
    std::fstream teacherEmploymentOut; 
    if (!std::filesystem::exists(teacherEmploymentFile)) {
        teacherEmploymentOut.open(teacherEmploymentFile, std::fstream::out);                                      
    } else {
        teacherEmploymentOut.open(teacherEmploymentFile); 
    }
    teacherEmploymentOut << this->teacherName << ": " << this->job << "\n"; 
    
    return true; 
}
