#include "RentalSystem.h"
#include <iostream>


RentalService::RentalService(std::string rentalName, int days)
    : rentalType(rentalName), days(days) {
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }};

void RentalService::setRentalStrategy(std::shared_ptr<RentalPricer> rentalStrategy) {
    if (!rentalStrategy) {
        throw std::invalid_argument("Rental strategy cannot be null.");
    }
    strategy = rentalStrategy;
}

double RentalService::executeRental(int days, double basePrice) {
    if (!strategy) {
        throw std::runtime_error("Rental strategy is not set.");
    }
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }
    return strategy->calculatePrice(days, basePrice);
}

std::string RentalService::getRentalType() const {
    return rentalType;
}

void RentalService::setRentalType(const std::string& type) {
    rentalType = type;
}

std::string RentalService::getCurrentStrategyType() const {
    if (!strategy) {
        throw std::runtime_error("Rental strategy is not set.");
    }
    return strategy->getStrategyType();
}

void RentalService::increaseDays(int additionalDays) {
    if (additionalDays < 1) {
        throw std::invalid_argument("Additional days must be at least 1.");
    }
    days += additionalDays;
}

void RentalService::decreaseDays(int daysToDecrease) {
    if (daysToDecrease < 1) {
        throw std::invalid_argument("Days to decrease must be at least 1.");
    }
    if (days - daysToDecrease < 1) {
        throw std::invalid_argument("Cannot decrease days below 1.");
    }
    days -= daysToDecrease;
}

int RentalService::getDays() const {
    return days;
}

std::string RentalService::toString() const {
    return "RentalService: " + rentalType + ", Days: " + std::to_string(days) + ", Strategy: " + (strategy ? strategy->getStrategyType() : "None");
}



