#include "RentalSystem.h"

class BikeRental : public RentalPricer
{
private:
    bool helmet;
    int minimumAge;
    int driverAge;
    bool electric; 
    double insuranceFee;

public:
    BikeRental(bool helmet = false, int minimumAge = 16, int driverAge = 18, bool electric = false, double insuranceFee = 5.0);

    int getDriverAge() const;
    void setDriverAge(int age);
    bool getElectric() const;
    int getMinimumDrivingAge() const;
    void setMinimumDrivingAge(int age);
    bool getHelmet() const;
    void setHelmet(bool helmet);
    double getInsuranceFee() const;
    void setInsuranceFee(double fee);

    double calculatePrice(int days, double price) override;
};