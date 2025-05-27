#include <iostream>
#include "RentalSystem.h"

int main()
{
    RentalService rentalService("Test rental", 5);
    std::cout << "Rental type: " << rentalService.getRentalType() << std::endl;

    return 0;
}