#include <string>

#pragma once


class RentalPricer{
    public:
    virtual double calculatePrice(int days, double price)  = 0; 
    virtual ~RentalPricer() = default; 
};

class CarRental : public RentalPricer{
    private:
    bool isElectric;

    public:
    CarRental(bool isElectric);
    bool getElectric() const;
    double calculatePrice(int days, double price) override;
};

class HouseRental : public RentalPricer{
    public:
    double calculatePrice(int days, double price) override;
};

class RentalService{
    private:
    RentalPricer* pricer;
    
    public:
    void setRentalPricer(RentalPricer* rentalPricer);
    RentalPricer* getPricer() const;
    void executeRental(int days, double price);
};
