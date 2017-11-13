#include "Edit.h"
#include "ccolor.h"
int main()
{
	Edit e;

	//e.setPosition(7, 3);
	//e.setLength(8);
	//e.setText("Ala");
	//e.setTextColor(Edit::Black);
	//e.setBackgroundColor(Edit::Red);
	//e.display();

	//e.userText();

	std::string s = e.getText();

	std::cout << "Wpisano: " << s << std::endl;

	std::cout << "Ala" << green << "ma" << red << "kota" << setColor(FOREGROUND_RED | BACKGROUND_GREEN) << "i psa" << reset;

	system("pause");

	return 0;
	return 0;
}