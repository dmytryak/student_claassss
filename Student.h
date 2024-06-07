#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>

class Student
{
private:
    static int next_id;
    int id;
    int course;
    int y, m, d;
    std::string name;
    std::string surname;
    std::string ph_number;
    std::string faculty;
    std::string group;

public:
    Student(const std::string& name, const std::string& surname, int year, int month, int day, const std::string& phone, const std::string& faculty, int course, const std::string& group);
    //Student(const Student& other);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    int get_id() const
    {
        return id;
    }
    int get_year() const
    {
        return y;
    }
    int get_month() const
    {
        return m;
    }
    int get_day() const
    {
        return d;
    }
    int get_course() const
    {
        return course;
    }
    std::string get_fac() const
    {
        return faculty;
    }
    std::string get_name() const
    {
        return name;
    }
    std::string get_surname() const
    {
        return surname;
    }
    std::string get_group() const
    {
        return group;
    }
    std::string get_number() const
    {
        return ph_number;
    }
    

    //void print() const;

    static void list_st(const std::vector<Student>& students);
    static void add_st(std::vector<Student>& students);
    static void list_st_fac(const std::vector<Student>& students);
    static void list_st_year(const std::vector<Student>& students);
    static void list_st_gr(const std::vector<Student>& students);
    static void remove_st(std::vector<Student>& students);
    static void list_st_fac_cs(const std::vector<Student>& students);
};

#endif