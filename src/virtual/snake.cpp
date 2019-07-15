#define glowa ogon[0];

#include "enum.hpp"

class c_Snake
{
private:
    /* data */

    int obecny_kierunek;
    int obecna_dlugosc;
    // c_Cell *ogon;  
    
    /*
    ogon to tablica komórek
    zakładam, c_Cell zawiera współżędne X i Y
    */

public:

    c_Snake(int ilosc_pustych_pol, int start_x, int start_y, int startowy_kierunek, int start_dlugosc = 3);
    ~c_Snake();
    void move(int kierunek = obecny_kierunek, int pole = CELL_EMPTY);

};

c_Snake::c_Snake(int ilosc_pustych_pol, int start_x, int start_y, int startowy_kierunek, int start_dlugosc = 3)
{
    obecna_dlugosc = start_dlugosc;
    obecny_kierunek = startowy_kierunek;
    /* 
    
    *ogon = new c_Cell[ilosc_pustych_pol];
    glowa.X = start_x;
    glowa.Y = start_y;
    glowa.typ = CELL_WALL;
    glowa.kolor = kolor_gracza;

    
    switch(startowy_kierunek){
        
        case lewo : 
            for(int i = 1; i < start_dlugosc; i++){
                ogon[i].X = ogon[i-1].X + 1;
                ogon[i].Y = ogon[i-1].Y;
                ogon[i].typ = CELL_WALL;
                ogon[i].kolor = kolor_gracza;
            }
            break;
        
        case prawo :
        for(int i = 1; i < start_dlugosc; i++){
                ogon[i].X = ogon[i-1].X - 1;
                ogon[i].Y = ogon[i-1].Y;
                ogon[i].typ = CELL_WALL;
                ogon[i].kolor = kolor_gracza;
            }
            break;
        
        case dol : 
            for(int i = 1; i < start_dlugosc; i++){
                ogon[i].X = ogon[i-1].X;
                ogon[i].Y = ogon[i-1].Y + 1;
                ogon[i].typ = CELL_WALL;
                ogon[i].kolor = kolor_gracza;
            }
            break;
        
        case gora : 
            for(int i = 1; i < start_dlugosc; i++){
                ogon[i].X = ogon[i-1].X;
                ogon[i].Y = ogon[i-1].Y - 1;
                ogon[i].typ = CELL_WALL;
                ogon[i].kolor = kolor_gracza;
            }
            break;
    }

    */
   
}

c_Snake::~c_Snake()
{
    for (int i = 0; i < obecna_dlugosc; i++)
    {
        //ogon[i].typ = CELL_EMPTY;
    }
    
    
}

void c_Snake::move(int kierunek = obecny_kierunek, int pole = CELL_EMPTY){

    for(int i = obecna_dlugosc; i > 0; i--){
        /*
        ogon[i] = ogon[i-1];
        */
    }

    if (pole == CELL_WALL)
    {
        c_Snake::~c_Snake();
        return; //nie wiem czy to działa tak jak myśle, że to działa 
    }

    if(pole == CELL_FRUIT)
    {
        obecna_dlugosc++;
    }
    else
    {
        //ogon[obecna_dlugosc].typ = CELL_EMPTY;
    }

    switch (kierunek)
    {
    case lewo :
        glowa.X--;
        break;
    case prawo :
        glowa.X++;
        break;
    case gora :
        glowa.Y++;
        break;
    case dol :
        glowa.Y--;
        break;
    
    }    

}