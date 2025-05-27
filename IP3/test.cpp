#include <iostream>
#include "RentalSystem.h"
#include <assert.h>

int main()
{
    int days = 5;
    int carBasePrice = 20;
    int houseBasePrice = 100;
    double price;
    RentalService rentalService("Test rental", days);

    try
    {
        rentalService.setRentalStrategy(std::make_shared<CarRental>(false, 18, true, 20));

        assert(rentalService.getCurrentStrategyType() == "Car");
         price = rentalService.executeRental(days, carBasePrice);
        assert(price == 100);

        rentalService.increaseDays(2);
        assert(rentalService.getDays() == 7);
        price = rentalService.executeRental(rentalService.getDays(), carBasePrice);
        assert(price == 140);

        rentalService.decreaseDays(3);
        assert(rentalService.getDays() == 4);
        price = rentalService.executeRental(rentalService.getDays(), carBasePrice);
        assert(price == 80);
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}