#ifndef _TIPOS_H_
  #include "tipos.h"
#endif 
#ifndef _BARAJA_H_
  #include "Baraja.h"
#endif 
#ifndef _CARTA_H_
  #include "Carta.h"
#endif 
#ifndef _MAZO_H_
  #include "Mazo.h"
#endif 
#ifndef _JUGADOR_H_
  #include "Jugador.h"
#endif 
#ifndef _MESA_H_
  #include "Mesa.h"
#endif 

int main()
{	
	Baraja baraja = Baraja();
	Jugador jugadores[4];
	jugadores[0] = Jugador("Eduardo", 0, 1);
	jugadores[1] = Jugador("Antonio", 1, 0);
	jugadores[2] = Jugador("Cris", 2, 0);
	jugadores[3] = Jugador("Crisanto", 3, 0);
	Mesa mesa = Mesa();

	Carta comienzo, cartaTemp;
	bool alguienLaTiene = false;
	frasesHablarPrimero frasePrimero;
	frasesHablarDespues fraseDespues;
	int mano;
	int numManos = 0;
	bool seguir = false;

	// PRIMERA MANO

	// Decidir el primer mano
	cout << "Comienza la partida de zanga.\n\n";
	while (!alguienLaTiene)
	{
		mesa.barajar(baraja);		
		mesa.repartir(baraja, jugadores);
		for (int indiceEspadas = (int)siete; indiceEspadas < (int)dos; indiceEspadas++)
		{
			comienzo = Carta((valores)indiceEspadas, espadas);
			for (int i = 0; i < 4; i++)
			{
				if (jugadores[i].tieneCarta(comienzo))
				{					
					cout << "El jugador " << i+1 << " tiene el " << comienzo.nombre() << ".\n";
					mesa.setJugadorManoPrimero(i);
					alguienLaTiene = true;
					break;
				}
			}
			if (alguienLaTiene) break;
		}
	}

	// Hablar
	mano = mesa.getJugadorManoPrimero();
	frasePrimero = jugadores[mano].hablarPrimero(mesa);	
	if (frasePrimero == juego)
	{
		mesa.juega(mano);
		fraseDespues = jugadores[(mano+1)%4].hablarDespues(mesa);
		if (fraseDespues == juegoTambien)
		{
			mesa.juega((mano+1)%4);
			fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa);
			if (fraseDespues == juegoTambien)
			{
				mesa.juega((mano+2)%4);
				fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
				if (fraseDespues == juegoTambien)
				{
					mesa.juega((mano+3)%4);
				}
				else
				{
					mesa.mandaSolo((mano+3)%4, mano);
					if (jugadores[mano].aceptarSolo((mano+3)%4, mesa))
						mesa.vaSolo(mano, meVoyYo);
					else
						mesa.vaSolo((mano+3)%4, vayaUsted);
				}
			}
			else
			{
				mesa.mandaSolo((mano+2)%4, mano);
				if (jugadores[mano].aceptarSolo((mano+2)%4, mesa))
					mesa.vaSolo(mano, meVoyYo);
				else
					mesa.vaSolo((mano+2)%4, vayaUsted);
			}
		} 
		else 
		{
			mesa.mandaSolo((mano+1)%4, mano);
			if (jugadores[mano].aceptarSolo((mano+1)%4, mesa))
				mesa.vaSolo(mano, meVoyYo);
			else
				mesa.vaSolo((mano+1)%4, vayaUsted);
		}
	} 
	else if (frasePrimero == paso)
	{
		mesa.pasa(mano);
		frasePrimero = jugadores[(mano+1)%4].hablarPrimero(mesa);
		if (frasePrimero == juego)
		{
			mesa.juega((mano+1)%4);
			fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa);
			if (fraseDespues == juegoTambien)
			{
				mesa.juega((mano+2)%4);
				fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
				if (fraseDespues == juegoTambien)
				{
					mesa.juega((mano+3)%4);
				}
				else
				{
					mesa.mandaSolo((mano+3)%4, (mano+1)%4);
					if (jugadores[(mano+1)%4].aceptarSolo((mano+3)%4, mesa))
						mesa.vaSolo((mano+1)%4, meVoyYo);
					else
						mesa.vaSolo((mano+3)%4, vayaUsted);
				}
			} 
			else
			{
				mesa.mandaSolo((mano+2)%4, (mano+1)%4);
				if (jugadores[(mano+1)%4].aceptarSolo((mano+2)%4, mesa))
					mesa.vaSolo((mano+1)%4, meVoyYo);
				else
					mesa.vaSolo((mano+2)%4, vayaUsted);
			}
		} 
		else if (frasePrimero == paso)
		{
			mesa.pasa((mano+1)%4);
			frasePrimero = jugadores[(mano+2)%4].hablarPrimero(mesa);
			if (frasePrimero == juego)
			{
				mesa.juega((mano+2)%4);
				fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
				if (fraseDespues == juegoTambien)
				{
					mesa.juega((mano+3)%4);
				}
				else
				{
					if (jugadores[(mano+2)%4].aceptarSolo((mano+3)%4, mesa))
						mesa.vaSolo((mano+2)%4, meVoyYo);
					else
						mesa.vaSolo((mano+3)%4, vayaUsted);
				}
			}
			else if (frasePrimero == paso)
			{
				mesa.pasa((mano+2)%4);
				frasePrimero = jugadores[(mano+3)%4].hablarPrimero(mesa);
				if (frasePrimero == paso)
				{
					mesa.cambiaPorZanga(jugadores, (mano+3)%4);
					if (jugadores[(mano+3)%4].recambiarCartas(mesa))
					{
						mesa.recambiaSusCartas(jugadores, (mano+3)%4);
					}
				} 
				else if (frasePrimero == juego)
				{
					mesa.juega((mano+3)%4);	
				}
				else
				{
					mesa.vaSolo((mano+3)%4, meVoy);					
				}
			}
			else
			{
				mesa.vaSolo((mano+2)%4, meVoy);
			}
		}
		else
		{
			mesa.vaSolo((mano+1)%4, meVoy);
		}
	}
	else
	{
		mesa.vaSolo(mano, meVoy);
	}
	mesa.setTriunfo(jugadores[mesa.getJugadorTriunfo()].triunfar());
	mesa.comprobarEstuche(baraja);
	cout << "\n";
	cout << "Comienzo de la mano " << numManos +1 << ".\n";

	for (int i = 0; i < 8; i++)
	{
		mano = mesa.getJugadorMano();
		if (i == 2 && (mesa.getNumBazas1() == 2 || mesa.getNumBazas2() == 2))
		{
			if (jugadores[mano].pedirCinco(mesa))
			{
				mesa.pideCinco(mano);
			}
		}
		// Tirar
		if (!mesa.getAlguienSolo())
		{	
			mesa.ponerCarta(jugadores[mano].tirarCarta(0, mesa), mano);
			mesa.ponerCarta(jugadores[(mano+1)%4].tirarCarta(1, mesa), (mano+1)%4);
			mesa.ponerCarta(jugadores[(mano+2)%4].tirarCarta(2, mesa), (mano+2)%4);	
			mesa.ponerCarta(jugadores[(mano+3)%4].tirarCarta(3, mesa), (mano+3)%4);
		}
		else
		{			
			if (jugadores[mano].getNumero() != mesa.getJugadorSolo())
				mesa.ponerCarta(jugadores[mano].tirarCarta(0, mesa), mano);
			if (jugadores[(mano+1)%4].getNumero() != mesa.getJugadorSolo())
				mesa.ponerCarta(jugadores[(mano+1)%4].tirarCarta(1, mesa), (mano+1)%4);
			if (jugadores[(mano+2)%4].getNumero() != mesa.getJugadorSolo())
				mesa.ponerCarta(jugadores[(mano+2)%4].tirarCarta(2, mesa), (mano+2)%4);	
			if (jugadores[(mano+3)%4].getNumero() != mesa.getJugadorSolo())
				mesa.ponerCarta(jugadores[(mano+3)%4].tirarCarta(3, mesa), (mano+3)%4);			
		}
		mesa.organizarBaza();
		mano = mesa.getJugadorMano();
		if (i == 5 && mesa.getAlguienCinco())
		{
			if (mesa.getNumBazas1() == 5 || mesa.getNumBazas2() == 5)
			{
				mesa.cumpleCinco(true);
				if (jugadores[mano].pedirTodas(mesa))
				{
					mesa.pideTodas(mano);
					seguir = true;
				}
			}
			else
			{
				mesa.cumpleCinco(false);
			}
		}
		if (mesa.getAlguienTodas() && 
			(mesa.getNumBazas1() >= 1 || mesa.getNumBazas2() >= 1))
		{
			mesa.cumpleTodas(false);
			seguir = false;
		}
		if (i == 8 && mesa.getAlguienTodas())
		{
			if (mesa.getNumBazas1() == 8 || mesa.getNumBazas2() == 8)
				mesa.cumpleTodas(true);
			else
				mesa.cumpleTodas(false);
		}
		if (!seguir && (mesa.getNumBazas1() >= 5 || mesa.getNumBazas2() >= 5))
			break;
	}
	mesa.organizarPiedras();
	numManos++;
	cout << "Fin de la mano 1.\n\n";

	// SIGUIENTES MANOS

	while (!((mesa.getNumPiedras1() <= 0 && mesa.getNumPiedrasCentro() <= 0)
		|| (mesa.getNumPiedras2() <= 0 && mesa.getNumPiedrasCentro() <= 0)))
	{

		mesa.barajar(baraja);
		mesa.repartir(baraja, jugadores);

		// Hablar
		mano = mesa.getJugadorManoPrimero();
		frasePrimero = jugadores[mano].hablarPrimero(mesa);	
		if (frasePrimero == juego)
		{
			mesa.juega(mano);
			fraseDespues = jugadores[(mano+1)%4].hablarDespues(mesa);
			if (fraseDespues == juegoTambien)
			{
				mesa.juega((mano+1)%4);
				fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa);
				if (fraseDespues == juegoTambien)
				{
					mesa.juega((mano+2)%4);
					fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
					if (fraseDespues == juegoTambien)
					{
						mesa.juega((mano+3)%4);
					}
					else
					{
						mesa.mandaSolo((mano+3)%4, mano);
						if (jugadores[mano].aceptarSolo((mano+3)%4, mesa))
							mesa.vaSolo(mano, meVoyYo);
						else
							mesa.vaSolo((mano+3)%4, vayaUsted);
					}
				}
				else
				{
					mesa.mandaSolo((mano+2)%4, mano);
					if (jugadores[mano].aceptarSolo((mano+2)%4, mesa))
						mesa.vaSolo(mano, meVoyYo);
					else
						mesa.vaSolo((mano+2)%4, vayaUsted);
				}
			} 
			else 
			{
				mesa.mandaSolo((mano+1)%4, mano);
				if (jugadores[mano].aceptarSolo((mano+1)%4, mesa))
					mesa.vaSolo(mano, meVoyYo);
				else
					mesa.vaSolo((mano+1)%4, vayaUsted);
			}
		} 
		else if (frasePrimero == paso)
		{
			mesa.pasa(mano);
			frasePrimero = jugadores[(mano+1)%4].hablarPrimero(mesa);
			if (frasePrimero == juego)
			{
				mesa.juega((mano+1)%4);
				fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa);
				if (fraseDespues == juegoTambien)
				{
					mesa.juega((mano+2)%4);
					fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
					if (fraseDespues == juegoTambien)
					{
						mesa.juega((mano+3)%4);
					}
					else
					{
						mesa.mandaSolo((mano+3)%4, (mano+1)%4);
						if (jugadores[(mano+1)%4].aceptarSolo((mano+3)%4, mesa))
							mesa.vaSolo((mano+1)%4, meVoyYo);
						else
							mesa.vaSolo((mano+3)%4, vayaUsted);
					}
				} 
				else
				{
					mesa.mandaSolo((mano+2)%4, (mano+1)%4);
					if (jugadores[(mano+1)%4].aceptarSolo((mano+2)%4, mesa))
						mesa.vaSolo((mano+1)%4, meVoyYo);
					else
						mesa.vaSolo((mano+2)%4, vayaUsted);
				}
			} 
			else if (frasePrimero == paso)
			{
				mesa.pasa((mano+1)%4);
				frasePrimero = jugadores[(mano+2)%4].hablarPrimero(mesa);
				if (frasePrimero == juego)
				{
					mesa.juega((mano+2)%4);
					fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa);
					if (fraseDespues == juegoTambien)
					{
						mesa.juega((mano+3)%4);
					}
					else
					{
						if (jugadores[(mano+2)%4].aceptarSolo((mano+3)%4, mesa))
							mesa.vaSolo((mano+2)%4, meVoyYo);
						else
							mesa.vaSolo((mano+3)%4, vayaUsted);
					}
				}
				else if (frasePrimero == paso)
				{
					mesa.pasa((mano+2)%4);
					frasePrimero = jugadores[(mano+3)%4].hablarPrimero(mesa);
					if (frasePrimero == paso)
					{
						mesa.cambiaPorZanga(jugadores, (mano+3)%4);
						if (jugadores[(mano+3)%4].recambiarCartas(mesa))
						{
							mesa.recambiaSusCartas(jugadores, (mano+3)%4);
						}
					} 
					else if (frasePrimero == juego)
					{
						mesa.juega((mano+3)%4);	
					}
					else
					{
						mesa.vaSolo((mano+3)%4, meVoy);					
					}
				}
				else
				{
					mesa.vaSolo((mano+2)%4, meVoy);
				}
			}
			else
			{
				mesa.vaSolo((mano+1)%4, meVoy);
			}
		}
		else
		{
			mesa.vaSolo(mano, meVoy);
		}
		mesa.setTriunfo(jugadores[mesa.getJugadorTriunfo()].triunfar());
		mesa.comprobarEstuche(baraja);
		cout << "\n";
		cout << "Comienzo de la mano " << numManos +1 << ".\n";

		for (int i = 0; i < 8; i++)
		{
			mano = mesa.getJugadorMano();
			if (i == 2 && (mesa.getNumBazas1() == 2 || mesa.getNumBazas2() == 2))
			{
				if (jugadores[mano].pedirCinco(mesa))
				{
					mesa.pideCinco(mano);
				}
			}
			// Tirar
			if (!mesa.getAlguienSolo())
			{	
				mesa.ponerCarta(jugadores[mano].tirarCarta(0, mesa), mano);
				mesa.ponerCarta(jugadores[(mano+1)%4].tirarCarta(1, mesa), (mano+1)%4);
				mesa.ponerCarta(jugadores[(mano+2)%4].tirarCarta(2, mesa), (mano+2)%4);	
				mesa.ponerCarta(jugadores[(mano+3)%4].tirarCarta(3, mesa), (mano+3)%4);
			}
			else
			{			
				if (jugadores[mano].getNumero() != mesa.getJugadorSolo())
					mesa.ponerCarta(jugadores[mano].tirarCarta(0, mesa), mano);
				if (jugadores[(mano+1)%4].getNumero() != mesa.getJugadorSolo())
					mesa.ponerCarta(jugadores[(mano+1)%4].tirarCarta(1, mesa), (mano+1)%4);
				if (jugadores[(mano+2)%4].getNumero() != mesa.getJugadorSolo())
					mesa.ponerCarta(jugadores[(mano+2)%4].tirarCarta(2, mesa), (mano+2)%4);	
				if (jugadores[(mano+3)%4].getNumero() != mesa.getJugadorSolo())
					mesa.ponerCarta(jugadores[(mano+3)%4].tirarCarta(3, mesa), (mano+3)%4);			
			}
			mesa.organizarBaza();
			mano = mesa.getJugadorMano();
			if (i == 5 && mesa.getAlguienCinco())
			{
				if (mesa.getNumBazas1() == 5 || mesa.getNumBazas2() == 5)
				{
					mesa.cumpleCinco(true);
					if (jugadores[mano].pedirTodas(mesa))
					{
						mesa.pideTodas(mano);
						seguir = true;
					}
				}
				else
				{
					mesa.cumpleCinco(false);
				}
			}
			if (mesa.getAlguienTodas() && 
				(mesa.getNumBazas1() >= 1 || mesa.getNumBazas2() >= 1))
			{
				mesa.cumpleTodas(false);
				seguir = false;
			}
			if (i == 8 && mesa.getAlguienTodas())
			{
				if (mesa.getNumBazas1() == 8 || mesa.getNumBazas2() == 8)
					mesa.cumpleTodas(true);
				else
					mesa.cumpleTodas(false);
			}
			if (!seguir && (mesa.getNumBazas1() >= 5 || mesa.getNumBazas2() >= 5))
				break;
		}
		if (mesa.getAlguienEstuche())
		{
			mesa.pedirEstuche();
		}
		mesa.organizarPiedras();
		numManos++;
		cout << "Fin de la mano " << numManos << ".\n\n";
	}

	if (mesa.getNumPiedras2() == 0)
		cout << "La pareja 1 gana en " << numManos << " manos.\n";
	else
		cout << "La pareja 2 gana en " << numManos << " manos.\n";

	return 0;
}

