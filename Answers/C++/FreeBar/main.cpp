#include <iostream>
#include "Beer.h"
#include "RedWine.h"
#include "WhiteWine.h"
#include "MyColorChanger.h"

using namespace std;

const int ERROR_VALUE = -1; //Error return value

const unsigned int STOCK_HEIN = 1;  // Heineken stock
const unsigned int STOCK_GOLD = 2;  // Goldstar stock
const unsigned int STOCK_MACC = 3;  // Maccabi stock
const unsigned int STOCK_TUBO = 4;  // Tuborg stock
const unsigned int STOCK_CAR  = 5;  // Carmel Amarled Rizling stock	
const unsigned int STOCK_GS   = 6;  // Golan Smadar stock
const unsigned int STOCK_YS   = 7;  // Yarden Shardone
const unsigned int STOCK_KIAN = 8;  // Kianti
const unsigned int STOCK_YHCA = 9;  // Yarden Har Chermon Adom
const unsigned int STOCK_YKS  = 10; // Yarden Kabarne Subinion
const unsigned int STOCK_CM   = 11; // Chadeau Margot

//const unsigned int SHELF_SIZE = STOCK_HEIN + STOCK_GOLD + STOCK_MACC + STOCK_TUBO + STOCK_CAR + STOCK_GS + STOCK_YS + STOCK_KIAN + STOCK_YHCA + STOCK_YKS + STOCK_CM;
const unsigned int SHELF_SIZE = 11;


void initializeStock(Drink* drinks[SHELF_SIZE], int stock[SHELF_SIZE]);
void printWellcome();
int startMenu();
int DrinkMenu(Drink* drinks[SHELF_SIZE], int stock[SHELF_SIZE]);
void HandleOrders(Drink* drinks[SHELF_SIZE], const int choice);

int main(void)
{
	int choice = 0;
	Drink* drinks[SHELF_SIZE];
	int stock[SHELF_SIZE];
	int lastDrink = 0;

	initializeStock(drinks, stock);

	printWellcome();

	while ( choice != 100 )
	{
		choice = startMenu();
		switch(choice)
		{
			case 0:
				choice = DrinkMenu(drinks, stock);
				if ( choice == ERROR_VALUE )
					break;
				yellowText();
				drinks[choice]->prepare();
				whiteText();
				stock[choice]--;
				lastDrink = choice + 1; //Adding 1 to prevent conflict with Heineken index.
				break;

			case 99:
				if ( lastDrink == 0 ) //Haven't ordered yet.
				{
					redText();
					cout << "\nYou haven't ordered yet. But it's look like you're already drunk :)" << endl;
					whiteText();
				}
				else
					drinks[lastDrink-1]->ordered();
				break;

			case 100:
				//Will exit.
				break;

			default:
				redText();
				cout << "\n========================================\nERROR: Not a valid options, please choose again.\n========================================" << endl;
				whiteText();
				break;
		}
	}

	aquaText();
	cout << "\nHope you enjoyed your drinking!\nSee you soon!\n" << endl;
	whiteText();
	system("pause");
	return 0;
}

//Print Wellcome message
void printWellcome()
{
	aquaText();
	cout << "============================================================"		<< endl;
	cout <<				"\t\tWellcome To My Bar Mate!!\n"
					"\t     Feel Free To Ask For Any Drink!\n"
			"   Here, You Can Enjoy Qualitative Wines And Good Beers."		<< endl;
	cout << "============================================================\n\n"	<< endl;
	whiteText();
}

//Print the start menu and return the user's choice.
int startMenu()
{
	int choice = 0;
	whiteText();
	cout << "\nWhat can I get you, sir?\n\n" 
				"0 - list Options\n"
				"99 - How did you prepare my last drink?\n"
				"100 - Leave the bar"							<< endl;

	greenText();
	cout << "\nThe Choice is Yours : ";

	cin >> choice;
	whiteText();
	return choice;
}

//Print the drinks contained in the stock. (in the drinks array) . and return the user's choice.
int DrinkMenu(Drink* drinks[SHELF_SIZE], int stock[SHELF_SIZE])
{
	int choice = 0;
	cout << "\nOur Drinks:" << endl;
	for ( int i = 0 ; i < SHELF_SIZE ; i++ )
	{
		if ( *( stock + i ) != 0 )
		{
			cout << "\t" << i+1 << " - " << drinks[i]->getName() << endl;
		}
	}

	greenText();
	cout << "\nThe Choice is Yours : ";
	cin >> choice; 
	whiteText();
	choice = choice - 1; //Drink index is the choice - 1

	if ( stock[choice] == 0 || choice < 0 || choice > SHELF_SIZE )
	{
		redText();
		cout << "\n========================================\nERROR: Not a valid options, please choose again.\n========================================" << endl;
		whiteText();
		return ERROR_VALUE;
	}

	return choice; 
}

//initialized the drinks bar and the stock list.
void initializeStock(Drink* drinks[SHELF_SIZE], int stock[SHELF_SIZE])
{
	//Stock can be modified in the constant values at the top of the file.
	*( stock + 0 )  = STOCK_HEIN;
	*( stock + 1 )  = STOCK_GOLD;
	*( stock + 2 )  = STOCK_MACC;
	*( stock + 3 )  = STOCK_TUBO;
	*( stock + 4 )  = STOCK_CAR;
	*( stock + 5 )  = STOCK_GS;
	*( stock + 6 )  = STOCK_YS;
	*( stock + 7 )  = STOCK_KIAN;
	*( stock + 8 )  = STOCK_YHCA;
	*( stock + 9 )  = STOCK_YKS;
	*( stock + 10 ) = STOCK_CM;
		
	*( drinks + 0 )  = new Beer("Heineken");
	*( drinks + 1 )  = new Beer("Goldstar");
	*( drinks + 2 )  = new Beer("Maccabi");
	*( drinks + 3 )  = new Beer("Tuborg");
	*( drinks + 4 )  = new WhiteWine("Carmel Amarled Rizling", 1986);
	*( drinks + 5 )  = new WhiteWine("Golan Smadar", 1989);
	*( drinks + 6 )  = new WhiteWine("Yarden Shardone", 1997);
	*( drinks + 7 )  = new RedWine("Kianti", 1997);
	*( drinks + 8 )  = new RedWine("Yarden Har Chermon Adom", 1994);
	*( drinks + 9 )  = new RedWine("Yarden Kabarne Subinion", 1997);
	*( drinks + 10 ) = new RedWine("Chadeau Margot", 1997);
}