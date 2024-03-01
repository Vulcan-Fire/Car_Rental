# Car_Rental

Car Rental Management System
Overview
This project is a simple Car Rental Management System implemented in C++. The system allows customers, employees, and managers to interact with the car rental service. Users can rent and return cars, while managers have additional functionalities such as adding/removing customers, employees, and cars, as well as checking the owner of a rented car.

Table of Contents
Introduction
Table of Contents
Features
Usage
Classes
File Handling
Data Persistence
Build and Run
Contributing
License
Features
Customer Interaction:

Customers can rent and return cars.
Rental duration is limited, and a fine is imposed for late returns.
Renters are provided with feedback on their punctuality.
Employee Interaction:

Employees have similar functionalities to customers in renting and returning cars.
Employees are also subject to rental limits and rent scores.
Manager Interaction:

Managers can perform administrative tasks, including adding/removing customers and employees.
Managers can check the owner of a rented car.
Managers can add new cars to the rental fleet.
Usage
Customer
Type return to return a rented car.
Type rent to rent a car from the available collection.
Employee
Type return to process a returned car.
Type rent to rent a car from the available collection.
Manager
Type AddCustomer to add a new customer to the system.
Type AddEmployee to add a new employee to the system.
Type CarOwner to check the owner of a rented car.
Type RemoveCustomer to remove a customer from the system.
Type RemoveEmployee to remove an employee from the system.
Type AddCar to add a new car to the rental fleet.
General
Type abort to end the program.
Classes
The project defines three classes:

User: Base class for Customer, Employee, and Manager classes containing common attributes and methods.
Car: Represents a car with model, value, and condition attributes.
Customer, Employee, Manager: Derived classes from the User class, each with specific functionalities.
File Handling
The system loads and saves data using file handling. Custs.txt, Employees.txt, Managers.txt, Cars.txt, CarOwner.txt, and Allcars.txt store user information, car details, and rental information.

Data Persistence
User and car information is stored persistently in text files. The system reads this data at startup and updates the files when users perform actions like renting, returning, or administrative tasks.

Build and Run
Compile the C++ code using a C++ compiler to build and run the project. For example, using g++:

bash
Copy code
g++ -o car_rental_system car_rental_system.cpp
./car_rental_system
Contributing
Feel free to contribute to the project by creating issues or submitting pull requests. Any improvements or additional features are welcome.

License
This project is licensed under me.
