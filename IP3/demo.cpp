#include <iostream>
#include "RentalStrategy.h"

int main()
{

    RentalService rentalService;

    try
    {

        CarRental petrolCar(false);
        rentalService.setRentalPricer(&petrolCar);
        rentalService.executeRental(4, 150);

        CarRental electricCar(true);
        rentalService.setRentalPricer(&electricCar);
        rentalService.executeRental(5, 150);

        HouseRental houseRental;
        rentalService.setRentalPricer(&houseRental);
        rentalService.executeRental(3, 250);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}