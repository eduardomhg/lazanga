
#include "stdafx.h"

#ifndef _JUGADOR_H_
#include "Jugador.h"
#endif 


// FUNCIONES AUXILIARES
int Jugador::valorCartaTriunfo(Carta carta)
{
	palos palo = carta.getPalo();
	valores valor = carta.getValor();
	switch(algoritmoIA)
	{
	case 4:
		if (carta.numeroJuego(bastos, palo) == 39)
			return 8;
		if (carta.numeroJuego(bastos, palo) == 38)
			return 7;
		if (carta.numeroJuego(bastos, palo) == 37)
			return 7;
		switch(palo)
		{
		case espadas:
		case bastos:
			switch(valor)
			{
			case rey:
				return 6;
			case caballo:
				return 5;
			case sota:
				return 4;
			case siete:
			case seis:
				return 3;
			default:
				return 3;
			}
		default:
			switch(valor)
			{
			case as:
			case rey:
				return 6;
			case caballo:
				return 5;
			case sota:
				return 4;
			case dos:
			case tres:
				return 3;
			default:
				return 3;
			}
		}
	default:
		if (carta.numeroJuego(bastos, palo) == 39)
			return 7;
		if (carta.numeroJuego(bastos, palo) == 38)
			return 6;
		if (carta.numeroJuego(bastos, palo) == 37)
			return 5;
		switch(palo)
		{
		case espadas:
		case bastos:
			switch(valor)
			{
			case rey:
				return 4;
			case caballo:
			case sota:
				return 3;
			case siete:
			case seis:
				return 2;
			default:
				return 1;
			}
		default:
			switch(valor)
			{
			case as:
			case rey:
				return 4;
			case caballo:
			case sota:
				return 3;
			case dos:
			case tres:
				return 2;
			default:
				return 1;
			}
		}
	}
}

int Jugador::valorCartaNoTriunfo(Carta carta)
{
	palos palo = carta.getPalo();
	valores valor = carta.getValor();
	switch(algoritmoIA)
	{
	case 4:
		if (carta.numeroJuego(bastos, palo) == 39)
			return 8;
		if (carta.numeroJuego(bastos, palo) == 37)
			return 7;
		switch(palo)
		{
		case espadas:
		case bastos:
			switch(valor)
			{
			case rey:
				return 4;
			case caballo:
				return 2;
			case sota:
				return 1;
			default:
				return 0;
			}
		default:
			switch(valor)
			{
			case rey:
				return 4;
			case caballo:
				return 2;
			case sota:
				return 1;		
			default:
				return 0;
			}
		}
	default:
		if (carta.numeroJuego(bastos, palo) == 39)
			return 7;
		if (carta.numeroJuego(bastos, palo) == 37)
			return 5;
		switch(palo)
		{
		case espadas:
		case bastos:
			switch(valor)
			{
			case rey:
				return 5;
			case caballo:
				return 3;
			case sota:
				return 2;
			case siete:
				return 1;
			default:
				return 0;
			}
		default:
			switch(valor)
			{
			case rey:
				return 5;
			case caballo:
				return 3;
			case sota:
				return 2;
			case as:
			case dos:
				return 1;		
			default:
				return 0;
			}
		}
	}
}

int Jugador::valorCartaTriunfoOrden(Carta carta)
{
	palos palo = carta.getPalo();
	valores valor = carta.getValor();
	if (carta.numeroJuego(bastos, palo) == 39)
		return 11;
	if (carta.numeroJuego(bastos, palo) == 38)
		return 10;
	if (carta.numeroJuego(bastos, palo) == 37)
		return 9;
	switch(palo)
	{
	case espadas:
	case bastos:
		switch(valor)
		{
		case rey:
			return 7;
		case caballo:
			return 6;
		case sota:
			return 5;
		case siete:
			return 4;
		case seis:
			return 3;
		case cinco:
			return 2;
		case cuatro:
			return 1;
		default:
			return 0;
		}
	default:
		switch(valor)
		{
		case as:
			return 8;
		case rey:
			return 7;
		case caballo:
			return 6;
		case sota:
			return 5;
		case dos:
			return 4;
		case tres:
			return 3;
		case cuatro:
			return 2;
		case cinco:	
			return 1;
		default:
			return 0;
		}
	}
}

int Jugador::valorCartaNoTriunfoOrden(Carta carta)
{
	palos palo = carta.getPalo();
	valores valor = carta.getValor();
	if (carta.numeroJuego(bastos, palo) == 39)
		return 11;
	if (carta.numeroJuego(bastos, palo) == 37)
		return 10;
	switch(palo)
	{
	case espadas:
	case bastos:
		switch(valor)
		{
		case rey:
			return 9;
		case caballo:
			return 8;
		case sota:
			return 7;
		case siete:
			return 6;
		case seis:
			return 5;
		case cinco:
			return 4;
		case cuatro:
			return 3;
		case tres:
			return 2;
		default:
			return 1;
		}
	default:
		switch(valor)
		{
		case rey:
			return 9;
		case caballo:
			return 8;
		case sota:
			return 7;
		case as:
			return 6;
		case dos:
			return 5;		
		case tres:
			return 4;
		case cuatro:
			return 3;
		case cinco:
			return 2;
		case seis:
			return 1;
		default:
			return 0;
		}
	}
}

Mazo Jugador::soloCartasLegales(Mazo input, Mesa mesa, int turno)
{
	if (turno == 0)
	{
		return input;
	}
	else
	{
		Mazo mazoLegal = Mazo();
		for (int i = 0; i < input.getNumCartas(); i++)
		{
			if (esLegal(input.getCarta(i), mesa.getCarta(mesa.getJugadorMano()), mesa.getTriunfo()))
			{
				mazoLegal.anyadirCarta(input.getCarta(i));
			}
		}
		return mazoLegal;
	}
}

Mazo Jugador::soloTriunfos(Mazo input, Mesa mesa)
{
	Mazo mazoTriunfos = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo()== mesa.getTriunfo() ||
			input.getCarta(i).numeroJuego(bastos, bastos) == 39 ||
			input.getCarta(i).numeroJuego(bastos, bastos) == 37)
		{
			mazoTriunfos.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoTriunfos;
}

Mazo Jugador::soloNoTriunfos(Mazo input, Mesa mesa)
{
	Mazo mazoNoTriunfos = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (!(input.getCarta(i).getPalo()== mesa.getTriunfo() ||
			input.getCarta(i).numeroJuego(bastos, bastos) == 39 ||
			input.getCarta(i).numeroJuego(bastos, bastos) == 37))
		{
			mazoNoTriunfos.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoNoTriunfos;
}

Mazo Jugador::soloBastos(Mazo input)
{
	Mazo mazoBastos = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo() == bastos)
		{
			mazoBastos.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoBastos;
}

Mazo Jugador::soloCopas(Mazo input)
{
	Mazo mazoCopas = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo() == copas)
		{
			mazoCopas.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoCopas;
}

Mazo Jugador::soloEspadas(Mazo input)
{
	Mazo mazoEspadas = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo() == espadas)
		{
			mazoEspadas.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoEspadas;
}

Mazo Jugador::soloOros(Mazo input)
{
	Mazo mazoOros = Mazo();
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo() == oros)
		{
			mazoOros.anyadirCarta(input.getCarta(i));
		}
	}
	return mazoOros;
}


Mazo Jugador::ordenarMazoTriunfos(Mazo input)
{
	Mazo ordenado = input;
	Carta cartaTemporal = Carta();
	for (int i = 0; i < ordenado.getNumCartas(); i++)
	{
		for (int j = i+1; j < ordenado.getNumCartas(); j++)
		{
			if (valorCartaTriunfoOrden(ordenado.getCarta(j)) 
				< valorCartaTriunfoOrden(ordenado.getCarta(i)))
			{
				cartaTemporal = ordenado.cartas[i];
				ordenado.cartas[i] = ordenado.cartas[j];
				ordenado.cartas[j] = cartaTemporal;
			}
		}
	}
	return ordenado;
}

Mazo Jugador::ordenarMazoNoTriunfos(Mazo input)
{
	Mazo ordenado = input;
	Carta cartaTemporal = Carta();
	for (int i = 0; i < ordenado.getNumCartas(); i++)
	{
		for (int j = i+1; j < ordenado.getNumCartas(); j++)
		{
			if (valorCartaNoTriunfoOrden(ordenado.getCarta(j)) 
				< valorCartaNoTriunfoOrden(ordenado.getCarta(i)))
			{
				cartaTemporal = ordenado.cartas[i];
				ordenado.cartas[i] = ordenado.cartas[j];
				ordenado.cartas[j] = cartaTemporal;
			}
		}
	}
	return ordenado;
}

palos Jugador::minimoNumeroCartas(Mazo input)
{
	int numCartasPalo[4] = {0,0,0,0};
	int numMinimo = 9;
	palos paloMinimo;
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		numCartasPalo[(int)input.getCarta(i).getPalo()]++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (numCartasPalo[i] < numMinimo && numCartasPalo[i] != 0)
		{
			numMinimo = numCartasPalo[i];
			paloMinimo = safe_cast<palos>(i);
		}
	}
	return paloMinimo;
}

int Jugador::numeroCartasPalo(Mazo input, palos palo)
{
	int numCartasPalo = 0;
	for (int i = 0; i < input.getNumCartas(); i++)
	{
		if (input.getCarta(i).getPalo() == palo)
			numCartasPalo++;
	}
	return numCartasPalo;
}


bool Jugador::tengoParaServir(Carta cartaInicial, palos triunfo)
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
	return tengoMismoPalo;
}


/////////////// FUNCIONES DE IA //////////////

int Jugador::elegirCarta(int turno, Mesa mesa, int usuarioCartaElegida, Mazo mazoOriginal)
{
	Mazo mazoLegal = soloCartasLegales(this->mazo, mesa, turno);
	Mazo mazoTriunfos = ordenarMazoTriunfos(soloTriunfos(mazoLegal, mesa));
	Mazo mazoNoTriunfos = ordenarMazoNoTriunfos(soloNoTriunfos(mazoLegal, mesa));
	Mazo mazoBastos = ordenarMazoNoTriunfos(soloBastos(mazoLegal));
	Mazo mazoCopas = ordenarMazoNoTriunfos(soloCopas(mazoLegal));
	Mazo mazoEspadas = ordenarMazoNoTriunfos(soloEspadas(mazoLegal));
	Mazo mazoOros = ordenarMazoNoTriunfos(soloOros(mazoLegal));
	Carta cartaElegida;
	int numeroBaza = mesa.getNumBazas1() + mesa.getNumBazas2() + 1; // Numero de baza que se juega
	int indice = 50; // Indice de la carta que se elige
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
	case 3:
	case 4:
		if (!mesa.getAlguienSolo()) // No se va nadie solo
		{
			switch(turno)
			{
			case 0: // Soy mano
				if (numeroBaza < 6) // Primeras 5 bazas
				{
					if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
					{					
						if (valorCartaNoTriunfo(
							mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1)) >= 2)
							// Si tengo algun Rey, Caballo o Sota de no triunfos
						{
							if (mazoNoTriunfos.getNumCartas() > 1 && valorCartaNoTriunfo(
								mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1)) == 
								valorCartaNoTriunfo(
								mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2)))
								// Si tengo dos o más Reyes, Caballos o Sotas
							{
								if (mazoNoTriunfos.getNumCartas() > 2 && valorCartaNoTriunfo(
									mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2)) == 
									valorCartaNoTriunfo(
									mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-3)))
									// Si tengo tres Reyes, Caballos o Sotas
								{
									if (minimoNumeroCartas(mazoNoTriunfos) ==
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1).getPalo())
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
									}
									else if (minimoNumeroCartas(mazoNoTriunfos) ==
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2).getPalo())
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2);
									} 
									else
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-3);
									}
								}
								else
									// Si tengo dos Reyes, Caballos o Sotas
								{
									if (numeroCartasPalo(mazoNoTriunfos, 
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1).getPalo()) <=
										numeroCartasPalo(mazoNoTriunfos, 
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2).getPalo())) 
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
									}
									else
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2);
									}

								}
							}
							else // Si tengo un solo Rey, Caballo o Sota
							{
								cartaElegida = 
									mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
							}

						}
						else // Si no tengo Reyes, Caballos o Sotas
						{
							for (int i = 0; i < mazoNoTriunfos.getNumCartas(); i++)
							{
								if (mazoNoTriunfos.getCarta(i).getPalo() ==
									minimoNumeroCartas(mazoNoTriunfos))
								{
									cartaElegida = 
										mazoNoTriunfos.getCarta(i);
									break;
								}
							}
						}		
					}
					else // Si solo tengo triunfos
					{
						cartaElegida = 
							mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
					}
				}
				else // Últimas 3 bazas
				{
					int coefTriunfos = 0;
					for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
					{
						coefTriunfos += valorCartaTriunfo(mazoTriunfos.getCarta(i));
					}
					if (coefTriunfos > 10 || mazoNoTriunfos.getNumCartas() == 0)
						// Si tengo buenos triunfos o solo triunfos
					{
						cartaElegida = 
							mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
					}
					else // Si no tengo buenos triunfos y algun no triunfo
					{
						cartaElegida = mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
					}
				}
				break;
			case 1: // Soy segundo
				if (mesa.getCarta((numero+3)%4).getPalo() == mesa.getTriunfo() ||
					mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 39 ||
					mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 37)
					// Si arrastra
				{
					if (tengoParaServir(mesa.getCarta((numero+3)%4), mesa.getTriunfo()))
						// Si tengo para servir
					{
						if (mesa.getCarta((numero+3)%4).numeroJuego(
							mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
							mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
							mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
							// Si tengo alguna mayor
						{
							for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
							{
								if (mazoTriunfos.getCarta(i).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) >
									mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
								{
									cartaElegida = mazoTriunfos.getCarta(i);
									break;
								}
							}
						} 
						else // Si no tengo ninguna mayor
						{
							cartaElegida = mazoTriunfos.getCarta(0);
						}
					}
					else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
					{
						if (mazoTriunfos.getNumCartas() == 0) // No tengo triunfos
						{
							// PONER AQUI LO DE PEDIR AL COMPAÑERO
							cartaElegida = mazoNoTriunfos.getCarta(0);
						}
						else // Tengo alguna pieza de estuche
						{
							if (numeroBaza < 6) // Primeras 5 bazas
							{					
								if (valorCartaTriunfo(mesa.getCarta((numero+3)%4)) > 2)
									// Si el arrastre es con una Sota o mayor
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
								else // Si el arrastre es menor que una Sota
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}
							else // Ultimas 3 bazas
							{
								cartaElegida = mazoTriunfos.getCarta(0);

							}
						}
					}

				}
				else // Si no arrastra
				{
					if (tengoParaServir(mesa.getCarta((numero+3)%4), mesa.getTriunfo()))
						// Si tengo para servir
					{
						switch(mesa.getCarta((numero+3)%4).getPalo())
						{
						case bastos:
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
								mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
							{
								cartaElegida = mazoBastos.getCarta(mazoBastos.getNumCartas()-1);
							} 
							else
							{
								cartaElegida = mazoBastos.getCarta(0);
							}
							break;
						case copas:
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
								mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
							{
								cartaElegida = mazoCopas.getCarta(mazoCopas.getNumCartas()-1);
							} 
							else
							{
								cartaElegida = mazoCopas.getCarta(0);
							}
							break;
						case espadas:
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
								mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
							{
								cartaElegida = mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1);
							} 
							else
							{
								cartaElegida = mazoEspadas.getCarta(0);
							}
							break;
						default:
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
								mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
							{
								cartaElegida = mazoOros.getCarta(mazoOros.getNumCartas()-1);
							} 
							else
							{
								cartaElegida = mazoOros.getCarta(0);
							}
							break;
						}
					}
					else // Si no tengo para servir
					{
						if (numeroBaza < 6) // Primeras 5 bazas
						{
							if (mazoTriunfos.getNumCartas() > 0 && 
								valorCartaTriunfo(mazoTriunfos.getCarta(0)) < 3)
								// Si tengo triunfos menores que una Sota
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
							else // Si no tengo triunfos menores que una Sota
							{
								// PONER AQUI LO DE PEDIR AL COMPAÑERO
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
						}
						else // Ultimas 3 bazas
						{
							if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
							else // Si no tengo triunfos
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
						}
					}
				}
				break;
			case 2: // Soy tercero
				if (mesa.getCarta((numero+2)%4).getPalo() == mesa.getTriunfo() ||
					mesa.getCarta((numero+2)%4).numeroJuego(bastos, bastos) == 39 ||
					mesa.getCarta((numero+2)%4).numeroJuego(bastos, bastos) == 37)
				// Si arrastra mi compañero
				{
					if (tengoParaServir(mesa.getCarta((numero+2)%4), mesa.getTriunfo()))
					// Si tengo para servir
					{
						if (mesa.getCarta((numero+2)%4).numeroJuego(
							mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 
							mesa.getCarta((numero+3)%4).numeroJuego(
							mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) &&
							valorCartaTriunfo(mesa.getCarta((numero+2)%4)) > 2)
							// Si va ganando mi compañero con una Sota o más
						{
							cartaElegida = mazoTriunfos.getCarta(0);
						}
						else // Si no va ganando mi compañero o va ganando con menos de Sota
						{
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) <
								mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si tengo alguna mayor
							{
								cartaElegida = 
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
							} 
							else // Si no tengo ninguna mayor
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
						}						
					}
					else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
					{
						if (mazoTriunfos.getNumCartas() == 0) // No tengo triunfos
						{
							// PONER AQUI LO DE PEDIR AL COMPAÑERO
							cartaElegida = mazoNoTriunfos.getCarta(0);
						}
						else // Tengo alguna pieza de estuche
						{
							if (mesa.getCarta((numero+2)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 
								mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) &&
								valorCartaTriunfo(mesa.getCarta((numero+2)%4)) > 2)
								// Si va ganando mi compañero con una Sota o más
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
							else // Si no va ganando mi compañero o va ganando con menos de Sota
							{
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) <
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si tengo alguna mayor
								{
									cartaElegida = 
										mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
								} 
								else // Si no tengo ninguna mayor
								{
									if (mazoNoTriunfos.getNumCartas() > 0)
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
							}			
						}
					}
				}
				else // Si no arrastra mi compañero
				{
					if (tengoParaServir(mesa.getCarta((numero+2)%4), mesa.getTriunfo()))
						// Si tengo para servir
					{
						switch(mesa.getCarta((numero+2)%4).getPalo())
						{
						case bastos:
							if (mesa.getCarta((numero+2)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
								mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si va ganando mi compañero
							{
								if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) - 
									mesa.getCarta((numero+2)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 1)									
									// Si le gano por más de un valor de diferencia
								{
									cartaElegida = mazoBastos.getCarta(mazoBastos.getNumCartas()-1);
								}
								else // Si no le gano por más de un valor de diferencia
								{
									cartaElegida = mazoBastos.getCarta(0);
								}
							} 
							else // Si no va ganando mi compañero
							{
								if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
									mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))									
									// Si le puedo ganar
								{
									cartaElegida = mazoBastos.getCarta(mazoBastos.getNumCartas()-1);
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoBastos.getCarta(0);
								}
							}
							break;
						case copas:
							if (mesa.getCarta((numero+2)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
								mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si va ganando mi compañero
							{
								if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) - 
									mesa.getCarta((numero+2)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 1)									
									// Si le gano por más de un valor de diferencia
								{
									cartaElegida = mazoCopas.getCarta(mazoCopas.getNumCartas()-1);
								}
								else // Si no le gano por más de un valor de diferencia
								{
									cartaElegida = mazoCopas.getCarta(0);
								}
							} 
							else // Si no va ganando mi compañero
							{
								if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
									mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))									
									// Si le puedo ganar
								{
									cartaElegida = mazoCopas.getCarta(mazoCopas.getNumCartas()-1);
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoCopas.getCarta(0);
								}
							}
							break;
						case espadas:
							if (mesa.getCarta((numero+2)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
								mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si va ganando mi compañero
							{
								if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) - 
									mesa.getCarta((numero+2)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 1)									
									// Si le gano por más de un valor de diferencia
								{
									cartaElegida = mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1);
								}
								else // Si no le gano por más de un valor de diferencia
								{
									cartaElegida = mazoEspadas.getCarta(0);
								}
							} 
							else // Si no va ganando mi compañero
							{
								if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
									mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))									
									// Si le puedo ganar
								{
									cartaElegida = mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1);
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoEspadas.getCarta(0);
								}
							}
							break;
						default:
							if (mesa.getCarta((numero+2)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
								mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
								// Si va ganando mi compañero
							{
								if (mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) - 
									mesa.getCarta((numero+2)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 1)									
									// Si le gano por más de un valor de diferencia
								{
									cartaElegida = mazoOros.getCarta(mazoOros.getNumCartas()-1);
								}
								else // Si no le gano por más de un valor de diferencia
								{
									cartaElegida = mazoOros.getCarta(0);
								}
							} 
							else // Si no va ganando mi compañero
							{
								if (mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
									mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))									
									// Si le puedo ganar
								{
									cartaElegida = mazoOros.getCarta(mazoOros.getNumCartas()-1);
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoOros.getCarta(0);
								}
							}
							break;
						}
					}
					else // Si no tengo para servir
					{
						if (mesa.getCarta((numero+2)%4).numeroJuego(
							mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) >
							mesa.getCarta((numero+3)%4).numeroJuego(
							mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) &&
							valorCartaNoTriunfo(mesa.getCarta((numero+2)%4)) >= 3)
							// Si va ganando mi compañero con un Rey o un Caballo
						{
							if (numeroBaza < 6) // Primeras 5 bazas
							{
								if (mazoNoTriunfos.getNumCartas() > 0)
									// Si tengo algun no triunfo
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
								else // Si solo tengo triunfos
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
							else // Ultimas 3 bazas
							{
								if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
								else // Si no tengo triunfos
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}
						}
						else // Si no va ganando mi compañero o va ganando con una Sota o menos
						{
							if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
							{
								if (mesa.getCarta((numero+3)%4).getPalo() == mesa.getTriunfo() ||
									mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 37)
									// Si el segundo mata con un triunfo
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
										mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 
										mesa.getCarta((numero+3)%4).numeroJuego(
										mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
										// Si puedo ganarle 
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(
												mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()) > 
												mesa.getCarta((numero+3)%4).numeroJuego(
												mesa.getCarta((numero+2)%4).getPalo(), mesa.getTriunfo()))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no puedo ganarle
									{
										if (mazoNoTriunfos.getNumCartas() > 0) 
											// Si tengo no triunfos
											cartaElegida = mazoNoTriunfos.getCarta(0);
										else // Si solo tengo triunfos
											cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
								else // Si el segundo no mata con un triunfo
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
							else // Si no tengo triunfos
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
						}
					}
				}
				break;
			default: // Soy último
				Carta primeraCarta = mesa.getCarta((numero+1)%4);
				Carta segundaCarta = mesa.getCarta((numero+2)%4);
				Carta terceraCarta = mesa.getCarta((numero+3)%4);
				palos paloInicial = primeraCarta.getPalo();
				palos triunfo = mesa.getTriunfo();
				if (primeraCarta.getPalo() == triunfo ||
					primeraCarta.numeroJuego(bastos, bastos) == 39 ||
					primeraCarta.numeroJuego(bastos, bastos) == 37)
					// Si arrastra
				{
					if (tengoParaServir(primeraCarta, triunfo))
						// Si tengo para servir
					{
						if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
							primeraCarta.numeroJuego(paloInicial, triunfo) && 
							segundaCarta.numeroJuego(paloInicial, triunfo) > 
							terceraCarta.numeroJuego(paloInicial, triunfo))
							// Si va ganando mi compañero
						{
							cartaElegida = mazoTriunfos.getCarta(0);
						} 
						else // Si no va ganando mi compañero
						{
							if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
								terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando el primero
							{
								if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
									numeroJuego(paloInicial, triunfo) > 
									primeraCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
								{
									for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
									{
										if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))
										{
											cartaElegida = mazoTriunfos.getCarta(i);
											break;
										}
									}
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
							else // Si va ganando el tercero
							{
								if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
									numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
								{
									for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
									{
										if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
											terceraCarta.numeroJuego(paloInicial, triunfo))
										{
											cartaElegida = mazoTriunfos.getCarta(i);
											break;
										}
									}
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
						}
					}
					else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
					{
						if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
							primeraCarta.numeroJuego(paloInicial, triunfo) && 
							segundaCarta.numeroJuego(paloInicial, triunfo) > 
							terceraCarta.numeroJuego(paloInicial, triunfo))
							// Si va ganando mi compañero
						{
							if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
							else // Si solo tengo triunfos
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
						}
						else // Si no va ganando mi compañero
						{
							if (mazoTriunfos.getNumCartas() > 0)
							// Si tengo alguna pieza de estuche
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando el primero
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										if (mazoNoTriunfos.getNumCartas() > 0)
											// Si tengo algun no triunfos
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
										else // Si solo tengo piezas de Estuche
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}									
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												terceraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										if (mazoNoTriunfos.getNumCartas() > 0)
										// Si tengo algun no triunfos
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
										else // Si solo tengo piezas de Estuche
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}
									}								
								}
							}
							else // Si no tengo piezas de estuche
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
						}
					}				
				}
				else // Si no arrastra
				{
					if (tengoParaServir(primeraCarta, triunfo))
						// Si tengo para servir
					{
						switch(paloInicial)
						{
						case bastos:
							if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
								primeraCarta.numeroJuego(paloInicial, triunfo) && 
								segundaCarta.numeroJuego(paloInicial, triunfo) > 
								terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando mi compañero
							{
								cartaElegida = mazoBastos.getCarta(0);
							} 
							else // Si no va ganando mi compañero
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoBastos.getNumCartas(); i++)
										{
											if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoBastos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoBastos.getNumCartas(); i++)
										{
											if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												terceraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoBastos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
								}																
							}
							break;
						case copas:
							if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
								primeraCarta.numeroJuego(paloInicial, triunfo) && 
								segundaCarta.numeroJuego(paloInicial, triunfo) > 
								terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando mi compañero
							{
								cartaElegida = mazoCopas.getCarta(0);
							} 
							else // Si no va ganando mi compañero
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoCopas.getNumCartas(); i++)
										{
											if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoCopas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoCopas.getNumCartas(); i++)
										{
											if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												terceraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoCopas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
								}																
							}
							break;
						case espadas:
							if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
								primeraCarta.numeroJuego(paloInicial, triunfo) && 
								segundaCarta.numeroJuego(paloInicial, triunfo) > 
								terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando mi compañero
							{
								cartaElegida = mazoEspadas.getCarta(0);
							} 
							else // Si no va ganando mi compañero
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
										{
											if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoEspadas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
										{
											if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												terceraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoEspadas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
								}																
							}
							break;
						default:
							if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
								primeraCarta.numeroJuego(paloInicial, triunfo) && 
								segundaCarta.numeroJuego(paloInicial, triunfo) > 
								terceraCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando mi compañero
							{
								cartaElegida = mazoOros.getCarta(0);
							} 
							else // Si no va ganando mi compañero
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									terceraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoOros.getNumCartas(); i++)
										{
											if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoOros.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoOros.getCarta(0);
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoOros.getNumCartas(); i++)
										{
											if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												terceraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoOros.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoOros.getCarta(0);
									}
								}																
							}
							break;
						}
					}
					else // Si no tengo para servir
					{
						if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
							primeraCarta.numeroJuego(paloInicial, triunfo) && 
							segundaCarta.numeroJuego(paloInicial, triunfo) > 
							terceraCarta.numeroJuego(paloInicial, triunfo))
							// Si va ganando mi compañero
						{
							if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
							else // Si solo tengo triunfos
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
						}
						else // Si no va ganando mi compañero
						{
							if (primeraCarta.getPalo() == triunfo ||
								primeraCarta.numeroJuego(bastos, bastos) >= 37 ||
								terceraCarta.getPalo() == triunfo ||
								terceraCarta.numeroJuego(bastos, bastos) >= 37)
								// Si van ganando con un triunfo
							{
								if (mazoTriunfos.getNumCartas() > 0)
								{
									if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
										terceraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
										{
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}
										}
									}
									else // Si va ganando el tercero
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											terceraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													terceraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}
										}
									}
								}
								else // Si no tengo piezas de estuche
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}
							else // Si no van ganando con un triunfo
							{
								if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
								else // Si no tengo triunfos
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}
						}
					}
				}
				break;
			}
		}
		else // Alguien se va solo
		{
			if (mesa.getJugadorSolo() == numero) // Me voy yo solo
			{
				switch(turno)
				{
				case 0: // Soy mano
					if (mazoTriunfos.getNumCartas() > 0) // Si tengo algun triunfo
					{
						cartaElegida = mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
					}
					else
					{
						cartaElegida = mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
					}				
					break;
				case 1: // Soy segundo
					if (mesa.getCarta((numero+3)%4).getPalo() == mesa.getTriunfo() ||
						mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 39 ||
						mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 37)
						// Si arrastra
					{
						if (tengoParaServir(mesa.getCarta((numero+3)%4), mesa.getTriunfo()))
							// Si tengo para servir
						{
							if (mesa.getCarta((numero+3)%4).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
								mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
								mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
								// Si tengo alguna mayor
							{
								cartaElegida = 
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);							
							} 
							else // Si no tengo ninguna mayor
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
						}
						else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
						{
							if (mazoTriunfos.getNumCartas() == 0) // No tengo triunfos
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
							else // Tengo alguna pieza de estuche
							{
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
									// Si tengo alguna mayor
								{
									cartaElegida = 
										mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);							
								} 
								else // Si no tengo ninguna mayor
								{
									if (mazoNoTriunfos.getNumCartas() > 0)
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}							
							}
						}

					}
					else // Si no arrastra
					{
						if (tengoParaServir(mesa.getCarta((numero+3)%4), mesa.getTriunfo()))
							// Si tengo para servir
						{
							switch(mesa.getCarta((numero+3)%4).getPalo())
							{
							case bastos:
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
									mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
									// Si puedo ganarle
								{
									cartaElegida = mazoBastos.getCarta(mazoBastos.getNumCartas()-1);
								} 
								else // Si no puedo ganarle
								{
									cartaElegida = mazoBastos.getCarta(0);
								}
								break;
							case copas:
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
									mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
									// Si puedo ganarle
								{
									cartaElegida = mazoCopas.getCarta(mazoCopas.getNumCartas()-1);
								} 
								else // Si no puedo ganarle
								{
									cartaElegida = mazoCopas.getCarta(0);
								}
								break;
							case espadas:
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
									mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
									// Si puedo ganarle
								{
									cartaElegida = mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1);
								} 
								else // Si no puedo ganarle
								{
									cartaElegida = mazoEspadas.getCarta(0);
								}
								break;
							default:
								if (mesa.getCarta((numero+3)%4).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()) <
									mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
									mesa.getCarta((numero+3)%4).getPalo(), mesa.getTriunfo()))
									// Si puedo ganarle
								{
									cartaElegida = mazoOros.getCarta(mazoOros.getNumCartas()-1);
								} 
								else // Si no puedo ganarle
								{
									cartaElegida = mazoOros.getCarta(0);
								}
								break;
							}
						}
						else // Si no tengo para servir
						{
							if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
							{
								cartaElegida = 
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
							} 
							else // Si no tengo triunfos
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
						}
					}
					break;			
				default: // Soy último
					Carta primeraCarta = mesa.getCarta((numero+1)%4);
					Carta segundaCarta = mesa.getCarta((numero+3)%4);
					palos paloInicial = primeraCarta.getPalo();
					palos triunfo = mesa.getTriunfo();
					if (primeraCarta.getPalo() == triunfo ||
						primeraCarta.numeroJuego(bastos, bastos) == 39 ||
						primeraCarta.numeroJuego(bastos, bastos) == 37)
					// Si arrastra
					{
						if (tengoParaServir(primeraCarta, triunfo))
							// Si tengo para servir
						{
							if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
								segundaCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando el primero
							{
								if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
									numeroJuego(paloInicial, triunfo) > 
									primeraCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
								{
									for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
									{
										if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))
										{
											cartaElegida = mazoTriunfos.getCarta(i);
											break;
										}
									}
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
							else // Si va ganando el segundo
							{
								if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
									numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))									
									// Si le puedo ganar
								{
									for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
									{
										if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))
										{
											cartaElegida = mazoTriunfos.getCarta(i);
											break;
										}
									}
								}
								else // Si no le puedo ganar
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}						
							}
						}
						else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
						{
							if (mazoTriunfos.getNumCartas() == 0) // No tengo triunfos
							{
								cartaElegida = mazoNoTriunfos.getCarta(0);
							}
							else // Tengo piezas de estuche
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										if (mazoNoTriunfos.getNumCartas() > 0)
											// Si tengo algun no triunfos
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
										else // Si solo tengo piezas de Estuche
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}									
									}
								}
								else // Si va ganando el segundo
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										if (mazoNoTriunfos.getNumCartas() > 0)
											// Si tengo algun no triunfos
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
										else // Si solo tengo piezas de Estuche
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}
									}								
								}
							}
						}				
					}
					else // Si no arrastra
					{
						if (tengoParaServir(primeraCarta, triunfo))
							// Si tengo para servir
						{
							switch(paloInicial)
							{
							case bastos:
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoBastos.getNumCartas(); i++)
										{
											if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoBastos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
								}
								else // Si va ganando el segundo
								{
									if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoBastos.getNumCartas(); i++)
										{
											if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoBastos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
								}																							
								break;
							case copas:
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoCopas.getNumCartas(); i++)
										{
											if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoCopas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
								}
								else // Si va ganando el tercero
								{
									if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoCopas.getNumCartas(); i++)
										{
											if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoCopas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
								}																							
								break;
							case espadas:
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
										{
											if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoEspadas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
								}
								else // Si va ganando el segundo
								{
									if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
										{
											if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoEspadas.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
								}																							
								break;
							default:
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoOros.getNumCartas(); i++)
										{
											if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoOros.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoOros.getCarta(0);
									}
								}
								else // Si va ganando el segjundo
								{
									if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoOros.getNumCartas(); i++)
										{
											if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoOros.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoOros.getCarta(0);
									}
								}																						
								break;
							}
						}
						else // Si no tengo para servir
						{
							if (primeraCarta.getPalo() == triunfo ||
								primeraCarta.numeroJuego(bastos, bastos) >= 37 ||
								segundaCarta.getPalo() == triunfo ||
								segundaCarta.numeroJuego(bastos, bastos) >= 37)
								// Si van ganando con un triunfo
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando el primero
								{
									if (mazoTriunfos.getNumCartas() > 0)
									// Si tengo algun triunfo
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
										{										
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											} 
											else
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}
										}
									}
									else // Si no tengo triunfos
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
								else // Si va ganando el segundo
								{
									if (mazoTriunfos.getNumCartas() > 0)
									// Si tengo algun triunfo
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{										
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}
										}
									}
									else // Si no tengo triunfos
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
							}
							else // Si no van ganando con un triunfo
							{
								if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
								else // Si no tengo triunfos
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}						
						}
					}
					break;
				}
			}
			else // Se va solo un oponente
			{
				switch(turno)
				{
				case 0: // Soy mano					
					if (numeroBaza < 6) // Primeras 5 bazas
					{
						if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
						{					
							if (valorCartaNoTriunfo(
								mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1)) >= 2)
								// Si tengo algun Rey, Caballo o Sota de no triunfos
							{
								if (mazoNoTriunfos.getNumCartas() > 1 && valorCartaNoTriunfo(
									mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1)) == 
									valorCartaNoTriunfo(
									mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2)))
									// Si tengo dos o más Reyes, Caballos o Sotas
								{
									if (mazoNoTriunfos.getNumCartas() > 2 && valorCartaNoTriunfo(
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2)) == 
										valorCartaNoTriunfo(
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-3)))
										// Si tengo tres Reyes, Caballos o Sotas
									{
										if (minimoNumeroCartas(mazoNoTriunfos) ==
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1).getPalo())
										{
											cartaElegida = 
												mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
										}
										else if (minimoNumeroCartas(mazoNoTriunfos) ==
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2).getPalo())
										{
											cartaElegida = 
												mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2);
										} 
										else
										{
											cartaElegida = 
												mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-3);
										}
									}
									else
										// Si tengo dos Reyes, Caballos o Sotas
									{
										if (numeroCartasPalo(mazoNoTriunfos, 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1).getPalo()) <=
											numeroCartasPalo(mazoNoTriunfos, 
											mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2).getPalo())) 
										{
											cartaElegida = 
												mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
										}
										else
										{
											cartaElegida = 
												mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-2);
										}

									}
								}
								else // Si tengo un solo Rey, Caballo o Sota
								{
									cartaElegida = 
										mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
								}

							}
							else // Si no tengo Reyes, Caballos o Sotas
							{
								for (int i = 0; i < mazoNoTriunfos.getNumCartas(); i++)
								{
									if (mazoNoTriunfos.getCarta(i).getPalo() ==
										minimoNumeroCartas(mazoNoTriunfos))
									{
										cartaElegida = 
											mazoNoTriunfos.getCarta(i);
										break;
									}
								}
							}		
						}
						else // Si solo tengo triunfos
						{
							cartaElegida = 
								mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
						}
					}
					else // Últimas 3 bazas
					{
						int coefTriunfos = 0;
						for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
						{
							coefTriunfos += valorCartaTriunfo(mazoTriunfos.getCarta(i));
						}
						if (coefTriunfos > 10 || mazoNoTriunfos.getNumCartas() == 0)
							// Si tengo buenos triunfos o solo triunfos
						{
							cartaElegida = 
								mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
						}
						else // Si no tengo buenos triunfos y algun no triunfo
						{
							cartaElegida = mazoNoTriunfos.getCarta(mazoNoTriunfos.getNumCartas()-1);
						}
					}
					break;
				case 1: // Soy segundo
					if (mesa.getJugadorSolo() == (numero+1)%4)
					{
						// Si el que empieza es mi compañero
						Carta primeraCarta = mesa.getCarta((numero+2)%4);
						palos paloInicial = primeraCarta.getPalo();
						palos triunfo = mesa.getTriunfo();
						if (paloInicial == triunfo ||
							primeraCarta.numeroJuego(bastos, bastos) == 39 ||
							primeraCarta.numeroJuego(bastos, bastos) == 37)
							// Si arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								cartaElegida = mazoTriunfos.getCarta(0);
							}
							else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
							{
								if (mazoNoTriunfos.getNumCartas() == 0) // Solo tengo piezas de estuche
								{
									// PONER AQUI LO DE PEDIR AL COMPAÑERO
									cartaElegida = mazoTriunfos.getCarta(0);
								}
								else // Tengo alguna carta no triunfo
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
							}

						}
						else // Si no arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								switch(paloInicial)
								{
								case bastos:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) && 
										mazoBastos.getCarta(mazoBastos.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) - primeraCarta.numeroJuego(paloInicial, triunfo) > 1)
										// Si le gano al compañero por más de uno
									{
										cartaElegida = mazoBastos.getCarta(mazoBastos.getNumCartas()-1);
									} 
									else // Si no le gano por más de uno
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
									break;
								case copas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) && 
										mazoCopas.getCarta(mazoCopas.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) - primeraCarta.numeroJuego(paloInicial, triunfo) > 1)
										// Si le gano al compañero por más de uno
									{
										cartaElegida = mazoCopas.getCarta(mazoCopas.getNumCartas()-1);
									} 
									else // Si no le gano por más de uno
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
									break;
								case espadas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) && 
										mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) - primeraCarta.numeroJuego(paloInicial, triunfo) > 1)
										// Si le gano al compañero por más de uno
									{
										cartaElegida = mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1);
									} 
									else // Si no le gano por más de uno
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
									break;
								default:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) && 
										mazoOros.getCarta(mazoOros.getNumCartas()-1).numeroJuego(
										paloInicial, triunfo) - primeraCarta.numeroJuego(paloInicial, triunfo) > 1)
										// Si le gano al compañero por más de uno
									{
										cartaElegida = mazoOros.getCarta(mazoOros.getNumCartas()-1);
									} 
									else // Si no le gano por más de uno
									{
										cartaElegida = mazoOros.getCarta(0);
									}
									break;
								}
							}
							else // Si no tengo para servir
							{
								if (mazoNoTriunfos.getNumCartas() > 0) 
									// Si tengo algún no triunfo
								{
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
								else // Si sólo tengo triunfos
								{
									cartaElegida = 
										mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1);
								}
							}
						}
					}
					else // Si el que empieza es el que se va solo
					{
						Carta primeraCarta = mesa.getCarta((numero+3)%4);
						palos paloInicial = primeraCarta.getPalo();
						palos triunfo = mesa.getTriunfo();

						if (mesa.getCarta((numero+3)%4).getPalo() == mesa.getTriunfo() ||
							mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 39 ||
							mesa.getCarta((numero+3)%4).numeroJuego(bastos, bastos) == 37)
							// Si arrastra
						{
							if (tengoParaServir(mesa.getCarta((numero+3)%4), mesa.getTriunfo()))
								// Si tengo para servir
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) <
									mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).numeroJuego(
									paloInicial, triunfo))
									// Si tengo alguna mayor
								{
									for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
									{
										if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) >
											primeraCarta.numeroJuego(paloInicial, triunfo))
										{
											cartaElegida = mazoTriunfos.getCarta(i);
											break;
										}
									}
								} 
								else // Si no tengo ninguna mayor
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								}
							}
							else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
							{
								if (mazoTriunfos.getNumCartas() == 0) // No tengo triunfos
								{
									// PONER AQUI LO DE PEDIR AL COMPAÑERO
									cartaElegida = mazoNoTriunfos.getCarta(0);
								}
								else // Tengo alguna pieza de estuche
								{
									if (numeroBaza < 6) // Primeras 5 bazas
									{					
										if (valorCartaTriunfo(mesa.getCarta((numero+3)%4)) > 2)
											// Si el arrastre es con una Sota o mayor
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}
										else // Si el arrastre es menor que una Sota
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}
										}
									}
									else // Ultimas 3 bazas
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
							}

						}
						else // Si no arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								switch(paloInicial)
								{
								case bastos:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo))
									{
										for (int i = 0; i < mazoBastos.getNumCartas(); i++)
										{
											if (mazoBastos.getCarta(i).numeroJuego(
												paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoBastos.getCarta(i);
												break;
											}
										}
									} 
									else
									{
										cartaElegida = mazoBastos.getCarta(0);
									}
									break;
								case copas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo))
									{
										for (int i = 0; i < mazoCopas.getNumCartas(); i++)
										{
											if (mazoCopas.getCarta(i).numeroJuego(
												paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoCopas.getCarta(i);
												break;
											}
										}
									} 
									else
									{
										cartaElegida = mazoCopas.getCarta(0);
									}
									break;
								case espadas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo))
									{
										for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
										{
											if (mazoEspadas.getCarta(i).numeroJuego(
												paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoEspadas.getCarta(i);
												break;
											}
										}
									} 
									else
									{
										cartaElegida = mazoEspadas.getCarta(0);
									}
									break;
								default:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) <
										mazoOros.getCarta(mazoOros.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo))
									{
										for (int i = 0; i < mazoOros.getNumCartas(); i++)
										{
											if (mazoOros.getCarta(i).numeroJuego(
												paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoOros.getCarta(i);
												break;
											}
										}
									} 
									else
									{
										cartaElegida = mazoOros.getCarta(0);
									}
									break;
								}
							}
							else // Si no tengo para servir
							{
								if (numeroBaza < 6) // Primeras 5 bazas
								{
									if (mazoTriunfos.getNumCartas() > 0 && 
										valorCartaTriunfo(mazoTriunfos.getCarta(0)) < 3)
										// Si tengo triunfos menores que una Sota
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
									else // Si no tengo triunfos menores que una Sota
									{
										// PONER AQUI LO DE PEDIR AL COMPAÑERO
										if (mazoNoTriunfos.getNumCartas() > 0)
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
										else
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}
									}
								}
								else // Ultimas 3 bazas
								{
									if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
									else // Si no tengo triunfos
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
							}
						}
					}
					break;				
				default: // Soy último
					if (mesa.getJugadorSolo() == (numero+1)%4)
						// Si el primero es el que se va solo
					{
						Carta primeraCarta = mesa.getCarta((numero+1)%4);					
						Carta segundaCarta = mesa.getCarta((numero+2)%4);
						palos paloInicial = primeraCarta.getPalo();
						palos triunfo = mesa.getTriunfo();
						if (primeraCarta.getPalo() == triunfo ||
							primeraCarta.numeroJuego(bastos, bastos) == 39 ||
							primeraCarta.numeroJuego(bastos, bastos) == 37)
						// Si arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
									primeraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando mi compañero
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								} 
								else // Si no va ganando mi compañero
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												primeraCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
							}
							else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
							{
								if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
									primeraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando mi compañero
								{
									if (mazoNoTriunfos.getNumCartas() > 0) 
										// Si tengo algun no triunfo
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else // Si solo tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
								else // Si no va ganando mi compañero
								{
									if (mazoTriunfos.getNumCartas() > 0)
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
												// Si tengo algun no triunfos
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else // Si solo tengo piezas de Estuche
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}																		
										}
									}
									else
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
							}				
						}
						else // Si no arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								switch(paloInicial)
								{
								case bastos:
									if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoBastos.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoBastos.getNumCartas(); i++)
											{
												if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoBastos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoBastos.getCarta(0);
										}																
									}
									break;
								case copas:
									if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoCopas.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoCopas.getNumCartas(); i++)
											{
												if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoCopas.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoCopas.getCarta(0);
										}																
									}
									break;
								case espadas:
									if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoEspadas.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
											{
												if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoEspadas.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoEspadas.getCarta(0);
										}																
									}
									break;
								default:
									if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
										primeraCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoOros.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											primeraCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoOros.getNumCartas(); i++)
											{
												if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													primeraCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoOros.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoOros.getCarta(0);
										}																
									}
									break;
								}
							}
							else // Si no tengo para servir
							{
								if (segundaCarta.numeroJuego(paloInicial, triunfo) > 
									primeraCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando mi compañero
								{
									if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else // Si solo tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
								else // Si no va ganando mi compañero
								{
									if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
									else // Si no tengo triunfos
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
							}
						}
					}
					else // Si el primero es mi compañero
					{
						Carta primeraCarta = mesa.getCarta((numero+2)%4);					
						Carta segundaCarta = mesa.getCarta((numero+3)%4);
						palos paloInicial = primeraCarta.getPalo();
						palos triunfo = mesa.getTriunfo();
						if (primeraCarta.getPalo() == triunfo ||
							primeraCarta.numeroJuego(bastos, bastos) == 39 ||
							primeraCarta.numeroJuego(bastos, bastos) == 37)
						// Si arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
								// Si tengo para servir
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando mi compañero
								{
									cartaElegida = mazoTriunfos.getCarta(0);
								} 
								else // Si no va ganando mi compañero
								{
									if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
										numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))									
										// Si le puedo ganar
									{
										for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
										{
											if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											{
												cartaElegida = mazoTriunfos.getCarta(i);
												break;
											}
										}
									}
									else // Si no le puedo ganar
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
							}
							else // Si no tengo para servir o solo tengo Espadilla, Malilla o Bastillo
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
								// Si va ganando mi compañero
								{
									if (mazoNoTriunfos.getNumCartas() > 0) 
									// Si tengo algun no triunfo
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else // Si solo tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
								else // Si no va ganando mi compañero
								{
									if (mazoTriunfos.getNumCartas() > 0)
									{
										if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
											{
												if (mazoTriunfos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoTriunfos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											if (mazoNoTriunfos.getNumCartas() > 0)
												// Si tengo algun no triunfos
											{
												cartaElegida = mazoNoTriunfos.getCarta(0);
											}
											else // Si solo tengo piezas de Estuche
											{
												cartaElegida = mazoTriunfos.getCarta(0);
											}									
										}
									}
									else
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
								}
							}				
						}
						else // Si no arrastra
						{
							if (tengoParaServir(primeraCarta, triunfo))
							// Si tengo para servir
							{
								switch(paloInicial)
								{
								case bastos:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoBastos.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoBastos.getCarta(mazoBastos.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoBastos.getNumCartas(); i++)
											{
												if (mazoBastos.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoBastos.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoBastos.getCarta(0);
										}																
									}
									break;
								case copas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoCopas.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoCopas.getCarta(mazoCopas.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoCopas.getNumCartas(); i++)
											{
												if (mazoCopas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoCopas.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoCopas.getCarta(0);
										}																
									}
									break;
								case espadas:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoEspadas.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoEspadas.getCarta(mazoEspadas.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoEspadas.getNumCartas(); i++)
											{
												if (mazoEspadas.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoEspadas.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoEspadas.getCarta(0);
										}																
									}
									break;
								default:
									if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
										segundaCarta.numeroJuego(paloInicial, triunfo))
										// Si va ganando mi compañero
									{
										cartaElegida = mazoOros.getCarta(0);
									} 
									else // Si no va ganando mi compañero
									{
										if (mazoOros.getCarta(mazoOros.getNumCartas()-1).
											numeroJuego(paloInicial, triunfo) > 
											segundaCarta.numeroJuego(paloInicial, triunfo))									
											// Si le puedo ganar
										{
											for (int i = 0; i < mazoOros.getNumCartas(); i++)
											{
												if (mazoOros.getCarta(i).numeroJuego(paloInicial, triunfo) > 
													segundaCarta.numeroJuego(paloInicial, triunfo))
												{
													cartaElegida = mazoOros.getCarta(i);
													break;
												}
											}
										}
										else // Si no le puedo ganar
										{
											cartaElegida = mazoOros.getCarta(0);
										}																
									}
									break;
								}
							}
							else // Si no tengo para servir
							{
								if (primeraCarta.numeroJuego(paloInicial, triunfo) > 
									segundaCarta.numeroJuego(paloInicial, triunfo))
									// Si va ganando mi compañero
								{
									if (mazoNoTriunfos.getNumCartas() > 0) // Si tengo algun no triunfo
									{
										cartaElegida = mazoNoTriunfos.getCarta(0);
									}
									else // Si solo tengo triunfos
									{
										cartaElegida = mazoTriunfos.getCarta(0);
									}
								}
								else // Si no va ganando mi compañero
								{
									if (segundaCarta.getPalo() == triunfo ||
										segundaCarta.numeroJuego(bastos, bastos) == 37)
									// Si el que se va solo mata con triunfos
									{
										if (mazoTriunfos.getNumCartas() > 0)
										{
											if (mazoTriunfos.getCarta(mazoTriunfos.getNumCartas()-1)
												.numeroJuego(paloInicial, triunfo) > 
												segundaCarta.numeroJuego(paloInicial, triunfo))
											// Si le puedo ganar
											{
												for (int i = 0; i < mazoTriunfos.getNumCartas(); i++)
												{
													if (mazoTriunfos.getCarta(i).numeroJuego(
														paloInicial, triunfo) >
														segundaCarta.numeroJuego(paloInicial, triunfo))
													{
														cartaElegida = mazoTriunfos.getCarta(i);
														break;
													}
												}
											}
											else // Si no le puedo ganar
											{
												if (mazoNoTriunfos.getNumCartas() > 0)
												// Si tengo algun no triunfo
												{
													cartaElegida = mazoNoTriunfos.getCarta(0);
												}
												else // Si solo tengo triunfos
												{
													cartaElegida = mazoTriunfos.getCarta(0);
												}
											}
										}
										else
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
									}
									else // Si el que se va solo no mata con triunfos
									{
										if (mazoTriunfos.getNumCartas() > 0) // Si tengo triunfos
										{
											cartaElegida = mazoTriunfos.getCarta(0);
										}
										else // Si no tengo triunfos
										{
											cartaElegida = mazoNoTriunfos.getCarta(0);
										}
									}									
								}
							}
						}
					}										
					break;
				}
			}		
		}
		for (int i = 0; i < mazo.getNumCartas(); i++)
		{
			if (mazo.getCarta(i) == cartaElegida)
			{
				indice = i;
				break;
			}
		}
		if (indice == 50)
			cout << "ERROR";
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
	int coeficientes[4] = {0, 0, 0, 0};
	int coeficienteMax = 0;
	int umbralJuego = 5;
	int umbralSolo = 25;
	switch (algoritmoIA)
	{
	case 10:
		return usuarioFrasePrimero;
	case 4:
		umbralJuego = 14;
		umbralSolo = 28;
	case 2:	
	case 3:
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (mazo.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(mazo.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(mazo.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMax)
			{
				coeficienteMax = coeficientes[palo];
			}
			else if (coeficientes[palo] == coeficienteMax)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMax = coeficientes[palo];
				}
			}			
		}
		if (coeficienteMax < umbralJuego)
		{
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
		} 
		else if (coeficienteMax < umbralSolo)
		{
			return juego;
		}
		else
		{
			return meVoySolo;
		}
	default:
		return juego;
	}		
}

frasesHablarDespues Jugador::hablarDespues(Mesa mesa, frasesHablarDespues usuarioFraseDespues)
{
	int coeficientes[4] = {0, 0, 0, 0};
	int coeficienteMax = 0;
	int umbralSolo = 25;
	switch (algoritmoIA)
	{
	case 10:
		return usuarioFraseDespues;
	case 4:
		umbralSolo = 28;
	case 2:
	case 3:
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (mazo.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(mazo.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(mazo.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMax)
			{
				coeficienteMax = coeficientes[palo];
			}
			else if (coeficientes[palo] == coeficienteMax)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMax = coeficientes[palo];
				}
			}			
		}
		if (coeficienteMax < umbralSolo)
		{
			return juegoTambien;
		}
		else
		{
			return vayaSolo;
		}
	default:
		return juegoTambien;
	}
}

palos Jugador::triunfar(palos usuarioTriunfo)
{
	int coeficientes[4] = {0, 0, 0, 0};
	int coeficienteMax = 0;
	palos paloMax;
	switch (algoritmoIA)
	{		
	case 10:
		return usuarioTriunfo;
	case 1:
	case 2:
	case 3:
	case 4:
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (mazo.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(mazo.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(mazo.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMax)
			{
				coeficienteMax = coeficientes[palo];
				paloMax = safe_cast<palos>(palo);
			}
			else if (coeficientes[palo] == coeficienteMax)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMax = coeficientes[palo];
					paloMax = safe_cast<palos>(palo);
				}
			}			
		}
		return paloMax;
	default:
		System::Random paloAleatorio(System::DateTime::Now.Millisecond);
		return (palos)paloAleatorio.Next(4);
	}		
}

bool Jugador::aceptarSolo(int jugador, Mesa mesa, bool usuarioAceptaSolo)
{
	int coeficientes[4] = {0, 0, 0, 0};
	int coeficienteMax = 0;
	int umbralSolo = 22;
	switch (algoritmoIA)
	{	
	case 10:
		return usuarioAceptaSolo;
	case 4:
		umbralSolo = 25;
	case 2:
	case 3:	
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (mazo.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(mazo.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(mazo.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMax)
			{
				coeficienteMax = coeficientes[palo];
			}
			else if (coeficientes[palo] == coeficienteMax)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMax = coeficientes[palo];
				}
			}			
		}
		if (coeficienteMax < umbralSolo)
		{
			return false;
		}
		else
		{
			return true;
		}
	default:
		return false;
	}
}

frasesHablarZanga Jugador::hablarZanga(Mesa mesa, frasesHablarZanga usuarioFraseZanga) 
{
	int coeficientes[4] = {0, 0, 0, 0};
	int coeficienteMax = 0;
	int coeficienteMaxOriginal = 0;
	int diferenciaCambio = 6;
	int umbralSolo = 25;
	Mazo cartasOriginales = mesa.getZanga();

	switch (algoritmoIA)
	{
	case 10:
		return usuarioFraseZanga;
	case 2:
	case 3:
	case 4:
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (mazo.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					mazo.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(mazo.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(mazo.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMax)
			{
				coeficienteMax = coeficientes[palo];
			}
			else if (coeficientes[palo] == coeficienteMax)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMax = coeficientes[palo];
				}
			}			
		}
		for (int i = 0; i < 4; i++)
			coeficientes[i] = 0;
		for (int palo = 0; palo < 4; palo++)
		{
			for (int carta = 0; carta < 8; carta++)
			{
				if (cartasOriginales.getCarta(carta).getPalo() == safe_cast<palos>(palo) ||
					cartasOriginales.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 39 ||
					cartasOriginales.getCarta(carta).numeroJuego(bastos, safe_cast<palos>(palo)) == 37)
					coeficientes[palo] += valorCartaTriunfo(cartasOriginales.getCarta(carta));
				else
					coeficientes[palo] += valorCartaNoTriunfo(cartasOriginales.getCarta(carta));
			}			
		}
		for (int palo = 0; palo < 4; palo++)
		{
			if (coeficientes[palo] > coeficienteMaxOriginal)
			{
				coeficienteMax = coeficientes[palo];
			}
			else if (coeficientes[palo] == coeficienteMaxOriginal)
			{
				if ((palos)palo == espadas || (palos)palo == bastos)
				{
					coeficienteMaxOriginal = coeficientes[palo];
				}
			}			
		}
		if (coeficienteMax < coeficienteMaxOriginal - diferenciaCambio)
		{
			return rechazoZanga;
		} 
		else if (coeficienteMax < umbralSolo)
		{
			return juegoZanga;
		}
		else
		{
			return meVoySoloZanga;
		}
	default:
		return juegoZanga;
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
