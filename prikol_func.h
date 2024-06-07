#ifndef PRIKOL_FUNC_H
#define PRIKOL_FUNC_H

#include <vector>
#include <string>
#include "Student.h"

void save(const std::vector<Student>& students, const std::string& filename);
void load(std::vector<Student>& students, const std::string& filename);
void decryptFile(const std::string& input_file, const std::string& output_file);
void encryptFile(const std::string& input_file, const std::string& output_file);
void clearfile(const std::string& filename);
#endif
