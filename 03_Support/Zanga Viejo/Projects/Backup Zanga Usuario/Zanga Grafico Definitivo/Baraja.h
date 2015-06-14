#ifndef _BARAJA_H_
#define _BARAJA_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 
#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

class Baraja
{
private:
	Carta cartas[40];
public:
	Baraja();

	Carta getCarta(int indice);

	void barajar();

	void ordenar(palos triunfo, palos paloInicial);
};

#endif
