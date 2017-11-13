#ifndef EDIT_H
#define EDIT_H

#include <conio.h>
#include <iostream>
#include <iomanip>


std::ostream& red(std::ostream& _o);
std::ostream& blue(std::ostream& _o);
std::ostream& green(std::ostream& _o);
std::ostream& white(std::ostream& _o);
class Edit
{

private:


    std::   string text2;
    int pos1, pos2,lengt;
    std::   string text;
public:
    Edit();
    ~Edit();
    Edit(Edit &x);
    enum Color
    {
        White,
        Blue
    };


    void setPosition(int x, int y);//ustawiam pozycje tekstu
    void setLength(int b);//ustawiam dlugosc wpisywanego tekstu
    void setText(std::string c);//co zostanie wyswietlone na ekranie
    void setTextColor (Edit::Color d);//kolor tekstu
    void setBackgroundColor(Edit::Color c);//kolor tla
    void display();//wyswietla mi tekst

    std::string UserText();//ustawiam zmienna
    std::string getText();//zwracam zmienna

//nie umialem cout<<setColor(FOREGROUND_RED|BACKGROUND_GREEN)<<"Test";
};

#endif // EDIT_H
