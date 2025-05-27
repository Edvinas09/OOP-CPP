#include "RentalSystem.h"
#include <stdexcept>


HouseRental::HouseRental(int peopleCount, double cleaningFee, bool hasPets)
    : RentalPricer(100, "House"), peopleCount(peopleCount), cleaningFee(cleaningFee), hasPets(hasPets) {
    if (peopleCount < 1) {
        throw std::invalid_argument("People count must be at least 1.");
    }
}

double HouseRental::calculatePrice(int days, double price){
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative.");
    }

    double totalPrice = days * price;

    if (hasPets) {
        totalPrice += cleaningFee* 1.2; 
    }

    return totalPrice + ((peopleCount - 1) * 10) + cleaningFee;
}

int HouseRental::getPeopleCount() const {
    return peopleCount;
}

void HouseRental::setPeopleCount(int count) {
    if (count < 1) {
        throw std::invalid_argument("People count must be at least 1.");
    }
    peopleCount = count;
}

double HouseRental::getCleaningFee() const {
    return cleaningFee;
}

void HouseRental::setCleaningFee(double fee) {
    if (fee < 0) {
        throw std::invalid_argument("Cleaning fee must be non-negative.");
    }
    cleaningFee = fee;
}


bool HouseRental::getHasPets() const {
    return hasPets;
}

void HouseRental::setHasPets(bool hasPets) {
    this->hasPets = hasPets;
}
