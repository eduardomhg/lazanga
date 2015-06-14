
#ifndef _TIPOS_H_
#define _TIPOS_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

enum palos {bastos, copas, espadas, oros};
enum valores {rey, caballo, sota, siete, seis, cinco, cuatro, tres, dos, as};
enum frasesHablarPrimero {juego, paso, meVoySolo};
enum frasesHablarDespues {juegoTambien, vayaSolo};
enum frasesHablarZanga{juegoZanga, meVoySoloZanga, rechazoZanga};
enum frasesHablarRecambio{juegoRecambio, meVoySoloRecambio};
enum situaciones{primero, despues, aceptarSolo, primeroZanga, primeroRecambio, 
	cincoPedir, todasPedir};
enum formasSolo {meVoy, meVoyYo, vayaUsted};

enum mensajesMulti {numeroNombre, desconectado, nombre, voz, chat, 
	cambioJugador, cambioListo, comenzar};
enum mensajesJuego {semillaBaraja, hablarPrimero, hablarDespues, hablarZanga, hablarRecambio, 
	tirarCartaMensaje, ack, aceptarSoloMensaje, hablarTriunfo, hablarCinco, hablarTodas, 
	comenzarJuego, informarJugadorServidor};

int minimo(int a, int b);

#endif


