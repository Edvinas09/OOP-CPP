# OOP-CPP Projects

This repository contains several C++ projects developed for a university Object-Oriented Programming (OOP) course. Each project demonstrates key OOP concepts such as encapsulation, inheritance, polymorphism, operator overloading, and resource management.

## Structure

- **IP1/**: Contains the `HotelRoom` class implementation and unit tests.
- **IP2/**: Implements a hash table with open addressing and linear probing, including operator overloads and deep copy functionality.
- **IP3/**: Demonstrates a rental system with polymorphic pricing strategies for cars, houses, and bikes.

## Project Descriptions

### IP1: HotelRoom

Implements a `HotelRoom` class with attributes such as room type, room number, and price per night. Includes constructors, destructors, and unit tests to verify class behavior.

### IP2: HashTable

Implements a hash table in C++ with open addressing and linear probing. Features CRUD operations, operator overloads (`+=`, `-=`, `()`, `!`, `[]`), deep copy (copy constructor and assignment), and an object counter.

### IP3: Rental System

A polymorphic rental system supporting different rental strategies:
- `CarRental`
- `HouseRental`
- `BikeRental`

Each rental type has its own pricing logic and constraints. The system demonstrates the use of inheritance, virtual methods, and smart pointers.

## How to Build

Each project folder apar from IP1 contains a `makefile` for building the executables. For example, to build and run tests in `IP2`:

```sh
cd IP2
make run
```

For `IP3`:

```sh
cd IP3
make all
./test.exe
```

## Notes

- All code was written as part of coursework for a university OOP class.
- Unit tests are included in each project to verify correctness.
