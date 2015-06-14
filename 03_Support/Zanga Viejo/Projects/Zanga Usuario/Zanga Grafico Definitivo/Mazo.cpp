
#include "stdafx.h"

#ifndef _MAZO_H_
  #include "Mazo.h"
#endif 


Mazo::Mazo()
{
	numCartas = 0;
}

Mazo::Mazo(Baraja baraja, int numero)
{
	if (numero < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			this->cartas[i] = baraja.getCarta(i+4*numero);			
		}
		for (int i = 4; i < 8; i++)
		{
			this->cartas[i] = baraja.getCarta(i+12+4*numero);
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			this->cartas[i] = baraja.getCarta(i+32);			
		}
	}
	numCartas = 8;
}

Carta Mazo::getCarta(int indice)
{
	return this->cartas[indice];
}

int Mazo::getNumCartas()
{
	return this->numCartas;
}

Carta Mazo::quitarCarta(int indice)
{
	Carta cartaTemp = this->cartas[indice];
	for (int i = indice; i < numCartas-1; i++)
	{
		this->cartas[i] = this->cartas[i+1];
	}
	this->numCartas--;
	return cartaTemp;		
}

void Mazo::anyadirCarta(Carta carta)
{
	for (int i = numCartas; i > 0; i--)
	{
		this->cartas[i] = this->cartas[i-1];
	}
	this->cartas[0] = carta;
	this->numCartas++;
}

void Mazo::ordenar(palos triunfo)
{
	Carta cartaTemporal = Carta();
	for (int i = 0; i < 7; i++)
	{
		for (int j = i+1; j < 8; j++)
		{
			if (cartas[i].numeroJuego(triunfo, triunfo) < cartas[j].numeroJuego(triunfo, triunfo))
			{
				cartaTemporal = this->cartas[i];
				this->cartas[i] = this->cartas[j];
				this->cartas[j] = cartaTemporal;
			}
		}
	}
}

bool Mazo::hayCarta(Carta carta)
{
	bool hay = false;
	for (int i = 0; i < numCartas; i++)
	{
		if (cartas[i] == carta)
		{
			hay = true;
			break;
		}
	}
	return hay;
}

