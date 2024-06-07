#include <iostream>
#include <vector>
#include <string>
#include "conio.h"
#include "Student.h"
#include <conio.h>
#include "Logger.h"
#include "cipher.h"
#include <cstdlib>
#include "prikol_func.h"


int main() {
    Logger logger("logfile.txt");
    Logger encrypt("encrypt.txt");

    std::vector<Student> students;
    load(students, "students.txt");

    /*
    students.emplace_back("John", "Petrucci", 2000, 1, 15, "507393501", "FI", 1, "GR-12");
    students.emplace_back("Kailo", "Pen", 1999, 5, 22, "507393501", "FI", 2, "GR-1");
    students.emplace_back("Kate", "Kenny", 2001, 11, 10, "507393501", "FM", 1, "GR-1");
    */

    int option = -1;
    std::string text_0 = "Starting the program.";
    std::string text_1 = "A new student has been added.";
    std::string text_2 = "Revised list of students.";
    std::string text_3 = "Viewed students by faculty.";
    std::string text_4 = "Students born after a certain year are reviewed.";
    std::string text_5 = "Viewed students by group.";
    std::string text_6 = "View the list of students by faculty and course.";
    std::string text_7 = "A student has been removed.";
    std::string text_9 = "Exit.";
    std::string text_d = "Error";

    logger.log(text_0);
    encrypt.log(encryptor(text_0));
    while (true) {
        std::cout << "### Main menu ###" << std::endl;
        std::cout << "1 - Add student" << std::endl;
        std::cout << "2 - List of students" << std::endl;
        std::cout << "3 - List of students of the given faculty" << std::endl;
        std::cout << "4 - List of students who were born after a given year" << std::endl;
        std::cout << "5 - List of students of the given group" << std::endl;
        std::cout << "6 - List of students by faculty and course" << std::endl;
        std::cout << "7 - Remove student" << std::endl;
        std::cout << "9 - Exit" << std::endl;
        std::cout << "Press the desired key to select an option: ";
        if (!(std::cin >> option)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            option = -1;
        }
        system("cls");
        switch (option) {
        case 1:
        {
            Student::add_st(students);
            logger.log(text_1);
            encrypt.log(encryptor(text_1));
            system("cls");
            break;
        }
        case 2:
        {
            Student::list_st(students);
            logger.log(text_2);
            encrypt.log(encryptor(text_2));
            system("cls");
            break;
        }
        case 3:
        {
            Student::list_st_fac(students);
            logger.log(text_3);
            encrypt.log(encryptor(text_3));
            system("cls");
            break;
        }
        case 4:
        {
            Student::list_st_year(students);
            logger.log(text_4);
            encrypt.log(encryptor(text_4));
            system("cls");
            break;
        }
        case 5:
        {

            Student::list_st_gr(students);
            logger.log(text_5);
            encrypt.log(encryptor(text_5));
            system("cls");
            break;
        }
        case 6:
        {
            Student::list_st_fac_cs(students);
            logger.log(text_6);
            encrypt.log(encryptor(text_6));
            system("cls");
            break;
        }
        case 7:
        {
            Student::remove_st(students);
            encrypt.log(encryptor(text_7));
            system("cls");
            break;
        }
        case 8:
        {
            int choose;
            std::cout << "Choose the file to clear" << std::endl << "1 - decrypt.txt" << std::endl << "2 - encrypt.txt" << std::endl << "3 - logfile.txt" << std::endl << "4 - students.txt" << std::endl << "5 - encrypt_student.txt" << std::endl;
            std::cin >> choose;
            if(choose == 1)
                clearfile("decrypt.txt");
            if (choose == 2)
                clearfile("encrypt.txt");
            if (choose == 3)
                clearfile("logfile.txt");
            if (choose == 4)
                clearfile("students.txt");
            if (choose == 5)
                clearfile("encrypt_student.txt");
            _getche();
            system("cls");
            break;
        }
        case 9:
        {
            system("cls");
            logger.log(text_9);
            encrypt.log(encryptor(text_9));
            std::cout << "Exiting program..." << std::endl;
            save(students, "students.txt");
            decryptFile("encrypt.txt", "decrypt.txt");
            encryptFile("students.txt", "encrypt_student.txt");
            return 0;
        }
        default:
        {
            system("cls");
            std::cout << "No such option" << std::endl;
            logger.log(text_d);
            encrypt.log(encryptor(text_d));
        }
        }
    }
    return 0;
}