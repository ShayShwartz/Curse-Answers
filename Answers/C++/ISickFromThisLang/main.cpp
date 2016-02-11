#include <iostream>
#include "Exceptions.h"
#include "Fraction.h"
#include "MyColorChanger.h"

using namespace std;

int main(void)
{
	try{
		Fraction a(2, 4);
		Fraction b(5, 10);
		Fraction c;
		int intTesting = 0;
		whiteText();
		cout << "Initializing 3 fractions: " << endl;
		cout << "a: ";
		greenText();
		a.print();
		whiteText();
		cout << "b: ";
		greenText();
		b.print();
		whiteText();
		cout<< "c: ";
		greenText();
		c.print();
		cout << endl;
		
		redText();
		cout << "For easier testing, pay attention that a = 0.5 and b = 0.5.\nLook at the decimal value, it'll show you clearest answer." << endl << endl;
		whiteText();
		cout << "Testing operators: " << endl;
		
		// +

		cout << "Operator ' + '\na + b = ";
		c = a + b;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "a + 1 = ";
		c = a + 1;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "1 + a = ";
		c = 1 + a;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();

		// -
		cout << "\nOperator ' - '\na - b = ";
		c = a - b;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "a - 1 = ";
		c = a - 1;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "1 - a = ";
		c = 1 - a;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();

		// *
		cout << "\nOperator ' * '\na * b = ";
		c = a * b;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "a * 2 = ";
		c = a * 2;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "2 * a = ";
		c = 2 * a;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();

		// /
		cout << "\nOperator ' / '\na / b = ";
		c = a / b;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "a / 2 = ";
		c = a / 2;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();
		cout << "2 / a = ";
		c = 2 / a;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		whiteText();

		// += 
		cout << endl;
		grayText();
		cout << "Set c back to origin (0 / 0)" << endl;
		whiteText();
		c.setDenominator(0);
		c.setNominator(0);
		cout << "\nOperator ' += '\nc += a += 2 :\nc = ";
		c += a += 2;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		grayText();
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		cout << "Set c back to origin (0 / 0)" << endl;
		c.setNominator(0);
		c.setDenominator(0);
		whiteText();

		// -=
		cout << "\nOperator ' -= '\nc -= a -= 2 :\nc = ";
		c -= a -= 2;
		greenText();
		c.print();
		yellowText();
		c.printDecimalFraction();
		grayText();
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		cout << "Set c back to origin (0 / 0)" << endl;
		c.setNominator(0);
		c.setDenominator(0);
		whiteText();

		// *=
		cout << "\nOperator ' *= '\na *= b *= 2 :\na = ";
		a *= b *= 2;
		greenText();
		a.print();
		yellowText();
		a.printDecimalFraction();
		grayText();
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		cout << "Set c back to origin (0 / 0)" << endl;
		c.setNominator(0);
		c.setDenominator(0);
		cout << "Set b back to origin (5 / 10)" << endl;
		b.setNominator(5);
		b.setDenominator(10);
		whiteText();

		// /=
		cout << "\nOperator ' /= '\na /= b /= 2 :\na = ";
		a /= b /= 2;
		greenText();
		a.print();
		yellowText();
		a.printDecimalFraction();
		grayText();
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		cout << "Set c back to origin (0 / 0)" << endl;
		c.setNominator(0);
		c.setDenominator(0);
		cout << "Set b back to origin (5 / 10)" << endl;
		b.setNominator(5);
		b.setDenominator(10);

		//Testing Global operators with '='
		//Operator '+='
		redText();
		cout << "Modify intTesting to 2" << endl;
		whiteText();
		intTesting = 2;
		cout << "\nGlobal Operator ' += '\nintTesting += a += a :\nintTesting = ";
		intTesting += a += a;
		greenText();
		cout << intTesting << endl;
		grayText();
		cout << "Set intTesting back to origin (2)" << endl;
		intTesting = 2;
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		whiteText();

		//Operator '-='
		cout << "\nGlobal Operator ' -= '\nintTesting -= a += a :\nintTesting = ";
		intTesting -= a += a;
		greenText();
		cout << intTesting << endl;
		grayText();
		cout << "Set intTesting back to origin (2)" << endl;
		intTesting = 2;
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		whiteText();
		
		//Operator '*='
		cout << "\nGlobal Operator ' *= '\nintTesting *= a :\nintTesting = ";
		intTesting *= a;
		greenText();
		cout << intTesting << endl;
		grayText();
		cout << "Set intTesting back to origin (2)" << endl;
		intTesting = 2;
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		whiteText();

		//Operator '/='
		cout << "\nGlobal Operator ' /= '\nintTesting /= a :\nintTesting = ";
		intTesting /= a;
		greenText();
		cout << intTesting << endl;
		grayText();
		cout << "Set intTesting back to origin (2)" << endl;
		intTesting = 2;
		cout << "Set a back to origin (2 / 4)" << endl;
		a.setNominator(2);
		a.setDenominator(4);
		whiteText();

		//set & get
		cout << "\n\nTesting set & get:" << endl;
		cout << "Set a Fraction to 3/5" << endl;
		a.setNominator(3);
		a.setDenominator(5);
		cout << "a nominator: " << a.getNominator() << endl << "a denominator: " << a.getDenominator() <<endl;

		
		//ERROR TESTING
	//first check
		// a/0;
	//second check
		/* c = Fraction(0,0);
		 a/c;*/
	//third check
		// a /= 0;
	//fourth check
		// Fraction(4,0);


	}
	catch(Exceptions& e)
	{
		cout << "========================================\n" << e.what() << "\n========================================" << endl;
	}

	system("pause");
	return 0;
}

