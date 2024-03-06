#include "Course.h"
#include <string>

Course::Course()
{
	semesterTag = "SP24";
	letterGrade = "A";
	credits = 0;
}

Course::Course(std::string courseStr)
{
	setCourse(courseStr);
}

std::string Course::getSemesterTag()
{
	return semesterTag;
}

std::string Course::getCourseTag()
{
	return courseTag;
}

std::string Course::getCourseName()
{
	return courseName;
}

std::string Course::getLetterGrade()
{
	return letterGrade;
}

double Course::getCredits()
{
	return credits;
}

void Course::setSemesterTag(std::string newSemesterTag)
{
	if ((newSemesterTag.size() == 4) &&
		((newSemesterTag[0] == 'S' && newSemesterTag[1] == 'P') ||
			(newSemesterTag[0] == 'F' && newSemesterTag[1] == 'A') ||
			(newSemesterTag[0] == 'S' && newSemesterTag[1] == 'U')))
	{
		semesterTag = newSemesterTag;
	}
}

void Course::setCourseTag(std::string newCourseTag)
{
	courseTag = newCourseTag;
}

void Course::setCourseName(std::string newCourseName)
{
	courseName = newCourseName;
}

void Course::setLetterGrade(std::string newLetterGrade)
{
	if ((newLetterGrade[0] >= 'A' && newLetterGrade[0] <= 'D') ||
		newLetterGrade[0] == 'F')
	{
		if (newLetterGrade.size() == 1)
		{
			newLetterGrade = newLetterGrade;
		}
		else if (newLetterGrade.size() == 2)
		{
			if (newLetterGrade[1] == '+' ||
				newLetterGrade[1] == '-')
			{
				letterGrade = newLetterGrade;
			}
		}
	}
}

void Course::setCredits(double newCredits)
{
	if (newCredits >= 0)
	{
		credits = newCredits;
	}
}

void Course::setCourse(std::string newSemesterTag, std::string newCourseTag,
	                   std::string newCourseName, std::string newLetterGrade,
	                   double newCredits)
{
	setSemesterTag(newSemesterTag);
	setCourseTag(newCourseTag);
	setCourseName(newCourseName);
	setLetterGrade(newLetterGrade);
	setCredits(newCredits);
}

void Course::setCourse(std::string courseStr)
{
	size_t commaPos;
	size_t lastCommaPos;

	commaPos = courseStr.find(',');
	setSemesterTag(courseStr.substr(0, commaPos - 1));
	lastCommaPos = commaPos;

	commaPos = courseStr.find(',', lastCommaPos + 1);
	setCourseTag(courseStr.substr(lastCommaPos + 1, commaPos - lastCommaPos - 1));
	lastCommaPos = commaPos;

	commaPos = courseStr.find(',', lastCommaPos + 1);
	setCourseName(courseStr.substr(lastCommaPos + 1, commaPos - lastCommaPos - 1));
	lastCommaPos = commaPos;

	commaPos = courseStr.find(',', lastCommaPos + 1);
	setCredits(std::stod(courseStr.substr(lastCommaPos + 1, commaPos - lastCommaPos - 1)));
	lastCommaPos = commaPos;

	setLetterGrade(courseStr.substr(lastCommaPos + 1, courseStr.size()));

}

double Course::calculateGradeValue()
{
	double gradeValue = 0;

	if (letterGrade == "A+")
	{
		gradeValue = 4.0;
	}
	else if (letterGrade == "A")
	{
		gradeValue = 4.0;
	}
	else if (letterGrade == "A-")
	{
		gradeValue = 3.67;
	}
	else if (letterGrade == "B+")
	{
		gradeValue = 3.33;
	}
	else if (letterGrade == "B")
	{
		gradeValue = 3.0;
	}
	else if (letterGrade == "B-")
	{
		gradeValue = 2.67;
	}
	else if (letterGrade == "C+")
	{
		gradeValue = 2.33;
	}
	else if (letterGrade == "C")
	{
		gradeValue = 2.0;
	}
	else if (letterGrade == "C-")
	{
		gradeValue = 1.67;
	}
	else if (letterGrade == "D+")
	{
		gradeValue = 1.33;
	}
	else if (letterGrade == "D")
	{
		gradeValue = 1.0;
	}
	else if (letterGrade == "D-")
	{
		gradeValue = 0.67;
	}
	else if (letterGrade == "F")
	{
		gradeValue = 0.0;
	}
	return gradeValue;
}