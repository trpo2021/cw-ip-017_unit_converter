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

double underpow(double basis, char n)
{
	if(n==-1) return 1/basis;
	else return basis;
}
double kg_to_notkg(double a, string b, char n)
{
	if(b=="Carrat") return a*underpow(pow_ten(5,3),n);
	if(b=="Short ton") return kg_to_notkg(a, "Carrat",0)/underpow(4535920,n);
	if(b=="Ounce") return kg_to_notkg(a, "Short ton",0)*underpow(pow_ten(32,3),n);
	if(b=="Pound") return kg_to_notkg(a, "Short ton",0)*underpow(pow_ten(2,3),n);
	if(b=="Long ton") return kg_to_notkg(a, "Short ton",0)/underpow(1.2,n);
	return 0;
}

double pow_sixty(double x, int a)
{
	while(a<0){
		a+=1;
		x/=60;
	}
	while(a>0){
		a-=1;
		x*=60;
	}
	return x;
}

double hour_to_nothour(double a, string b, int n)
{
	if(b=="Day") return underpow(a/24,n);
	if(b=="Week") return underpow(hour_to_nothour(a, "Day")/7,n);
	if(b=="Month") return underpow((hour_to_nothour(a, "Day")*24)/731,n);
	if(b=="Year") return underpow(hour_to_nothour(a, "Month")/12,n);
	return 0;
}
