#pragma once
#ifndef CHAPTER17_H
#define CHAPTER17_H
#include <iostream>
#include <string>
#include <string_view>

class Person
{
    // In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};

// By adding this colon we make it so that baseballplayer inherits the member functions and variables from the person class
class BaseballPlayer : public Person
{
    // Members are public for simplicity sake
public:
    double m_battingAverage{};
    int m_homeRuns{};
    
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {}
};

// Employee also inherits from Person but Employee has no direct relationship with baseball player, only person
class Employee : public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
    {}

    void printNameAndSalary() const;
};

#endif