#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 

#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

#ifndef _MAZO_H_
  #include "Mazo.h"
#endif 

#ifndef _MESA_H_
  #include "Mesa.h"
#endif 

class Mesa;

class Jugador
{
private:
	string nombre;
	int numero;
	Mazo mazo;
	int algoritmoIA;
public:
	Jugador();

	Jugador(string nombre, int numero, int algoritmoIA);	

	Carta tirarCarta(int turno, Mesa mesa);

	frasesHablarPrimero hablarPrimero(Mesa mesa);

	frasesHablarDespues hablarDespues(Mesa mesa);

	bool recambiarCartas(Mesa mesa);

	palos triunfar();

	bool aceptarSolo(int jugador, Mesa mesa);

	bool pedirCinco(Mesa mesa);

	bool pedirTodas(Mesa mesa);

	// A PARTIR DE AQUÍ NO AFECTA IA
	bool esLegal(int indiceCarta, Carta cartaInicial, palos triunfo);

	Mazo getMazo();

	int getNumero();

	void setMazo(Mazo mazo);

	bool tieneCarta(Carta carta);
};


#endif