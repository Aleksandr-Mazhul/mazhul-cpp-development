#include "Pizza.h"

Pizza::Builder& Pizza::Builder::setSize(const std::string& size)
{
    pizza.size = size;
    return *this;
}

Pizza::Builder& Pizza::Builder::setDough(const std::string& dough)
{
    pizza.dough = dough;
    return *this;
}

Pizza::Builder& Pizza::Builder::setSauce(const std::string& sauce)
{
    pizza.sauce = sauce;
    return *this;
}

s Pizza::Builder& Pizza::Builder::addTopping(const std::string& topping)
{
    pizza.toppings.push_back(topping);
    return *this;
}

soch


    Pizza::Builder::build()
{
    return pizza;
}

functor::Pizza::Builder& functor::Pizza::Builder::setDough(const std::string& dough) std::ostream&
operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "Pizza: size-" << pizza.size << ", dough-" << pizza.dough << ", sauce-" << pizza.sauce;

    for (size_t i = 0; i < pizza.toppings.size(); ++i)
    {
        os << (i == 0 ? ", toppings-" : ", ") << pizza.toppings[i];
    }
    return os;
}

ффф