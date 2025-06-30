#include <iostream>
#include "RentalSystem.h"
#include "BikeRental.h"
#include <assert.h>
#include <fstream>

//TODO: Parasyti BikeRental klase, kuri paveldi RentalPricer klase ir turi papildomus atributus:
// helmet - jeigu yra padidinam kaina 2 eurais per diena
// minimumDrivingAge - negali buti mazesnis uz 16
//driverAge - negali buti mazesnis uz minimumDrivingAge
//electric - jeigu true, kaina mazinama 10%(panasiai kaip CarRental klaseje)
//pricePerDay, insuranceFee

int main()
{
    int days = 5;
    int carBasePrice = 20;
    int houseBasePrice = 100;
    double price;
    std::ofstream output("test.txt");

    
    try
    {
        // Car Rental Tests
        auto carRental = std::make_shared<CarRental>(false, 18, true, 20); // isElectric, minimumDrivingAge, unlimitedMileage, driverAge
        price = carRental->calculatePrice(days, carBasePrice);
        assert(price == 140); // 5 days * 20 per day + 40 unlimited mileage
        carRental->setDriverAge(25);
        assert(carRental->getDriverAge() == 25);
        carRental->setMinimumDrivingAge(21);
        assert(carRental->getMinimumDrivingAge() == 21);
        carRental->setUnlimitedMileage(false);
        assert(carRental->getUnlimitedMileage() == false);
        assert(carRental->getElectric() == false);
        price = carRental->calculatePrice(days, carBasePrice);
        assert(price == 100); // 5 days * 20 per day, no unlimited mileage
        output << "Car Rental Tests passed successfully.\n";
        
        // House Rental Tests
        auto houseRental = std::make_shared<HouseRental>(3, 50, true); // peopleCount, cleaningFee, hasPets
        price = houseRental->calculatePrice(days, houseBasePrice);
        assert(price == 670); // 5 days * 100 per day + 50 cleaning fee + 2*30 for people, 60(cleaning free increased by 20% for pets)
        houseRental->setPeopleCount(4);
        assert(houseRental->getPeopleCount() == 4);
        houseRental->setCleaningFee(75);
        assert(houseRental->getCleaningFee() == 75);
        houseRental->setHasPets(true);
        assert(houseRental->getHasPets() == true);
        price = houseRental->calculatePrice(days, houseBasePrice);
        assert(price == 755); // 5 days * 100 per day + 75 cleaning fee + 3*30 for people, 90(cleaning free increased by 20% for pets)
        output << "House Rental Tests passed successfully.\n";


        // //Bike Rental Tests

        auto bikeRental = std::make_shared<BikeRental>(true, 16,18, false, 5); // helmet, minimum age, driver age, electric, insurance fee

        price = bikeRental->calculatePrice(days, 10);
        assert(price == 57); // 5 days * 10 per day + 5 insurance fee, if helmet is true, it should be +2

        bikeRental->setDriverAge(18);
        assert(bikeRental->getDriverAge() == 18);

        bikeRental->setMinimumDrivingAge(16);
        assert(bikeRental->getMinimumDrivingAge() == 16);

        bikeRental->setInsuranceFee(10);    
        assert(bikeRental->getInsuranceFee() == 10);
        price = bikeRental->calculatePrice(days, 10);
        assert(price == 62); // 5 days * 10 per day + 10 insurance fee, if helmet is false, it should be -2
        assert(bikeRental->getElectric() == false);
        output << "Bike Rental Tests passed successfully.\n";

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        //Rental Service Tests
        RentalService rentalService("Test rental", days);
        rentalService.setRentalStrategy(std::make_shared<CarRental>(false, 18, true, 20));
        price = rentalService.executeRental(days, carBasePrice);
        assert(price == 140); // 5 days * 20 per day + 40 unlimited mileage

        rentalService.setRentalStrategy(std::make_shared<HouseRental>(3, 50, true));
        price = rentalService.executeRental(days, houseBasePrice);
        assert(price == 670); // 5 days * 100 per day + 50 cleaning fee + 2*30 for people, 60(cleaning free increased by 20% for pets)

        rentalService.setRentalStrategy(std::make_shared<BikeRental>(true, 16, 18, false, 5));
        price = rentalService.executeRental(days, 10);
        assert(price == 57); // 5 days * 10 per day + 5 insurance fee, if helmet is true, it should be +2
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}