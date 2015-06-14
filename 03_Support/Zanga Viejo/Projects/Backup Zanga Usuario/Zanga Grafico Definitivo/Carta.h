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

	System::String^ strValor();

	palos getPalo();

	System::String^ strPalo();

	System::String^ nombre();

	System::String^ nombreZanga(palos triunfo);

	System::String^ nombreArchivo();

	int numeroOrden();

	int numeroJuego(palos paloInicial, palos triunfo);				
};

#endif