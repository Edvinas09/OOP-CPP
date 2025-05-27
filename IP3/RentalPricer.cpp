#include "RentalSystem.h"
#include <stdexcept>

RentalPricer::RentalPricer() {};

RentalPricer::RentalPricer(double pricePerDay, std::string type)
: pricePerDay(pricePerDay), StrategyType(type) {}

void RentalPricer::setPricePerDay(double price) {
    pricePerDay = price;
}
double RentalPricer::getPricePerDay() const {
    return pricePerDay;
}

std::string RentalPricer::getStrategyType() {
    return StrategyType;
}

double RentalPricer::calculatePrice(int days, double price) {
    if (days < 1) {
        throw std::invalid_argument("Days must be at least 1.");
    }
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative.");
    }
    return 0; // virtualus metodas
}