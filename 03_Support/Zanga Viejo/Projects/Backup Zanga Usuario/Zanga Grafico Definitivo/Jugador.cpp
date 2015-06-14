
#include "stdafx.h"

#ifndef _JUGADOR_H_
  #include "Jugador.h"
#endif 


int Jugador::elegirCarta(int turno, Mesa mesa, int usuarioCartaElegida, Mazo mazoOriginal)
{
	int indice;
	switch (algoritmoIA)
	{
	case 10:
		for (int i = 0; i < mazo.getNumCartas(); i++)
		{
			if (mazo.getCarta(i) == mazoOriginal.getCarta(usuarioCartaElegida))
			{
				indice = i;
				break;
			}
		}
		break;
	default:
		if (turno == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < mazo.getNumCartas(); i++)
			{
				if (esLegal(mazo.getCarta(i), mesa.getCarta(mesa.getJugadorMano()), mesa.getTriunfo()))
				{
					indice = i;
					break;
				}
			}
		}
	}		
	return indice;
}


frasesHablarPrimero Jugador::hablarPrimero(Mesa mesa, frasesHablarPrimero usuarioFrasePrimero)
{	
	switch (algoritmoIA)
	{
	case 10:
		return usuarioFrasePrimero;
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

frasesHablarDespues Jugador::hablarDespues(Mesa mesa,frasesHablarDespues usuarioFraseDespues)
{
	switch (algoritmoIA)
	{
	case 10:
		return usuarioFraseDespues;
	default:
		return juegoTambien;
	}
}

palos Jugador::triunfar(palos usuarioTriunfo)
{
	switch (algoritmoIA)
	{
	case 10:
		return usuarioTriunfo;
	default:
		System::Random paloAleatorio(System::DateTime::Now.Millisecond);
		return (palos)paloAleatorio.Next(4);
	}		
}

bool Jugador::aceptarSolo(int jugador, Mesa mesa, bool usuarioAceptaSolo)
{
	switch (algoritmoIA)
	{
	case 10:
		return usuarioAceptaSolo;
	default:
		return false;
	}
}

frasesHablarZanga Jugador::hablarZanga(Mesa mesa, frasesHablarZanga usuarioFraseZanga) 
{
	switch (algoritmoIA)
	{
		case 10:
		return usuarioFraseZanga;
	default:
		return juegoZanga;
	}
}

frasesHablarRecambio Jugador::hablarRecambio(Mesa mesa, frasesHablarRecambio usuarioFraseRecambio)
{
	switch (algoritmoIA)
	{
		case 10:
		return usuarioFraseRecambio;
	default:
		return juegoRecambio;
	}
}

bool Jugador::pedirCinco(Mesa mesa, bool usuarioPideCinco)
{
	switch (algoritmoIA)
	{
	case 10:
		return usuarioPideCinco;
	default:
		if (numero == 0 || numero == 2)
		{
			if (mesa.getNumPiedrasVirtuales1() > 0)
				return false;
			else
				return false;
		}
		else
		{
			if (mesa.getNumPiedrasVirtuales2() > 0)
				return false;
			else
				return false;
		}
	}
}

bool Jugador::pedirTodas(Mesa mesa, bool usuarioPideTodas)
{
	switch (algoritmoIA)
	{
	case 10:
		return usuarioPideTodas;
	default:
		if (numero == 0 || numero == 2)
		{
			if (mesa.getNumPiedrasVirtuales1() > 0)
				return false;
			else
				return false;
		}
		else
		{
			if (mesa.getNumPiedrasVirtuales2() > 0)
				return false;
			else
				return false;
		}
	}
}





// A PARTIR DE AQUÍ NO AFECTA IA

Jugador::Jugador(){}

Jugador::Jugador(string nombre, int numero, int algoritmoIA)
{
	this->nombre = nombre;
	this->numero = numero;
	this->mazo = Mazo();
	this->algoritmoIA = algoritmoIA;
}	


Carta Jugador::tirarCarta(int indice)
{
	return mazo.quitarCarta(indice);
}

bool Jugador::esLegal(Carta carta, Carta cartaInicial, palos triunfo)
{
	palos paloInicial;
	bool tengoMismoPalo = false;

	if (cartaInicial.numeroJuego(bastos, triunfo) != 39
		&& cartaInicial.numeroJuego(bastos, triunfo) != 37)
	{
		paloInicial = cartaInicial.getPalo();
	}
	else
	{
		paloInicial = triunfo;
	}

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
	default:		
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

	if (!tengoMismoPalo) 
		return true;
	else
	{
		switch(carta.numeroJuego(paloInicial, triunfo))
		{
		case 39:
		case 37:				
			return (paloInicial == triunfo);
			break;	
		default:
			return (carta.getPalo() == paloInicial);
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
