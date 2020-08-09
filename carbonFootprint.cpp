/*
* this program is aimed to calculate the total
* yearly CO2 emmission of the participants according to
* their personal consumption 
* Author: Khalid 
* Date : 6th Oct 2019 
*/
#include "carbonFootprint.hpp"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::fixed;
using std::setprecision;

//delarating the variables
double transportationFootprint(double kPD, double effic) 
{
	double litresUsedPerYear;
	litresUsedPerYear = 365 * (kPD/effic);
	double kgCO2;
	kgCO2 = 2.3 * litresUsedPerYear;

	return kgCO2;
}
double electricityFootprint(double kWhPerMonth, int num)
{
   double kgCO2 = (kWhPerMonth * 12 * 0.257) / num;
   return kgCO2;
}

double foodFootprint(double meat, double dairy, double fv, double carb) 
{
	double meatkgCO2 = (meat/100)*53.1;
	double dairykgCO2 = (dairy/100)*13.8;
	double fvkgCO2 = (fv/100)*7.6;
	double carbkgCO2 =  (carb/100)*3.1;
	double totalFood = (meatkgCO2 + dairykgCO2 + fvkgCO2 + carbkgCO2);
	return totalFood;
}

double totalFootprint(double trans, double elec, double food)
{
	double tCO2 = (trans+ elec + food) / 1000;
	return tCO2;
}

int main()       
{	
	// turning your output in two decimal places 
	cout << fixed;
	cout << setprecision(2);
	
	double result1 = transportationFootprint(10, 8);
	cout << " your carbon footPrint with respect to car use is "
		<< result1 << "kg/year" << endl;

	double result2 = electricityFootprint(900, 4);
	cout << " your carbon footprint with respect to electricity"
		" use is " << result2 << "kg/year" << endl;

	double result3 = foodFootprint(20, 5, 50, 75);
	cout << " your carbon footprint with respect to food consumption"
		" is " << result3 << "kg/year" << endl;
 
	double result4 = totalFootprint(result1, result2, result3);
	cout << " you produce an annual total of "<< result4 <<  
		" metric tons of CO2 per year." << endl; 
	cout << " All done!" << endl;

 
	return 0;
}

