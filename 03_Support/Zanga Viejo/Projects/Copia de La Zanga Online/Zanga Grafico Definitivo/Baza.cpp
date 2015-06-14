
#include "stdafx.h"

#ifndef _BAZA_H_
  #include "Baza.h"
#endif 


Baza::Baza()
{
	this->cartas = gcnew array<Carta^>(4);
	for (int i = 0; i < 4; i++)
		this->cartas[i] = gcnew Carta();
}

Baza::Baza(const Baza% baza)
{
	this->cartas = gcnew array<Carta^>(4);
	for (int i = 0; i < 4; i++)
		this->cartas[i] = gcnew Carta(*(baza.cartas[i]));
}

Baza% Baza::operator =(const Baza% baza)
{
	this->cartas = gcnew array<Carta^>(4);
	for (int i = 0; i < 4; i++)
		*(this->cartas[i]) = *(baza.cartas[i]);
	return *this;
}

Baza::Baza(Carta^ carta0, Carta^ carta1, Carta^ carta2, Carta^ carta3)
{
	this->cartas = gcnew array<Carta^>(4);
	this->cartas[0] = gcnew Carta(*carta0);
	this->cartas[1] = gcnew Carta(*carta1);
	this->cartas[2] = gcnew Carta(*carta2);
	this->cartas[3] = gcnew Carta(*carta3);
}

Carta^ Baza::getCarta(int indice)
{
	return this->cartas[indice];
}

bool Baza::hayCarta(Carta^ carta)
{
	bool hay = false;
	for (int i = 0; i < 4; i++)
	{
		if (*(cartas[i]) == *carta)
		{
			hay = true;
			break;
		}
	}
	return hay;
}

