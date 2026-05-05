#include "Order.h"
#include "Pizza.h"

#include <iostream>

int main()
{


    std::string name;

    std::cout << "Enter name: ";

    std::getline(std::cin, name);

    std::cout << "Hello, " << name << '\n';
    auto pizza1 = Pizza::Builder().setSize("small").build();
    std::cout << pizza1 << std::endl;

    auto pizza2 = Pizza::Builder()
                      .setSize("large")
                      .setDough("thick")
                      .setSauce("bbq")
                      .addTopping("mushrooms")
                      .addTopping("olives")
                      .addTopping("pepperoni")
                      .build();

    std::cout << pizza2 << std::endl;

    auto pizza3 = Pizza::Builder().setSize("medium").addTopping("mozzarella").build();

    std::cout << pizza3 << std::endl;

    Order order(1, "Alex");
    order.addPizza(pizza1);

    std::cout << order;
}
