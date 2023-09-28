#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
DoubleCell::DoubleCell()
    :Storedvalue(0.0){}

// Constructor with value
DoubleCell::DoubleCell(double value)
    : Storedvalue(value){}

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell& other)
    : Storedvalue(other.Storedvalue){}

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell&& other) noexcept
        : Storedvalue(other.Storedvalue)
        {
    other.Storedvalue = 0;
        }


// Destructor
DoubleCell:: ~DoubleCell() //Assigns value of Storedvalue to 0
{
Storedvalue = 0;
}

// Assignment operator by copy
DoubleCell& DoubleCell::operator=(const DoubleCell& other){ //Copies value of other to Storedvalue
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference
DoubleCell& DoubleCell::operator=(DoubleCell&& other) noexcept //Makes reference to other.Storedvalue
{
    if (this != &other)
    {
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}

// Assignment operator for double
DoubleCell& DoubleCell::operator=(double value){ //Assigns value to Storedvalue
            Storedvalue = value;
            return *this;
}

// Arithmetic operators
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{ //Uses reference of the DoubleCell other to sum Storedvalue
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell:: operator +(double value) const //Uses double value to sum directly to Storedvalue
{
    return DoubleCell(Storedvalue + value);
}

//DoubleCell substracting
DoubleCell DoubleCell::operator -(const DoubleCell& other) const //Uses reference of the DoubleCell other to substract Storedvalue
{
    return DoubleCell(Storedvalue - other.Storedvalue);
}

//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{ //Uses double value to substract directly to Storedvalue
    return DoubleCell(Storedvalue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{ //Uses reference of the DoubleCell other to multiply Storedvalue
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const //Uses double value to multiply directly to Storedvalue
{
    return DoubleCell(Storedvalue * value);
}

//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{ //Uses reference of the DoubleCell other to divide Storedvalue
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive souble division 
DoubleCell DoubleCell::operator /(double value) const{ //Uses double value to divide directly to Storedvalue
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Setters
void DoubleCell::SetValue(double value){
            Storedvalue = value;
}

// Getters
double DoubleCell::GetValue() const
{
    return Storedvalue;
}
