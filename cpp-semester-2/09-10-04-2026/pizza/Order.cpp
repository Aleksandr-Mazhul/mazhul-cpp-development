#include "Order.h"

#include "Pizza.h"

Order::Order(int number, const std::string& name)
    : orderNumber(number)
      , customerName(name)
{
}

int Order::totalPrice() const
{
    int total = 0;
    for (const auto& pizza : pizzas)
    {
        total += pizza.getPrice();
    }
    return total;
}

void Order::addPizza(const Pizza& pizza)
{
    pizzas.push_back(pizza);
}

int Order::count() const
{
    return pizzas.size();
}

std::ostream& operator<<(std::ostream& os, const Order& order)
{
    os << "Order #" << order.orderNumber << "\n";
    os << "Customer: " << order.customerName << "\n";

    os << "Pizzas (" << order.count() << "):\n";

    for (const auto& p : order.pizzas)
    {
        os << "  - " << p << "\n";
    }

    os << "Total price: " << order.totalPrice() << "\n";

    return os;
}
