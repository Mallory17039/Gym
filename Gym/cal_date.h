#pragma once
#include <ctime>
#include <iostream>


int cal() {
    int y1;
    int y2;
    int m1;
    int m2;
    int d1;
    int d2;
    cout << "Enter the start year: " << endl;
    cin >> y1;
    cout << "Enter the start year's month" << endl;
    cin >> m1;
    cout << "Enter the start month's date" << endl;
    cin >> d1;

    cout << "Enter the end year: " << endl;
    cin >> y2;
    cout << "Enter the end year's month: " << endl;
    cin >> m2;
    cout << "Enter the end month's date: " << endl;
    cin >> d2;

    // std::tm expected years after 1900
    y1 = y1 - 1900;
    y2 = y2 - 1900;

    struct std::tm a = { 0,0,0,d1,m1,y1 }; 
    struct std::tm b = { 0,0,0,d2,m2,y2 }; 
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24);
        std::cout << std::ctime(&x);
        std::cout << std::ctime(&y);
        std::cout << "difference = " << difference << " days" << std::endl;
        return (int)difference;
    }
    return 0;
}