#include <iostream>
#include "RentalStrategy.h"
#include <assert.h>

//Sukurti BikeRental klase, kuri paveldi RentalPricer klase, kaina skaiciuojama pagal tai ar dviratis )elektrinis ar ne

int main()
{
    CarRental petrolCar(false);
    CarRental electricCar(true);
    HouseRental houseRental;
    RentalService rentalService;


    rentalService.setRentalPricer(&petrolCar);
    assert(rentalService.getPricer() == &petrolCar);
    assert(rentalService.getPricer()->calculatePrice(5,10) == 50);
    //assert(rentalService.getPricer()->rentalType() == "Petrol car rental");

    
    rentalService.setRentalPricer(&electricCar);
    assert(rentalService.getPricer() == &electricCar);
    assert(rentalService.getPricer()->calculatePrice(5,10) == 37.5);
    //assert(rentalService.getPricer()->rentalType() == "Electric car rental");

    rentalService.setRentalPricer(&houseRental);
    assert(rentalService.getPricer()->calculatePrice(3,250) == 750);
    //assert(houseRental.rentalType() == "House rental");

    /*
    rentalService.setRentalPricer(&ElectricBike);
    assert(rentalService.getPricer() == &ElectricBike);
    assert(rentalService.getPricer()->calculatePrice(5) == 150);
    assert(rentalService.getPricer()->rentalType() == "Electric bike rental");
    
    rentalService.setRentalPricer(&Bike);
    assert(rentalService.getPricer() == &Bike);
    assert(rentalService.getPricer()->calculatePrice(5) == 75);
    assert(rentalService.getPricer()->rentalType() == "Bike rental");
    */

    return 0;
}