#include "RentalStrategy.h"

double HouseRental::calculatePrice(int days, double basePrice) {
    return days * basePrice;
}


/*

class StrategyInterface {
public:
    virtual ~StrategyInterface() = default;
    virtual void execute() const = 0;
};

class ConcreteStrategyA : public StrategyInterface {
    void execute() const override{
        std::cout << "Doing work using strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public StrategyInterface {
    void execute() const override{
        std::cout << "Doing work using strategy B" << std::endl;
    }
};


class Context {
private:
    std::unique_ptr<StrategyInterface> strategy_;
public:
    void SetStrategy(std::unique_ptr<StrategyInterface>& strategy) {
        strategy_ = std::move(strategy);
    }
    void PerformWork(){
        strategy_->execute();
    }
};

void ClientCode() {

    Context c;
    std::unique_ptr<StrategyInterface> strategy = std::make_unique<ConcreteStrategyA>();
    c.SetStrategy(strategy);
    c.PerformWork();

    strategy = std::make_unique<ConcreteStrategyB>();
    c.SetStrategy(strategy);
    c.PerformWork();
}

int main() {    
    ClientCode();
    return 0;
}
    */