#include <string> 

class Teacher {
    private:
        std::string job; 
        std::string teacherName; 

    public: 
        Teacher(std::string teacherName, std::string job); 
        bool math_challenges();
        bool english_challenges(); 
        bool tech_challenges(); 
        void employ_teacher();     
};