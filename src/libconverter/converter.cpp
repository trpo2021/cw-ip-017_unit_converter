#include "converter.h"
#include <gtk/gtk.h>
#include <sstream>
#include <math.h>
#include <string>
#include <vector>
#define UI_FILE "../converter/Unit_converter.glade"

#define UNUSED(x) (void)(x);

void weight_calc(
        vector<double>& elements, double input_element, int position_of_element)
{
    int i;
    double coefficients[10]{
            1 / 1.e+3,               // 1 gr
            1 / 1.e+3,               // 2 mili
            1.e+9,                   // 3 metric ton
            1.01604608e+0,           // 4 long ton
            1 / 1.12e+0,             // 5 short ton
            1 / 2000e+0,             // 6 pound
            1 / 16e+0,               // 7 ounce
            1 / 141.7475e+0,         // 8 carrat
            1 / 1.20442733033504e+23 // 9 atom
    };
    elements.resize(10);
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i - 1];
    }
    for (i = position_of_element; i < 10; i++) {
        elements[i + 1] = elements[i] / coefficients[i];
    }
}

void from_double_to_char(
        vector<double> elements,
        int i,
        const gchar* input_char,
        GtkEntry* output)
{
    string temprory;
    stringstream ss;
    ss << elements[i];
    ss >> temprory;
    input_char = temprory.c_str();
    gtk_entry_set_text(output, input_char);
}

void time(
        vector<double>& elements, double input_element, int position_of_element)
{
    int i;
    double coefficients[11]{
            1 / (1.e+3),    // 0 sec
            1 / (1.e+3),    // 1 milisec
            1 / (1.e+3),    // 2 microsec
            1 / (1.e+3),    // 3 nanosec
            1 / (1.e+3),    // 4 picasec
            60000000000000, // 5 minutes
            60,             // 6 hours
            24,             // 7 days
            7,              // 8 weeks
            29.5 / 7,       // 9 months
            12,             // 10 years
    };
    elements.resize(11);
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i];
    }
    for (i = position_of_element; i < 10; i++) {
        elements[i + 1] = elements[i] / coefficients[i + 1];
    }
}

double Kelvin_Celsius(double parametr, bool mable)
{
    return parametr + pow(-1, mable) * 273;
}
double In_Fahrenheit(double parametr, bool temp)
{
    if (temp == true)
        parametr = Kelvin_Celsius(parametr, temp);
    return parametr * 1.8 + 32;
}
double From_Fahrenheit(double parametr, bool temp)
{
    if (temp == true)
        parametr += 459;
    else
        parametr -= 32;
    return parametr / 1.8;
}

void length(
        vector<double>& elements, double input_element, int position_of_element)
{
    int i;
    double coefficients[11]{
            1,
            1.e+3,                 // 1 Kilometer
            1.e-5,                 // 2 Centimeter
            1.e-1,                 // 3 Millimeter
            1.e-3,                 // 4 Micrometer
            1.e-3,                 // 5 Nanometer
            1609350000000e+0,      // 6 Mile
            1 / 1760.0065617e+0,   // 7 Yard
            1 / 3.e+0,             // 8 Foot
            1 / 12.e+0,            // 9 Inch
            372466929133858300.e+0 // 10 Light Year
    };
    elements.resize(11);
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i];
    }
    for (i = position_of_element; i < 10; i++) {
        elements[i + 1] = elements[i] / coefficients[i + 1];
    }
}

void temp(
        vector<double>& elements, double input_element, int position_of_element)
{
    elements.resize(3);
    switch (position_of_element) {
    case 0: {
        elements[0] = input_element;
        elements[1] = Kelvin_Celsius(input_element, false);
        elements[2] = In_Fahrenheit(input_element, false);
        break;
    }
    case 1: {
        elements[0] = Kelvin_Celsius(input_element, true);
        elements[1] = input_element;
        elements[2] = In_Fahrenheit(input_element, true);
        break;
    }
    case 2: {
        elements[0] = From_Fahrenheit(input_element, false);
        ;
        elements[1] = From_Fahrenheit(input_element, true);
        elements[2] = input_element;
        break;
    }
    }
}
