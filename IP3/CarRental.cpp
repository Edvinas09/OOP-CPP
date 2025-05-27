#include "RentalSystem.h"
#include <stdexcept>


CarRental::CarRental(bool isElectric, int minimumDrivingAge, bool unlimitedMileage, int driverAge)
    : RentalPricer(20, "Car"), isElectric(isElectric), minimumDrivingAge(minimumDrivingAge), unlimitedMileage(unlimitedMileage), driverAge(driverAge) {
    if (driverAge < minimumDrivingAge) {
        throw std::invalid_argument("Driver age must be at least the minimum driving age.");
    }
}

double CarRental::calculatePrice(int days, double price) {
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative.");
    }

    double totalPrice = days * price;

    if (isElectric) {
        totalPrice *= 0.80; 
    }

    if (unlimitedMileage) {
        totalPrice += 40;
    }

    return totalPrice;
}

int CarRental::getDriverAge(int age) {
    return driverAge;
}
void CarRental::setDriverAge(int age) {
    if (age < minimumDrivingAge) {
        throw std::invalid_argument("Driver age must be at least the minimum driving age.");
    }
    driverAge = age;
}

bool CarRental::getElectric() const {
    return isElectric;
}

int CarRental::getMinimumDrivingAge() const {
    return minimumDrivingAge;
}

void CarRental::setMinimumDrivingAge(int age) {
    if (age < 18) {
        throw std::invalid_argument("Minimum driving age must be at least 18.");
    }
    minimumDrivingAge = age;
}

bool CarRental::getUnlimitedMileage() const {
    return unlimitedMileage;
}

void CarRental::setUnlimitedMileage(bool unlimited) {
    unlimitedMileage = unlimited;
}
