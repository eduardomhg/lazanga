
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

#endif


