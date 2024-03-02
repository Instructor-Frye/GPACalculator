#pragma once
#include <string>

class Course
{
	private:
		std::string semesterTag;
		std::string courseTag;
		std::string courseName;
		std::string letterGrade;
		double credits;
	public:
		Course();
		Course(std::string courseData);
		std::string getSemesterTag();
		std::string getCourseTag();
		std::string getCourseName();
		std::string getLetterGrade();
		double  getCredits();
		void setSemesterTag(std::string newSemesterTag);
		void setCourseTag(std::string newCourseTag);
		void setCourseName(std::string newCourseName);
		void setLetterGrade(std::string newLetterGrade);
		void setCredits(double newCredits);
		void setCourse(std::string newSemesterTag, std::string newCourseTag,
					   std::string newCourseName, std::string newLetterGrade,
					   double newCredits);
		double calculateGradeValue();
};

