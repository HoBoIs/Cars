//car.h
#pragma once
#include <iostream>
#include <string>
#include <sstream>
//using namespace std; DON'T do useing namespace in *.h!!!
//(You will understand why when you will use libraries/modules) 
class Car;
std::istream& operator>>(std::istream& is, Car& c);

class Car
{
    friend std::istream& operator>>(std::istream& is, Car& c);

private:
    std::string name;
    std::string color;
    double price;

public:
    //---------------------------------------------------------------------------------------
    /*
    * Constructor/Destructor
    *
    * Handles creation and deletion of Car objects.
    *
    * Parameter: name_in
    *       The name of a new car
    * Parameter: color_in
    *       The color of a new car
    * Parameter: price_in
    *       The price of a new car
    */
    Car(std::string name_in, std::string color_in, double price_in);
    Car();
    virtual ~Car();
    //---------------------------------------------------------------------------------------
    /*
    * getName
    *
    * Returns the name of the car.
    *
    * Return:
    *       The name of the car
    */
    std::string getName();
    /*
    * getColor
    *
    * Returns the color of the car.
    *
    * Return:
    *       The color of the car
    */
    std::string getColor();
    /*
    * getPrice
    *
    * Returns the price of the car.
    *
    * Return:
    *       The price of the car
    */
    double getPrice();
    //---------------------------------------------------------------------------------------
    /*
    * paint
    *
    * Paints the car a new color and increases the price by $1,000.
    *
    * Parameter: new_color
    *       The color of paint to be used on the car
    */
    void paint(std::string new_color);
    //---------------------------------------------------------------------------------------
    /*
    * toString
    *
    * Returns a single string containing useful information about the car.
    *
    * Return:
    *       A data string about this car
    */
    std::string toString();
    //---------------------------------------------------------------------------------------
};

//car.cpp
using namespace std;

//---------------------------------------------------------------------------------------
std::istream& operator>>(std::istream& is, Car& c){
    is >> c.name >> c.color >> c.price;
    //if $ is there after the price:
    //char dollarsign;
    //is >> dollarsign;
    return is;
}

Car::Car()
{
    price=0;
}

Car::Car(string name_in, string color_in, double price_in)
{
    name = name_in;
    color = color_in;
    price = price_in;
}
Car::~Car() {}
//---------------------------------------------------------------------------------------
string Car::getName()
{
    return name;
}
string Car::getColor()
{
    return color;
}
double Car::getPrice()
{
    return price;
}
//---------------------------------------------------------------------------------------
void Car::paint(string new_color)
{
    color = new_color;
    price += 1000;
}
//---------------------------------------------------------------------------------------
string Car::toString()
{
    stringstream ss;
    ss << "Name: " << name << endl;
    ss << "Color: " << color << endl;
    ss << "Price: $" << price << endl;
    return ss.str();
}
//---------------------------------------------------------------------------------------

