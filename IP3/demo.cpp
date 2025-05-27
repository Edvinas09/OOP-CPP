#include <iostream>
#include "RentalSystem.h"

int main()
{
    int days = 5;
    int carBasePrice = 20;
    int houseBasePrice = 100;
    RentalService rentalService("Test rental", days);
    try{

    //Polimorfizmas
    rentalService.setRentalStrategy(std::make_shared<CarRental>(false, 18, true, 20));
    double price = rentalService.executeRental(days, carBasePrice);
    std::cout << "Car rental price: " << price << std::endl;

    //Polimorfizmas
    rentalService.setRentalStrategy(std::make_shared<HouseRental>(3, false));
    price = rentalService.executeRental(days, houseBasePrice);
    std::cout << "House rental price: " << price << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}