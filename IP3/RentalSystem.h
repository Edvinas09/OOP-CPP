#include <string>
#include <memory>

#pragma once

class RentalPricer
{
private:
    double pricePerDay;
    std::string StrategyType;
public:
    RentalPricer();
    RentalPricer(double pricePerDay, std::string type);
    virtual ~RentalPricer() = default;
    
    virtual double calculatePrice(int days, double price) = 0;

    virtual void setPricePerDay(double price);
    virtual double getPricePerDay() const;
    virtual std::string getStrategyType();
};

class CarRental : public RentalPricer
{
private:
    bool isElectric;
    int minimumDrivingAge;
    bool unlimitedMileage;
    int driverAge;

public:
    CarRental(bool isElectric=false, int minimumDrivingAge=18, bool unlimitedMileage=false, int driverAge=18);
    int getDriverAge(int age);
    void setDriverAge(int age);
    bool getElectric() const;
    int getMinimumDrivingAge() const;
    void setMinimumDrivingAge(int age);
    bool getUnlimitedMileage() const;
    void setUnlimitedMileage(bool unlimited);

    double calculatePrice(int days, double price) override;
};

class HouseRental : public RentalPricer
{
    private:
    int peopleCount;
    double cleaningFee;
    bool hasPets;
public:
    HouseRental(int peopleCount=1, double cleaningFee=20.0, bool hasPets=false);
    int getPeopleCount() const;
    void setPeopleCount(int count);
    double getCleaningFee() const;
    void setCleaningFee(double fee);
    bool getHasPets() const;
    void setHasPets(bool hasPets);


    double calculatePrice(int days, double price) override;
};

class RentalService
{
    private:
    std::shared_ptr<RentalPricer> strategy;
    std::string rentalType;
    int days;
public:
    RentalService(std::string rentalName, int days=1);

    void setRentalStrategy(std::shared_ptr<RentalPricer> rentalStrategy);
    std::string getCurrentStrategyType() const;
    double executeRental(int days, double basePrice);
    void increaseDays(int additionalDays);
    void decreaseDays(int daysToDecrease);
    std::string getRentalType() const;
    void setRentalType(const std::string& type);
    int getDays() const;

    std::string toString() const;

};