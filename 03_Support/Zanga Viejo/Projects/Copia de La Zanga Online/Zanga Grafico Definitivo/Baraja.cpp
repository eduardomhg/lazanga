
#include "stdafx.h"

#ifndef _BARAJA_H_
  #include "Baraja.h"
#endif 

Baraja::Baraja()
{
	int indice = 0;
	this->cartas = gcnew array<Carta^>(40);
	for (int p = 0; p < 4; p++)
	{
		for (int v = 0; v < 10; v++)
		{
			this->cartas[indice] = gcnew Carta((valores)v, (palos)p);
			indice++;
		}
	}
}

Baraja::Baraja(const Baraja% baraja)
{
	this->cartas = gcnew array<Carta^>(40);
	for (int i = 0; i < 40; i++)
	{
		this->cartas[i] = gcnew Carta(*(baraja.cartas[i]));
	}
}

Baraja% Baraja::operator =(const Baraja% baraja)
{
	this->cartas = gcnew array<Carta^>(40);
	for (int i = 0; i < 40; i++)
	{
		*(this->cartas[i]) = *(baraja.cartas[i]);
	}
	return *this;
}


Carta^ Baraja::getCarta(int indice)
{
	return this->cartas[indice];
}

void Baraja::barajar(int semilla)
{
	int origen, destino;
	Carta^ cartaTemporal = gcnew Carta();
	System::Random cartaAleatoria(semilla);
	for (int i = 0; i < 100; i++)
	{		
		origen = cartaAleatoria.Next(40);
		destino = cartaAleatoria.Next(40);
		*cartaTemporal = *(this->cartas[origen]);
		*(this->cartas[origen]) = *(this->cartas[destino]);
		*(this->cartas[destino]) = *cartaTemporal;
	}
}

void Baraja::ordenar(palos triunfo, palos paloInicial)
{
	Carta^ cartaTemporal = gcnew Carta();
	for (int i = 0; i < 39; i++)
	{
		for (int j = i+1; j < 40; j++)
		{
			if (cartas[i]->numeroJuego(paloInicial, triunfo) 
				< cartas[j]->numeroJuego(paloInicial, triunfo))
			{
				*cartaTemporal = *(this->cartas[i]);
				*(this->cartas[i]) = *(this->cartas[j]);
				*(this->cartas[j]) = *cartaTemporal;
			}
		}
	}
}

