#include "converter.h"
#include <gtk/gtk.h>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#define UI_FILE "../converter/Unit_converter.glade"

#define UNUSED(x) (void)(x);

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

string filename[] = { "area.txt","length.txt","time.txt","weight.txt","volume.txt" };

void parametr(
	vector<double>& elements, double input_element, int position_of_element, int file_num) 
{
    string str;
    int i = 0;
    vector<double> coefficients;
    ifstream file(filename[file_num].c_str());
    while (getline(file, str))
    {
        coefficients.push_back(atof(str.c_str()));
    }
    elements.resize(coefficients.size());
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i];
    }
    for (i = position_of_element; i < coefficients.size() - 1; i++) {
        elements[i + 1] = elements[i] / coefficients[i + 1];
    }
}
