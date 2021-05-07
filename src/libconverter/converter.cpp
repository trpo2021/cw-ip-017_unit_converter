#include <vector>
#include <sstream>
#include <string>
#include <gtk/gtk.h>
#include "converter.h"
#define UI_FILE "../converter/Unit_converter.glade"
void weight_calc (vector<double>& elements, double input_element, int position_of_element) {
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
    elements.resize (10);
    elements[position_of_element] = input_element;
    for (i = position_of_element; i > 0; --i) {
        elements[i - 1] = elements[i] * coefficients[i - 1];
    }
    for (i = position_of_element; i < 10; i++) {
        elements[i + 1] = elements[i] / coefficients[i];
    }
}

void from_double_to_char (vector<double> elements, int i, const gchar* input_char, GtkEntry* output) {
    string temprory;
    stringstream ss;
    ss << elements[i];
    ss >> temprory;
    input_char = temprory.c_str ();
    gtk_entry_set_text (output, input_char);
}