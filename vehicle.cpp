/*
 * Name: vehicle.cpp
 * Author: Augustus Allred
 * Created: 5/5/23
 * Purpose: Vehicle inheritance
 */

#include <iostream>

// Base class
class Vehicle
{
    /***************** DATA MEMBERS ******************/
protected:
    // protected is accessible from derived class
    std::string m_make;
    std::string m_model;

private:
    // private access from this class only
    int m_year;

public:
    /************ PUBLIC MEMBER FUNCTIONS ************/
    // Parameter based constructor
    Vehicle(int year, std::string make, std::string model)
    {
        m_year = year;
        m_make = make;
        m_model = model;
    }
    // A virtual method with = 0 (the pure specifier)
    // Derived classes must implement this function
    virtual void start() = 0;

    // This method does not have to be overridden
    void drive()
    {
        std::cout << "Vehicle is driving" << std::endl;
    }

    // Getters and setters
    std::string make()
    {
        return m_make;
    }

    void make(std::string make)
    {
        m_make = make;
    }

    double year()
    {
        return m_year;
    }

    void year(int year)
    {
        m_year = year;
    }

    std::string model()
    {
        return m_model;
    }

    void model(std::string model)
    {
        m_model = model;
    }
};

int main() {
    return 0;
}