#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "Course.h"

const int CONSOLE_WIDTH = 120;
const int COURSE_ID_COL_SIZE = 12;
const int COURSE_NAME_COL_SIZE = 40;
const int COURSE_CREDITS_COL_SIZE = 10;
const int COURSE_GRADE_COL_SIZE = 6;

int GetUserChoice();
void DisplayReport(std::vector<Course> listOfCourses);
void SaveReport(std::vector<Course> listOfCourses);
void AddClass(std::vector<Course> &listOfCourses);
void PrintDivider();
void printReport(std::ostream& output, std::vector<Course> listOfCourses);
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
            SaveReport(listOfCourses);
        }
        else if (userChoice == 3)
        {
            AddClass(listOfCourses);
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
    printReport(std::cout, listOfCourses);
}

void SaveReport(std::vector<Course> listOfCourses)
{
    std::ofstream outputFile;

    outputFile.open("report.txt");
    printReport(outputFile, listOfCourses);
    outputFile.close();
}

void AddClass(std::vector<Course> &listOfCourses)
{
    std::string semesterTag, courseTag, courseName, courseGrade;
    double courseCredits;
    Course newCourse;

    std::cin.ignore(256, '\n');
    // Prompt for input
    std::cout << "Enter Semester (EX:SP24): ";
    std::getline(std::cin, semesterTag);

    std::cout << "Enter Course Tag(EX:CS 112): ";
    std::getline(std::cin, courseTag);

    std::cout << "Enter Course Name: ";
    std::getline(std::cin, courseName);

    std::cout << "Enter Course Credits: ";
    std::cin >> courseCredits;

    std::cout << "Enter Course Grade: ";
    std::cin >> courseGrade;

    // Append the information to grades.txt
    std::ofstream outputFile("grades.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "\n" << semesterTag << "," << courseTag << "," << courseName << "," << courseCredits << "," << courseGrade;
        outputFile.close();
        std::cout << "Course information appended to grades.txt successfully." << std::endl;
    }
    else {
        std::cout << "Unable to open file grades.txt" << std::endl;
    }

    newCourse.setSemesterTag(semesterTag);
    newCourse.setCourseTag(courseTag);
    newCourse.setCourseName(courseName);
    newCourse.setCredits(courseCredits);
    newCourse.setLetterGrade(courseGrade);

    listOfCourses.push_back(newCourse);
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


void printReport(std::ostream &output, std::vector<Course> listOfCourses)
{
    std::string semesterTag;
    std::string semesterName;
    double totalCredits = 0.0;
    double totalGradeValue = 0.0;


    semesterTag = listOfCourses[0].getSemesterTag();
    if (semesterTag.substr(0, 2) == "SP")
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
    output << std::setw((CONSOLE_WIDTH / 2) + (semesterName.size() / 2)) << std::right << semesterName << "\n";
    output << std::left << std::setw(COURSE_ID_COL_SIZE) << "Cousre ID";
    output << std::setw(COURSE_NAME_COL_SIZE) << "Course Name";
    output << std::setw(COURSE_CREDITS_COL_SIZE) << "Credits";
    output << std::setw(COURSE_GRADE_COL_SIZE) << "Grade" << "\n";
    for (int index = 0; index < listOfCourses.size(); index++)
    {
        output << std::setw(COURSE_ID_COL_SIZE) << listOfCourses[index].getCourseTag();
        output << std::setw(COURSE_NAME_COL_SIZE) << listOfCourses[index].getCourseName();
        output << std::setw(COURSE_CREDITS_COL_SIZE) << listOfCourses[index].getCredits();
        output << std::setw(COURSE_GRADE_COL_SIZE) << listOfCourses[index].getLetterGrade() << "\n";
        totalCredits = totalCredits + listOfCourses[index].getCredits();
        totalGradeValue = totalGradeValue + (listOfCourses[index].calculateGradeValue() * listOfCourses[index].getCredits());
    }
    output << std::right << std::setw(COURSE_ID_COL_SIZE + COURSE_NAME_COL_SIZE) << "Credits: " << totalCredits;
    output << std::setw(COURSE_CREDITS_COL_SIZE) << "GPA: " << totalGradeValue / totalCredits << "\n";

}

