#include "RentalStrategy.h"
#include <iostream>


void RentalService::setRentalPricer(RentalPricer* rentalPricer) {
    pricer = rentalPricer;
}

RentalPricer* RentalService::getPricer() const {
    return pricer;
}

void RentalService::executeRental(int days, double basePrice) {
    if (pricer) {
        std::cout << "Rental price: " << pricer->calculatePrice(days, basePrice) << std::endl;
    } else {
        std::cout << "No rental pricer set." << std::endl;
    }
}