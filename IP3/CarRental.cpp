#include "RentalStrategy.h"

CarRental::CarRental(bool electric) : isElectric(electric) {}

bool CarRental::getElectric() const {
    return isElectric;
}

double CarRental::calculatePrice(int days, double basePrice) {
    if (isElectric) {
        return days * basePrice * 0.75; 
    }
    return days * basePrice; 
}