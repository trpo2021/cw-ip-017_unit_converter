#include <iostream>
#include <cmath>
#include <libconverter/converter.h>

double Kelvin_Celsius(double parametr, bool mable) {
    return parametr + pow(-1, mable) * 273;
}

double In_Fahrenheit(double parametr, bool temp) {
    if (temp == true) parametr = Kelvin_Celsius(parametr, temp);
    return parametr * 1.8 + 32;
}

double From_Fahrenheit(double parametr, bool temp) { // !!!!!!!
    if (temp == true) parametr += 459;
    else parametr -= 32;
    return parametr / 1.8;
}

double exp_ten(double parametr, int degree) {
    while (degree < 0) {
        degree ++;
        parametr /= 10;
    }
    while (degree > 0) {
        degree --;
        parametr *= 10;
    }
    return parametr;
}

double Metres_Mile(double parametr, bool mable) {
    return parametr * pow(pow(-1, mable), 1609.34);
}

double Metres_Yard(double parametr, bool mable) {
    return parametr * pow(pow(-1,mable),0.9144);
}

double Metres_Foot(double parametr, bool mable) {
    return parametr * pow(pow(-1, mable), 3.28084);
}

double Metres_Inch(double parametr, bool mable) {
    return parametr * pow(pow(-1, mable), 39.37);
}

double Metres_LightYear(double parametr, bool mable) {
    return exp_ten(parametr, -16 * pow(-1, mable)) * pow(pow(-1, mable), 1.057008707);}


