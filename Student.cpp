#include "Student.h"
#include <iostream>
#include <conio.h>
#include <map>

int Student::next_id = 1;

Student::Student(const std::string& name, const std::string& surname, int year, int month, int day, const std::string& phone, const std::string& faculty, int course, const std::string& group) : name(name), surname(surname), y(year), m(month), d(day), ph_number(phone), faculty(faculty), course(course), group(group)
{
    id = next_id++;
}
/*Student::Student(const Student& other) : name(other.name), surname(other.surname), y(other.y), m(other.m), d(other.d), ph_number(other.ph_number), faculty(other.faculty), course(other.course), group(other.group)
{
    id = next_id++;
}
*/
/*void Student::print() const
{
    int size_sn = surname.size();
    int size_g = group.size();
    if (size_sn >= 8)
    {
        if (size_g <= 4)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "    |" << std::endl;
        if (size_g == 5)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "   |" << std::endl;
        if (size_g > 5)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "  |" << std::endl;
    }
    if (size_sn < 8)
    {
        if (size_g <= 4)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "    |" << std::endl;
        if (size_g == 5)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "   |" << std::endl;
        if (size_g > 5)
            std::cout << "| " << id << "\t" << name << "\t" << surname << "\t\t" << y << "-" << m << "-" << d << "\t" << ph_number << "\t" << faculty << "\t\t" << course << "\t\t" << group << "  |" << std::endl;
    }
}
*/
std::ostream& operator<<(std::ostream& os, const Student& student)
{
    int size_sn = student.surname.size();
    int size_g = student.group.size();
    if (size_sn >= 8)
    {
        if (size_g <= 4)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "    |";
        if (size_g == 5)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "   |";
        if (size_g > 5)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "  |";
    }
    if (size_sn < 8)
    {
        if (size_g <= 4)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "    |";
        if (size_g == 5)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "   |";
        if (size_g > 5)
            os << "| " << student.id << "\t" << student.name << "\t" << student.surname << "\t\t" << student.y << "-" << student.m << "-" << student.d << "\t" << student.ph_number << "\t" << student.faculty << "\t\t" << student.course << "\t\t" << student.group << "  |";
    }
    return os;
}

void Student::list_st(const std::vector<Student>& students)
{
    std::cout << "List of all students:" << std::endl;
    std::cout << " _______________________________________________________________________________________________________ " << std::endl;
    std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }
    std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl << std::endl;
    _getch();
}

void Student::add_st(std::vector<Student>& students)
{
    int year = 0, month = 0, day = 0, course = 0;
    std::string name, surname, phone, faculty, group;

    std::cout << "Enter student's name: ";
    std::cin >> name;
    std::cout << "Enter student's surname: ";
    std::cin >> surname;

    while (year == 0)
    {
        std::cout << "Enter student's birth year:";
        if (!(std::cin >> year)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            year = 0;
        }
    }

    while (month < 1 || month > 12) {
        std::cout << "Enter student's birth month:";
        if (!(std::cin >> month)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            month = 0;
        }
    }

    while (day < 1 || day > 31) {
        std::cout << "Enter student's birth day:";
        if (!(std::cin >> day)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            day = 0;
        }
    }

    std::cout << "Enter student's phone number: ";
    std::cin >> phone;
    std::cout << "Enter student's faculty: ";
    std::cin >> faculty;

    while (course < 1 || course > 6) {
        std::cout << "Enter student's course:";
        if (!(std::cin >> course)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            course = 0;
        }
    }

    std::cout << "Enter student's group: ";
    std::cin >> group;

    students.emplace_back(name, surname, year, month, day, phone, faculty, course, group);
    std::cout << "Student added successfully." << std::endl << std::endl;
}

void Student::list_st_fac(const std::vector<Student>& students)
{
    std::string faculty;
    std::cout << "Enter faculty: ";
    std::cin >> faculty;
    std::cout << "List of students by faculty: " << faculty << std::endl;
    std::cout << " _______________________________________________________________________________________________________ " << std::endl;
    std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;
    for (const auto& student : students)
    {
        if (student.get_fac() == faculty)
        {
            std::cout << student << std::endl;
        }
    }
    std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl << std::endl;
    _getch();
}

void Student::list_st_year(const std::vector<Student>& students)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "List of students born after " << year << " year:" << std::endl;
    std::cout << " _______________________________________________________________________________________________________ " << std::endl;
    std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;
    for (const auto& student : students)
    {
        if (student.get_year() > year)
        {
            std::cout << student << std::endl;
        }
    }
    std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl << std::endl;
    _getch();
}

void Student::list_st_gr(const std::vector<Student>& students)
{
    std::string group;
    std::cout << "Enter group: ";
    std::cin >> group;
    std::cout << "List of students from group " << group << std::endl;
    std::cout << " _______________________________________________________________________________________________________ " << std::endl;
    std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;
    for (const auto& student : students)
    {
        if (student.get_group() == group)
        {
            std::cout << student << std::endl;
        }
    }
    std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl << std::endl;
    _getch();
}

void Student::remove_st(std::vector<Student>& students)
{
    int id, s, e;
    std::cout << "Enter ID of student to remove:";
    std::cin >> id;
    for (const auto& student : students)
    {
        if (student.get_id() == id)
        {
            s = (id - 1);
            e = s + 1;
            std::cout << "Student successfully removed:" << std::endl;
            std::cout << student << std::endl;
            students.erase(students.begin() + s, students.begin() + e);
        }
    }
    _getch();
}

void Student::list_st_fac_cs(const std::vector<Student>& students) {
    std::map<std::string, std::vector<Student>> faculty_map;
    std::map<int, std::vector<Student>> course_map;

    for (const auto& student : students) {
        faculty_map[student.get_fac()].push_back(student);
    }
    std::cout << "List of students by faculty:" << std::endl;
    for (const auto& fac_pair : faculty_map) {
        std::cout << "Faculty: " << fac_pair.first << std::endl;
        std::cout << " _______________________________________________________________________________________________________ " << std::endl;
        std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;
        for (const auto& student : fac_pair.second) {
            std::cout << student << std::endl;
        }
        std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
    }

    std::cout << std::endl << "List of students by course:" << std::endl;

    for (const auto& student : students) {
        course_map[student.get_course()].push_back(student);
    }

    for (const auto& course_pair : course_map) {
        std::cout << "Course: " << course_pair.first << std::endl;
        std::cout << " _______________________________________________________________________________________________________ " << std::endl;
        std::cout << "| ID#\t#Name#\t#Surname#\t#Birthday#\t#Phone Number#\t#Faculty#\t#Y.O.U.#\t#Group  |" << std::endl;

        for (const auto& student : course_pair.second) {
            std::cout << student << std::endl;
        }

        std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
    }
    _getch();
}