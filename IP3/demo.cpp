#include <iostream>
#include "RentalSystem.h"

int main()
{
    int days = 5;
    int carBasePrice = 20;
    int houseBasePrice = 100;
    double price;
    RentalService rentalService("Test rental", days);
    try{

    rentalService.setRentalStrategy(std::make_shared<RentalPricer>(0, "Base Rental"));
    price = rentalService.executeRental(days,10);
    std::cout << "Details of " << rentalService.toString() << std::endl;
    std::cout << "Base rental price: " << price << std::endl;
    

    //Polimorfizmas
    rentalService.setRentalStrategy(std::make_shared<CarRental>(false, 18, true, 20));
    price = rentalService.executeRental(days, carBasePrice);
    std::cout<<"\nDetails of " << rentalService.toString() << std::endl;
    std::cout << "Car rental price: " << price << std::endl;
    

    //Polimorfizmas
    rentalService.setRentalStrategy(std::make_shared<HouseRental>(3, 50));
    price = rentalService.executeRental(days, houseBasePrice);
    std::cout<<"\nDetails of " << rentalService.toString() << std::endl;
    std::cout << "House rental price: " << price << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}