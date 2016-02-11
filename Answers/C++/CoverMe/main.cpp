#include <iostream>
#include "Exception.h"
#include "SafeArray.h"
#include "MyColorChanger.h"

using namespace std;

int main(void)
{	
	const unsigned int SAFE_ARRAY_SIZE = 5;
	try
	{	
		SafeArray<int> arr(SAFE_ARRAY_SIZE);
		whiteText();
		cout << "SafeArray.print() method:" << endl;
		greenText();
		arr.print();
		whiteText();
		cout << "Values by index:" << endl;
		greenText();
		cout << "0: " << arr[0] << "\n1: " << arr[1] << "\n2: " << arr[2] << "\n3: " << arr[3] << "\n4: " << arr[4] << endl ;
		whiteText();
		//Initialized the array from 4 to 0.
		for ( int i = 0 ; i < SAFE_ARRAY_SIZE ; i++ )
			arr[i] = SAFE_ARRAY_SIZE - 1 - i;
		cout << "Reverse values:" << endl;
		greenText();
		cout << "0: " << arr[0] << "\n1: " << arr[1] << "\n2: " << arr[2] << "\n3: " << arr[3] << "\n4: " << arr[4] << endl ;
		whiteText();
		//cout << arr[5] << endl; //Throw exception.
		//cout << arr[-1] << endl; //Throw exception.
		cout << "arr[0]: ";
		greenText();
		cout << arr << endl;  //4
		whiteText();
		cout << "arr[1]: ";
		greenText();
		cout << ++arr << endl;//3
		whiteText();
		cout << "arr[2]: ";
		greenText();
		cout << ++arr << endl;//2
		whiteText();
		cout << "arr[1]: ";
		greenText();
		cout << --arr << endl;//3
		whiteText();
		cout << "arr[2]: ";
		greenText();
		cout << arr++ << endl;//2
		whiteText();
		cout << "arr[3]: ";
		greenText();
		cout << arr++ << endl;//1
		whiteText();
		cout << "arr[4]: ";
		greenText();
		cout << arr++ << endl;//0
		whiteText();
		cout << "arr[5]: ";
		greenText();
		cout << ++arr << endl;//Exception
		whiteText();
	}

	catch(Exception &e)
	{
		redText();
		cout << "\n==================================\n" << e.what() << "\n==================================\n"<< endl;
		whiteText();
	}

	system("pause");
	return 0;
}

