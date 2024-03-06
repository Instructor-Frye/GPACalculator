#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Course.h"

const int CONSOLE_WIDTH = 120;
const int COURSE_ID_COL_SIZE = 12;
const int COURSE_NAME_COL_SIZE = 40;
const int COURSE_CREDITS_COL_SIZE = 10;
const int COURSE_GRADE_COL_SIZE = 6;

int GetUserChoice();
void DisplayReport(std::vector<Course> listOfCourses);
void SaveReport();
void AddClass();
void PrintDivider();
std::vector<Course> readCourses();


int main()
{
    bool repeat = true;
    int userChoice;
    Course course;
    std::vector<Course> listOfCourses;


    listOfCourses = readCourses();


    do
    {
        userChoice = GetUserChoice();
        if (userChoice == 1)
        {
            DisplayReport(listOfCourses);
        }
        else if (userChoice == 2)
        {
            SaveReport();
        }
        else if (userChoice == 3)
        {
            AddClass();
        }
        else if (userChoice == 4)
        {
            repeat = false;
        }
        else
        {
            std::cout << "\nInvalid input, please input 1, 2, 3, or 4.\n";
        }
        PrintDivider();
    } while (repeat == true);
}

int GetUserChoice()
{
    int userChoice;
    std::cout << "1.  Display Report\n"
        << "2.  Save Report\n"
        << "3.  Add Class\n"
        << "4.  Exit\n";
    std::cout << "Choose a menu item (1-4): ";
    std::cin >> userChoice;
    return userChoice;
}

void DisplayReport(std::vector<Course> listOfCourses)
{
    std::string semesterTag;
    std::string semesterName;
    semesterTag = listOfCourses[0].getSemesterTag();
    if (semesterTag.substr(0,2) == "SP")
    {
        semesterName = "Spring 20" + semesterTag.substr(2, 2);
    }
    else if (semesterTag.substr(0, 2) == "FA")
    {
        semesterName = "Fall 20" + semesterTag.substr(2, 2);
    }
    else
    {
        semesterName = "Summer 20" + semesterTag.substr(2, 2);
    }
    std::cout << std::setw((CONSOLE_WIDTH / 2) + (semesterName.size() / 2)) << std::right << semesterName << "\n";
    std::cout << std::left << std::setw(COURSE_ID_COL_SIZE) << "Cousre ID";
    std::cout << std::setw(COURSE_NAME_COL_SIZE) << "Course Name";
    std::cout << std::setw(COURSE_CREDITS_COL_SIZE) << "Credits";
    std::cout << std::setw(COURSE_GRADE_COL_SIZE) << "Grade" << "\n";
    for (int index = 0; index < listOfCourses.size(); index++)
    {
        std::cout << std::setw(COURSE_ID_COL_SIZE) << listOfCourses[index].getCourseTag();
        std::cout << std::setw(COURSE_NAME_COL_SIZE) << listOfCourses[index].getCourseName();
        std::cout << std::setw(COURSE_CREDITS_COL_SIZE) << listOfCourses[index].getCredits();
        std::cout << std::setw(COURSE_GRADE_COL_SIZE) << listOfCourses[index].getLetterGrade() << "\n";

    }
}

void SaveReport()
{
    std::cout << "Report Saved.\n\n";
}

void AddClass()
{
    std::cout << "Class Added.\n\n";
}

void PrintDivider()
{
    for (int counter = 0; counter < CONSOLE_WIDTH; counter++)
    {
        std::cout << "-";
    }
    std::cout << "\n\n";
}

std::vector<Course> readCourses()
{
    std::ifstream inputFile;
    std::string dataLine;
    Course newCourse;
    std::vector<Course> newCourses;

    inputFile.open("grades.txt");
    while (!inputFile.eof())
    {
        getline(inputFile, dataLine);
        newCourse.setCourse(dataLine);
        newCourses.push_back(newCourse);
    }
    inputFile.close();

    return newCourses;
}

