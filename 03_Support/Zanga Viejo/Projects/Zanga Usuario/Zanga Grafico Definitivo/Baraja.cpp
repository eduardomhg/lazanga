
#include "stdafx.h"

#ifndef _BARAJA_H_
  #include "Baraja.h"
#endif 

Baraja::Baraja()
{
	int indice = 0;	
	for (int p = 0; p < 4; p++)
	{
		for (int v = 0; v < 10; v++)
		{
			this->cartas[indice] = Carta((valores)v, (palos)p);
			indice++;
		}
	}
}

Carta Baraja::getCarta(int indice)
{
	return this->cartas[indice];
}

void Baraja::barajar()
{
	int origen, destino;
	Carta cartaTemporal = Carta();
	System::Random cartaAleatoria(System::DateTime::Now.Millisecond);
	for (int i = 0; i < 100; i++)
	{
		origen = cartaAleatoria.Next(40);
		destino = cartaAleatoria.Next(40);
		cartaTemporal = this->cartas[origen];
		this->cartas[origen] = this->cartas[destino];
		this->cartas[destino] = cartaTemporal;
	}
}

void Baraja::ordenar(palos triunfo, palos paloInicial)
{
	Carta cartaTemporal = Carta();
	for (int i = 0; i < 39; i++)
	{
		for (int j = i+1; j < 40; j++)
		{
			if (cartas[i].numeroJuego(paloInicial, triunfo) 
				< cartas[j].numeroJuego(paloInicial, triunfo))
			{
				cartaTemporal = this->cartas[i];
				this->cartas[i] = this->cartas[j];
				this->cartas[j] = cartaTemporal;
			}
		}
	}
}

