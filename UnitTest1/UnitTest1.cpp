#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_11.2/LAB_11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountStudentsWithoutThrees)
        {
            vector<Student> students;

            
            Student student1;
            student1.physics_grade = 5;
            student1.math_grade = 5;
            student1.programming_grade = 5;

            Student student2;
            student2.physics_grade = 3;
            student2.math_grade = 4;
            student2.programming_grade = 4;

            
            students.push_back(student1);
            students.push_back(student2);

           
            Assert::AreEqual(1, countStudentsWithoutThrees(students));
        }

        TEST_METHOD(TestCalculatePercentageOfStudentsWithAverageBelowFour)
        {
            vector<Student> students;

            
            Student student1;
            student1.physics_grade = 3;
            student1.math_grade = 3;
            student1.programming_grade = 3;

            Student student2;
            student2.physics_grade = 4;
            student2.math_grade = 4;
            student2.programming_grade = 4;

        
            students.push_back(student1);
            students.push_back(student2);

          
            Assert::AreEqual(50.0, calculatePercentageOfStudentsWithAverageBelowFour(students));
        }
    };
}
