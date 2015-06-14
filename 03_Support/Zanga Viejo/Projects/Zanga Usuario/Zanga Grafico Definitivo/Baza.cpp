
#include "stdafx.h"

#ifndef _BAZA_H_
  #include "Baza.h"
#endif 


Baza::Baza(){}

Baza::Baza(Carta carta0, Carta carta1, Carta carta2, Carta carta3)
{
	this->cartas[0] = carta0;
	this->cartas[1] = carta1;
	this->cartas[2] = carta2;
	this->cartas[3] = carta3;
}

Carta Baza::getCarta(int indice)
{
	return this->cartas[indice];
}

bool Baza::hayCarta(Carta carta)
{
	bool hay = false;
	for (int i = 0; i < 4; i++)
	{
		if (cartas[i] == carta)
		{
			hay = true;
			break;
		}
	}
	return hay;
}

