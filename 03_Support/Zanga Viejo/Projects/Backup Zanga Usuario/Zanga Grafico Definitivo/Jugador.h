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

	int elegirCarta(int turno, Mesa mesa, int usuarioCartaElegida, Mazo mazoOriginal);

	Carta tirarCarta(int indice);

	frasesHablarPrimero hablarPrimero(Mesa mesa, frasesHablarPrimero usuarioFrasePrimero);

	frasesHablarDespues hablarDespues(Mesa mesa,frasesHablarDespues usuarioFraseDespues);

	frasesHablarZanga hablarZanga(Mesa mesa, frasesHablarZanga usuarioFraseZanga);

	frasesHablarRecambio Jugador::hablarRecambio(Mesa mesa, frasesHablarRecambio usuarioFraseRecambio);

	palos triunfar(palos usuarioTriunfo);

	bool aceptarSolo(int jugador, Mesa mesa, bool usuarioAceptaSolo);

	bool pedirCinco(Mesa mesa, bool usuarioPideCinco);

	bool pedirTodas(Mesa mesa, bool usuarioPideTodas);

	// A PARTIR DE AQUÍ NO AFECTA IA
	bool esLegal(Carta carta, Carta cartaInicial, palos triunfo);

	Mazo getMazo();

	int getNumero();

	void setMazo(Mazo mazo);

	bool tieneCarta(Carta carta);
};


#endif