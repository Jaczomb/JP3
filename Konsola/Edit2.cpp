#include "Edit.h"

#include <windows.h>


Edit::Edit() {};

Edit::~Edit() {};

Edit::Edit(Edit &x)
{

    pos1=x.pos1;
    pos2=x.pos2;
    lengt=x.lengt;
    text=x.text;
    text2=x.text2;

};



void Edit:: setPosition(int x, int y)
{
    pos1=x;
    pos2=y;
}

void Edit:: setLength(int b)
{
    lengt=b;

}

void Edit:: setText(std::string c)
{
    text=c;

}

void Edit::setBackgroundColor(Edit::Color r)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0x1F);

    COORD c;

    c.X=pos1;
    c.Y=pos2;
    if(r == Blue)
        SetConsoleCursorPosition(hc,c);


}

void Edit::setTextColor(Edit::Color d)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0xF);

    COORD c;

    c.X=pos1;
    c.Y=pos2;
    if(d == Blue)
        SetConsoleCursorPosition(hc,c);



}



std::string Edit::getText()
{
    return text2;
}




std::string Edit:: UserText()
{

    std::string slowo;
    std::cin>>slowo;

    text2=slowo;


    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hc,0x7);


    return slowo;


}


void Edit:: display()
{
    std::    cout<<text;
    _sleep(1000);

}

std::ostream& red(std::ostream& _o)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hc,0xC);
    return _o;
}

std::ostream& blue(std::ostream& _o)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hc,0x1);
    return _o;
}

std::ostream& green(std::ostream& _o)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hc,0x2);
    return _o;
}
std::ostream& white(std::ostream& _o)
{

    HANDLE hc;
    hc=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hc,0xF);
    return _o;
}
