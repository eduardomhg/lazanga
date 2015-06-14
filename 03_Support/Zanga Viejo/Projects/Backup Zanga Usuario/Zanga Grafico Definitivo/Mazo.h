

#ifndef _MAZO_H_
#define _MAZO_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 

#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

#ifndef _BARAJA_H_
  #include "Baraja.h"
#endif 

class Mazo
{
private:
	Carta cartas[8];
	int numCartas;
public:
	Mazo();

	Mazo(Baraja baraja, int numero);

	Carta getCarta(int indice);

	int getNumCartas();

	Carta quitarCarta(int indice);

	void ordenar();

	bool hayCarta(Carta carta);
};

#endif