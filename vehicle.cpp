/*
 * Name: vehicle.cpp
 * Author: Gus Allred
 * Created: 5/5/23
 * Revised: 4/30/24
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
    Truck(int year, std::string make, std::string model, std::string bed) : Vehicle(year, make, model)
    {
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


// Derived class
class Car : public Vehicle
{

private:
    std::string m_storage;

public:
    /************ PUBLIC MEMBER FUNCTIONS ************/
    // Derived class constructor calls base class constructor
    // Derived class parameter is passed to the base class
    Car(int year, std::string make, std::string model, std::string storage) : Vehicle(year, make, model)
    {
        m_storage = storage;
    }
    // Override the start() method from the Vehicle base class
    void start()
    {
        std::cout << "Vvvvvv Vvvvvvvv Vvvvvvvvvvvv!" << std::endl;
    }
    // Override the drive() method from the Vehicle base class
    void drive()
    {
        std::cout << m_model << " is cruising at a high speed." << std::endl;
    }
    // Getter and setter for storage type
    std::string storage()
    {
        return m_storage;
    }

    void storage(std::string storage)
    {
        m_storage = storage;
    }
};


// Derived class
class Motorcycle : public Vehicle
{

private:
    std::string m_engine;

public:
    /************ PUBLIC MEMBER FUNCTIONS ************/
    // Derived class constructor calls base class constructor
    // Derived class parameter is passed to the base class
    Motorcycle(int year, std::string make, std::string model, std::string engine) : Vehicle(year, make, model)
    {
        m_engine = engine;
    }
    // Override the start() method from the Vehicle base class
    void start()
    {
        std::cout << "kahoo-kahoo-kahoo-kaWOOahuhukaWrrrrrooyooyooha-kahoo-kahoo!" << std::endl;
    }
    // Override the drive() method from the Vehicle base class
    void drive()
    {
        std::cout << "Your " << m_model << " is flying down the interstate. Be careful, man!" << std::endl;
    }
    // Getter and setter for bed type
    std::string engine()
    {
        return m_engine;
    }

    void bed(std::string engine)
    {
        m_engine = engine;
    }
};


int main()
{
    // local user entry loop variable
    char loop;

    while (true)
    {
        // local user entry variables
        int choice;
        std::string str_choice;
        int year;
        std::string str_year;
        std::string make;
        std::string model;
        std::string bed;
        std::string storage;
        std::string engine;

        // Get information from user
        std::cout << "\n[1] Truck" << std::endl;
        std::cout << "[2] Car" << std::endl;
        std::cout << "[3] Motorcycle" << std::endl;
        // Validation
        while (true)
        {
            // Get valid integer input with try catch
            try
            {
                // Prompt user
                std::cout << "\nEnter Choice: ";
                std::getline(std::cin, str_choice);
                // Cast string input to integer. If double, it truncates it
                // If it is a non numberic string, an exception is thrown
                choice = std::stoi(str_choice);
            }
            catch (...)
            {
                std::cout << "Please enter a whole number." << std::endl;
                // Start the loop over
                continue;
            }
            // Input validation to keep input in a valid range with if statements
            // Is the integer a positive number?
            if (choice < 1 || choice > 3)
            {
                std::cout << "Please enter either 1, 2, or 3." << std::endl;
                // Start the loop over
                continue;
            }
            else
            {
                // Break out the loop with valid input
                break;
            }
        }

        if (choice == 1)
        {
            std::cout << "\nYou chose Truck" << std::endl;
        }

        else if (choice == 2)
        {
            std::cout << "\nYou chose Car" << std::endl;
        }

        else if (choice == 3)
        {
            std::cout << "\nYou chose Motorcycle" << std::endl;
        }

        // Validation
        while (true)
        {
            // Get valid integer input with try catch
            try
            {
                // Prompt user
                std::cout << "\nEnter year: ";
                std::getline(std::cin, str_year);
                // Cast string input to integer. If double, it truncates it
                // If it is a non numberic string, an exception is thrown
                year = std::stoi(str_year);
            }
            catch (...)
            {
                std::cout << "Please enter a whole number." << std::endl;
                // Start the loop over
                continue;
            }
            // Input validation to keep input in a valid range with if statements
            // Is the integer a positive number?
            if (year < 1900 || year > 2024)
            {
                std::cout << "Please enter a year between 1900 and 2024." << std::endl;
                // Start the loop over
                continue;
            }
            else
            {
                // Break out the loop with valid input
                break;
            }
        }

        std::cout << "\nEnter make: ";
        std::getline(std::cin, make);
        std::cout << "\nEnter model: ";
        std::getline(std::cin, model);

        if (choice == 1)
        {
            std::cout << "\nEnter bed type: ";
            std::getline(std::cin, bed);
            std::cout << std::endl;

            // Create an object of the derived Anaconda class
            Truck truck(year, make, model, bed);
            // Call methods of the derived class
            truck.start();
            truck.drive();
            std::cout << "\nYou own a " << truck.year()
                    << " " << truck.make() << " "
                    << truck.model() << " with a "
                    << truck.bed() << " bed." << std::endl;
        }

        else if (choice == 2)
        {
            std::cout << "\nEnter storage type: ";
            std::getline(std::cin, storage);
            std::cout << std::endl;

            // Create an object of the derived Anaconda class
            Car car(year, make, model, storage);
            // Call methods of the derived class
            car.start();
            car.drive();
            std::cout << "\nYou own a " << car.year()
                    << " " << car.make() << " "
                    << car.model() << " with "
                    << car.storage() << " storage." << std::endl;
        }
        
        else if (choice == 3)
        {
            std::cout << "\nEnter engine type: ";
            std::getline(std::cin, engine);
            std::cout << std::endl;

            // Create an object of the derived Anaconda class
            Motorcycle motorcycle(year, make, model, engine);
            // Call methods of the derived class
            motorcycle.start();
            motorcycle.drive();
            std::cout << "\nYou own a " << motorcycle.year()
                    << " " << motorcycle.make() << " "
                    << motorcycle.model() << " with a "
                    << motorcycle.engine() << " engine." << std::endl;
        }
        
        std::cout << std::endl << std::endl;

        // Validation
        while(true)
        {
            // Prompt user to run the program again
            std::cout << "New vehicle? (y/n): ";
            std::cin >> loop;
            loop = std::tolower(loop);
            //  Is the input S, M, or L
            if (loop != 'y' && loop != 'n')
            {
                std::cout << "\nPlease enter a (y/n).\n" << std::endl;
                // Start the loop over
                continue;
            }
            else {
                // Break out of the loop with valid input
                break;
            }
        }
        
        if (loop == 'y')
        {
            continue;
        }
        else if (loop == 'n')
        {
            break;
        }
    }

    return 0;
}