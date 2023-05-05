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

// Derived class
class Truck : public Vehicle
{

private:
    std::string m_bed;

public:
    /************ PUBLIC MEMBER FUNCTIONS ************/
    // Derived class constructor calls base class constructor
    // Derived class parameter is passed to the base class
    Truck(int year, std::string make, std::string model, std::string bed) : Vehicle(year, make, model) {
        m_bed = bed;
    }
    // Override the start() method from the Vehicle base class
    void start()
    {
        std::cout << "Vvvvvv chkckckaaaaa Vvvvvvvv Vvvvvvvv!" << std::endl;
    }
    // Override the drive() method from the Vehicle base class
    void drive()
    {
        std::cout << "Your " << m_model << " is transporting a heavy load." << std::endl;
    }
    // Getter and setter for bed type
    std::string bed()
    {
        return m_bed;
    }

    void bed(std::string bed)
    {
        m_bed = bed;
    }
};


int main()
{
    // Create an object of the derived Anaconda class
    Truck truck(2016, "Chevy", "Silverado", "short");
    // Call methods of the derived class
    truck.start();
    truck.drive();
    std::cout << "You own a " << truck.year()
              << " " << truck.make() << " "
              << truck.model() << " with a "
              << truck.bed() << " bed." << std::endl;
    truck.year(2018);
    std::cout << "You own a " << truck.year()
              << " " << truck.make() << " "
              << truck.model() << " with a "
              << truck.bed() << " bed." << std::endl;

    return 0;
}