#ifndef _BARAJA_H_
#define _BARAJA_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 
#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

public ref class Baraja
{
private:
	array<Carta^>^ cartas;
public:
	Baraja();

	Baraja(const Baraja% baraja);

	Baraja% operator =(const Baraja% baraja);

	Carta^ getCarta(int indice);

	void barajar(int semilla);

	void ordenar(palos triunfo, palos paloInicial);
};

#endif
