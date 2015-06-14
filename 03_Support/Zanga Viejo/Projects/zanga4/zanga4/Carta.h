#ifndef _CARTA_H_
#define _CARTA_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 

class Carta
{
private:
	valores valor;
	palos palo;
public:
	Carta();

	Carta(valores valor, palos palo);

	valores getValor();

	bool operator==(Carta carta);

	string strValor();

	palos getPalo();

	string strPalo();

	string nombre();

	int numeroOrden();

	int numeroJuego(palos paloInicial, palos triunfo);				
};

#endif