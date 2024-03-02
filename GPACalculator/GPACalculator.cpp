#include <iostream>

const int CONSOLE_WIDTH = 120;

int GetUserChoice();
void DisplayReport();
void SaveReport();
void AddClass();
void PrintDivider();

int main()
{
    bool repeat = true;
    int userChoice;
    do
    {
        userChoice = GetUserChoice();
        if (userChoice == 1)
        {
            DisplayReport();
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
    std::cout << "Choose a menu item. Enter '1' for item 1, '2' for item 2, '3' for item 3, or '4' for item 4: ";
    std::cin >> userChoice;
    return userChoice;
}

void DisplayReport()
{
    std::cout << "Report Displayed.\n\n";
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