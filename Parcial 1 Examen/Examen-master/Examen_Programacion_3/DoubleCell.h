#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:
    // Default constructor
    DoubleCell();

    // Constructor with value
    explicit DoubleCell(double value); //Declares a DoubleCell with a predetermined value

    // Copy constructor
    DoubleCell(const DoubleCell& other);

    //Reference constructor
    DoubleCell(DoubleCell&& other) noexcept;

    // Destructor
    ~DoubleCell() = 0;

    // Assignment operator by copy
    DoubleCell& operator=(const DoubleCell& other);

    // Assignment operator by reference
    DoubleCell& operator=(DoubleCell&& other) noexcept;

    // Assignment operator for double
    DoubleCell& operator=(double value);

    // Arithmetic operators
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Setters
        void SetValue(double value);

    // Getters

       double GetValue() const;


protected:
    double Storedvalue;
};

#endif  // DOUBLE_CELL_H
