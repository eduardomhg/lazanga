

#ifndef _BAZA_H_
#define _BAZA_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 

#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

#ifndef _BARAJA_H_
  #include "Baraja.h"
#endif 

public ref class Baza
{
private:
	array<Carta^>^ cartas;
public:
	Baza();

	Baza(const Baza% baza);

	Baza% Baza::operator =(const Baza% baza);

	Baza(Carta^ carta0, Carta^ carta1, Carta^ carta2, Carta^ carta3);

	Carta^ getCarta(int indice);

	bool hayCarta(Carta^ carta);
};

#endif