#ifndef CALCULATOR_H
#define CALCULATOR_H
template <class T>
class Calculator
{
public:
    Calculator(T n1, T n2);
    ~Calculator();
    T add();
    T subtract();
    T multiply();
    T divide();
private:
    T num1;
    T num2;
};
#endif // CALCULATOR_H