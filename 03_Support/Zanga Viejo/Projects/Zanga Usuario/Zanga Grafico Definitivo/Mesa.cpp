
#include "stdafx.h"

#ifndef _MESA_H_
  #include "Mesa.h"
#endif 

Mesa::Mesa()
{
	numCartas = 0;
	numPiedrasCentro = 0;
	numPiedras1 = 16;
	numPiedras2 = 16;
	jugadorMano = 0;
	jugadorManoPrimero = 0;
	jugadorTriunfo = 0;
	numBazas1 = 0;
	numBazas2 = 0;
	triunfo = bastos;
	alguienSolo = false;
	jugadorSolo = 0;
	piedrasSolo = 0;
	alguienCinco = false;
	jugadorCinco = 0;
	piedrasCinco = 0;
	cumplioCinco = false;
	alguienTodas = false;
	jugadorTodas = 0;
	piedrasTodas = 0;
	cumplioTodas = false;
	alguienEstuche = false;
	parejaEstuche = 0;
	piedrasEstuche = 0;
	piedrasCambioZanga = 0;
	numPiedrasVirtuales1 = 0;
	numPiedrasVirtuales2 = 0;
}

Carta Mesa::getCarta(int indice)
{
	return this->cartas[indice];
}

palos Mesa::getTriunfo()
{
	return this->triunfo;
}

bool Mesa::getAlguienSolo()
{
	return this->alguienSolo;
}

bool Mesa::getAlguienCinco()
{
	return this->alguienCinco;
}

int Mesa::getJugadorCinco()
{
	return this->jugadorCinco;
}

int Mesa::getJugadorTodas()
{
	return this->jugadorTodas;
}

bool Mesa::getCumplioCinco()
{
	return this->cumplioCinco;
}

bool Mesa::getCumplioTodas()
{
	return this->cumplioTodas;
}

int Mesa::getPiedrasCinco()
{
	return this->piedrasCinco;
}

int Mesa::getPiedrasTodas()
{
	return this->piedrasTodas;
}

int Mesa::getPiedrasEstuche()
{
	return this->piedrasEstuche;
}

int Mesa::getPiedrasSolo()
{
	return this->piedrasSolo;
}

int Mesa::getParejaEstuche()
{
	return this->parejaEstuche;
}

bool Mesa::getAlguienTodas()
{
	return this->alguienTodas;
}

bool Mesa::getAlguienEstuche()
{
	return this->alguienEstuche;
}

void Mesa::ponerCarta(Carta carta, int numJugador)
{
	this->cartas[numJugador] = carta;
	this->numCartas++;
}

void Mesa::ponerPiedras(int numPiedrasCentro)
{
	this->numPiedrasCentro = numPiedrasCentro;
}

void Mesa::anyadirPiedras(int numPiedrasCentro)
{
	this->numPiedrasCentro += numPiedrasCentro;
}

int Mesa::getPiedrasCambioZanga()
{
	return this->piedrasCambioZanga;
}

void Mesa::barajar(Baraja& baraja)
{
	baraja.barajar();
}

void Mesa::repartir(Baraja baraja, Jugador jugadores[4])
{
	numCartas = 0;
	numBazas1 = 0;
	numBazas2 = 0;
	for (int i = 0; i < 4; i++)
	{
		jugadores[i].setMazo(Mazo(baraja, (i+jugadorManoPrimero)%4));
	}		
	this->zanga = Mazo(baraja, 4);		
}

void Mesa::organizarBaza()
{
	int indice, indiceMax, valorJuegoMax = -1;
	for (indice = 0; indice < 4; indice++)
	{
		if (!alguienSolo)
		{
			if (this->cartas[indice].numeroJuego(cartas[jugadorMano].getPalo(), triunfo)
				> valorJuegoMax)
			{
				valorJuegoMax = this->cartas[indice].numeroJuego(cartas[jugadorMano].getPalo(), 
					triunfo);
				indiceMax = indice;
			}
		}
		else
		{
			if (cartas[indice].numeroJuego(cartas[jugadorMano].getPalo(), triunfo)
				> valorJuegoMax && indice != (jugadorSolo+2)%4)
			{
				valorJuegoMax = this->cartas[indice].numeroJuego(cartas[jugadorMano].getPalo(), 
					triunfo);
				indiceMax = indice;
			}
		}

	}
	switch(indiceMax)
	{
	case 0:
		{
			this->bazas1[numBazas1] = Baza(cartas[0], cartas[1], cartas[2], cartas[3]);
			this->numBazas1++;
			this->jugadorMano = 0;	
			break;
		}
	case 1:
		{
			this->bazas2[numBazas2] = Baza(cartas[0], cartas[1], cartas[2], cartas[3]);
			this->numBazas2++;
			this->jugadorMano = 1;	
			break;
		}
	case 2:
		{
			this->bazas1[numBazas1] = Baza(cartas[0], cartas[1], cartas[2], cartas[3]);
			this->numBazas1++;
			this->jugadorMano = 2;	
			break;
		}
	default:
		{
			this->bazas2[numBazas2] = Baza(cartas[0], cartas[1], cartas[2], cartas[3]);
			this->numBazas2++;
			this->jugadorMano = 3;	
			break;
		}
	}
	numCartas = 0;
}

void Mesa::organizarPiedras()
{
	int temp;
	if (alguienCinco)
	{
		if (jugadorCinco == 0 || jugadorCinco == 2)
		{
			if (cumplioCinco)
			{
				numPiedras1 += min(piedrasCinco, numPiedras2);
				numPiedras2 -= min(piedrasCinco, numPiedras2);
			}
			else
			{
				numPiedras2 += min(piedrasCinco, numPiedras1);
				numPiedras1 -= min(piedrasCinco, numPiedras1);
			}
		}
		else
		{
			if (cumplioCinco)
			{
				numPiedras2 += min(piedrasCinco, numPiedras1);
				numPiedras1 -= min(piedrasCinco, numPiedras1);
			}
			else
			{
				numPiedras1 += min(piedrasCinco, numPiedras2);
				numPiedras2 -= min(piedrasCinco, numPiedras2);
			}
		}
	}
	if (alguienTodas)
	{
		if (jugadorTodas == 0 || jugadorTodas == 2)
		{
			if (cumplioTodas)
			{
				numPiedras1 += min(piedrasTodas, numPiedras2);
				numPiedras2 -= min(piedrasTodas, numPiedras2);
			}
			else
			{
				numPiedras2 += min(piedrasTodas, numPiedras1);
				numPiedras1 -= min(piedrasTodas, numPiedras1);
			}
		}
		else
		{
			if (cumplioTodas)
			{
				numPiedras2 += min(piedrasTodas, numPiedras1);
				numPiedras1 -= min(piedrasTodas, numPiedras1);
			}
			else
			{
				numPiedras1 += min(piedrasTodas, numPiedras2);
				numPiedras2 -= min(piedrasTodas, numPiedras2);
			}
		}
	}
	if (numBazas1 > numBazas2)
	{
		if (alguienEstuche)
		{
			numPiedras1 += min(piedrasEstuche, numPiedras2);
			numPiedras2 -= min(piedrasEstuche, numPiedras2);
		}
		if (jugadorTriunfo == 0 || jugadorTriunfo == 2)
		{
			numPiedras1 += numPiedrasCentro;
			numPiedrasCentro -= numPiedrasCentro;
			if (alguienSolo)
			{
			numPiedras1 += min(piedrasSolo, numPiedras2);
			numPiedras2 -= min(piedrasSolo, numPiedras2);
			}				
		}
		else
		{
			if (alguienSolo)
			{
				numPiedras1 += min(piedrasSolo, numPiedras2);
				numPiedras2 -= min(piedrasSolo, numPiedras2);
			}
			temp = numPiedrasCentro;
			if (numPiedras2 > numPiedrasCentro)
			{
				numPiedras2 -= numPiedrasCentro;
				numPiedrasCentro += numPiedrasCentro;					
			}
			else
			{
				numPiedrasCentro += numPiedras2;
				numPiedras2 -= numPiedras2;
			}
			numPiedrasCentro -= temp;
			numPiedras1 += temp;								
		}
	}
	else if (numBazas2 > numBazas1)
	{
		if (alguienEstuche)
		{
			numPiedras2 += min(piedrasEstuche, numPiedras1);
			numPiedras1 -= min(piedrasEstuche, numPiedras1);
		}
		if (jugadorTriunfo == 1 || jugadorTriunfo == 3)
		{
			numPiedras2 += numPiedrasCentro;
			numPiedrasCentro -= numPiedrasCentro;				
			if (alguienSolo)
			{
				numPiedras2 += min(piedrasSolo, numPiedras1);
				numPiedras1 -= min(piedrasSolo, numPiedras1);
			}
		}
		else
		{
			if (alguienSolo)
			{
				numPiedras2 += min(piedrasSolo, numPiedras1);
				numPiedras1 -= min(piedrasSolo, numPiedras1);
			} 
			temp = numPiedrasCentro;
			if (numPiedras1 > numPiedrasCentro)
			{
				numPiedras1 -= numPiedrasCentro;
				numPiedrasCentro += numPiedrasCentro;					
			}
			else
			{
				numPiedrasCentro += numPiedras1;
				numPiedras1 -= numPiedras1;
			}			
			numPiedrasCentro -= temp;
			numPiedras2 += temp;			
		}
	}
	else
	{
		if (jugadorTriunfo == 0 || jugadorTriunfo == 2)
		{
			if (alguienSolo)
			{
				numPiedras2 += min(piedrasSolo, numPiedras1);
				numPiedras1 -= min(piedrasSolo, numPiedras1);
			}
			if (numPiedras1 > numPiedrasCentro)
			{
				numPiedras1 -= numPiedrasCentro;
				numPiedrasCentro += numPiedrasCentro;					
			}
			else
			{
				numPiedrasCentro += numPiedras1;
				numPiedras1 -= numPiedras1;
			}
		}
		else
		{
			if (alguienSolo)
			{
				numPiedras1 += min(piedrasSolo, numPiedras2);
				numPiedras2 -= min(piedrasSolo, numPiedras2);
			} 
			if (numPiedras2 > numPiedrasCentro)
			{
				numPiedras2 -= numPiedrasCentro;
				numPiedrasCentro += numPiedrasCentro;					
			}
			else
			{
				numPiedrasCentro += numPiedras2;
				numPiedras2 -= numPiedras2;
			}
		}
	}
	alguienSolo = false;
	jugadorSolo = 0;
	piedrasSolo = 0;
	alguienCinco = false;
	jugadorCinco = 0;
	piedrasCinco = 0;
	cumplioCinco = false;
	alguienTodas = false;
	jugadorTodas = 0;
	piedrasTodas = 0;
	cumplioTodas = false;
	alguienEstuche = false;
	parejaEstuche = 0;
	piedrasEstuche = 0;
	numPiedrasVirtuales1 = numPiedras1;
	numPiedrasVirtuales2 = numPiedras2;
}

void Mesa::setJugadorManoPrimero(int jugadorManoPrimero)
{
	this->jugadorManoPrimero = jugadorManoPrimero;
	this->jugadorMano = jugadorManoPrimero;
	this->jugadorTriunfo = jugadorManoPrimero;


	if (jugadorManoPrimero == 0 || jugadorManoPrimero == 2)		
	{
		if (numPiedras1 > 4)
		{						
			numPiedrasCentro += 4;
			numPiedras1 -= 4;
			cout << "El jugador " << jugadorManoPrimero + 1
				<< " es el proximo mano y mete 4 piedras.\n";
		}
		else
		{
			numPiedrasCentro += numPiedras1;
			cout << "El jugador " << jugadorManoPrimero + 1
				<< " es el proximo mano y mete " << numPiedras1 << " piedras.\n";
			numPiedras1 -= numPiedras1;									
		}
	}
	else
	{
		if (numPiedras2 > 4)
		{						
			numPiedrasCentro += 4;
			numPiedras2 -= 4;
			cout << "El jugador " << jugadorManoPrimero + 1
				<< " es el proximo mano y mete 4 piedras.\n";
		}
		else
		{
			numPiedrasCentro += numPiedras2;
			cout << "El jugador " << jugadorManoPrimero + 1
				<< " es el proximo mano y mete " << numPiedras2 << " piedras.\n";
			numPiedras2 -= numPiedras2;						
		}
	}
	numPiedrasVirtuales1 = numPiedras1;
	numPiedrasVirtuales2 = numPiedras2;
}

int Mesa::getJugadorManoPrimero()
{
	return jugadorManoPrimero;
}

int Mesa::getJugadorMano()
{
	return jugadorMano;
}

int Mesa::getJugadorSolo()
{
	return jugadorSolo;
}


void Mesa::pasa(int jugador)
{
	cout << "El jugador " << jugador+1 << " pasa y mete un vale.\n";
	if (jugador == 0 || jugador == 2)
	{
		this->numPiedrasCentro += 1;
		this->numPiedras1 -= 1;
	}
	else
	{
		this->numPiedrasCentro += 1;
		this->numPiedras2 -= 1;
	}
	numPiedrasVirtuales1 = numPiedras1;
	numPiedrasVirtuales2 = numPiedras2;
	this->jugadorTriunfo = (this->jugadorTriunfo + 1) % 4;
}

void Mesa::juega(int jugador)
{
	cout << "El jugador " << jugador+1 << " juega.\n";
}

void Mesa::mandaSolo(int mandador, int mandado)
{
	cout << "El jugador " << mandador+1 << " manda solo al jugador "
		<< mandado+1 <<".\n";
}

void Mesa::vaSolo(int jugador, formasSolo forma)
{
	switch (forma)
	{
	case meVoy:
		cout << "El jugador " << jugador+1 << " se va solo.\n";
		break;
	case meVoyYo:
		cout << "El jugador " << jugador+1 << " acepta el reto y se va solo.\n";
		break;
	default:
		cout << "El jugador " << jugadorTriunfo+1 << " no acepta el reto y el jugador " 
			<< jugador+1 <<" se va solo.\n";
	}		
	alguienSolo = true;
	jugadorSolo = jugador;
	if (jugador == 0 || jugador == 2)
	{			
		if (numPiedrasVirtuales1 > 2)
		{
			piedrasSolo = 2;
			numPiedrasVirtuales1 -= 2;
		}				
		else
		{
			piedrasSolo = numPiedrasVirtuales1;
			numPiedrasVirtuales1 -= numPiedrasVirtuales1;
		}
	}
	else
	{
		if (numPiedrasVirtuales2 > 2)
		{
			piedrasSolo = 2;
			numPiedrasVirtuales2 -= 2;
		}				
		else
		{
			piedrasSolo = numPiedrasVirtuales2;
			numPiedrasVirtuales2 -= numPiedrasVirtuales2;
		}
	}
	jugadorTriunfo = jugador;
	if (jugadorMano == (jugador+2)%4)
		jugadorMano = (jugadorMano+1)%4;
}

void Mesa::cambiaPorZanga(Jugador jugadores[4], int jugador)
{		
	cout << "El jugador " << jugador+1 << " pasa y cambia sus cartas por la zanga.\n";
	Mazo mazoTemp;
	if (jugador == 0 || jugador == 2)
	{
		this->numPiedrasCentro += 1;
		this->numPiedras1 -= 1;
		// Se supone que 1 tiene mas de 2
		if (numPiedras2 > 2)
		{
			piedrasCambioZanga = 2;
			numPiedrasCentro += 4;
			numPiedras1 -= 2;
			numPiedras2 -= 2;				
		} 
		else
		{
			piedrasCambioZanga = numPiedras2;
			numPiedrasCentro += 2 + numPiedras2;
			numPiedras1 -= 2;
			numPiedras2 -= numPiedras2;				
		}			
	}
	else
	{
		this->numPiedrasCentro += 1;
		this->numPiedras2 -= 1;
		if (numPiedras2 > 1)
		{
			piedrasCambioZanga = numPiedras1;
			numPiedrasCentro += 4;
			numPiedras1 -= 2;
			numPiedras2 -= 2;
		} 
		else
		{
			piedrasCambioZanga = numPiedras1;
			numPiedrasCentro += 2 + numPiedras1;
			numPiedras2 -= 2;
			numPiedras1 -= numPiedras1;
		}
	}
	mazoTemp = zanga;
	zanga = jugadores[jugador].getMazo();
	jugadores[jugador].setMazo(mazoTemp);
}

void Mesa::recambiaSusCartas(Jugador jugadores[4], int jugador)
{
	cout << "El jugador " << jugador+1 << " vuelve a coger sus cartas originales.\n";
	Mazo mazoTemp;
	// ACORDARSE DE QUE DEBE CONSIDERAR SUS CARTAS ANTERIORES PARA EL RECAMBIO
	if (jugador == 0 || jugador == 2)
	{			
		numPiedras2 += piedrasCambioZanga;
		numPiedrasCentro -= piedrasCambioZanga;
	}
	else
	{
		numPiedras1 += piedrasCambioZanga;
		numPiedrasCentro -= piedrasCambioZanga;
	}
	mazoTemp = zanga;
	zanga = jugadores[jugador].getMazo();
	jugadores[jugador].setMazo(mazoTemp);
}

void Mesa::pideCinco(int jugador)
{
	alguienCinco = true;
	jugadorCinco = jugador;
	if (jugador == 0 || jugador == 2)
	{			
		if (numPiedrasVirtuales1 > 2)
		{
			piedrasCinco = 2;
			numPiedrasVirtuales1 -= 2;
		}				
		else
		{
			piedrasCinco = numPiedrasVirtuales1;
			numPiedrasVirtuales1 -= numPiedrasVirtuales1;
		}
	}
	else
	{
		if (numPiedrasVirtuales2 > 2)
		{
			piedrasCinco = 2;
			numPiedrasVirtuales2 -= 2;
		}				
		else
		{
			piedrasCinco = numPiedrasVirtuales2;
			numPiedrasVirtuales2 -= numPiedrasVirtuales2;
		}
	}
}

void Mesa::pideTodas(int jugador)
{
	alguienTodas = true;
	jugadorTodas = jugador;
	if (jugador == 0 || jugador == 2)
	{			
		if (numPiedrasVirtuales1 > 2)
		{
			piedrasTodas = 2;
			numPiedrasVirtuales1 -= 2;
		}				
		else
		{
			piedrasTodas = numPiedrasVirtuales1;
			numPiedrasVirtuales1 -= numPiedrasVirtuales1;
		}
	}
	else
	{
		if (numPiedrasVirtuales2 > 2)
		{
			piedrasTodas = 2;
			numPiedrasVirtuales2 -= 2;
		}				
		else
		{
			piedrasTodas = numPiedrasVirtuales1;
			numPiedrasVirtuales2 -= numPiedrasVirtuales2;
		}
	}
}

void Mesa::cumpleCinco(bool cumple)
{
	cumplioCinco = cumple;
}

void Mesa::cumpleTodas(bool cumple)
{
	cumplioTodas = cumple;
}

int Mesa::getNumBazas1()
{
	return this->numBazas1;
}

int Mesa::getNumBazas2()
{
	return this->numBazas2;
}

int Mesa::getNumPiedras1()
{
	return this->numPiedras1;
}

int Mesa::getNumPiedras2()
{
	return this->numPiedras2;
}

int Mesa::getNumPiedrasCentro()
{
	return this->numPiedrasCentro;
}

int Mesa::getNumPiedrasVirtuales1()
{
	return this->numPiedrasVirtuales1;
}

int Mesa::getNumPiedrasVirtuales2()
{
	return this->numPiedrasVirtuales2;
}

void Mesa::setTriunfo(palos triunfo)
{
	switch(triunfo)
	{
	case bastos:
		cout << "El jugador " << jugadorTriunfo+1 << " triunfa a Bastos.\n";
		break;
	case copas:
		cout << "El jugador " << jugadorTriunfo+1 << " triunfa a Copas.\n";
		break;
	case espadas:
		cout << "El jugador " << jugadorTriunfo+1 << " triunfa a Espadas.\n";
		break;
	default:
		cout << "El jugador " << jugadorTriunfo+1 << " triunfa a Oros.\n";		
		break;
	}
	this->triunfo = triunfo;
}

int Mesa::getJugadorTriunfo()
{
	return this->jugadorTriunfo;
}

Mazo Mesa::getZanga()
{
	return this->zanga;
}

void Mesa::comprobarEstuche(Jugador jugadores[4])
{
	int num1 = 0, num2 = 0;
	for (int jugador = 0; jugador < 4; jugador++)
	{
		for (int carta = 0; carta < 8; carta++)
		{
			if (jugadores[jugador].getMazo().getCarta(carta).numeroJuego(bastos, triunfo) >= 37)
			{
				if ((jugador == 0 || jugador == 2))
				{
					if (!(this->alguienSolo && this->jugadorSolo == (jugador+2)%4))
						num1++;
				}
				else 
				{
					if (!(this->alguienSolo && this->jugadorSolo == (jugador+2)%4))
						num2++;
				}
			}
		}
	}
	if (num1 >= 3)
	{
		alguienEstuche = true;
		parejaEstuche = 1;			
	}
	else if (num2 >= 3)
	{
		alguienEstuche = true;
		parejaEstuche = 2;			
	} 
	else
	{
		alguienEstuche = false;
	}
}

void Mesa::pedirEstuche()
{
	if (numBazas1 > numBazas2)
	{
		if (numPiedrasVirtuales1 > 2)
		{
			piedrasEstuche = 2;
			numPiedrasVirtuales1 -= 2;
		}
		else
		{
			piedrasEstuche = numPiedrasVirtuales1;
			numPiedrasVirtuales1 -= numPiedrasVirtuales1;
		}
	}
	else if (numBazas2 > numBazas1)
	{
		if (numPiedrasVirtuales1 > 2)
		{
			piedrasEstuche = 2;
			numPiedrasVirtuales1 -= 2;
		}
		else
		{
			piedrasEstuche = numPiedrasVirtuales2;
			numPiedrasVirtuales2 -= numPiedrasVirtuales2;
		}
	}
}


