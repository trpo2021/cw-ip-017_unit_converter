#ifndef CONVERTER_LIB
#define CONVERTER_LIB

#include <gtk/gtk.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void weight_calc(
        vector<double>& elements,
        double input_element,
        int position_of_element);

void from_double_to_char(
        vector<double> elements,
        int i,
        const gchar* input_char,
        GtkEntry* output);

void time(
        vector<double>& elements,
        double input_element,
        int position_of_element);

double Kelvin_Celsius(double parametr, bool mable);

double In_Fahrenheit(double parametr, bool temp);

double From_Fahrenheit(double parametr, bool temp);

void length(
        vector<double>& elements,
        double input_element,
        int position_of_element);

void temp(
        vector<double>& elements,
        double input_element,
        int position_of_element);

#endif
