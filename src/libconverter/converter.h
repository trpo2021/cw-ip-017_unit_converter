#ifndef CONVERTER_LIB
#define CONVERTER_LIB
#include <gtk/gtk.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void from_double_to_char(
        vector<double> elements,
        int i,
        const gchar* input_char,
        GtkEntry* output);

double Kelvin_Celsius(double parametr, bool mable);

double In_Fahrenheit(double parametr, bool temp);

double From_Fahrenheit(double parametr, bool temp);

void temp(
        vector<double>& elements,
        double input_element,
        int position_of_element);

void parametr(
	vector<double> &elements, 
	double input_element,
        int position_of_element,
	int file_num);

#endif
