
#ifndef _JUGADOR_H_
  #include "Jugador.h"
#endif 

Jugador::Jugador(){}

Jugador::Jugador(string nombre, int numero, int algoritmoIA)
{
	this->nombre = nombre;
	this->numero = numero;
	this->mazo = Mazo();
	this->algoritmoIA = algoritmoIA;
}	

Carta Jugador::tirarCarta(int turno, Mesa mesa)
{
	Carta cartaTemp;
	switch (algoritmoIA)
	{
	default:
		if (turno == 0)
		{
			cartaTemp = mazo.quitarCarta(0);
		}
		else
		{
			for (int i = 0; i < mazo.getNumCartas(); i++)
			{
				if (esLegal(i, mesa.getCarta(mesa.getJugadorMano()), mesa.getTriunfo()))
				{
					cartaTemp = mazo.quitarCarta(i);
					break;
				}
			}
		}
	}		
	cout << "El jugador " << numero+1 << " tira el " << cartaTemp.nombre() << ".\n";
	return cartaTemp;		
}

frasesHablarPrimero Jugador::hablarPrimero(Mesa mesa)
{	
	switch (algoritmoIA)
	{
	case 1:
		if (numero == 0 || numero == 2)
		{
			if (mesa.getNumPiedras1() > 0)
				return paso;
			else
				return juego;
		}
		else
		{
			if (mesa.getNumPiedras2() > 0)
				return paso;
			else
				return juego;
		}
	default:
		return juego;
	}		
}

frasesHablarDespues Jugador::hablarDespues(Mesa mesa)
{
	switch (algoritmoIA)
	{
	default:
		return juegoTambien;
	}
}

bool Jugador::recambiarCartas(Mesa mesa) 
{
	switch (algoritmoIA)
	{
	default:
		return false;
	}
}

palos Jugador::triunfar()
{
	switch (algoritmoIA)
	{
	default:
		return bastos;
	}		
}

bool Jugador::aceptarSolo(int jugador, Mesa mesa)
{
	switch (algoritmoIA)
	{
	default:
		return false;
	}
}

bool Jugador::pedirCinco(Mesa mesa)
{
	switch (algoritmoIA)
	{
	default:
		return false;
	}
}

bool Jugador::pedirTodas(Mesa mesa)
{
	switch (algoritmoIA)
	{
	default:
		return false;
	}
}

// A PARTIR DE AQUÍ NO AFECTA IA
bool Jugador::esLegal(int indiceCarta, Carta cartaInicial, palos triunfo)
{
	palos paloInicial = cartaInicial.getPalo();
	bool tengoMismoPalo = false;

	switch(cartaInicial.numeroJuego(paloInicial, triunfo))
	{
		// Mirar que bastillo y espadilla son triunfos
	case 39:
		for (int i = 0; i < mazo.getNumCartas(); i++)
		{
			if (mazo.getCarta(i).getPalo() == triunfo
				|| mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 37)
			{
				tengoMismoPalo = true;
				break;
			}
		}	
		break;
	case 38:
		for (int i = 0; i < mazo.getNumCartas(); i++)
		{
			if ((mazo.getCarta(i).getPalo() == paloInicial
				|| mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 37)
				&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 39))
			{
				tengoMismoPalo = true;
				break;
			}
		}	
		break;
	case 37:
		{
			for (int i = 0; i < mazo.getNumCartas(); i++)
			{
				if (mazo.getCarta(i).getPalo() == triunfo
					&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 39)
					&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 38))
				{
					tengoMismoPalo = true;
					break;
				}
			}	
			break;
		}
	default:
		{
			for (int i = 0; i < mazo.getNumCartas(); i++)
			{
				if (mazo.getCarta(i).getPalo() == paloInicial
					&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 39)
					&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 38)
					&& !(mazo.getCarta(i).numeroJuego(paloInicial, triunfo) == 37))
				{
					tengoMismoPalo = true;
					break;
				}
			}
		}
	}

	if (!tengoMismoPalo) 
		return true;
	else
	{
		switch(mazo.getCarta(indiceCarta).numeroJuego(paloInicial, triunfo))
		{
		case 39:
		case 38:
		case 37:				
			return (paloInicial == triunfo);
			break;	
		default:
			return (mazo.getCarta(indiceCarta).getPalo() == paloInicial);
		}
	}
}

Mazo Jugador::getMazo()
{
	return this->mazo;
}

int Jugador::getNumero()
{
	return this->numero;
}

void Jugador::setMazo(Mazo mazo)
{
	this->mazo = mazo;
}

bool Jugador::tieneCarta(Carta carta)
{
	return this->mazo.hayCarta(carta);
}
