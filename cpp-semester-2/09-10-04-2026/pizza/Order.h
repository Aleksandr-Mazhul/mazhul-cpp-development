#pragma once
#include "Pizza.h"

#include <ostream>
#include <string>
#include <vector>

class Order
{





  public:
    Order(int number, const std::string& name);

    int totalPrice() const;

    void addPizza(const Pizza& pizza);

    int count() const;

    friend std::ostream& operator<<(std::ostream& os, const Order& order);

  private:
    int orderNumber;
    std::string customerName;
    std::vector<Pizza> pizzas;
};
