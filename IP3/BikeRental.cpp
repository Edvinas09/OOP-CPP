#include "RentalSystem.h"
#include "BikeRental.h"
#include <stdexcept>


BikeRental::BikeRental( bool helmet, int minimumAge, int driverAge, bool electric, double insuranceFee)
    : RentalPricer(10, "Bike"), helmet(helmet), minimumAge(minimumAge), driverAge(driverAge), electric(electric), insuranceFee(insuranceFee) {
    if (driverAge < minimumAge) {
        throw std::invalid_argument("Driver age must be at least the minimum age.");
    }
}

double BikeRental::calculatePrice(int days, double price){
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative.");
    }

    double totalPrice = days * price;

    if (helmet) {
        totalPrice += 2; 
    }

    if (electric) {
        totalPrice *= 0.90; 
    }
    return totalPrice + insuranceFee;
}

int BikeRental::getDriverAge() const {
    return driverAge;
}

void BikeRental::setDriverAge(int age) {
    if (age < minimumAge) {
        throw std::invalid_argument("Driver age must be at least the minimum age.");
    }
    driverAge = age;
}

bool BikeRental::getElectric() const {
    return electric;
}

int BikeRental::getMinimumDrivingAge() const {
    return minimumAge;
}

void BikeRental::setMinimumDrivingAge(int age) {
    if (age < 16) {
        throw std::invalid_argument("Minimum driving age must be at least 16.");
    }
    minimumAge = age;
}

bool BikeRental::getHelmet() const {
    return helmet;
}

double BikeRental::getInsuranceFee() const {
    return insuranceFee;
}

void BikeRental::setInsuranceFee(double fee) {
    if (fee < 0) {
        throw std::invalid_argument("Insurance fee must be non-negative.");
    }
    insuranceFee = fee;
}
