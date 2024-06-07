#include "prikol_func.h"
#include <fstream>
#include <iostream>
#include "cipher.h"
#include <conio.h>

void save(const std::vector<Student>& students, const std::string& filename) 
{
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }
    for (const auto& student : students) {
        outfile << student.get_name() << " " << student.get_surname() << " " << student.get_year() << " " << student.get_month() << " " << student.get_day() << " " << student.get_number() << " " << student.get_fac() << " " << student.get_course() << " " << student.get_group() << std::endl;
    }
    outfile.close();
}

void load(std::vector<Student>& students, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cout << "Could not open the file: " << filename << std::endl;
    }
    std::string name, surname, ph_number, faculty, group;
    int year, month, day, course;
    while (infile >> name >> surname >> year >> month >> day >> ph_number >> faculty >> course >> group) {
        students.emplace_back(name, surname, year, month, day, ph_number, faculty, course, group);
    }
    infile.close();
}

void decryptFile(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);
    if (!infile.is_open()) {
        std::cout << "Could not open the file: " << input_file << std::endl;
        return;
    }
    if (!outfile.is_open()) {
        std::cout << "Could not open the file: " << output_file << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        outfile << decrypt(line) << std::endl;
    }
    infile.close();
    outfile.close();
}

void encryptFile(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);
    if (!infile.is_open()) {
        std::cout << "Could not open the file: " << input_file << std::endl;
        return;
    }
    if (!outfile.is_open()) {
        std::cout << "Could not open the file: " << output_file << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        outfile << encryptor(line) << std::endl;
    }
    infile.close();
    outfile.close();
}

void clearfile(const std::string& filename) {
    std::ofstream smert(filename, std::ofstream::out | std::ofstream::trunc);
    std::cout << "File" << filename << "cleared successfully." << std::endl;
    smert.close();
}
