#ifndef _MESA_H_
#define _MESA_H_

#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 

#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

#ifndef _JUGADOR_H_
  #include "Jugador.h"
#endif 

#ifndef _BAZA_H_
  #include "Baza.h"
#endif 

class Jugador;

class Mesa
{
private:
	Carta cartas[4];
	Mazo zanga;
	int numCartas;
	int numPiedrasCentro;
	int numPiedras1;
	int numPiedras2;

	Baza bazas1[8];
	Baza bazas2[8];
	int numBazas1;
	int numBazas2;

	int jugadorMano;
	int jugadorManoPrimero;
	int jugadorTriunfo;
	palos triunfo;

	bool alguienSolo;
	int jugadorSolo;
	int piedrasSolo;

	bool alguienCinco;
	int jugadorCinco;
	int piedrasCinco;
	bool cumplioCinco;
	
	bool alguienTodas;
	int jugadorTodas;
	int piedrasTodas;
	bool cumplioTodas;

	bool alguienEstuche;
	int parejaEstuche;
	int piedrasEstuche;

	int piedrasCambioZanga;
	int numPiedrasVirtuales1;
	int numPiedrasVirtuales2;

public:
	Mesa();

	Carta getCarta(int indice);

	palos getTriunfo();

	bool getAlguienSolo();

	bool getAlguienCinco();

	bool getAlguienTodas();

	bool getAlguienEstuche();

	void ponerCarta(Carta carta, int numJugador);

	void ponerPiedras(int numPiedrasCentro);

	void anyadirPiedras(int numPiedrasCentro);

	int getPiedrasCambioZanga();

	void barajar(Baraja& baraja);

	void repartir(Baraja baraja, Jugador jugadores[4]);

	void organizarBaza();

	void organizarPiedras();

	void setJugadorManoPrimero(int jugadorManoPrimero);

	int getJugadorManoPrimero();

	int getJugadorMano();

	int getJugadorCinco();

	int getJugadorTodas();

	bool getCumplioCinco();

	bool getCumplioTodas();

	int getPiedrasCinco();

	int getPiedrasTodas();
	
	int getPiedrasEstuche();

	int getPiedrasSolo();

	int getParejaEstuche();

	int getJugadorSolo();

	Mazo getZanga();

	void pasa(int jugador);

	void juega(int jugador);
	
	void mandaSolo(int mandador, int mandado);

	void vaSolo(int jugador, formasSolo forma);

	void cambiaPorZanga(Jugador jugadores[4], int jugador);

	void recambiaSusCartas(Jugador jugadores[4], int jugador);

	void pideCinco(int jugador);

	void pideTodas(int jugador);

	void cumpleCinco(bool cumple);

	void cumpleTodas(bool cumple);

	int getNumBazas1();

	int getNumBazas2();

	int getNumPiedras1();

	int getNumPiedras2();

	int getNumPiedrasCentro();

	int getNumPiedrasVirtuales1();

	int getNumPiedrasVirtuales2();

	void setTriunfo(palos triunfo);

	int getJugadorTriunfo();

	void comprobarEstuche(Jugador jugadores[4]);

	void pedirEstuche();
};

#endif