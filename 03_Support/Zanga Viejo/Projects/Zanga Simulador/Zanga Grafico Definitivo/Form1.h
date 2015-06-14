#pragma once

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
#ifndef _BAZA_H_
#include "Baza.h"
#endif 

namespace ZangaGraficoDefinitivo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}








	private: System::Windows::Forms::PictureBox^  cartaArriba0;
	private: System::Windows::Forms::PictureBox^  cartaArriba1;
	private: System::Windows::Forms::PictureBox^  cartaArriba2;
	private: System::Windows::Forms::PictureBox^  cartaArriba3;
	private: System::Windows::Forms::PictureBox^  cartaArriba4;
	private: System::Windows::Forms::PictureBox^  cartaArriba5;
	private: System::Windows::Forms::PictureBox^  cartaArriba6;
	private: System::Windows::Forms::PictureBox^  cartaArriba7;
	private: System::Windows::Forms::PictureBox^  cartaDerecha7;

	private: System::Windows::Forms::PictureBox^  cartaDerecha6;

	private: System::Windows::Forms::PictureBox^  cartaDerecha5;

	private: System::Windows::Forms::PictureBox^  cartaDerecha4;

	private: System::Windows::Forms::PictureBox^  cartaDerecha3;

	private: System::Windows::Forms::PictureBox^  cartaDerecha2;

	private: System::Windows::Forms::PictureBox^  cartaDerecha1;

	private: System::Windows::Forms::PictureBox^  cartaDerecha0;

	private: System::Windows::Forms::PictureBox^  cartaIzquierda7;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda6;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda5;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda4;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda3;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda2;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda1;
	private: System::Windows::Forms::PictureBox^  cartaIzquierda0;
	private: System::Windows::Forms::PictureBox^  tapete;
	private: System::Windows::Forms::Button^  botonMeVoySolo;




	private: System::Windows::Forms::Button^  botonPaso;
	private: System::Windows::Forms::Button^  botonJuego;
	private: System::Windows::Forms::PictureBox^  cartaMesa0;
	private: System::Windows::Forms::PictureBox^  cartaMesa1;
	private: System::Windows::Forms::PictureBox^  cartaMesa2;
	private: System::Windows::Forms::PictureBox^  cartaMesa3;













	private: System::Windows::Forms::PictureBox^  cartaAbajo0;
	private: System::Windows::Forms::PictureBox^  cartaAbajo1;
	private: System::Windows::Forms::PictureBox^  cartaAbajo2;
	private: System::Windows::Forms::PictureBox^  cartaAbajo3;
	private: System::Windows::Forms::PictureBox^  cartaAbajo4;
	private: System::Windows::Forms::PictureBox^  cartaAbajo5;
	private: System::Windows::Forms::PictureBox^  cartaAbajo6;
	private: System::Windows::Forms::PictureBox^  bazaAbajo7;

	private: System::Windows::Forms::PictureBox^  bazaAbajo6;

	private: System::Windows::Forms::PictureBox^  bazaAbajo5;

	private: System::Windows::Forms::PictureBox^  bazaAbajo4;

	private: System::Windows::Forms::PictureBox^  bazaAbajo3;

	private: System::Windows::Forms::PictureBox^  bazaAbajo2;

	private: System::Windows::Forms::PictureBox^  bazaAbajo1;
	private: System::Windows::Forms::PictureBox^  bazaAbajo0;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda7;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda6;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda5;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda4;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda3;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda2;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda1;
	private: System::Windows::Forms::PictureBox^  bazaIzquierda0;










	private: System::Windows::Forms::PictureBox^  cartaAbajo7;
	private: System::Windows::Forms::PictureBox^  zangaArribaDerecha;
	private: System::Windows::Forms::PictureBox^  zangaAbajoIzquierda;


	private: System::Windows::Forms::PictureBox^  piedraCentro28;

	private: System::Windows::Forms::PictureBox^  piedraCentro20;

	private: System::Windows::Forms::PictureBox^  piedraCentro12;

	private: System::Windows::Forms::PictureBox^  piedraCentro8;



	private: System::Windows::Forms::PictureBox^  piedraCentro0;
	private: System::Windows::Forms::PictureBox^  piedraCentro4;
	private: System::Windows::Forms::PictureBox^  piedraCentro16;
	private: System::Windows::Forms::PictureBox^  piedraCentro24;




	private: System::Windows::Forms::PictureBox^  piedraCentro10;
	private: System::Windows::Forms::PictureBox^  piedraCentro14;
	private: System::Windows::Forms::PictureBox^  piedraCentro22;
	private: System::Windows::Forms::PictureBox^  piedraCentro30;






	private: System::Windows::Forms::PictureBox^  piedraCentro2;
	private: System::Windows::Forms::PictureBox^  piedraCentro5;
	private: System::Windows::Forms::PictureBox^  piedraCentro17;
	private: System::Windows::Forms::PictureBox^  piedraCentro25;
	private: System::Windows::Forms::PictureBox^  piedraCentro31;





	private: System::Windows::Forms::PictureBox^  piedraCentro23;

	private: System::Windows::Forms::PictureBox^  piedraCentro15;

	private: System::Windows::Forms::PictureBox^  piedraCentro11;
	private: System::Windows::Forms::PictureBox^  piedraCentro27;


	private: System::Windows::Forms::PictureBox^  piedraCentro19;

	private: System::Windows::Forms::PictureBox^  piedraCentro7;

	private: System::Windows::Forms::PictureBox^  piedraCentro3;
	private: System::Windows::Forms::PictureBox^  piedraCentro26;


	private: System::Windows::Forms::PictureBox^  piedraCentro18;

	private: System::Windows::Forms::PictureBox^  piedraCentro6;


	private: System::Windows::Forms::PictureBox^  piedraCentro1;
	private: System::Windows::Forms::PictureBox^  piedraCentro29;


	private: System::Windows::Forms::PictureBox^  piedraCentro21;

	private: System::Windows::Forms::PictureBox^  piedraCentro13;

	private: System::Windows::Forms::PictureBox^  piedraCentro9;
	private: System::Windows::Forms::PictureBox^  piedraDos31;


	private: System::Windows::Forms::PictureBox^  piedraDos23;

	private: System::Windows::Forms::PictureBox^  piedraDos15;

	private: System::Windows::Forms::PictureBox^  piedraDos11;
	private: System::Windows::Forms::PictureBox^  piedraDos27;


	private: System::Windows::Forms::PictureBox^  piedraDos19;

	private: System::Windows::Forms::PictureBox^  piedraDos7;

	private: System::Windows::Forms::PictureBox^  piedraDos3;
	private: System::Windows::Forms::PictureBox^  piedraDos26;


	private: System::Windows::Forms::PictureBox^  piedraDos18;

	private: System::Windows::Forms::PictureBox^  piedraDos6;

	private: System::Windows::Forms::PictureBox^  piedraDos1;
	private: System::Windows::Forms::PictureBox^  piedraDos29;


	private: System::Windows::Forms::PictureBox^  piedraDos21;

	private: System::Windows::Forms::PictureBox^  piedraDos13;

	private: System::Windows::Forms::PictureBox^  piedraDos9;
	private: System::Windows::Forms::PictureBox^  piedraDos10;
	private: System::Windows::Forms::PictureBox^  piedraDos14;
	private: System::Windows::Forms::PictureBox^  piedraDos22;
	private: System::Windows::Forms::PictureBox^  piedraDos30;





	private: System::Windows::Forms::PictureBox^  piedraDos2;
	private: System::Windows::Forms::PictureBox^  piedraDos5;
	private: System::Windows::Forms::PictureBox^  piedraDos17;
	private: System::Windows::Forms::PictureBox^  piedraDos25;




	private: System::Windows::Forms::PictureBox^  piedraDos0;
	private: System::Windows::Forms::PictureBox^  piedraDos4;
	private: System::Windows::Forms::PictureBox^  piedraDos16;
	private: System::Windows::Forms::PictureBox^  piedraDos24;






	private: System::Windows::Forms::PictureBox^  piedraDos8;
	private: System::Windows::Forms::PictureBox^  piedraDos12;
	private: System::Windows::Forms::PictureBox^  piedraDos20;
	private: System::Windows::Forms::PictureBox^  piedraDos28;




	private: System::Windows::Forms::PictureBox^  piedraUno31;

	private: System::Windows::Forms::PictureBox^  piedraUno23;

	private: System::Windows::Forms::PictureBox^  piedraUno15;

	private: System::Windows::Forms::PictureBox^  piedraUno11;
	private: System::Windows::Forms::PictureBox^  piedraUno27;


	private: System::Windows::Forms::PictureBox^  piedraUno19;

	private: System::Windows::Forms::PictureBox^  piedraUno7;

	private: System::Windows::Forms::PictureBox^  piedraUno3;
	private: System::Windows::Forms::PictureBox^  piedraUno26;


	private: System::Windows::Forms::PictureBox^  piedraUno18;

	private: System::Windows::Forms::PictureBox^  piedraUno6;

	private: System::Windows::Forms::PictureBox^  piedraUno1;
	private: System::Windows::Forms::PictureBox^  piedraUno29;


	private: System::Windows::Forms::PictureBox^  piedraUno21;

	private: System::Windows::Forms::PictureBox^  piedraUno13;

	private: System::Windows::Forms::PictureBox^  piedraUno9;
	private: System::Windows::Forms::PictureBox^  piedraUno10;
	private: System::Windows::Forms::PictureBox^  piedraUno14;
	private: System::Windows::Forms::PictureBox^  piedraUno22;
	private: System::Windows::Forms::PictureBox^  piedraUno30;





	private: System::Windows::Forms::PictureBox^  piedraUno2;
	private: System::Windows::Forms::PictureBox^  piedraUno5;
	private: System::Windows::Forms::PictureBox^  piedraUno17;
	private: System::Windows::Forms::PictureBox^  piedraUno25;




	private: System::Windows::Forms::PictureBox^  piedraUno0;
	private: System::Windows::Forms::PictureBox^  piedraUno4;
	private: System::Windows::Forms::PictureBox^  piedraUno16;
	private: System::Windows::Forms::PictureBox^  piedraUno24;




	private: System::Windows::Forms::PictureBox^  piedraUno8;
	private: System::Windows::Forms::PictureBox^  piedraUno12;
	private: System::Windows::Forms::PictureBox^  piedraUno20;
	private: System::Windows::Forms::PictureBox^  piedraUno28;




	private: System::Windows::Forms::Button^  botonComenzar;
	private: System::Windows::Forms::Button^  botonSalir;
	private: System::Windows::Forms::TextBox^  salida;
	private: System::Windows::Forms::Panel^  panelTriunfa;









	private: System::Windows::Forms::Label^  labelTriunfa;
	private: System::Windows::Forms::Label^  labelTriunfa2;


	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  labelProximoMano;

	private: System::Windows::Forms::Label^  labelProximoMano2;








	private: System::Windows::Forms::Panel^  panelSePidio;

	private: System::Windows::Forms::Label^  labelSePidio;


	private: System::Windows::Forms::CheckBox^  checkBoxSolo;
	private: System::Windows::Forms::CheckBox^  checkBoxCinco;
	private: System::Windows::Forms::CheckBox^  checkBoxTodas;



	private: System::Windows::Forms::Label^  labelTriunfos2;
	private: System::Windows::Forms::Label^  labelTriunfos;
	private: System::Windows::Forms::Panel^  panelTriunfos;
	private: System::Windows::Forms::PictureBox^  imagenBaraja0;
	private: System::Windows::Forms::PictureBox^  imagenBaraja2;
	private: System::Windows::Forms::PictureBox^  imagenBaraja3;
	private: System::Windows::Forms::PictureBox^  imagenBaraja1;
	private: System::Windows::Forms::PictureBox^  barajaCortar0;
	private: System::Windows::Forms::PictureBox^  barajaCortar2;
	private: System::Windows::Forms::PictureBox^  barajaCortar3;
	private: System::Windows::Forms::PictureBox^  barajaCortar1;
	private: System::Windows::Forms::Label^  labelPiedras2;
	private: System::Windows::Forms::Label^  labelPiedras1;




	private: System::Windows::Forms::Label^  labelPiedrasCentro;
	private: System::Windows::Forms::Label^  labelBazas2;


	private: System::Windows::Forms::Label^  labelBazas1;
	private: System::Windows::Forms::Label^  labelJugador3;
	private: System::Windows::Forms::Label^  labelJugador1;
	private: System::Windows::Forms::Label^  labelJugador0;



	private: System::Windows::Forms::Label^  labelJugador2;
	private: System::Windows::Forms::Button^  botonVayaSolo;
	private: System::Windows::Forms::Button^  botonTodas;


	private: System::Windows::Forms::Button^  botonCinco;

	private: System::Windows::Forms::Button^  botonRechazoZanga;

	private: System::Windows::Forms::Button^  botonVayaUsted;
	private: System::Windows::Forms::Button^  botonEspadas;
	private: System::Windows::Forms::Button^  botonBastos;
	private: System::Windows::Forms::Button^  botonCopas;



	private: System::Windows::Forms::Button^  botonOros;
private: System::Windows::Forms::Label^  labelPartidas;
private: System::Windows::Forms::Label^  labelProgreso;






















































	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->cartaArriba0 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba1 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba2 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba3 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba4 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba5 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba6 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaArriba7 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha7 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha6 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha5 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha4 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha3 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha2 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha1 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaDerecha0 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda7 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda6 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda5 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda4 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda3 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda2 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda1 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaIzquierda0 = (gcnew System::Windows::Forms::PictureBox());
			this->tapete = (gcnew System::Windows::Forms::PictureBox());
			this->botonMeVoySolo = (gcnew System::Windows::Forms::Button());
			this->botonPaso = (gcnew System::Windows::Forms::Button());
			this->botonJuego = (gcnew System::Windows::Forms::Button());
			this->cartaMesa0 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaMesa1 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaMesa2 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaMesa3 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo0 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo1 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo2 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo3 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo4 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo5 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo6 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo7 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo6 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo5 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo4 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo3 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo2 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaAbajo0 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda7 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda6 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda5 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda4 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda3 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda2 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda1 = (gcnew System::Windows::Forms::PictureBox());
			this->bazaIzquierda0 = (gcnew System::Windows::Forms::PictureBox());
			this->cartaAbajo7 = (gcnew System::Windows::Forms::PictureBox());
			this->zangaArribaDerecha = (gcnew System::Windows::Forms::PictureBox());
			this->zangaAbajoIzquierda = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro28 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro20 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro12 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro8 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro0 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro4 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro16 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro24 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro10 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro14 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro22 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro30 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro2 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro5 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro17 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro25 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro31 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro23 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro15 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro11 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro27 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro19 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro7 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro3 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro26 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro18 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro6 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro1 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro29 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro21 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro13 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraCentro9 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos31 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos23 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos15 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos11 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos27 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos19 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos7 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos3 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos26 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos18 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos6 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos1 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos29 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos21 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos13 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos9 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos10 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos14 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos22 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos30 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos2 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos5 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos17 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos25 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos0 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos4 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos16 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos24 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos8 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos12 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos20 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraDos28 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno31 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno23 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno15 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno11 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno27 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno19 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno7 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno3 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno26 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno18 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno6 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno1 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno29 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno21 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno13 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno9 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno10 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno14 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno22 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno30 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno2 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno5 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno17 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno25 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno0 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno4 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno16 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno24 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno8 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno12 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno20 = (gcnew System::Windows::Forms::PictureBox());
			this->piedraUno28 = (gcnew System::Windows::Forms::PictureBox());
			this->botonComenzar = (gcnew System::Windows::Forms::Button());
			this->botonSalir = (gcnew System::Windows::Forms::Button());
			this->salida = (gcnew System::Windows::Forms::TextBox());
			this->panelTriunfa = (gcnew System::Windows::Forms::Panel());
			this->labelTriunfa = (gcnew System::Windows::Forms::Label());
			this->labelTriunfa2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->labelProximoMano = (gcnew System::Windows::Forms::Label());
			this->labelProximoMano2 = (gcnew System::Windows::Forms::Label());
			this->panelSePidio = (gcnew System::Windows::Forms::Panel());
			this->checkBoxSolo = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCinco = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxTodas = (gcnew System::Windows::Forms::CheckBox());
			this->labelSePidio = (gcnew System::Windows::Forms::Label());
			this->labelTriunfos2 = (gcnew System::Windows::Forms::Label());
			this->labelTriunfos = (gcnew System::Windows::Forms::Label());
			this->panelTriunfos = (gcnew System::Windows::Forms::Panel());
			this->imagenBaraja0 = (gcnew System::Windows::Forms::PictureBox());
			this->imagenBaraja2 = (gcnew System::Windows::Forms::PictureBox());
			this->imagenBaraja3 = (gcnew System::Windows::Forms::PictureBox());
			this->imagenBaraja1 = (gcnew System::Windows::Forms::PictureBox());
			this->barajaCortar0 = (gcnew System::Windows::Forms::PictureBox());
			this->barajaCortar2 = (gcnew System::Windows::Forms::PictureBox());
			this->barajaCortar3 = (gcnew System::Windows::Forms::PictureBox());
			this->barajaCortar1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelPiedras2 = (gcnew System::Windows::Forms::Label());
			this->labelPiedras1 = (gcnew System::Windows::Forms::Label());
			this->labelPiedrasCentro = (gcnew System::Windows::Forms::Label());
			this->labelBazas2 = (gcnew System::Windows::Forms::Label());
			this->labelBazas1 = (gcnew System::Windows::Forms::Label());
			this->labelJugador3 = (gcnew System::Windows::Forms::Label());
			this->labelJugador1 = (gcnew System::Windows::Forms::Label());
			this->labelJugador0 = (gcnew System::Windows::Forms::Label());
			this->labelJugador2 = (gcnew System::Windows::Forms::Label());
			this->botonVayaSolo = (gcnew System::Windows::Forms::Button());
			this->botonTodas = (gcnew System::Windows::Forms::Button());
			this->botonCinco = (gcnew System::Windows::Forms::Button());
			this->botonRechazoZanga = (gcnew System::Windows::Forms::Button());
			this->botonVayaUsted = (gcnew System::Windows::Forms::Button());
			this->botonEspadas = (gcnew System::Windows::Forms::Button());
			this->botonBastos = (gcnew System::Windows::Forms::Button());
			this->botonCopas = (gcnew System::Windows::Forms::Button());
			this->botonOros = (gcnew System::Windows::Forms::Button());
			this->labelPartidas = (gcnew System::Windows::Forms::Label());
			this->labelProgreso = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tapete))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->zangaArribaDerecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->zangaAbajoIzquierda))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno28))->BeginInit();
			this->panelTriunfa->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panelSePidio->SuspendLayout();
			this->panelTriunfos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar1))->BeginInit();
			this->SuspendLayout();
			// 
			// cartaArriba0
			// 
			this->cartaArriba0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba0->Location = System::Drawing::Point(485, 11);
			this->cartaArriba0->Name = L"cartaArriba0";
			this->cartaArriba0->Size = System::Drawing::Size(40, 61);
			this->cartaArriba0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba0->TabIndex = 15;
			this->cartaArriba0->TabStop = false;
			// 
			// cartaArriba1
			// 
			this->cartaArriba1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba1->Location = System::Drawing::Point(439, 11);
			this->cartaArriba1->Name = L"cartaArriba1";
			this->cartaArriba1->Size = System::Drawing::Size(40, 61);
			this->cartaArriba1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba1->TabIndex = 14;
			this->cartaArriba1->TabStop = false;
			// 
			// cartaArriba2
			// 
			this->cartaArriba2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba2->Location = System::Drawing::Point(393, 11);
			this->cartaArriba2->Name = L"cartaArriba2";
			this->cartaArriba2->Size = System::Drawing::Size(40, 61);
			this->cartaArriba2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba2->TabIndex = 13;
			this->cartaArriba2->TabStop = false;
			// 
			// cartaArriba3
			// 
			this->cartaArriba3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba3->Location = System::Drawing::Point(347, 11);
			this->cartaArriba3->Name = L"cartaArriba3";
			this->cartaArriba3->Size = System::Drawing::Size(40, 61);
			this->cartaArriba3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba3->TabIndex = 12;
			this->cartaArriba3->TabStop = false;
			// 
			// cartaArriba4
			// 
			this->cartaArriba4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba4->Location = System::Drawing::Point(301, 11);
			this->cartaArriba4->Name = L"cartaArriba4";
			this->cartaArriba4->Size = System::Drawing::Size(40, 61);
			this->cartaArriba4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba4->TabIndex = 11;
			this->cartaArriba4->TabStop = false;
			// 
			// cartaArriba5
			// 
			this->cartaArriba5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba5->Location = System::Drawing::Point(255, 11);
			this->cartaArriba5->Name = L"cartaArriba5";
			this->cartaArriba5->Size = System::Drawing::Size(40, 61);
			this->cartaArriba5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba5->TabIndex = 10;
			this->cartaArriba5->TabStop = false;
			// 
			// cartaArriba6
			// 
			this->cartaArriba6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba6->Location = System::Drawing::Point(209, 11);
			this->cartaArriba6->Name = L"cartaArriba6";
			this->cartaArriba6->Size = System::Drawing::Size(40, 61);
			this->cartaArriba6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba6->TabIndex = 9;
			this->cartaArriba6->TabStop = false;
			// 
			// cartaArriba7
			// 
			this->cartaArriba7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaArriba7->Location = System::Drawing::Point(163, 11);
			this->cartaArriba7->Name = L"cartaArriba7";
			this->cartaArriba7->Size = System::Drawing::Size(40, 61);
			this->cartaArriba7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaArriba7->TabIndex = 8;
			this->cartaArriba7->TabStop = false;
			// 
			// cartaDerecha7
			// 
			this->cartaDerecha7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha7->Location = System::Drawing::Point(615, 159);
			this->cartaDerecha7->Name = L"cartaDerecha7";
			this->cartaDerecha7->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha7->TabIndex = 16;
			this->cartaDerecha7->TabStop = false;
			// 
			// cartaDerecha6
			// 
			this->cartaDerecha6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha6->Location = System::Drawing::Point(615, 205);
			this->cartaDerecha6->Name = L"cartaDerecha6";
			this->cartaDerecha6->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha6->TabIndex = 17;
			this->cartaDerecha6->TabStop = false;
			// 
			// cartaDerecha5
			// 
			this->cartaDerecha5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha5->Location = System::Drawing::Point(615, 251);
			this->cartaDerecha5->Name = L"cartaDerecha5";
			this->cartaDerecha5->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha5->TabIndex = 18;
			this->cartaDerecha5->TabStop = false;
			// 
			// cartaDerecha4
			// 
			this->cartaDerecha4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha4->Location = System::Drawing::Point(615, 297);
			this->cartaDerecha4->Name = L"cartaDerecha4";
			this->cartaDerecha4->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha4->TabIndex = 19;
			this->cartaDerecha4->TabStop = false;
			// 
			// cartaDerecha3
			// 
			this->cartaDerecha3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha3->Location = System::Drawing::Point(615, 343);
			this->cartaDerecha3->Name = L"cartaDerecha3";
			this->cartaDerecha3->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha3->TabIndex = 20;
			this->cartaDerecha3->TabStop = false;
			// 
			// cartaDerecha2
			// 
			this->cartaDerecha2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha2->Location = System::Drawing::Point(615, 389);
			this->cartaDerecha2->Name = L"cartaDerecha2";
			this->cartaDerecha2->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha2->TabIndex = 21;
			this->cartaDerecha2->TabStop = false;
			// 
			// cartaDerecha1
			// 
			this->cartaDerecha1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha1->Location = System::Drawing::Point(615, 435);
			this->cartaDerecha1->Name = L"cartaDerecha1";
			this->cartaDerecha1->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha1->TabIndex = 22;
			this->cartaDerecha1->TabStop = false;
			// 
			// cartaDerecha0
			// 
			this->cartaDerecha0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaDerecha0->Location = System::Drawing::Point(615, 481);
			this->cartaDerecha0->Name = L"cartaDerecha0";
			this->cartaDerecha0->Size = System::Drawing::Size(61, 40);
			this->cartaDerecha0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaDerecha0->TabIndex = 23;
			this->cartaDerecha0->TabStop = false;
			// 
			// cartaIzquierda7
			// 
			this->cartaIzquierda7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda7->Location = System::Drawing::Point(12, 481);
			this->cartaIzquierda7->Name = L"cartaIzquierda7";
			this->cartaIzquierda7->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda7->TabIndex = 31;
			this->cartaIzquierda7->TabStop = false;
			// 
			// cartaIzquierda6
			// 
			this->cartaIzquierda6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda6->Location = System::Drawing::Point(12, 435);
			this->cartaIzquierda6->Name = L"cartaIzquierda6";
			this->cartaIzquierda6->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda6->TabIndex = 30;
			this->cartaIzquierda6->TabStop = false;
			// 
			// cartaIzquierda5
			// 
			this->cartaIzquierda5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda5->Location = System::Drawing::Point(12, 389);
			this->cartaIzquierda5->Name = L"cartaIzquierda5";
			this->cartaIzquierda5->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda5->TabIndex = 29;
			this->cartaIzquierda5->TabStop = false;
			// 
			// cartaIzquierda4
			// 
			this->cartaIzquierda4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda4->Location = System::Drawing::Point(12, 343);
			this->cartaIzquierda4->Name = L"cartaIzquierda4";
			this->cartaIzquierda4->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda4->TabIndex = 28;
			this->cartaIzquierda4->TabStop = false;
			// 
			// cartaIzquierda3
			// 
			this->cartaIzquierda3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda3->Location = System::Drawing::Point(12, 297);
			this->cartaIzquierda3->Name = L"cartaIzquierda3";
			this->cartaIzquierda3->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda3->TabIndex = 27;
			this->cartaIzquierda3->TabStop = false;
			// 
			// cartaIzquierda2
			// 
			this->cartaIzquierda2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda2->Location = System::Drawing::Point(12, 251);
			this->cartaIzquierda2->Name = L"cartaIzquierda2";
			this->cartaIzquierda2->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda2->TabIndex = 26;
			this->cartaIzquierda2->TabStop = false;
			// 
			// cartaIzquierda1
			// 
			this->cartaIzquierda1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda1->Location = System::Drawing::Point(12, 205);
			this->cartaIzquierda1->Name = L"cartaIzquierda1";
			this->cartaIzquierda1->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda1->TabIndex = 25;
			this->cartaIzquierda1->TabStop = false;
			// 
			// cartaIzquierda0
			// 
			this->cartaIzquierda0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaIzquierda0->Location = System::Drawing::Point(12, 159);
			this->cartaIzquierda0->Name = L"cartaIzquierda0";
			this->cartaIzquierda0->Size = System::Drawing::Size(61, 40);
			this->cartaIzquierda0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaIzquierda0->TabIndex = 24;
			this->cartaIzquierda0->TabStop = false;
			// 
			// tapete
			// 
			this->tapete->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tapete->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tapete.Image")));
			this->tapete->Location = System::Drawing::Point(94, 90);
			this->tapete->Name = L"tapete";
			this->tapete->Size = System::Drawing::Size(500, 501);
			this->tapete->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->tapete->TabIndex = 32;
			this->tapete->TabStop = false;
			// 
			// botonMeVoySolo
			// 
			this->botonMeVoySolo->Enabled = false;
			this->botonMeVoySolo->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonMeVoySolo->Location = System::Drawing::Point(12, 643);
			this->botonMeVoySolo->Name = L"botonMeVoySolo";
			this->botonMeVoySolo->Size = System::Drawing::Size(70, 28);
			this->botonMeVoySolo->TabIndex = 5;
			this->botonMeVoySolo->Text = L"Me Voy Solo";
			this->botonMeVoySolo->UseVisualStyleBackColor = true;
			this->botonMeVoySolo->Click += gcnew System::EventHandler(this, &Form1::botonMeVoySolo_Click);
			// 
			// botonPaso
			// 
			this->botonPaso->Enabled = false;
			this->botonPaso->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonPaso->Location = System::Drawing::Point(87, 610);
			this->botonPaso->Name = L"botonPaso";
			this->botonPaso->Size = System::Drawing::Size(70, 28);
			this->botonPaso->TabIndex = 4;
			this->botonPaso->Text = L"Paso";
			this->botonPaso->UseVisualStyleBackColor = true;
			this->botonPaso->Click += gcnew System::EventHandler(this, &Form1::botonPaso_Click);
			// 
			// botonJuego
			// 
			this->botonJuego->Enabled = false;
			this->botonJuego->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonJuego->Location = System::Drawing::Point(12, 610);
			this->botonJuego->Name = L"botonJuego";
			this->botonJuego->Size = System::Drawing::Size(70, 28);
			this->botonJuego->TabIndex = 3;
			this->botonJuego->Text = L"Juego";
			this->botonJuego->UseVisualStyleBackColor = true;
			this->botonJuego->Click += gcnew System::EventHandler(this, &Form1::botonJuego_Click);
			// 
			// cartaMesa0
			// 
			this->cartaMesa0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaMesa0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cartaMesa0.Image")));
			this->cartaMesa0->Location = System::Drawing::Point(324, 396);
			this->cartaMesa0->Name = L"cartaMesa0";
			this->cartaMesa0->Size = System::Drawing::Size(40, 61);
			this->cartaMesa0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaMesa0->TabIndex = 39;
			this->cartaMesa0->TabStop = false;
			this->cartaMesa0->Visible = false;
			// 
			// cartaMesa1
			// 
			this->cartaMesa1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaMesa1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cartaMesa1.Image")));
			this->cartaMesa1->Location = System::Drawing::Point(416, 310);
			this->cartaMesa1->Name = L"cartaMesa1";
			this->cartaMesa1->Size = System::Drawing::Size(40, 61);
			this->cartaMesa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaMesa1->TabIndex = 40;
			this->cartaMesa1->TabStop = false;
			this->cartaMesa1->Visible = false;
			// 
			// cartaMesa2
			// 
			this->cartaMesa2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaMesa2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cartaMesa2.Image")));
			this->cartaMesa2->Location = System::Drawing::Point(324, 221);
			this->cartaMesa2->Name = L"cartaMesa2";
			this->cartaMesa2->Size = System::Drawing::Size(40, 61);
			this->cartaMesa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaMesa2->TabIndex = 41;
			this->cartaMesa2->TabStop = false;
			this->cartaMesa2->Visible = false;
			// 
			// cartaMesa3
			// 
			this->cartaMesa3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaMesa3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cartaMesa3.Image")));
			this->cartaMesa3->Location = System::Drawing::Point(229, 310);
			this->cartaMesa3->Name = L"cartaMesa3";
			this->cartaMesa3->Size = System::Drawing::Size(40, 61);
			this->cartaMesa3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaMesa3->TabIndex = 42;
			this->cartaMesa3->TabStop = false;
			this->cartaMesa3->Visible = false;
			// 
			// cartaAbajo0
			// 
			this->cartaAbajo0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo0->Location = System::Drawing::Point(164, 610);
			this->cartaAbajo0->Name = L"cartaAbajo0";
			this->cartaAbajo0->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo0->TabIndex = 0;
			this->cartaAbajo0->TabStop = false;
			this->cartaAbajo0->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo0_Click);
			// 
			// cartaAbajo1
			// 
			this->cartaAbajo1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo1->Location = System::Drawing::Point(210, 610);
			this->cartaAbajo1->Name = L"cartaAbajo1";
			this->cartaAbajo1->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo1->TabIndex = 1;
			this->cartaAbajo1->TabStop = false;
			this->cartaAbajo1->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo1_Click);
			// 
			// cartaAbajo2
			// 
			this->cartaAbajo2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo2->Location = System::Drawing::Point(256, 610);
			this->cartaAbajo2->Name = L"cartaAbajo2";
			this->cartaAbajo2->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo2->TabIndex = 2;
			this->cartaAbajo2->TabStop = false;
			this->cartaAbajo2->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo2_Click);
			// 
			// cartaAbajo3
			// 
			this->cartaAbajo3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo3->Location = System::Drawing::Point(302, 610);
			this->cartaAbajo3->Name = L"cartaAbajo3";
			this->cartaAbajo3->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo3->TabIndex = 3;
			this->cartaAbajo3->TabStop = false;
			this->cartaAbajo3->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo3_Click);
			// 
			// cartaAbajo4
			// 
			this->cartaAbajo4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo4->Location = System::Drawing::Point(348, 610);
			this->cartaAbajo4->Name = L"cartaAbajo4";
			this->cartaAbajo4->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo4->TabIndex = 4;
			this->cartaAbajo4->TabStop = false;
			this->cartaAbajo4->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo4_Click);
			// 
			// cartaAbajo5
			// 
			this->cartaAbajo5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo5->Location = System::Drawing::Point(394, 610);
			this->cartaAbajo5->Name = L"cartaAbajo5";
			this->cartaAbajo5->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo5->TabIndex = 5;
			this->cartaAbajo5->TabStop = false;
			this->cartaAbajo5->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo5_Click);
			// 
			// cartaAbajo6
			// 
			this->cartaAbajo6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo6->Location = System::Drawing::Point(440, 610);
			this->cartaAbajo6->Name = L"cartaAbajo6";
			this->cartaAbajo6->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo6->TabIndex = 6;
			this->cartaAbajo6->TabStop = false;
			this->cartaAbajo6->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo6_Click);
			// 
			// bazaAbajo7
			// 
			this->bazaAbajo7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo7.BackgroundImage")));
			this->bazaAbajo7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo7.Image")));
			this->bazaAbajo7->Location = System::Drawing::Point(323, 463);
			this->bazaAbajo7->Name = L"bazaAbajo7";
			this->bazaAbajo7->Size = System::Drawing::Size(43, 61);
			this->bazaAbajo7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo7->TabIndex = 58;
			this->bazaAbajo7->TabStop = false;
			this->bazaAbajo7->Visible = false;
			// 
			// bazaAbajo6
			// 
			this->bazaAbajo6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo6.Image")));
			this->bazaAbajo6->Location = System::Drawing::Point(314, 490);
			this->bazaAbajo6->Name = L"bazaAbajo6";
			this->bazaAbajo6->Size = System::Drawing::Size(61, 43);
			this->bazaAbajo6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo6->TabIndex = 57;
			this->bazaAbajo6->TabStop = false;
			this->bazaAbajo6->Visible = false;
			// 
			// bazaAbajo5
			// 
			this->bazaAbajo5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo5.BackgroundImage")));
			this->bazaAbajo5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo5.Image")));
			this->bazaAbajo5->Location = System::Drawing::Point(323, 481);
			this->bazaAbajo5->Name = L"bazaAbajo5";
			this->bazaAbajo5->Size = System::Drawing::Size(43, 61);
			this->bazaAbajo5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo5->TabIndex = 56;
			this->bazaAbajo5->TabStop = false;
			this->bazaAbajo5->Visible = false;
			// 
			// bazaAbajo4
			// 
			this->bazaAbajo4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo4.Image")));
			this->bazaAbajo4->Location = System::Drawing::Point(314, 511);
			this->bazaAbajo4->Name = L"bazaAbajo4";
			this->bazaAbajo4->Size = System::Drawing::Size(61, 43);
			this->bazaAbajo4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo4->TabIndex = 55;
			this->bazaAbajo4->TabStop = false;
			this->bazaAbajo4->Visible = false;
			// 
			// bazaAbajo3
			// 
			this->bazaAbajo3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo3.BackgroundImage")));
			this->bazaAbajo3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo3.Image")));
			this->bazaAbajo3->Location = System::Drawing::Point(323, 502);
			this->bazaAbajo3->Name = L"bazaAbajo3";
			this->bazaAbajo3->Size = System::Drawing::Size(43, 61);
			this->bazaAbajo3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo3->TabIndex = 54;
			this->bazaAbajo3->TabStop = false;
			this->bazaAbajo3->Visible = false;
			// 
			// bazaAbajo2
			// 
			this->bazaAbajo2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo2.Image")));
			this->bazaAbajo2->Location = System::Drawing::Point(314, 530);
			this->bazaAbajo2->Name = L"bazaAbajo2";
			this->bazaAbajo2->Size = System::Drawing::Size(61, 43);
			this->bazaAbajo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo2->TabIndex = 53;
			this->bazaAbajo2->TabStop = false;
			this->bazaAbajo2->Visible = false;
			// 
			// bazaAbajo1
			// 
			this->bazaAbajo1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo1.BackgroundImage")));
			this->bazaAbajo1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo1.Image")));
			this->bazaAbajo1->Location = System::Drawing::Point(323, 521);
			this->bazaAbajo1->Name = L"bazaAbajo1";
			this->bazaAbajo1->Size = System::Drawing::Size(43, 61);
			this->bazaAbajo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo1->TabIndex = 51;
			this->bazaAbajo1->TabStop = false;
			this->bazaAbajo1->Visible = false;
			// 
			// bazaAbajo0
			// 
			this->bazaAbajo0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaAbajo0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaAbajo0.Image")));
			this->bazaAbajo0->Location = System::Drawing::Point(314, 548);
			this->bazaAbajo0->Name = L"bazaAbajo0";
			this->bazaAbajo0->Size = System::Drawing::Size(61, 43);
			this->bazaAbajo0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaAbajo0->TabIndex = 52;
			this->bazaAbajo0->TabStop = false;
			this->bazaAbajo0->Visible = false;
			// 
			// bazaIzquierda7
			// 
			this->bazaIzquierda7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda7.Image")));
			this->bazaIzquierda7->Location = System::Drawing::Point(162, 319);
			this->bazaIzquierda7->Name = L"bazaIzquierda7";
			this->bazaIzquierda7->Size = System::Drawing::Size(61, 43);
			this->bazaIzquierda7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda7->TabIndex = 73;
			this->bazaIzquierda7->TabStop = false;
			this->bazaIzquierda7->Visible = false;
			// 
			// bazaIzquierda6
			// 
			this->bazaIzquierda6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda6.BackgroundImage")));
			this->bazaIzquierda6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda6.Image")));
			this->bazaIzquierda6->Location = System::Drawing::Point(152, 310);
			this->bazaIzquierda6->Name = L"bazaIzquierda6";
			this->bazaIzquierda6->Size = System::Drawing::Size(43, 61);
			this->bazaIzquierda6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda6->TabIndex = 71;
			this->bazaIzquierda6->TabStop = false;
			this->bazaIzquierda6->Visible = false;
			// 
			// bazaIzquierda5
			// 
			this->bazaIzquierda5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda5.Image")));
			this->bazaIzquierda5->Location = System::Drawing::Point(143, 319);
			this->bazaIzquierda5->Name = L"bazaIzquierda5";
			this->bazaIzquierda5->Size = System::Drawing::Size(61, 43);
			this->bazaIzquierda5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda5->TabIndex = 72;
			this->bazaIzquierda5->TabStop = false;
			this->bazaIzquierda5->Visible = false;
			// 
			// bazaIzquierda4
			// 
			this->bazaIzquierda4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda4.BackgroundImage")));
			this->bazaIzquierda4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda4.Image")));
			this->bazaIzquierda4->Location = System::Drawing::Point(131, 310);
			this->bazaIzquierda4->Name = L"bazaIzquierda4";
			this->bazaIzquierda4->Size = System::Drawing::Size(43, 61);
			this->bazaIzquierda4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda4->TabIndex = 70;
			this->bazaIzquierda4->TabStop = false;
			this->bazaIzquierda4->Visible = false;
			// 
			// bazaIzquierda3
			// 
			this->bazaIzquierda3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda3.Image")));
			this->bazaIzquierda3->Location = System::Drawing::Point(122, 319);
			this->bazaIzquierda3->Name = L"bazaIzquierda3";
			this->bazaIzquierda3->Size = System::Drawing::Size(61, 43);
			this->bazaIzquierda3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda3->TabIndex = 69;
			this->bazaIzquierda3->TabStop = false;
			this->bazaIzquierda3->Visible = false;
			// 
			// bazaIzquierda2
			// 
			this->bazaIzquierda2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda2.BackgroundImage")));
			this->bazaIzquierda2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda2.Image")));
			this->bazaIzquierda2->Location = System::Drawing::Point(113, 310);
			this->bazaIzquierda2->Name = L"bazaIzquierda2";
			this->bazaIzquierda2->Size = System::Drawing::Size(43, 61);
			this->bazaIzquierda2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda2->TabIndex = 68;
			this->bazaIzquierda2->TabStop = false;
			this->bazaIzquierda2->Visible = false;
			// 
			// bazaIzquierda1
			// 
			this->bazaIzquierda1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda1.Image")));
			this->bazaIzquierda1->Location = System::Drawing::Point(104, 319);
			this->bazaIzquierda1->Name = L"bazaIzquierda1";
			this->bazaIzquierda1->Size = System::Drawing::Size(61, 43);
			this->bazaIzquierda1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda1->TabIndex = 67;
			this->bazaIzquierda1->TabStop = false;
			this->bazaIzquierda1->Visible = false;
			// 
			// bazaIzquierda0
			// 
			this->bazaIzquierda0->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda0.BackgroundImage")));
			this->bazaIzquierda0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bazaIzquierda0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bazaIzquierda0.Image")));
			this->bazaIzquierda0->Location = System::Drawing::Point(94, 310);
			this->bazaIzquierda0->Name = L"bazaIzquierda0";
			this->bazaIzquierda0->Size = System::Drawing::Size(43, 61);
			this->bazaIzquierda0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bazaIzquierda0->TabIndex = 66;
			this->bazaIzquierda0->TabStop = false;
			this->bazaIzquierda0->Visible = false;
			// 
			// cartaAbajo7
			// 
			this->cartaAbajo7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cartaAbajo7->Location = System::Drawing::Point(486, 610);
			this->cartaAbajo7->Name = L"cartaAbajo7";
			this->cartaAbajo7->Size = System::Drawing::Size(40, 61);
			this->cartaAbajo7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cartaAbajo7->TabIndex = 74;
			this->cartaAbajo7->TabStop = false;
			this->cartaAbajo7->Click += gcnew System::EventHandler(this, &Form1::cartaAbajo7_Click);
			// 
			// zangaArribaDerecha
			// 
			this->zangaArribaDerecha->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"zangaArribaDerecha.BackgroundImage")));
			this->zangaArribaDerecha->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->zangaArribaDerecha->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"zangaArribaDerecha.Image")));
			this->zangaArribaDerecha->Location = System::Drawing::Point(508, 131);
			this->zangaArribaDerecha->Name = L"zangaArribaDerecha";
			this->zangaArribaDerecha->Size = System::Drawing::Size(43, 61);
			this->zangaArribaDerecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->zangaArribaDerecha->TabIndex = 75;
			this->zangaArribaDerecha->TabStop = false;
			this->zangaArribaDerecha->Visible = false;
			// 
			// zangaAbajoIzquierda
			// 
			this->zangaAbajoIzquierda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"zangaAbajoIzquierda.BackgroundImage")));
			this->zangaAbajoIzquierda->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->zangaAbajoIzquierda->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"zangaAbajoIzquierda.Image")));
			this->zangaAbajoIzquierda->Location = System::Drawing::Point(140, 493);
			this->zangaAbajoIzquierda->Name = L"zangaAbajoIzquierda";
			this->zangaAbajoIzquierda->Size = System::Drawing::Size(43, 61);
			this->zangaAbajoIzquierda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->zangaAbajoIzquierda->TabIndex = 76;
			this->zangaAbajoIzquierda->TabStop = false;
			this->zangaAbajoIzquierda->Visible = false;
			// 
			// piedraCentro28
			// 
			this->piedraCentro28->BackColor = System::Drawing::Color::Red;
			this->piedraCentro28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro28->Location = System::Drawing::Point(298, 319);
			this->piedraCentro28->Name = L"piedraCentro28";
			this->piedraCentro28->Size = System::Drawing::Size(6, 6);
			this->piedraCentro28->TabIndex = 77;
			this->piedraCentro28->TabStop = false;
			this->piedraCentro28->Visible = false;
			// 
			// piedraCentro20
			// 
			this->piedraCentro20->BackColor = System::Drawing::Color::Red;
			this->piedraCentro20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro20->Location = System::Drawing::Point(310, 319);
			this->piedraCentro20->Name = L"piedraCentro20";
			this->piedraCentro20->Size = System::Drawing::Size(6, 6);
			this->piedraCentro20->TabIndex = 78;
			this->piedraCentro20->TabStop = false;
			this->piedraCentro20->Visible = false;
			// 
			// piedraCentro12
			// 
			this->piedraCentro12->BackColor = System::Drawing::Color::Red;
			this->piedraCentro12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro12->Location = System::Drawing::Point(322, 319);
			this->piedraCentro12->Name = L"piedraCentro12";
			this->piedraCentro12->Size = System::Drawing::Size(6, 6);
			this->piedraCentro12->TabIndex = 79;
			this->piedraCentro12->TabStop = false;
			this->piedraCentro12->Visible = false;
			// 
			// piedraCentro8
			// 
			this->piedraCentro8->BackColor = System::Drawing::Color::Red;
			this->piedraCentro8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro8->Location = System::Drawing::Point(334, 319);
			this->piedraCentro8->Name = L"piedraCentro8";
			this->piedraCentro8->Size = System::Drawing::Size(6, 6);
			this->piedraCentro8->TabIndex = 80;
			this->piedraCentro8->TabStop = false;
			this->piedraCentro8->Visible = false;
			// 
			// piedraCentro0
			// 
			this->piedraCentro0->BackColor = System::Drawing::Color::Red;
			this->piedraCentro0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro0->Location = System::Drawing::Point(334, 331);
			this->piedraCentro0->Name = L"piedraCentro0";
			this->piedraCentro0->Size = System::Drawing::Size(6, 6);
			this->piedraCentro0->TabIndex = 84;
			this->piedraCentro0->TabStop = false;
			this->piedraCentro0->Visible = false;
			// 
			// piedraCentro4
			// 
			this->piedraCentro4->BackColor = System::Drawing::Color::Red;
			this->piedraCentro4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro4->Location = System::Drawing::Point(322, 331);
			this->piedraCentro4->Name = L"piedraCentro4";
			this->piedraCentro4->Size = System::Drawing::Size(6, 6);
			this->piedraCentro4->TabIndex = 83;
			this->piedraCentro4->TabStop = false;
			this->piedraCentro4->Visible = false;
			// 
			// piedraCentro16
			// 
			this->piedraCentro16->BackColor = System::Drawing::Color::Red;
			this->piedraCentro16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro16->Location = System::Drawing::Point(310, 331);
			this->piedraCentro16->Name = L"piedraCentro16";
			this->piedraCentro16->Size = System::Drawing::Size(6, 6);
			this->piedraCentro16->TabIndex = 82;
			this->piedraCentro16->TabStop = false;
			this->piedraCentro16->Visible = false;
			// 
			// piedraCentro24
			// 
			this->piedraCentro24->BackColor = System::Drawing::Color::Red;
			this->piedraCentro24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro24->Location = System::Drawing::Point(298, 331);
			this->piedraCentro24->Name = L"piedraCentro24";
			this->piedraCentro24->Size = System::Drawing::Size(6, 6);
			this->piedraCentro24->TabIndex = 81;
			this->piedraCentro24->TabStop = false;
			this->piedraCentro24->Visible = false;
			// 
			// piedraCentro10
			// 
			this->piedraCentro10->BackColor = System::Drawing::Color::Red;
			this->piedraCentro10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro10->Location = System::Drawing::Point(334, 355);
			this->piedraCentro10->Name = L"piedraCentro10";
			this->piedraCentro10->Size = System::Drawing::Size(6, 6);
			this->piedraCentro10->TabIndex = 92;
			this->piedraCentro10->TabStop = false;
			this->piedraCentro10->Visible = false;
			// 
			// piedraCentro14
			// 
			this->piedraCentro14->BackColor = System::Drawing::Color::Red;
			this->piedraCentro14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro14->Location = System::Drawing::Point(322, 355);
			this->piedraCentro14->Name = L"piedraCentro14";
			this->piedraCentro14->Size = System::Drawing::Size(6, 6);
			this->piedraCentro14->TabIndex = 91;
			this->piedraCentro14->TabStop = false;
			this->piedraCentro14->Visible = false;
			// 
			// piedraCentro22
			// 
			this->piedraCentro22->BackColor = System::Drawing::Color::Red;
			this->piedraCentro22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro22->Location = System::Drawing::Point(310, 355);
			this->piedraCentro22->Name = L"piedraCentro22";
			this->piedraCentro22->Size = System::Drawing::Size(6, 6);
			this->piedraCentro22->TabIndex = 90;
			this->piedraCentro22->TabStop = false;
			this->piedraCentro22->Visible = false;
			// 
			// piedraCentro30
			// 
			this->piedraCentro30->BackColor = System::Drawing::Color::Red;
			this->piedraCentro30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro30->Location = System::Drawing::Point(298, 355);
			this->piedraCentro30->Name = L"piedraCentro30";
			this->piedraCentro30->Size = System::Drawing::Size(6, 6);
			this->piedraCentro30->TabIndex = 89;
			this->piedraCentro30->TabStop = false;
			this->piedraCentro30->Visible = false;
			// 
			// piedraCentro2
			// 
			this->piedraCentro2->BackColor = System::Drawing::Color::Red;
			this->piedraCentro2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro2->Location = System::Drawing::Point(334, 343);
			this->piedraCentro2->Name = L"piedraCentro2";
			this->piedraCentro2->Size = System::Drawing::Size(6, 6);
			this->piedraCentro2->TabIndex = 88;
			this->piedraCentro2->TabStop = false;
			this->piedraCentro2->Visible = false;
			// 
			// piedraCentro5
			// 
			this->piedraCentro5->BackColor = System::Drawing::Color::Red;
			this->piedraCentro5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro5->Location = System::Drawing::Point(322, 343);
			this->piedraCentro5->Name = L"piedraCentro5";
			this->piedraCentro5->Size = System::Drawing::Size(6, 6);
			this->piedraCentro5->TabIndex = 87;
			this->piedraCentro5->TabStop = false;
			this->piedraCentro5->Visible = false;
			// 
			// piedraCentro17
			// 
			this->piedraCentro17->BackColor = System::Drawing::Color::Red;
			this->piedraCentro17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro17->Location = System::Drawing::Point(310, 343);
			this->piedraCentro17->Name = L"piedraCentro17";
			this->piedraCentro17->Size = System::Drawing::Size(6, 6);
			this->piedraCentro17->TabIndex = 86;
			this->piedraCentro17->TabStop = false;
			this->piedraCentro17->Visible = false;
			// 
			// piedraCentro25
			// 
			this->piedraCentro25->BackColor = System::Drawing::Color::Red;
			this->piedraCentro25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro25->Location = System::Drawing::Point(298, 343);
			this->piedraCentro25->Name = L"piedraCentro25";
			this->piedraCentro25->Size = System::Drawing::Size(6, 6);
			this->piedraCentro25->TabIndex = 85;
			this->piedraCentro25->TabStop = false;
			this->piedraCentro25->Visible = false;
			// 
			// piedraCentro31
			// 
			this->piedraCentro31->BackColor = System::Drawing::Color::Red;
			this->piedraCentro31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro31->Location = System::Drawing::Point(382, 355);
			this->piedraCentro31->Name = L"piedraCentro31";
			this->piedraCentro31->Size = System::Drawing::Size(6, 6);
			this->piedraCentro31->TabIndex = 108;
			this->piedraCentro31->TabStop = false;
			this->piedraCentro31->Visible = false;
			// 
			// piedraCentro23
			// 
			this->piedraCentro23->BackColor = System::Drawing::Color::Red;
			this->piedraCentro23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro23->Location = System::Drawing::Point(370, 355);
			this->piedraCentro23->Name = L"piedraCentro23";
			this->piedraCentro23->Size = System::Drawing::Size(6, 6);
			this->piedraCentro23->TabIndex = 107;
			this->piedraCentro23->TabStop = false;
			this->piedraCentro23->Visible = false;
			// 
			// piedraCentro15
			// 
			this->piedraCentro15->BackColor = System::Drawing::Color::Red;
			this->piedraCentro15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro15->Location = System::Drawing::Point(358, 355);
			this->piedraCentro15->Name = L"piedraCentro15";
			this->piedraCentro15->Size = System::Drawing::Size(6, 6);
			this->piedraCentro15->TabIndex = 106;
			this->piedraCentro15->TabStop = false;
			this->piedraCentro15->Visible = false;
			// 
			// piedraCentro11
			// 
			this->piedraCentro11->BackColor = System::Drawing::Color::Red;
			this->piedraCentro11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro11->Location = System::Drawing::Point(346, 355);
			this->piedraCentro11->Name = L"piedraCentro11";
			this->piedraCentro11->Size = System::Drawing::Size(6, 6);
			this->piedraCentro11->TabIndex = 105;
			this->piedraCentro11->TabStop = false;
			this->piedraCentro11->Visible = false;
			// 
			// piedraCentro27
			// 
			this->piedraCentro27->BackColor = System::Drawing::Color::Red;
			this->piedraCentro27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro27->Location = System::Drawing::Point(382, 343);
			this->piedraCentro27->Name = L"piedraCentro27";
			this->piedraCentro27->Size = System::Drawing::Size(6, 6);
			this->piedraCentro27->TabIndex = 104;
			this->piedraCentro27->TabStop = false;
			this->piedraCentro27->Visible = false;
			// 
			// piedraCentro19
			// 
			this->piedraCentro19->BackColor = System::Drawing::Color::Red;
			this->piedraCentro19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro19->Location = System::Drawing::Point(370, 343);
			this->piedraCentro19->Name = L"piedraCentro19";
			this->piedraCentro19->Size = System::Drawing::Size(6, 6);
			this->piedraCentro19->TabIndex = 103;
			this->piedraCentro19->TabStop = false;
			this->piedraCentro19->Visible = false;
			// 
			// piedraCentro7
			// 
			this->piedraCentro7->BackColor = System::Drawing::Color::Red;
			this->piedraCentro7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro7->Location = System::Drawing::Point(358, 343);
			this->piedraCentro7->Name = L"piedraCentro7";
			this->piedraCentro7->Size = System::Drawing::Size(6, 6);
			this->piedraCentro7->TabIndex = 102;
			this->piedraCentro7->TabStop = false;
			this->piedraCentro7->Visible = false;
			// 
			// piedraCentro3
			// 
			this->piedraCentro3->BackColor = System::Drawing::Color::Red;
			this->piedraCentro3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro3->Location = System::Drawing::Point(346, 343);
			this->piedraCentro3->Name = L"piedraCentro3";
			this->piedraCentro3->Size = System::Drawing::Size(6, 6);
			this->piedraCentro3->TabIndex = 101;
			this->piedraCentro3->TabStop = false;
			this->piedraCentro3->Visible = false;
			// 
			// piedraCentro26
			// 
			this->piedraCentro26->BackColor = System::Drawing::Color::Red;
			this->piedraCentro26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro26->Location = System::Drawing::Point(382, 331);
			this->piedraCentro26->Name = L"piedraCentro26";
			this->piedraCentro26->Size = System::Drawing::Size(6, 6);
			this->piedraCentro26->TabIndex = 100;
			this->piedraCentro26->TabStop = false;
			this->piedraCentro26->Visible = false;
			// 
			// piedraCentro18
			// 
			this->piedraCentro18->BackColor = System::Drawing::Color::Red;
			this->piedraCentro18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro18->Location = System::Drawing::Point(370, 331);
			this->piedraCentro18->Name = L"piedraCentro18";
			this->piedraCentro18->Size = System::Drawing::Size(6, 6);
			this->piedraCentro18->TabIndex = 99;
			this->piedraCentro18->TabStop = false;
			this->piedraCentro18->Visible = false;
			// 
			// piedraCentro6
			// 
			this->piedraCentro6->BackColor = System::Drawing::Color::Red;
			this->piedraCentro6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro6->Location = System::Drawing::Point(358, 331);
			this->piedraCentro6->Name = L"piedraCentro6";
			this->piedraCentro6->Size = System::Drawing::Size(6, 6);
			this->piedraCentro6->TabIndex = 98;
			this->piedraCentro6->TabStop = false;
			this->piedraCentro6->Visible = false;
			// 
			// piedraCentro1
			// 
			this->piedraCentro1->BackColor = System::Drawing::Color::Red;
			this->piedraCentro1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro1->Location = System::Drawing::Point(346, 331);
			this->piedraCentro1->Name = L"piedraCentro1";
			this->piedraCentro1->Size = System::Drawing::Size(6, 6);
			this->piedraCentro1->TabIndex = 97;
			this->piedraCentro1->TabStop = false;
			this->piedraCentro1->Visible = false;
			// 
			// piedraCentro29
			// 
			this->piedraCentro29->BackColor = System::Drawing::Color::Red;
			this->piedraCentro29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro29->Location = System::Drawing::Point(382, 319);
			this->piedraCentro29->Name = L"piedraCentro29";
			this->piedraCentro29->Size = System::Drawing::Size(6, 6);
			this->piedraCentro29->TabIndex = 96;
			this->piedraCentro29->TabStop = false;
			this->piedraCentro29->Visible = false;
			// 
			// piedraCentro21
			// 
			this->piedraCentro21->BackColor = System::Drawing::Color::Red;
			this->piedraCentro21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro21->Location = System::Drawing::Point(370, 319);
			this->piedraCentro21->Name = L"piedraCentro21";
			this->piedraCentro21->Size = System::Drawing::Size(6, 6);
			this->piedraCentro21->TabIndex = 95;
			this->piedraCentro21->TabStop = false;
			this->piedraCentro21->Visible = false;
			// 
			// piedraCentro13
			// 
			this->piedraCentro13->BackColor = System::Drawing::Color::Red;
			this->piedraCentro13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro13->Location = System::Drawing::Point(358, 319);
			this->piedraCentro13->Name = L"piedraCentro13";
			this->piedraCentro13->Size = System::Drawing::Size(6, 6);
			this->piedraCentro13->TabIndex = 94;
			this->piedraCentro13->TabStop = false;
			this->piedraCentro13->Visible = false;
			// 
			// piedraCentro9
			// 
			this->piedraCentro9->BackColor = System::Drawing::Color::Red;
			this->piedraCentro9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraCentro9->Location = System::Drawing::Point(346, 319);
			this->piedraCentro9->Name = L"piedraCentro9";
			this->piedraCentro9->Size = System::Drawing::Size(6, 6);
			this->piedraCentro9->TabIndex = 93;
			this->piedraCentro9->TabStop = false;
			this->piedraCentro9->Visible = false;
			// 
			// piedraDos31
			// 
			this->piedraDos31->BackColor = System::Drawing::Color::Red;
			this->piedraDos31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos31->Location = System::Drawing::Point(224, 167);
			this->piedraDos31->Name = L"piedraDos31";
			this->piedraDos31->Size = System::Drawing::Size(6, 6);
			this->piedraDos31->TabIndex = 140;
			this->piedraDos31->TabStop = false;
			this->piedraDos31->Visible = false;
			// 
			// piedraDos23
			// 
			this->piedraDos23->BackColor = System::Drawing::Color::Red;
			this->piedraDos23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos23->Location = System::Drawing::Point(212, 167);
			this->piedraDos23->Name = L"piedraDos23";
			this->piedraDos23->Size = System::Drawing::Size(6, 6);
			this->piedraDos23->TabIndex = 139;
			this->piedraDos23->TabStop = false;
			this->piedraDos23->Visible = false;
			// 
			// piedraDos15
			// 
			this->piedraDos15->BackColor = System::Drawing::Color::Red;
			this->piedraDos15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos15->Location = System::Drawing::Point(200, 167);
			this->piedraDos15->Name = L"piedraDos15";
			this->piedraDos15->Size = System::Drawing::Size(6, 6);
			this->piedraDos15->TabIndex = 138;
			this->piedraDos15->TabStop = false;
			this->piedraDos15->Visible = false;
			// 
			// piedraDos11
			// 
			this->piedraDos11->BackColor = System::Drawing::Color::Red;
			this->piedraDos11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos11->Location = System::Drawing::Point(188, 167);
			this->piedraDos11->Name = L"piedraDos11";
			this->piedraDos11->Size = System::Drawing::Size(6, 6);
			this->piedraDos11->TabIndex = 137;
			this->piedraDos11->TabStop = false;
			this->piedraDos11->Visible = false;
			// 
			// piedraDos27
			// 
			this->piedraDos27->BackColor = System::Drawing::Color::Red;
			this->piedraDos27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos27->Location = System::Drawing::Point(224, 155);
			this->piedraDos27->Name = L"piedraDos27";
			this->piedraDos27->Size = System::Drawing::Size(6, 6);
			this->piedraDos27->TabIndex = 136;
			this->piedraDos27->TabStop = false;
			this->piedraDos27->Visible = false;
			// 
			// piedraDos19
			// 
			this->piedraDos19->BackColor = System::Drawing::Color::Red;
			this->piedraDos19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos19->Location = System::Drawing::Point(212, 155);
			this->piedraDos19->Name = L"piedraDos19";
			this->piedraDos19->Size = System::Drawing::Size(6, 6);
			this->piedraDos19->TabIndex = 135;
			this->piedraDos19->TabStop = false;
			this->piedraDos19->Visible = false;
			// 
			// piedraDos7
			// 
			this->piedraDos7->BackColor = System::Drawing::Color::Red;
			this->piedraDos7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos7->Location = System::Drawing::Point(200, 155);
			this->piedraDos7->Name = L"piedraDos7";
			this->piedraDos7->Size = System::Drawing::Size(6, 6);
			this->piedraDos7->TabIndex = 134;
			this->piedraDos7->TabStop = false;
			this->piedraDos7->Visible = false;
			// 
			// piedraDos3
			// 
			this->piedraDos3->BackColor = System::Drawing::Color::Red;
			this->piedraDos3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos3->Location = System::Drawing::Point(188, 155);
			this->piedraDos3->Name = L"piedraDos3";
			this->piedraDos3->Size = System::Drawing::Size(6, 6);
			this->piedraDos3->TabIndex = 133;
			this->piedraDos3->TabStop = false;
			this->piedraDos3->Visible = false;
			// 
			// piedraDos26
			// 
			this->piedraDos26->BackColor = System::Drawing::Color::Red;
			this->piedraDos26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos26->Location = System::Drawing::Point(224, 143);
			this->piedraDos26->Name = L"piedraDos26";
			this->piedraDos26->Size = System::Drawing::Size(6, 6);
			this->piedraDos26->TabIndex = 132;
			this->piedraDos26->TabStop = false;
			this->piedraDos26->Visible = false;
			// 
			// piedraDos18
			// 
			this->piedraDos18->BackColor = System::Drawing::Color::Red;
			this->piedraDos18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos18->Location = System::Drawing::Point(212, 143);
			this->piedraDos18->Name = L"piedraDos18";
			this->piedraDos18->Size = System::Drawing::Size(6, 6);
			this->piedraDos18->TabIndex = 131;
			this->piedraDos18->TabStop = false;
			this->piedraDos18->Visible = false;
			// 
			// piedraDos6
			// 
			this->piedraDos6->BackColor = System::Drawing::Color::Red;
			this->piedraDos6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos6->Location = System::Drawing::Point(200, 143);
			this->piedraDos6->Name = L"piedraDos6";
			this->piedraDos6->Size = System::Drawing::Size(6, 6);
			this->piedraDos6->TabIndex = 130;
			this->piedraDos6->TabStop = false;
			this->piedraDos6->Visible = false;
			// 
			// piedraDos1
			// 
			this->piedraDos1->BackColor = System::Drawing::Color::Red;
			this->piedraDos1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos1->Location = System::Drawing::Point(188, 143);
			this->piedraDos1->Name = L"piedraDos1";
			this->piedraDos1->Size = System::Drawing::Size(6, 6);
			this->piedraDos1->TabIndex = 129;
			this->piedraDos1->TabStop = false;
			this->piedraDos1->Visible = false;
			// 
			// piedraDos29
			// 
			this->piedraDos29->BackColor = System::Drawing::Color::Red;
			this->piedraDos29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos29->Location = System::Drawing::Point(224, 131);
			this->piedraDos29->Name = L"piedraDos29";
			this->piedraDos29->Size = System::Drawing::Size(6, 6);
			this->piedraDos29->TabIndex = 128;
			this->piedraDos29->TabStop = false;
			this->piedraDos29->Visible = false;
			// 
			// piedraDos21
			// 
			this->piedraDos21->BackColor = System::Drawing::Color::Red;
			this->piedraDos21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos21->Location = System::Drawing::Point(212, 131);
			this->piedraDos21->Name = L"piedraDos21";
			this->piedraDos21->Size = System::Drawing::Size(6, 6);
			this->piedraDos21->TabIndex = 127;
			this->piedraDos21->TabStop = false;
			this->piedraDos21->Visible = false;
			// 
			// piedraDos13
			// 
			this->piedraDos13->BackColor = System::Drawing::Color::Red;
			this->piedraDos13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos13->Location = System::Drawing::Point(200, 131);
			this->piedraDos13->Name = L"piedraDos13";
			this->piedraDos13->Size = System::Drawing::Size(6, 6);
			this->piedraDos13->TabIndex = 126;
			this->piedraDos13->TabStop = false;
			this->piedraDos13->Visible = false;
			// 
			// piedraDos9
			// 
			this->piedraDos9->BackColor = System::Drawing::Color::Red;
			this->piedraDos9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos9->Location = System::Drawing::Point(188, 131);
			this->piedraDos9->Name = L"piedraDos9";
			this->piedraDos9->Size = System::Drawing::Size(6, 6);
			this->piedraDos9->TabIndex = 125;
			this->piedraDos9->TabStop = false;
			this->piedraDos9->Visible = false;
			// 
			// piedraDos10
			// 
			this->piedraDos10->BackColor = System::Drawing::Color::Red;
			this->piedraDos10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos10->Location = System::Drawing::Point(176, 167);
			this->piedraDos10->Name = L"piedraDos10";
			this->piedraDos10->Size = System::Drawing::Size(6, 6);
			this->piedraDos10->TabIndex = 124;
			this->piedraDos10->TabStop = false;
			this->piedraDos10->Visible = false;
			// 
			// piedraDos14
			// 
			this->piedraDos14->BackColor = System::Drawing::Color::Red;
			this->piedraDos14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos14->Location = System::Drawing::Point(164, 167);
			this->piedraDos14->Name = L"piedraDos14";
			this->piedraDos14->Size = System::Drawing::Size(6, 6);
			this->piedraDos14->TabIndex = 123;
			this->piedraDos14->TabStop = false;
			this->piedraDos14->Visible = false;
			// 
			// piedraDos22
			// 
			this->piedraDos22->BackColor = System::Drawing::Color::Red;
			this->piedraDos22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos22->Location = System::Drawing::Point(152, 167);
			this->piedraDos22->Name = L"piedraDos22";
			this->piedraDos22->Size = System::Drawing::Size(6, 6);
			this->piedraDos22->TabIndex = 122;
			this->piedraDos22->TabStop = false;
			this->piedraDos22->Visible = false;
			// 
			// piedraDos30
			// 
			this->piedraDos30->BackColor = System::Drawing::Color::Red;
			this->piedraDos30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos30->Location = System::Drawing::Point(140, 167);
			this->piedraDos30->Name = L"piedraDos30";
			this->piedraDos30->Size = System::Drawing::Size(6, 6);
			this->piedraDos30->TabIndex = 121;
			this->piedraDos30->TabStop = false;
			this->piedraDos30->Visible = false;
			// 
			// piedraDos2
			// 
			this->piedraDos2->BackColor = System::Drawing::Color::Red;
			this->piedraDos2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos2->Location = System::Drawing::Point(176, 155);
			this->piedraDos2->Name = L"piedraDos2";
			this->piedraDos2->Size = System::Drawing::Size(6, 6);
			this->piedraDos2->TabIndex = 120;
			this->piedraDos2->TabStop = false;
			this->piedraDos2->Visible = false;
			// 
			// piedraDos5
			// 
			this->piedraDos5->BackColor = System::Drawing::Color::Red;
			this->piedraDos5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos5->Location = System::Drawing::Point(164, 155);
			this->piedraDos5->Name = L"piedraDos5";
			this->piedraDos5->Size = System::Drawing::Size(6, 6);
			this->piedraDos5->TabIndex = 119;
			this->piedraDos5->TabStop = false;
			this->piedraDos5->Visible = false;
			// 
			// piedraDos17
			// 
			this->piedraDos17->BackColor = System::Drawing::Color::Red;
			this->piedraDos17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos17->Location = System::Drawing::Point(152, 155);
			this->piedraDos17->Name = L"piedraDos17";
			this->piedraDos17->Size = System::Drawing::Size(6, 6);
			this->piedraDos17->TabIndex = 118;
			this->piedraDos17->TabStop = false;
			this->piedraDos17->Visible = false;
			// 
			// piedraDos25
			// 
			this->piedraDos25->BackColor = System::Drawing::Color::Red;
			this->piedraDos25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos25->Location = System::Drawing::Point(140, 155);
			this->piedraDos25->Name = L"piedraDos25";
			this->piedraDos25->Size = System::Drawing::Size(6, 6);
			this->piedraDos25->TabIndex = 117;
			this->piedraDos25->TabStop = false;
			this->piedraDos25->Visible = false;
			// 
			// piedraDos0
			// 
			this->piedraDos0->BackColor = System::Drawing::Color::Red;
			this->piedraDos0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos0->Location = System::Drawing::Point(176, 143);
			this->piedraDos0->Name = L"piedraDos0";
			this->piedraDos0->Size = System::Drawing::Size(6, 6);
			this->piedraDos0->TabIndex = 116;
			this->piedraDos0->TabStop = false;
			this->piedraDos0->Visible = false;
			// 
			// piedraDos4
			// 
			this->piedraDos4->BackColor = System::Drawing::Color::Red;
			this->piedraDos4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos4->Location = System::Drawing::Point(164, 143);
			this->piedraDos4->Name = L"piedraDos4";
			this->piedraDos4->Size = System::Drawing::Size(6, 6);
			this->piedraDos4->TabIndex = 115;
			this->piedraDos4->TabStop = false;
			this->piedraDos4->Visible = false;
			// 
			// piedraDos16
			// 
			this->piedraDos16->BackColor = System::Drawing::Color::Red;
			this->piedraDos16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos16->Location = System::Drawing::Point(152, 143);
			this->piedraDos16->Name = L"piedraDos16";
			this->piedraDos16->Size = System::Drawing::Size(6, 6);
			this->piedraDos16->TabIndex = 114;
			this->piedraDos16->TabStop = false;
			this->piedraDos16->Visible = false;
			// 
			// piedraDos24
			// 
			this->piedraDos24->BackColor = System::Drawing::Color::Red;
			this->piedraDos24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos24->Location = System::Drawing::Point(140, 143);
			this->piedraDos24->Name = L"piedraDos24";
			this->piedraDos24->Size = System::Drawing::Size(6, 6);
			this->piedraDos24->TabIndex = 113;
			this->piedraDos24->TabStop = false;
			this->piedraDos24->Visible = false;
			// 
			// piedraDos8
			// 
			this->piedraDos8->BackColor = System::Drawing::Color::Red;
			this->piedraDos8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos8->Location = System::Drawing::Point(176, 131);
			this->piedraDos8->Name = L"piedraDos8";
			this->piedraDos8->Size = System::Drawing::Size(6, 6);
			this->piedraDos8->TabIndex = 112;
			this->piedraDos8->TabStop = false;
			this->piedraDos8->Visible = false;
			// 
			// piedraDos12
			// 
			this->piedraDos12->BackColor = System::Drawing::Color::Red;
			this->piedraDos12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos12->Location = System::Drawing::Point(164, 131);
			this->piedraDos12->Name = L"piedraDos12";
			this->piedraDos12->Size = System::Drawing::Size(6, 6);
			this->piedraDos12->TabIndex = 111;
			this->piedraDos12->TabStop = false;
			this->piedraDos12->Visible = false;
			// 
			// piedraDos20
			// 
			this->piedraDos20->BackColor = System::Drawing::Color::Red;
			this->piedraDos20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos20->Location = System::Drawing::Point(152, 131);
			this->piedraDos20->Name = L"piedraDos20";
			this->piedraDos20->Size = System::Drawing::Size(6, 6);
			this->piedraDos20->TabIndex = 110;
			this->piedraDos20->TabStop = false;
			this->piedraDos20->Visible = false;
			// 
			// piedraDos28
			// 
			this->piedraDos28->BackColor = System::Drawing::Color::Red;
			this->piedraDos28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraDos28->Location = System::Drawing::Point(140, 131);
			this->piedraDos28->Name = L"piedraDos28";
			this->piedraDos28->Size = System::Drawing::Size(6, 6);
			this->piedraDos28->TabIndex = 109;
			this->piedraDos28->TabStop = false;
			this->piedraDos28->Visible = false;
			// 
			// piedraUno31
			// 
			this->piedraUno31->BackColor = System::Drawing::Color::Red;
			this->piedraUno31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno31->Location = System::Drawing::Point(545, 548);
			this->piedraUno31->Name = L"piedraUno31";
			this->piedraUno31->Size = System::Drawing::Size(6, 6);
			this->piedraUno31->TabIndex = 172;
			this->piedraUno31->TabStop = false;
			this->piedraUno31->Visible = false;
			// 
			// piedraUno23
			// 
			this->piedraUno23->BackColor = System::Drawing::Color::Red;
			this->piedraUno23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno23->Location = System::Drawing::Point(533, 548);
			this->piedraUno23->Name = L"piedraUno23";
			this->piedraUno23->Size = System::Drawing::Size(6, 6);
			this->piedraUno23->TabIndex = 171;
			this->piedraUno23->TabStop = false;
			this->piedraUno23->Visible = false;
			// 
			// piedraUno15
			// 
			this->piedraUno15->BackColor = System::Drawing::Color::Red;
			this->piedraUno15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno15->Location = System::Drawing::Point(521, 548);
			this->piedraUno15->Name = L"piedraUno15";
			this->piedraUno15->Size = System::Drawing::Size(6, 6);
			this->piedraUno15->TabIndex = 170;
			this->piedraUno15->TabStop = false;
			this->piedraUno15->Visible = false;
			// 
			// piedraUno11
			// 
			this->piedraUno11->BackColor = System::Drawing::Color::Red;
			this->piedraUno11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno11->Location = System::Drawing::Point(509, 548);
			this->piedraUno11->Name = L"piedraUno11";
			this->piedraUno11->Size = System::Drawing::Size(6, 6);
			this->piedraUno11->TabIndex = 169;
			this->piedraUno11->TabStop = false;
			this->piedraUno11->Visible = false;
			// 
			// piedraUno27
			// 
			this->piedraUno27->BackColor = System::Drawing::Color::Red;
			this->piedraUno27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno27->Location = System::Drawing::Point(545, 536);
			this->piedraUno27->Name = L"piedraUno27";
			this->piedraUno27->Size = System::Drawing::Size(6, 6);
			this->piedraUno27->TabIndex = 168;
			this->piedraUno27->TabStop = false;
			this->piedraUno27->Visible = false;
			// 
			// piedraUno19
			// 
			this->piedraUno19->BackColor = System::Drawing::Color::Red;
			this->piedraUno19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno19->Location = System::Drawing::Point(533, 536);
			this->piedraUno19->Name = L"piedraUno19";
			this->piedraUno19->Size = System::Drawing::Size(6, 6);
			this->piedraUno19->TabIndex = 167;
			this->piedraUno19->TabStop = false;
			this->piedraUno19->Visible = false;
			// 
			// piedraUno7
			// 
			this->piedraUno7->BackColor = System::Drawing::Color::Red;
			this->piedraUno7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno7->Location = System::Drawing::Point(521, 536);
			this->piedraUno7->Name = L"piedraUno7";
			this->piedraUno7->Size = System::Drawing::Size(6, 6);
			this->piedraUno7->TabIndex = 166;
			this->piedraUno7->TabStop = false;
			this->piedraUno7->Visible = false;
			// 
			// piedraUno3
			// 
			this->piedraUno3->BackColor = System::Drawing::Color::Red;
			this->piedraUno3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno3->Location = System::Drawing::Point(509, 536);
			this->piedraUno3->Name = L"piedraUno3";
			this->piedraUno3->Size = System::Drawing::Size(6, 6);
			this->piedraUno3->TabIndex = 165;
			this->piedraUno3->TabStop = false;
			this->piedraUno3->Visible = false;
			// 
			// piedraUno26
			// 
			this->piedraUno26->BackColor = System::Drawing::Color::Red;
			this->piedraUno26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno26->Location = System::Drawing::Point(545, 524);
			this->piedraUno26->Name = L"piedraUno26";
			this->piedraUno26->Size = System::Drawing::Size(6, 6);
			this->piedraUno26->TabIndex = 164;
			this->piedraUno26->TabStop = false;
			this->piedraUno26->Visible = false;
			// 
			// piedraUno18
			// 
			this->piedraUno18->BackColor = System::Drawing::Color::Red;
			this->piedraUno18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno18->Location = System::Drawing::Point(533, 524);
			this->piedraUno18->Name = L"piedraUno18";
			this->piedraUno18->Size = System::Drawing::Size(6, 6);
			this->piedraUno18->TabIndex = 163;
			this->piedraUno18->TabStop = false;
			this->piedraUno18->Visible = false;
			// 
			// piedraUno6
			// 
			this->piedraUno6->BackColor = System::Drawing::Color::Red;
			this->piedraUno6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno6->Location = System::Drawing::Point(521, 524);
			this->piedraUno6->Name = L"piedraUno6";
			this->piedraUno6->Size = System::Drawing::Size(6, 6);
			this->piedraUno6->TabIndex = 162;
			this->piedraUno6->TabStop = false;
			this->piedraUno6->Visible = false;
			// 
			// piedraUno1
			// 
			this->piedraUno1->BackColor = System::Drawing::Color::Red;
			this->piedraUno1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno1->Location = System::Drawing::Point(509, 524);
			this->piedraUno1->Name = L"piedraUno1";
			this->piedraUno1->Size = System::Drawing::Size(6, 6);
			this->piedraUno1->TabIndex = 161;
			this->piedraUno1->TabStop = false;
			this->piedraUno1->Visible = false;
			// 
			// piedraUno29
			// 
			this->piedraUno29->BackColor = System::Drawing::Color::Red;
			this->piedraUno29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno29->Location = System::Drawing::Point(545, 512);
			this->piedraUno29->Name = L"piedraUno29";
			this->piedraUno29->Size = System::Drawing::Size(6, 6);
			this->piedraUno29->TabIndex = 160;
			this->piedraUno29->TabStop = false;
			this->piedraUno29->Visible = false;
			// 
			// piedraUno21
			// 
			this->piedraUno21->BackColor = System::Drawing::Color::Red;
			this->piedraUno21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno21->Location = System::Drawing::Point(533, 512);
			this->piedraUno21->Name = L"piedraUno21";
			this->piedraUno21->Size = System::Drawing::Size(6, 6);
			this->piedraUno21->TabIndex = 159;
			this->piedraUno21->TabStop = false;
			this->piedraUno21->Visible = false;
			// 
			// piedraUno13
			// 
			this->piedraUno13->BackColor = System::Drawing::Color::Red;
			this->piedraUno13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno13->Location = System::Drawing::Point(521, 512);
			this->piedraUno13->Name = L"piedraUno13";
			this->piedraUno13->Size = System::Drawing::Size(6, 6);
			this->piedraUno13->TabIndex = 158;
			this->piedraUno13->TabStop = false;
			this->piedraUno13->Visible = false;
			// 
			// piedraUno9
			// 
			this->piedraUno9->BackColor = System::Drawing::Color::Red;
			this->piedraUno9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno9->Location = System::Drawing::Point(509, 512);
			this->piedraUno9->Name = L"piedraUno9";
			this->piedraUno9->Size = System::Drawing::Size(6, 6);
			this->piedraUno9->TabIndex = 157;
			this->piedraUno9->TabStop = false;
			this->piedraUno9->Visible = false;
			// 
			// piedraUno10
			// 
			this->piedraUno10->BackColor = System::Drawing::Color::Red;
			this->piedraUno10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno10->Location = System::Drawing::Point(497, 548);
			this->piedraUno10->Name = L"piedraUno10";
			this->piedraUno10->Size = System::Drawing::Size(6, 6);
			this->piedraUno10->TabIndex = 156;
			this->piedraUno10->TabStop = false;
			this->piedraUno10->Visible = false;
			// 
			// piedraUno14
			// 
			this->piedraUno14->BackColor = System::Drawing::Color::Red;
			this->piedraUno14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno14->Location = System::Drawing::Point(485, 548);
			this->piedraUno14->Name = L"piedraUno14";
			this->piedraUno14->Size = System::Drawing::Size(6, 6);
			this->piedraUno14->TabIndex = 155;
			this->piedraUno14->TabStop = false;
			this->piedraUno14->Visible = false;
			// 
			// piedraUno22
			// 
			this->piedraUno22->BackColor = System::Drawing::Color::Red;
			this->piedraUno22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno22->Location = System::Drawing::Point(473, 548);
			this->piedraUno22->Name = L"piedraUno22";
			this->piedraUno22->Size = System::Drawing::Size(6, 6);
			this->piedraUno22->TabIndex = 154;
			this->piedraUno22->TabStop = false;
			this->piedraUno22->Visible = false;
			// 
			// piedraUno30
			// 
			this->piedraUno30->BackColor = System::Drawing::Color::Red;
			this->piedraUno30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno30->Location = System::Drawing::Point(461, 548);
			this->piedraUno30->Name = L"piedraUno30";
			this->piedraUno30->Size = System::Drawing::Size(6, 6);
			this->piedraUno30->TabIndex = 153;
			this->piedraUno30->TabStop = false;
			this->piedraUno30->Visible = false;
			// 
			// piedraUno2
			// 
			this->piedraUno2->BackColor = System::Drawing::Color::Red;
			this->piedraUno2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno2->Location = System::Drawing::Point(497, 536);
			this->piedraUno2->Name = L"piedraUno2";
			this->piedraUno2->Size = System::Drawing::Size(6, 6);
			this->piedraUno2->TabIndex = 152;
			this->piedraUno2->TabStop = false;
			this->piedraUno2->Visible = false;
			// 
			// piedraUno5
			// 
			this->piedraUno5->BackColor = System::Drawing::Color::Red;
			this->piedraUno5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno5->Location = System::Drawing::Point(485, 536);
			this->piedraUno5->Name = L"piedraUno5";
			this->piedraUno5->Size = System::Drawing::Size(6, 6);
			this->piedraUno5->TabIndex = 151;
			this->piedraUno5->TabStop = false;
			this->piedraUno5->Visible = false;
			// 
			// piedraUno17
			// 
			this->piedraUno17->BackColor = System::Drawing::Color::Red;
			this->piedraUno17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno17->Location = System::Drawing::Point(473, 536);
			this->piedraUno17->Name = L"piedraUno17";
			this->piedraUno17->Size = System::Drawing::Size(6, 6);
			this->piedraUno17->TabIndex = 150;
			this->piedraUno17->TabStop = false;
			this->piedraUno17->Visible = false;
			// 
			// piedraUno25
			// 
			this->piedraUno25->BackColor = System::Drawing::Color::Red;
			this->piedraUno25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno25->Location = System::Drawing::Point(461, 536);
			this->piedraUno25->Name = L"piedraUno25";
			this->piedraUno25->Size = System::Drawing::Size(6, 6);
			this->piedraUno25->TabIndex = 149;
			this->piedraUno25->TabStop = false;
			this->piedraUno25->Visible = false;
			// 
			// piedraUno0
			// 
			this->piedraUno0->BackColor = System::Drawing::Color::Red;
			this->piedraUno0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno0->Location = System::Drawing::Point(497, 524);
			this->piedraUno0->Name = L"piedraUno0";
			this->piedraUno0->Size = System::Drawing::Size(6, 6);
			this->piedraUno0->TabIndex = 148;
			this->piedraUno0->TabStop = false;
			this->piedraUno0->Visible = false;
			// 
			// piedraUno4
			// 
			this->piedraUno4->BackColor = System::Drawing::Color::Red;
			this->piedraUno4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno4->Location = System::Drawing::Point(485, 524);
			this->piedraUno4->Name = L"piedraUno4";
			this->piedraUno4->Size = System::Drawing::Size(6, 6);
			this->piedraUno4->TabIndex = 147;
			this->piedraUno4->TabStop = false;
			this->piedraUno4->Visible = false;
			// 
			// piedraUno16
			// 
			this->piedraUno16->BackColor = System::Drawing::Color::Red;
			this->piedraUno16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno16->Location = System::Drawing::Point(473, 524);
			this->piedraUno16->Name = L"piedraUno16";
			this->piedraUno16->Size = System::Drawing::Size(6, 6);
			this->piedraUno16->TabIndex = 146;
			this->piedraUno16->TabStop = false;
			this->piedraUno16->Visible = false;
			// 
			// piedraUno24
			// 
			this->piedraUno24->BackColor = System::Drawing::Color::Red;
			this->piedraUno24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno24->Location = System::Drawing::Point(461, 524);
			this->piedraUno24->Name = L"piedraUno24";
			this->piedraUno24->Size = System::Drawing::Size(6, 6);
			this->piedraUno24->TabIndex = 145;
			this->piedraUno24->TabStop = false;
			this->piedraUno24->Visible = false;
			// 
			// piedraUno8
			// 
			this->piedraUno8->BackColor = System::Drawing::Color::Red;
			this->piedraUno8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno8->Location = System::Drawing::Point(497, 512);
			this->piedraUno8->Name = L"piedraUno8";
			this->piedraUno8->Size = System::Drawing::Size(6, 6);
			this->piedraUno8->TabIndex = 144;
			this->piedraUno8->TabStop = false;
			this->piedraUno8->Visible = false;
			// 
			// piedraUno12
			// 
			this->piedraUno12->BackColor = System::Drawing::Color::Red;
			this->piedraUno12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno12->Location = System::Drawing::Point(485, 512);
			this->piedraUno12->Name = L"piedraUno12";
			this->piedraUno12->Size = System::Drawing::Size(6, 6);
			this->piedraUno12->TabIndex = 143;
			this->piedraUno12->TabStop = false;
			this->piedraUno12->Visible = false;
			// 
			// piedraUno20
			// 
			this->piedraUno20->BackColor = System::Drawing::Color::Red;
			this->piedraUno20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno20->Location = System::Drawing::Point(473, 512);
			this->piedraUno20->Name = L"piedraUno20";
			this->piedraUno20->Size = System::Drawing::Size(6, 6);
			this->piedraUno20->TabIndex = 142;
			this->piedraUno20->TabStop = false;
			this->piedraUno20->Visible = false;
			// 
			// piedraUno28
			// 
			this->piedraUno28->BackColor = System::Drawing::Color::Red;
			this->piedraUno28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piedraUno28->Location = System::Drawing::Point(461, 512);
			this->piedraUno28->Name = L"piedraUno28";
			this->piedraUno28->Size = System::Drawing::Size(6, 6);
			this->piedraUno28->TabIndex = 141;
			this->piedraUno28->TabStop = false;
			this->piedraUno28->Visible = false;
			// 
			// botonComenzar
			// 
			this->botonComenzar->Location = System::Drawing::Point(719, 632);
			this->botonComenzar->Name = L"botonComenzar";
			this->botonComenzar->Size = System::Drawing::Size(94, 39);
			this->botonComenzar->TabIndex = 1;
			this->botonComenzar->Text = L"Comenzar";
			this->botonComenzar->UseVisualStyleBackColor = true;
			this->botonComenzar->Click += gcnew System::EventHandler(this, &Form1::botonComenzar_Click);
			// 
			// botonSalir
			// 
			this->botonSalir->Location = System::Drawing::Point(829, 632);
			this->botonSalir->Name = L"botonSalir";
			this->botonSalir->Size = System::Drawing::Size(94, 39);
			this->botonSalir->TabIndex = 2;
			this->botonSalir->Text = L"Salir";
			this->botonSalir->UseVisualStyleBackColor = true;
			this->botonSalir->Click += gcnew System::EventHandler(this, &Form1::botonSalir_Click);
			// 
			// salida
			// 
			this->salida->BackColor = System::Drawing::SystemColors::Control;
			this->salida->Location = System::Drawing::Point(719, 494);
			this->salida->Multiline = true;
			this->salida->Name = L"salida";
			this->salida->ReadOnly = true;
			this->salida->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->salida->Size = System::Drawing::Size(204, 113);
			this->salida->TabIndex = 175;
			this->salida->TabStop = false;
			// 
			// panelTriunfa
			// 
			this->panelTriunfa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTriunfa->Controls->Add(this->labelTriunfa);
			this->panelTriunfa->Controls->Add(this->labelTriunfa2);
			this->panelTriunfa->Location = System::Drawing::Point(719, 191);
			this->panelTriunfa->Name = L"panelTriunfa";
			this->panelTriunfa->Size = System::Drawing::Size(204, 76);
			this->panelTriunfa->TabIndex = 177;
			// 
			// labelTriunfa
			// 
			this->labelTriunfa->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTriunfa->Location = System::Drawing::Point(3, 44);
			this->labelTriunfa->Name = L"labelTriunfa";
			this->labelTriunfa->Size = System::Drawing::Size(187, 26);
			this->labelTriunfa->TabIndex = 1;
			this->labelTriunfa->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelTriunfa2
			// 
			this->labelTriunfa2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTriunfa2->Location = System::Drawing::Point(11, 10);
			this->labelTriunfa2->Name = L"labelTriunfa2";
			this->labelTriunfa2->Size = System::Drawing::Size(190, 26);
			this->labelTriunfa2->TabIndex = 0;
			this->labelTriunfa2->Text = L"Triunfa";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->labelProximoMano);
			this->panel4->Controls->Add(this->labelProximoMano2);
			this->panel4->Location = System::Drawing::Point(719, 292);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(204, 76);
			this->panel4->TabIndex = 178;
			// 
			// labelProximoMano
			// 
			this->labelProximoMano->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelProximoMano->ForeColor = System::Drawing::Color::Black;
			this->labelProximoMano->Location = System::Drawing::Point(3, 44);
			this->labelProximoMano->Name = L"labelProximoMano";
			this->labelProximoMano->Size = System::Drawing::Size(187, 26);
			this->labelProximoMano->TabIndex = 1;
			this->labelProximoMano->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelProximoMano2
			// 
			this->labelProximoMano2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelProximoMano2->Location = System::Drawing::Point(11, 10);
			this->labelProximoMano2->Name = L"labelProximoMano2";
			this->labelProximoMano2->Size = System::Drawing::Size(190, 26);
			this->labelProximoMano2->TabIndex = 0;
			this->labelProximoMano2->Text = L"Próximo Mano";
			// 
			// panelSePidio
			// 
			this->panelSePidio->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelSePidio->Controls->Add(this->checkBoxSolo);
			this->panelSePidio->Controls->Add(this->checkBoxCinco);
			this->panelSePidio->Controls->Add(this->checkBoxTodas);
			this->panelSePidio->Controls->Add(this->labelSePidio);
			this->panelSePidio->Location = System::Drawing::Point(719, 393);
			this->panelSePidio->Name = L"panelSePidio";
			this->panelSePidio->Size = System::Drawing::Size(204, 76);
			this->panelSePidio->TabIndex = 179;
			// 
			// checkBoxSolo
			// 
			this->checkBoxSolo->AutoCheck = false;
			this->checkBoxSolo->AutoSize = true;
			this->checkBoxSolo->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->checkBoxSolo->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::Control;
			this->checkBoxSolo->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Control;
			this->checkBoxSolo->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->checkBoxSolo->Location = System::Drawing::Point(31, 46);
			this->checkBoxSolo->Name = L"checkBoxSolo";
			this->checkBoxSolo->Size = System::Drawing::Size(47, 17);
			this->checkBoxSolo->TabIndex = 3;
			this->checkBoxSolo->Text = L"Solo";
			this->checkBoxSolo->UseVisualStyleBackColor = true;
			// 
			// checkBoxCinco
			// 
			this->checkBoxCinco->AutoCheck = false;
			this->checkBoxCinco->AutoSize = true;
			this->checkBoxCinco->Location = System::Drawing::Point(84, 46);
			this->checkBoxCinco->Name = L"checkBoxCinco";
			this->checkBoxCinco->Size = System::Drawing::Size(53, 17);
			this->checkBoxCinco->TabIndex = 2;
			this->checkBoxCinco->Text = L"Cinco";
			this->checkBoxCinco->UseVisualStyleBackColor = true;
			// 
			// checkBoxTodas
			// 
			this->checkBoxTodas->AutoCheck = false;
			this->checkBoxTodas->AutoSize = true;
			this->checkBoxTodas->Location = System::Drawing::Point(143, 46);
			this->checkBoxTodas->Name = L"checkBoxTodas";
			this->checkBoxTodas->Size = System::Drawing::Size(56, 17);
			this->checkBoxTodas->TabIndex = 1;
			this->checkBoxTodas->Text = L"Todas";
			this->checkBoxTodas->UseVisualStyleBackColor = true;
			// 
			// labelSePidio
			// 
			this->labelSePidio->Font = (gcnew System::Drawing::Font(L"Cooper Black", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelSePidio->Location = System::Drawing::Point(11, 10);
			this->labelSePidio->Name = L"labelSePidio";
			this->labelSePidio->Size = System::Drawing::Size(190, 30);
			this->labelSePidio->TabIndex = 0;
			this->labelSePidio->Text = L"Se pidió...";
			// 
			// labelTriunfos2
			// 
			this->labelTriunfos2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTriunfos2->Location = System::Drawing::Point(11, 10);
			this->labelTriunfos2->Name = L"labelTriunfos2";
			this->labelTriunfos2->Size = System::Drawing::Size(190, 26);
			this->labelTriunfos2->TabIndex = 0;
			this->labelTriunfos2->Text = L"Triunfos";
			// 
			// labelTriunfos
			// 
			this->labelTriunfos->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTriunfos->ForeColor = System::Drawing::Color::Green;
			this->labelTriunfos->Location = System::Drawing::Point(3, 44);
			this->labelTriunfos->Name = L"labelTriunfos";
			this->labelTriunfos->Size = System::Drawing::Size(187, 26);
			this->labelTriunfos->TabIndex = 1;
			this->labelTriunfos->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panelTriunfos
			// 
			this->panelTriunfos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTriunfos->Controls->Add(this->labelTriunfos);
			this->panelTriunfos->Controls->Add(this->labelTriunfos2);
			this->panelTriunfos->Location = System::Drawing::Point(719, 90);
			this->panelTriunfos->Name = L"panelTriunfos";
			this->panelTriunfos->Size = System::Drawing::Size(204, 76);
			this->panelTriunfos->TabIndex = 176;
			// 
			// imagenBaraja0
			// 
			this->imagenBaraja0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagenBaraja0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja0.Image")));
			this->imagenBaraja0->Location = System::Drawing::Point(314, 511);
			this->imagenBaraja0->Name = L"imagenBaraja0";
			this->imagenBaraja0->Size = System::Drawing::Size(61, 43);
			this->imagenBaraja0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imagenBaraja0->TabIndex = 180;
			this->imagenBaraja0->TabStop = false;
			this->imagenBaraja0->Visible = false;
			// 
			// imagenBaraja2
			// 
			this->imagenBaraja2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagenBaraja2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja2.Image")));
			this->imagenBaraja2->Location = System::Drawing::Point(314, 131);
			this->imagenBaraja2->Name = L"imagenBaraja2";
			this->imagenBaraja2->Size = System::Drawing::Size(61, 43);
			this->imagenBaraja2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imagenBaraja2->TabIndex = 181;
			this->imagenBaraja2->TabStop = false;
			this->imagenBaraja2->Visible = false;
			// 
			// imagenBaraja3
			// 
			this->imagenBaraja3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja3.BackgroundImage")));
			this->imagenBaraja3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagenBaraja3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja3.Image")));
			this->imagenBaraja3->Location = System::Drawing::Point(131, 309);
			this->imagenBaraja3->Name = L"imagenBaraja3";
			this->imagenBaraja3->Size = System::Drawing::Size(43, 61);
			this->imagenBaraja3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imagenBaraja3->TabIndex = 182;
			this->imagenBaraja3->TabStop = false;
			this->imagenBaraja3->Visible = false;
			// 
			// imagenBaraja1
			// 
			this->imagenBaraja1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja1.BackgroundImage")));
			this->imagenBaraja1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagenBaraja1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imagenBaraja1.Image")));
			this->imagenBaraja1->Location = System::Drawing::Point(508, 309);
			this->imagenBaraja1->Name = L"imagenBaraja1";
			this->imagenBaraja1->Size = System::Drawing::Size(43, 61);
			this->imagenBaraja1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imagenBaraja1->TabIndex = 183;
			this->imagenBaraja1->TabStop = false;
			this->imagenBaraja1->Visible = false;
			// 
			// barajaCortar0
			// 
			this->barajaCortar0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->barajaCortar0->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar0.Image")));
			this->barajaCortar0->Location = System::Drawing::Point(314, 453);
			this->barajaCortar0->Name = L"barajaCortar0";
			this->barajaCortar0->Size = System::Drawing::Size(61, 43);
			this->barajaCortar0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->barajaCortar0->TabIndex = 184;
			this->barajaCortar0->TabStop = false;
			this->barajaCortar0->Visible = false;
			// 
			// barajaCortar2
			// 
			this->barajaCortar2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->barajaCortar2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar2.Image")));
			this->barajaCortar2->Location = System::Drawing::Point(314, 188);
			this->barajaCortar2->Name = L"barajaCortar2";
			this->barajaCortar2->Size = System::Drawing::Size(61, 43);
			this->barajaCortar2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->barajaCortar2->TabIndex = 185;
			this->barajaCortar2->TabStop = false;
			this->barajaCortar2->Visible = false;
			// 
			// barajaCortar3
			// 
			this->barajaCortar3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar3.BackgroundImage")));
			this->barajaCortar3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->barajaCortar3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar3.Image")));
			this->barajaCortar3->Location = System::Drawing::Point(187, 309);
			this->barajaCortar3->Name = L"barajaCortar3";
			this->barajaCortar3->Size = System::Drawing::Size(43, 61);
			this->barajaCortar3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->barajaCortar3->TabIndex = 186;
			this->barajaCortar3->TabStop = false;
			this->barajaCortar3->Visible = false;
			// 
			// barajaCortar1
			// 
			this->barajaCortar1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar1.BackgroundImage")));
			this->barajaCortar1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->barajaCortar1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"barajaCortar1.Image")));
			this->barajaCortar1->Location = System::Drawing::Point(448, 309);
			this->barajaCortar1->Name = L"barajaCortar1";
			this->barajaCortar1->Size = System::Drawing::Size(43, 61);
			this->barajaCortar1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->barajaCortar1->TabIndex = 187;
			this->barajaCortar1->TabStop = false;
			this->barajaCortar1->Visible = false;
			// 
			// labelPiedras2
			// 
			this->labelPiedras2->ForeColor = System::Drawing::Color::White;
			this->labelPiedras2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"labelPiedras2.Image")));
			this->labelPiedras2->Location = System::Drawing::Point(167, 179);
			this->labelPiedras2->Name = L"labelPiedras2";
			this->labelPiedras2->Size = System::Drawing::Size(39, 20);
			this->labelPiedras2->TabIndex = 188;
			this->labelPiedras2->Text = L"16";
			this->labelPiedras2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelPiedras2->Visible = false;
			// 
			// labelPiedras1
			// 
			this->labelPiedras1->ForeColor = System::Drawing::Color::White;
			this->labelPiedras1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"labelPiedras1.Image")));
			this->labelPiedras1->Location = System::Drawing::Point(486, 562);
			this->labelPiedras1->Name = L"labelPiedras1";
			this->labelPiedras1->Size = System::Drawing::Size(39, 20);
			this->labelPiedras1->TabIndex = 189;
			this->labelPiedras1->Text = L"16";
			this->labelPiedras1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelPiedras1->Visible = false;
			// 
			// labelPiedrasCentro
			// 
			this->labelPiedrasCentro->ForeColor = System::Drawing::Color::White;
			this->labelPiedrasCentro->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"labelPiedrasCentro.Image")));
			this->labelPiedrasCentro->Location = System::Drawing::Point(325, 367);
			this->labelPiedrasCentro->Name = L"labelPiedrasCentro";
			this->labelPiedrasCentro->Size = System::Drawing::Size(39, 20);
			this->labelPiedrasCentro->TabIndex = 190;
			this->labelPiedrasCentro->Text = L"16";
			this->labelPiedrasCentro->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelPiedrasCentro->Visible = false;
			// 
			// labelBazas2
			// 
			this->labelBazas2->ForeColor = System::Drawing::Color::White;
			this->labelBazas2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"labelBazas2.Image")));
			this->labelBazas2->Location = System::Drawing::Point(98, 376);
			this->labelBazas2->Name = L"labelBazas2";
			this->labelBazas2->Size = System::Drawing::Size(39, 20);
			this->labelBazas2->TabIndex = 191;
			this->labelBazas2->Text = L"16";
			this->labelBazas2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelBazas2->Visible = false;
			// 
			// labelBazas1
			// 
			this->labelBazas1->ForeColor = System::Drawing::Color::White;
			this->labelBazas1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"labelBazas1.Image")));
			this->labelBazas1->Location = System::Drawing::Point(280, 571);
			this->labelBazas1->Name = L"labelBazas1";
			this->labelBazas1->Size = System::Drawing::Size(30, 18);
			this->labelBazas1->TabIndex = 192;
			this->labelBazas1->Text = L"16";
			this->labelBazas1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelBazas1->Visible = false;
			// 
			// labelJugador3
			// 
			this->labelJugador3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelJugador3->Location = System::Drawing::Point(75, 205);
			this->labelJugador3->Name = L"labelJugador3";
			this->labelJugador3->Size = System::Drawing::Size(17, 270);
			this->labelJugador3->TabIndex = 193;
			this->labelJugador3->Text = L"Jugador   4";
			this->labelJugador3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelJugador1
			// 
			this->labelJugador1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelJugador1->Location = System::Drawing::Point(597, 205);
			this->labelJugador1->Name = L"labelJugador1";
			this->labelJugador1->Size = System::Drawing::Size(17, 270);
			this->labelJugador1->TabIndex = 194;
			this->labelJugador1->Text = L"Jugador   2";
			this->labelJugador1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelJugador0
			// 
			this->labelJugador0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelJugador0->Location = System::Drawing::Point(210, 591);
			this->labelJugador0->Name = L"labelJugador0";
			this->labelJugador0->Size = System::Drawing::Size(270, 17);
			this->labelJugador0->TabIndex = 195;
			this->labelJugador0->Text = L"J u g a d o r   1";
			this->labelJugador0->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelJugador2
			// 
			this->labelJugador2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelJugador2->Location = System::Drawing::Point(209, 72);
			this->labelJugador2->Name = L"labelJugador2";
			this->labelJugador2->Size = System::Drawing::Size(270, 17);
			this->labelJugador2->TabIndex = 196;
			this->labelJugador2->Text = L"J u g a d o r   3";
			this->labelJugador2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// botonVayaSolo
			// 
			this->botonVayaSolo->Enabled = false;
			this->botonVayaSolo->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonVayaSolo->Location = System::Drawing::Point(87, 643);
			this->botonVayaSolo->Name = L"botonVayaSolo";
			this->botonVayaSolo->Size = System::Drawing::Size(70, 28);
			this->botonVayaSolo->TabIndex = 6;
			this->botonVayaSolo->Text = L"Vaya Solo";
			this->botonVayaSolo->UseVisualStyleBackColor = true;
			this->botonVayaSolo->Click += gcnew System::EventHandler(this, &Form1::botonVayaSolo_Click);
			// 
			// botonTodas
			// 
			this->botonTodas->Enabled = false;
			this->botonTodas->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonTodas->Location = System::Drawing::Point(608, 643);
			this->botonTodas->Name = L"botonTodas";
			this->botonTodas->Size = System::Drawing::Size(70, 28);
			this->botonTodas->TabIndex = 10;
			this->botonTodas->Text = L"Pido Todas";
			this->botonTodas->UseVisualStyleBackColor = true;
			this->botonTodas->Click += gcnew System::EventHandler(this, &Form1::botonTodas_Click);
			// 
			// botonCinco
			// 
			this->botonCinco->Enabled = false;
			this->botonCinco->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonCinco->Location = System::Drawing::Point(533, 643);
			this->botonCinco->Name = L"botonCinco";
			this->botonCinco->Size = System::Drawing::Size(70, 28);
			this->botonCinco->TabIndex = 9;
			this->botonCinco->Text = L"Pido Cinco";
			this->botonCinco->UseVisualStyleBackColor = true;
			this->botonCinco->Click += gcnew System::EventHandler(this, &Form1::botonCinco_Click);
			// 
			// botonRechazoZanga
			// 
			this->botonRechazoZanga->Enabled = false;
			this->botonRechazoZanga->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonRechazoZanga->Location = System::Drawing::Point(608, 610);
			this->botonRechazoZanga->Name = L"botonRechazoZanga";
			this->botonRechazoZanga->Size = System::Drawing::Size(70, 28);
			this->botonRechazoZanga->TabIndex = 8;
			this->botonRechazoZanga->Text = L"Rechazo Zanga";
			this->botonRechazoZanga->UseVisualStyleBackColor = true;
			this->botonRechazoZanga->Click += gcnew System::EventHandler(this, &Form1::botonRechazoZanga_Click);
			// 
			// botonVayaUsted
			// 
			this->botonVayaUsted->Enabled = false;
			this->botonVayaUsted->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonVayaUsted->Location = System::Drawing::Point(533, 610);
			this->botonVayaUsted->Name = L"botonVayaUsted";
			this->botonVayaUsted->Size = System::Drawing::Size(70, 28);
			this->botonVayaUsted->TabIndex = 7;
			this->botonVayaUsted->Text = L"Vaya Usted";
			this->botonVayaUsted->UseVisualStyleBackColor = true;
			this->botonVayaUsted->Click += gcnew System::EventHandler(this, &Form1::botonVayaUsted_Click);
			// 
			// botonEspadas
			// 
			this->botonEspadas->Enabled = false;
			this->botonEspadas->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonEspadas->ForeColor = System::Drawing::Color::Blue;
			this->botonEspadas->Location = System::Drawing::Point(12, 571);
			this->botonEspadas->Name = L"botonEspadas";
			this->botonEspadas->Size = System::Drawing::Size(32, 33);
			this->botonEspadas->TabIndex = 197;
			this->botonEspadas->Text = L"E";
			this->botonEspadas->UseVisualStyleBackColor = true;
			this->botonEspadas->Click += gcnew System::EventHandler(this, &Form1::botonEspadas_Click);
			// 
			// botonBastos
			// 
			this->botonBastos->Enabled = false;
			this->botonBastos->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonBastos->ForeColor = System::Drawing::Color::Green;
			this->botonBastos->Location = System::Drawing::Point(50, 571);
			this->botonBastos->Name = L"botonBastos";
			this->botonBastos->Size = System::Drawing::Size(32, 33);
			this->botonBastos->TabIndex = 198;
			this->botonBastos->Text = L"B";
			this->botonBastos->UseVisualStyleBackColor = true;
			this->botonBastos->Click += gcnew System::EventHandler(this, &Form1::botonBastos_Click);
			// 
			// botonCopas
			// 
			this->botonCopas->Enabled = false;
			this->botonCopas->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonCopas->ForeColor = System::Drawing::Color::Red;
			this->botonCopas->Location = System::Drawing::Point(646, 571);
			this->botonCopas->Name = L"botonCopas";
			this->botonCopas->Size = System::Drawing::Size(32, 33);
			this->botonCopas->TabIndex = 200;
			this->botonCopas->Text = L"C";
			this->botonCopas->UseVisualStyleBackColor = true;
			this->botonCopas->Click += gcnew System::EventHandler(this, &Form1::botonCopas_Click);
			// 
			// botonOros
			// 
			this->botonOros->Enabled = false;
			this->botonOros->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonOros->ForeColor = System::Drawing::Color::Yellow;
			this->botonOros->Location = System::Drawing::Point(608, 571);
			this->botonOros->Name = L"botonOros";
			this->botonOros->Size = System::Drawing::Size(32, 33);
			this->botonOros->TabIndex = 199;
			this->botonOros->Text = L"O";
			this->botonOros->UseVisualStyleBackColor = true;
			this->botonOros->Click += gcnew System::EventHandler(this, &Form1::botonOros_Click);
			// 
			// labelPartidas
			// 
			this->labelPartidas->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Light", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPartidas->Location = System::Drawing::Point(671, 12);
			this->labelPartidas->Name = L"labelPartidas";
			this->labelPartidas->Size = System::Drawing::Size(300, 58);
			this->labelPartidas->TabIndex = 201;
			this->labelPartidas->Text = L"0 - 0";
			this->labelPartidas->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// labelProgreso
			// 
			this->labelProgreso->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelProgreso->Location = System::Drawing::Point(671, 61);
			this->labelProgreso->Name = L"labelProgreso";
			this->labelProgreso->Size = System::Drawing::Size(300, 26);
			this->labelProgreso->TabIndex = 202;
			this->labelProgreso->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 683);
			this->Controls->Add(this->labelProgreso);
			this->Controls->Add(this->labelPartidas);
			this->Controls->Add(this->botonCopas);
			this->Controls->Add(this->botonOros);
			this->Controls->Add(this->botonBastos);
			this->Controls->Add(this->botonEspadas);
			this->Controls->Add(this->botonTodas);
			this->Controls->Add(this->botonCinco);
			this->Controls->Add(this->botonRechazoZanga);
			this->Controls->Add(this->botonVayaUsted);
			this->Controls->Add(this->botonVayaSolo);
			this->Controls->Add(this->labelJugador2);
			this->Controls->Add(this->labelJugador0);
			this->Controls->Add(this->labelJugador1);
			this->Controls->Add(this->labelJugador3);
			this->Controls->Add(this->labelBazas1);
			this->Controls->Add(this->labelBazas2);
			this->Controls->Add(this->labelPiedrasCentro);
			this->Controls->Add(this->labelPiedras1);
			this->Controls->Add(this->labelPiedras2);
			this->Controls->Add(this->barajaCortar1);
			this->Controls->Add(this->barajaCortar3);
			this->Controls->Add(this->barajaCortar2);
			this->Controls->Add(this->barajaCortar0);
			this->Controls->Add(this->imagenBaraja1);
			this->Controls->Add(this->imagenBaraja3);
			this->Controls->Add(this->imagenBaraja2);
			this->Controls->Add(this->imagenBaraja0);
			this->Controls->Add(this->bazaAbajo7);
			this->Controls->Add(this->bazaAbajo6);
			this->Controls->Add(this->bazaAbajo5);
			this->Controls->Add(this->bazaAbajo4);
			this->Controls->Add(this->bazaAbajo3);
			this->Controls->Add(this->bazaAbajo2);
			this->Controls->Add(this->bazaAbajo1);
			this->Controls->Add(this->bazaAbajo0);
			this->Controls->Add(this->panelSePidio);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panelTriunfa);
			this->Controls->Add(this->panelTriunfos);
			this->Controls->Add(this->salida);
			this->Controls->Add(this->botonSalir);
			this->Controls->Add(this->botonComenzar);
			this->Controls->Add(this->piedraUno31);
			this->Controls->Add(this->piedraUno23);
			this->Controls->Add(this->piedraUno15);
			this->Controls->Add(this->piedraUno11);
			this->Controls->Add(this->piedraUno27);
			this->Controls->Add(this->piedraUno19);
			this->Controls->Add(this->piedraUno7);
			this->Controls->Add(this->piedraUno3);
			this->Controls->Add(this->piedraUno26);
			this->Controls->Add(this->piedraUno18);
			this->Controls->Add(this->piedraUno6);
			this->Controls->Add(this->piedraUno1);
			this->Controls->Add(this->piedraUno29);
			this->Controls->Add(this->piedraUno21);
			this->Controls->Add(this->piedraUno13);
			this->Controls->Add(this->piedraUno9);
			this->Controls->Add(this->piedraUno10);
			this->Controls->Add(this->piedraUno14);
			this->Controls->Add(this->piedraUno22);
			this->Controls->Add(this->piedraUno30);
			this->Controls->Add(this->piedraUno2);
			this->Controls->Add(this->piedraUno5);
			this->Controls->Add(this->piedraUno17);
			this->Controls->Add(this->piedraUno25);
			this->Controls->Add(this->piedraUno0);
			this->Controls->Add(this->piedraUno4);
			this->Controls->Add(this->piedraUno16);
			this->Controls->Add(this->piedraUno24);
			this->Controls->Add(this->piedraUno8);
			this->Controls->Add(this->piedraUno12);
			this->Controls->Add(this->piedraUno20);
			this->Controls->Add(this->piedraUno28);
			this->Controls->Add(this->piedraDos31);
			this->Controls->Add(this->piedraDos23);
			this->Controls->Add(this->piedraDos15);
			this->Controls->Add(this->piedraDos11);
			this->Controls->Add(this->piedraDos27);
			this->Controls->Add(this->piedraDos19);
			this->Controls->Add(this->piedraDos7);
			this->Controls->Add(this->piedraDos3);
			this->Controls->Add(this->piedraDos26);
			this->Controls->Add(this->piedraDos18);
			this->Controls->Add(this->piedraDos6);
			this->Controls->Add(this->piedraDos1);
			this->Controls->Add(this->piedraDos29);
			this->Controls->Add(this->piedraDos21);
			this->Controls->Add(this->piedraDos13);
			this->Controls->Add(this->piedraDos9);
			this->Controls->Add(this->piedraDos10);
			this->Controls->Add(this->piedraDos14);
			this->Controls->Add(this->piedraDos22);
			this->Controls->Add(this->piedraDos30);
			this->Controls->Add(this->piedraDos2);
			this->Controls->Add(this->piedraDos5);
			this->Controls->Add(this->piedraDos17);
			this->Controls->Add(this->piedraDos25);
			this->Controls->Add(this->piedraDos0);
			this->Controls->Add(this->piedraDos4);
			this->Controls->Add(this->piedraDos16);
			this->Controls->Add(this->piedraDos24);
			this->Controls->Add(this->piedraDos8);
			this->Controls->Add(this->piedraDos12);
			this->Controls->Add(this->piedraDos20);
			this->Controls->Add(this->piedraDos28);
			this->Controls->Add(this->piedraCentro31);
			this->Controls->Add(this->piedraCentro23);
			this->Controls->Add(this->piedraCentro15);
			this->Controls->Add(this->piedraCentro11);
			this->Controls->Add(this->piedraCentro27);
			this->Controls->Add(this->piedraCentro19);
			this->Controls->Add(this->piedraCentro7);
			this->Controls->Add(this->piedraCentro3);
			this->Controls->Add(this->piedraCentro26);
			this->Controls->Add(this->piedraCentro18);
			this->Controls->Add(this->piedraCentro6);
			this->Controls->Add(this->piedraCentro1);
			this->Controls->Add(this->piedraCentro29);
			this->Controls->Add(this->piedraCentro21);
			this->Controls->Add(this->piedraCentro13);
			this->Controls->Add(this->piedraCentro9);
			this->Controls->Add(this->piedraCentro10);
			this->Controls->Add(this->piedraCentro14);
			this->Controls->Add(this->piedraCentro22);
			this->Controls->Add(this->piedraCentro30);
			this->Controls->Add(this->piedraCentro2);
			this->Controls->Add(this->piedraCentro5);
			this->Controls->Add(this->piedraCentro17);
			this->Controls->Add(this->piedraCentro25);
			this->Controls->Add(this->piedraCentro0);
			this->Controls->Add(this->piedraCentro4);
			this->Controls->Add(this->piedraCentro16);
			this->Controls->Add(this->piedraCentro24);
			this->Controls->Add(this->piedraCentro8);
			this->Controls->Add(this->piedraCentro12);
			this->Controls->Add(this->piedraCentro20);
			this->Controls->Add(this->piedraCentro28);
			this->Controls->Add(this->zangaAbajoIzquierda);
			this->Controls->Add(this->zangaArribaDerecha);
			this->Controls->Add(this->cartaAbajo7);
			this->Controls->Add(this->bazaIzquierda7);
			this->Controls->Add(this->bazaIzquierda6);
			this->Controls->Add(this->bazaIzquierda5);
			this->Controls->Add(this->bazaIzquierda4);
			this->Controls->Add(this->bazaIzquierda3);
			this->Controls->Add(this->bazaIzquierda2);
			this->Controls->Add(this->bazaIzquierda1);
			this->Controls->Add(this->bazaIzquierda0);
			this->Controls->Add(this->cartaMesa3);
			this->Controls->Add(this->cartaMesa2);
			this->Controls->Add(this->cartaMesa1);
			this->Controls->Add(this->cartaMesa0);
			this->Controls->Add(this->botonMeVoySolo);
			this->Controls->Add(this->botonPaso);
			this->Controls->Add(this->botonJuego);
			this->Controls->Add(this->cartaIzquierda7);
			this->Controls->Add(this->cartaIzquierda6);
			this->Controls->Add(this->cartaIzquierda5);
			this->Controls->Add(this->cartaIzquierda4);
			this->Controls->Add(this->cartaIzquierda3);
			this->Controls->Add(this->cartaIzquierda2);
			this->Controls->Add(this->cartaIzquierda1);
			this->Controls->Add(this->cartaIzquierda0);
			this->Controls->Add(this->cartaDerecha0);
			this->Controls->Add(this->cartaDerecha1);
			this->Controls->Add(this->cartaDerecha2);
			this->Controls->Add(this->cartaDerecha3);
			this->Controls->Add(this->cartaDerecha4);
			this->Controls->Add(this->cartaDerecha5);
			this->Controls->Add(this->cartaDerecha6);
			this->Controls->Add(this->cartaDerecha7);
			this->Controls->Add(this->cartaArriba0);
			this->Controls->Add(this->cartaArriba1);
			this->Controls->Add(this->cartaArriba2);
			this->Controls->Add(this->cartaArriba3);
			this->Controls->Add(this->cartaArriba4);
			this->Controls->Add(this->cartaArriba5);
			this->Controls->Add(this->cartaArriba6);
			this->Controls->Add(this->cartaArriba7);
			this->Controls->Add(this->cartaAbajo6);
			this->Controls->Add(this->cartaAbajo5);
			this->Controls->Add(this->cartaAbajo4);
			this->Controls->Add(this->cartaAbajo3);
			this->Controls->Add(this->cartaAbajo2);
			this->Controls->Add(this->cartaAbajo1);
			this->Controls->Add(this->cartaAbajo0);
			this->Controls->Add(this->tapete);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"La Zanga 1.0";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaArriba7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaDerecha0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaIzquierda0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tapete))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaMesa3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaAbajo0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bazaIzquierda0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cartaAbajo7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->zangaArribaDerecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->zangaAbajoIzquierda))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraCentro9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraDos28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->piedraUno28))->EndInit();
			this->panelTriunfa->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panelSePidio->ResumeLayout(false);
			this->panelSePidio->PerformLayout();
			this->panelTriunfos->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagenBaraja1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barajaCortar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Thread^ hiloJuego;
		bool hiloSuspendido;
		int piedrasGraficas1;
		int piedrasGraficas2;
		int piedrasGraficasCentro;
		array<bool>^cartasActivas;
		array<bool, 2>^cartasNoTiradas;
		array<bool>^cartasResaltadas;
		int usuarioCartaElegida;
		frasesHablarPrimero usuarioFrasePrimero;
		frasesHablarDespues usuarioFraseDespues;
		frasesHablarZanga usuarioFraseZanga;
		frasesHablarRecambio usuarioFraseRecambio;
		palos usuarioTriunfo;
		bool usuarioAceptaSolo;
		bool usuarioPideCinco;
		bool usuarioPideTodas;
		situaciones situacion;

		//// Parametros
		/*const static int tiempoMesa = 750;
		const static int tiempoJugadores = 1000;
		const static int tiempoGraficos = 50;*/
		const static int tiempoMesa = 0;
		const static int tiempoJugadores = 0;
		const static int tiempoGraficos = 0;
		const static bool usuarioJuega = false;
		const static int numPartidas = 10000;

		// METODO QUE SE EJECUTA CONCURRENTEMENTE EN EL OTRO HILO
		// Y CONDUCE EL JUEGO

		void mainHiloJuego()
		{
			Jugador jugadores[4];
			Baraja baraja = Baraja();
			if (usuarioJuega)
				jugadores[0] = Jugador("Eduardo", 0, 10);
			else
				jugadores[0] = Jugador("Eduardo", 0, 4);
			jugadores[1] = Jugador("Antonio", 1, 3);
			jugadores[2] = Jugador("Cris", 2, 4);
			jugadores[3] = Jugador("Crisanto", 3, 3);
			Mazo mazosOriginales[4];
			Mesa mesa = Mesa();
			Carta comienzo, cartaTemp;
			bool alguienLaTiene = false;
			frasesHablarPrimero frasePrimero;
			frasesHablarDespues fraseDespues;
			frasesHablarZanga fraseZanga;
			frasesHablarRecambio fraseRecambio;
			int mano;
			int numManos = 0;
			bool seguir = false;
			int temp;
			System::DateTime final, principio = System::DateTime::Now;
			System::TimeSpan transcurrido;
			bool anunciadoNoCinco = false;
			int partidasGanadas1 = 0, partidasGanadas2 = 0;
			cambiarLabel(labelProgreso, "(Partida " + 
				System::Convert::ToString(partidasGanadas1+partidasGanadas2+1) +
				" de " + numPartidas + ")");
			cambiarLabel(labelPartidas, partidasGanadas1 + " - " + partidasGanadas2);

			// SONIDO
			/*System::Media::SoundPlayer simpleSound("c:\\Windows\\Media\\chimes.wav");
			simpleSound.Play();*/

			for(int partida = 0; partida < numPartidas; partida++)
			{

			// Chapuza
			this->limpiarMesaRapido(); 
			this->limpiarPiedras();
			this->limpiarEtiquetas();
			this->ocultarBarajas();
			this->ocultarBarajasCortar();
			this->limpiarSalida();
			mesa = Mesa();
			alguienLaTiene = false;
			numManos = 0;
			seguir = false;
			principio = System::DateTime::Now;
			anunciadoNoCinco = false;
			this->ponerPiedras1(16);
			this->ponerPiedras2(16);
			this->mostrarBaraja(0);
			this->mostrarNumerosPiedras();
			this->cambiarVisibilidadLabel(labelPiedrasCentro, false);
			cartasActivas = gcnew array<bool>(8);
			cartasNoTiradas = gcnew array<bool, 2>(4, 8);
			cartasResaltadas = gcnew array<bool>(8);
			for (int i = 0; i < 8; i++)
			{
				cartasActivas[i] = false;
				for (int j = 0; j < 4; j++)
					cartasNoTiradas[j, i] = true;
				cartasResaltadas[i] = false;
			}
			this->usuarioCartaElegida = 0;
			this->usuarioFrasePrimero = juego;
			this->usuarioFraseDespues = juegoTambien;
			this->usuarioFraseZanga = juegoZanga;
			this->usuarioTriunfo = bastos;
			this->usuarioAceptaSolo = false;
			this->usuarioPideCinco = false;
			this->usuarioPideTodas = false;
			usuarioFraseRecambio = juegoRecambio;
			situacion = primero;
			this->desactivarBotones();
			resaltarJugador(0, false);
			resaltarJugador(1, false);
			resaltarJugador(2, false);
			resaltarJugador(3, false);

			// PRIMERA MANO

			// Decidir el primer mano
			comienzaPartida();
			esperar(tiempoMesa);
			while (!alguienLaTiene)
			{
				mesa.barajar(baraja);		
				this->barajar(0);
				esperar(tiempoMesa);
				this->cortar(3);
				esperar(tiempoMesa);
				mesa.repartir(baraja, jugadores);
				this->anunciarRepartir(0);
				resaltarJugador(0, false);
				this->actualizarCartasJugadores(jugadores, 1);
				this->mostrarZanga(0);
				// Chapuza
				for (int i = 0; i < 4; i++)
				{
					mazosOriginales[i] = jugadores[i].getMazo();
				}
				esperar(tiempoMesa);
				for (int indiceEspadas = (int)siete; indiceEspadas < (int)dos; indiceEspadas++)
				{
					comienzo = Carta((valores)indiceEspadas, espadas);
					for (int i = 0; i < 4; i++)
					{
						if (jugadores[i].tieneCarta(comienzo))
						{					
							this->tieneEspadas(i+1, comienzo.nombre());
							esperar(tiempoMesa);		
							this->anunciarMano(mesa, i);
							mesa.setJugadorManoPrimero(i);							
							//this->cambiarLabelProximoMano("Jugador " 
							//	+ System::Convert::ToString(mesa.getJugadorManoPrimero()+1));
							esperar(tiempoMesa);
							alguienLaTiene = true;
							break;
						}
					}
					if (alguienLaTiene) break;
				}
			}
			this->comienzoMano(numManos);
			numManos++;
			mano = mesa.getJugadorManoPrimero();
			// Hablar
			resaltarJugador((mano+0)%4, true);
			resaltarJugador((mano+3)%4, false);
			if (usuarioJuega && mano == 0)
			{
				activarBotonesHablaPrimero(mesa);
				pausar();
			}
			else
			{
				esperar(tiempoJugadores);
			}
			frasePrimero = jugadores[mano].hablarPrimero(mesa, usuarioFrasePrimero);	
			if (frasePrimero == juego)
			{
				this->juega(mano);
				mesa.juega(mano);
				resaltarJugador((mano+1)%4, true);
				resaltarJugador((mano+0)%4, false);
				if (usuarioJuega && (mano+1)%4 == 0)
				{
					activarBotonesHablaDespues();
					pausar();
				}
				else
				{
					esperar(tiempoJugadores);
				}
				fraseDespues = jugadores[(mano+1)%4].hablarDespues(mesa, usuarioFraseDespues);
				if (fraseDespues == juegoTambien)
				{
					this->juega((mano+1)%4);
					mesa.juega((mano+1)%4);
					resaltarJugador((mano+2)%4, true);
					resaltarJugador((mano+1)%4, false);
					if (usuarioJuega && (mano+2)%4 == 0)
					{
						activarBotonesHablaDespues();
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa, usuarioFraseDespues);
					if (fraseDespues == juegoTambien)
					{
						this->juega((mano+2)%4);
						mesa.juega((mano+2)%4);
						resaltarJugador((mano+3)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarBotonesHablaDespues();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
						if (fraseDespues == juegoTambien)
						{
							this->juega((mano+3)%4);
							mesa.juega((mano+3)%4);
						}
						else
						{
							this->mandaSolo((mano+3)%4, mano);
							mesa.mandaSolo((mano+3)%4, mano);
							resaltarJugador((mano+0)%4, true);
							resaltarJugador((mano+3)%4, false);
							if (usuarioJuega && mano == 0)
							{
								activarBotonesAceptaSolo();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							if (jugadores[mano].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
							{
								this->vaSolo(mano, meVoyYo, mesa);
								mesa.vaSolo(mano, meVoyYo);
							}
							else
							{
								this->vaSolo((mano+3)%4, vayaUsted, mesa);									 
								mesa.vaSolo((mano+3)%4, vayaUsted);
							}
						}
					}
					else
					{
						this->mandaSolo((mano+2)%4, mano);
						mesa.mandaSolo((mano+2)%4, mano);
						resaltarJugador((mano+0)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && mano == 0)
						{
							activarBotonesAceptaSolo();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						if (jugadores[mano].aceptarSolo((mano+2)%4, mesa, usuarioAceptaSolo))
						{
							this->vaSolo(mano, meVoyYo, mesa);
							mesa.vaSolo(mano, meVoyYo);
						}
						else
						{
							this->vaSolo((mano+2)%4, vayaUsted, mesa);
							mesa.vaSolo((mano+2)%4, vayaUsted);
						}
					}
				} 
				else 
				{
					this->mandaSolo((mano+1)%4, mano);
					mesa.mandaSolo((mano+1)%4, mano);
					resaltarJugador((mano+0)%4, true);
					resaltarJugador((mano+1)%4, false);
					if (usuarioJuega && mano == 0)
					{
						activarBotonesAceptaSolo();
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					if (jugadores[mano].aceptarSolo((mano+1)%4, mesa, usuarioAceptaSolo))
					{
						this->vaSolo(mano, meVoyYo, mesa);
						mesa.vaSolo(mano, meVoyYo);
					}
					else
					{
						this->vaSolo((mano+1)%4, vayaUsted, mesa);
						mesa.vaSolo((mano+1)%4, vayaUsted);
					}
				}
			} 
			else if (frasePrimero == paso)
			{
				this->pasa(mano, mesa);
				mesa.pasa(mano);
				resaltarJugador((mano+1)%4, true);
				resaltarJugador((mano+0)%4, false);
				if (usuarioJuega && (mano+1)%4 == 0)
				{
					activarBotonesHablaPrimero(mesa);
					pausar();
				}
				else
				{
					esperar(tiempoJugadores);
				}
				frasePrimero = jugadores[(mano+1)%4].hablarPrimero(mesa, usuarioFrasePrimero);
				if (frasePrimero == juego)
				{
					this->juega((mano+1)%4);
					mesa.juega((mano+1)%4);
					resaltarJugador((mano+2)%4, true);
					resaltarJugador((mano+1)%4, false);
					if (usuarioJuega && (mano+2)%4 == 0)
					{
						activarBotonesHablaDespues();
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa, usuarioFraseDespues);
					if (fraseDespues == juegoTambien)
					{
						this->juega((mano+2)%4);
						mesa.juega((mano+2)%4);
						resaltarJugador((mano+3)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarBotonesHablaDespues();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
						if (fraseDespues == juegoTambien)
						{
							this->juega((mano+3)%4);
							mesa.juega((mano+3)%4);
						}
						else
						{
							this->mandaSolo((mano+3)%4, (mano+1)%4);
							mesa.mandaSolo((mano+3)%4, (mano+1)%4);
							resaltarJugador((mano+1)%4, true);
							resaltarJugador((mano+3)%4, false);
							if (usuarioJuega && (mano+1)%4 == 0)
							{
								activarBotonesAceptaSolo();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							if (jugadores[(mano+1)%4].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
							{
								this->vaSolo((mano+1)%4, meVoyYo, mesa);
								mesa.vaSolo((mano+1)%4, meVoyYo);
							}
							else
							{
								this->vaSolo((mano+3)%4, vayaUsted, mesa);
								mesa.vaSolo((mano+3)%4, vayaUsted);
							}
						}
					} 
					else
					{
						this->mandaSolo((mano+2)%4, (mano+1)%4);
						mesa.mandaSolo((mano+2)%4, (mano+1)%4);
						resaltarJugador((mano+1)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+1)%4 == 0)
						{
							activarBotonesAceptaSolo();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						if (jugadores[(mano+1)%4].aceptarSolo((mano+2)%4, mesa, usuarioAceptaSolo))
						{
							this->vaSolo((mano+1)%4, meVoyYo, mesa);
							mesa.vaSolo((mano+1)%4, meVoyYo);
						}
						else
						{
							this->vaSolo((mano+2)%4, vayaUsted, mesa);
							mesa.vaSolo((mano+2)%4, vayaUsted);
						}
					}
				} 
				else if (frasePrimero == paso)
				{
					this->pasa((mano+1)%4, mesa);
					mesa.pasa((mano+1)%4);
					resaltarJugador((mano+2)%4, true);
					resaltarJugador((mano+1)%4, false);
					if (usuarioJuega && (mano+2)%4 == 0)
					{
						activarBotonesHablaPrimero(mesa);
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					frasePrimero = jugadores[(mano+2)%4].hablarPrimero(mesa, usuarioFrasePrimero);
					if (frasePrimero == juego)
					{
						this->juega((mano+2)%4);
						mesa.juega((mano+2)%4);
						resaltarJugador((mano+3)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarBotonesHablaDespues();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
						if (fraseDespues == juegoTambien)
						{
							this->juega((mano+3)%4);
							mesa.juega((mano+3)%4);
						}
						else
						{
							this->mandaSolo((mano+3)%4, (mano+2)%4);
							mesa.mandaSolo((mano+3)%4, (mano+2)%4);
							resaltarJugador((mano+1)%2, true);
							resaltarJugador((mano+3)%4, false);
							if (usuarioJuega && (mano+2)%4 == 0)
							{
								activarBotonesAceptaSolo();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							if (jugadores[(mano+2)%4].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
							{
								this->vaSolo((mano+2)%4, meVoyYo, mesa);
								mesa.vaSolo((mano+2)%4, meVoyYo);
							}
							else
							{
								this->vaSolo((mano+3)%4, vayaUsted, mesa);
								mesa.vaSolo((mano+3)%4, vayaUsted);
							}
						}
					}
					else if (frasePrimero == paso)
					{
						this->pasa((mano+2)%4, mesa);
						mesa.pasa((mano+2)%4);
						resaltarJugador((mano+3)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarBotonesHablaPrimero(mesa);
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						frasePrimero = jugadores[(mano+3)%4].hablarPrimero(mesa, usuarioFrasePrimero);
						if (frasePrimero == paso)
						{
							this->cambiaPorZanga(jugadores, (mano+3)%4, mesa);
							mesa.cambiaPorZanga(jugadores, (mano+3)%4);
							esperar(tiempoMesa);
							this->actualizarCartasJugador(jugadores, (mano+3)%4);
							mazosOriginales[(mano+3)%4] = jugadores[(mano+3)%4].getMazo();
							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarBotonesHablaZanga();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							fraseZanga = jugadores[(mano+3)%4].hablarZanga(mesa, usuarioFraseZanga);
							if (fraseZanga == juegoZanga)
							{
								this->juega((mano+3)%4);
								mesa.juega((mano+3)%4);
							}
							else if (fraseZanga == meVoySoloZanga)
							{
								this->vaSolo((mano+3)%4, meVoy, mesa);	
								mesa.vaSolo((mano+3)%4, meVoy);	
							}
							else
							{
								this->recambiaSusCartas(jugadores, (mano+3)%4, mesa);
								mesa.recambiaSusCartas(jugadores, (mano+3)%4);
								esperar(tiempoMesa);
								this->actualizarCartasJugador(jugadores, (mano+3)%4);
								mazosOriginales[(mano+3)%4] = jugadores[(mano+3)%4].getMazo();

								if (usuarioJuega && (mano+3)%4 == 0)
								{
									activarBotonesHablaRecambio();
									pausar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								fraseRecambio = jugadores[(mano+3)%4].hablarRecambio(mesa, usuarioFraseRecambio);
								if (fraseRecambio == juegoRecambio)
								{
									this->juega((mano+3)%4);	
									mesa.juega((mano+3)%4);
								}
								else
								{
									this->vaSolo((mano+3)%4, meVoy, mesa);	
									mesa.vaSolo((mano+3)%4, meVoy);
								}
							}
						} 
						else if (frasePrimero == juego)
						{
							this->juega((mano+3)%4);	
							mesa.juega((mano+3)%4);	
						}
						else
						{
							this->vaSolo((mano+3)%4, meVoy, mesa);	
							mesa.vaSolo((mano+3)%4, meVoy);					
						}
					}
					else
					{
						this->vaSolo((mano+2)%4, meVoy, mesa);
						mesa.vaSolo((mano+2)%4, meVoy);
					}
				}
				else
				{
					this->vaSolo((mano+1)%4, meVoy, mesa);
					mesa.vaSolo((mano+1)%4, meVoy);
				}
			}
			else
			{
				this->vaSolo(mano, meVoy, mesa);
				mesa.vaSolo(mano, meVoy);
			}					
			resaltarJugador((mano+3)%4, false);
			resaltarJugador(mesa.getJugadorTriunfo(), true);
			if (usuarioJuega && mesa.getJugadorTriunfo() == 0)
			{
				activarBotonesTriunfo();
				pausar();
			}
			else
			{
				esperar(tiempoJugadores);
			}			
			mesa.setTriunfo(jugadores[mesa.getJugadorTriunfo()].triunfar(usuarioTriunfo));
			this->setTriunfo(mesa);
			resaltarJugador(0, false);
			resaltarJugador(1, false);
			resaltarJugador(2, false);
			resaltarJugador(3, false);

			esperar(tiempoMesa);
			mesa.comprobarEstuche(jugadores);			

			// Tirar
			//this->cambiarLabelProximoMano("Jugador " 
			//	+ System::Convert::ToString(1+(mesa.getJugadorManoPrimero()+1)%4));
			for (int i = 0; i < 8; i++)
			{
				this->usuarioCartaElegida = 0;
				for (int carta = 0; carta < 8; carta++)
				{
					cartasActivas[carta] = false;
					cartasResaltadas[carta] = false;
				}
				mano = mesa.getJugadorMano();
				if (i == 2 && (mesa.getNumBazas1() == 2 || mesa.getNumBazas2() == 2))
				{
					resaltarJugador(mano, true);
					resaltarJugador((mano+3)%4, false);
					if (usuarioJuega && mano == 0)
					{
						activarBotonesCinco();
						pausar();
					} 
					else 
					{
						esperar(tiempoJugadores);
					}
					if (jugadores[mano].pedirCinco(mesa, usuarioPideCinco))
					{						
						this->pideCinco(mano);						
						mesa.pideCinco(mano);
					}
				}				
				if (!mesa.getAlguienSolo())
				{	
					resaltarJugador(mano, true);
					resaltarJugador((mano+3)%4, false);
					if (usuarioJuega && mano == 0)
					{
						activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
						pausar();
						for (int carta = 0; carta < 8; carta++)
						{
							cartasActivas[carta] = false;
							cartasResaltadas[carta] = false;
						}
						refrescar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					temp = jugadores[mano].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
					cartaTemp = jugadores[mano].tirarCarta(temp);
					this->tirarCarta(mano, 
						indiceOriginal(cartaTemp, mazosOriginales[mano]), cartaTemp, 0, mesa); 						
					mesa.ponerCarta(cartaTemp, mano);


					resaltarJugador((mano+1)%4, true);
					resaltarJugador(mano, false);
					if (usuarioJuega && (mano+1)%4 == 0)
					{
						activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
						pausar();
						for (int carta = 0; carta < 8; carta++)
						{
							cartasActivas[carta] = false;
							cartasResaltadas[carta] = false;
						}
						refrescar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					temp = jugadores[(mano+1)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
					cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
					this->tirarCarta((mano+1)%4, 
						indiceOriginal(cartaTemp, mazosOriginales[(mano+1)%4]), cartaTemp, 1, mesa);
					mesa.ponerCarta(cartaTemp, (mano+1)%4);

					resaltarJugador((mano+2)%4, true);
					resaltarJugador((mano+1)%4, false);
					if (usuarioJuega && (mano+2)%4 == 0)
					{
						activarCartas(2, mazosOriginales[0], jugadores[0], mesa);
						pausar();
						for (int carta = 0; carta < 8; carta++)
						{
							cartasActivas[carta] = false;
							cartasResaltadas[carta] = false;
						}
						refrescar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					temp = jugadores[(mano+2)%4].elegirCarta(2, mesa, usuarioCartaElegida, mazosOriginales[0]);
					cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
					this->tirarCarta((mano+2)%4, 
						indiceOriginal(cartaTemp, mazosOriginales[(mano+2)%4]), cartaTemp, 2, mesa);
					mesa.ponerCarta(cartaTemp, (mano+2)%4);

					resaltarJugador((mano+3)%4, true);
					resaltarJugador((mano+2)%4, false);
					if (usuarioJuega && (mano+3)%4 == 0)
					{
						activarCartas(3, mazosOriginales[0], jugadores[0], mesa);
						pausar();
						for (int carta = 0; carta < 8; carta++)
						{
							cartasActivas[carta] = false;
							cartasResaltadas[carta] = false;
						}
						refrescar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					temp = jugadores[(mano+3)%4].elegirCarta(3, mesa, usuarioCartaElegida, mazosOriginales[0]);
					cartaTemp = jugadores[(mano+3)%4].tirarCarta(temp);
					this->tirarCarta((mano+3)%4, 
						indiceOriginal(cartaTemp, mazosOriginales[(mano+3)%4]), cartaTemp, 3, mesa);
					mesa.ponerCarta(cartaTemp, (mano+3)%4);
				}
				else
				{				
					resaltarJugador((mano+3)%4, false);
					if (jugadores[mano].getNumero() != (mesa.getJugadorSolo()+2)%4)
					{
						resaltarJugador((mano+0)%4, true);						
						if (usuarioJuega && mano == 0)
						{
							activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[mano].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[mano].tirarCarta(temp);
						this->tirarCarta(mano, indiceOriginal(cartaTemp, 
							mazosOriginales[mano]), cartaTemp, 0, mesa); 
						if (!usuarioJuega || (mano+1)%4 != 0)
							esperar(tiempoJugadores);
						mesa.ponerCarta(cartaTemp, mano);
					}
					resaltarJugador((mano+0)%4, false);
					if (jugadores[(mano+1)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
					{				
						resaltarJugador((mano+1)%4, true);

						if (jugadores[mano].getNumero() == (mesa.getJugadorSolo()+2)%4)
						{
							if (usuarioJuega && (mano+1)%4 == 0)
							{
								activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
								pausar();
								for (int carta = 0; carta < 8; carta++)
								{
									cartasActivas[carta] = false;
									cartasResaltadas[carta] = false;
								}
								refrescar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[(mano+1)%4].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
							this->tirarCarta((mano+1)%4, indiceOriginal(cartaTemp, 
								mazosOriginales[(mano+1)%4]), cartaTemp, 0, mesa);
						}
						else
						{
							if (usuarioJuega && (mano+1)%4 == 0)
							{
								activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
								pausar();
								for (int carta = 0; carta < 8; carta++)
								{
									cartasActivas[carta] = false;
									cartasResaltadas[carta] = false;
								}
								refrescar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[(mano+1)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
							this->tirarCarta((mano+1)%4, indiceOriginal(cartaTemp, 
								mazosOriginales[(mano+1)%4]), cartaTemp, 1, mesa);
						}
						mesa.ponerCarta(cartaTemp, (mano+1)%4);
					}
					resaltarJugador((mano+1)%4, false);
					if (jugadores[(mano+2)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
					{				
						resaltarJugador((mano+2)%4, true);

						if (jugadores[mano].getNumero() == (mesa.getJugadorSolo()+2)%4 ||
							jugadores[(mano+1)%4].getNumero() == (mesa.getJugadorSolo()+2)%4)
						{
							if (usuarioJuega && (mano+2)%4 == 0)
							{
								activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
								pausar();
								for (int carta = 0; carta < 8; carta++)
								{
									cartasActivas[carta] = false;
									cartasResaltadas[carta] = false;
								}
								refrescar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[(mano+2)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
							this->tirarCarta((mano+2)%4, indiceOriginal(cartaTemp, 
								mazosOriginales[(mano+2)%4]), cartaTemp, 1, mesa);
						}
						else
						{
							if (usuarioJuega && (mano+2)%4 == 0)
							{
								activarCartas(2, mazosOriginales[0], jugadores[0], mesa);
								pausar();
								for (int carta = 0; carta < 8; carta++)
								{
									cartasActivas[carta] = false;
									cartasResaltadas[carta] = false;
								}
								refrescar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[(mano+2)%4].elegirCarta(2, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
							this->tirarCarta((mano+2)%4, indiceOriginal(cartaTemp, 
								mazosOriginales[(mano+2)%4]), cartaTemp, 2, mesa);
						}
						mesa.ponerCarta(cartaTemp, (mano+2)%4);
					}	
					resaltarJugador((mano+2)%4, false);
					if (jugadores[(mano+3)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
					{
						resaltarJugador((mano+3)%4, true);

						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarCartas(3, mazosOriginales[0], jugadores[0], mesa);
							pausar();
							for (int carta = 0; carta < 8; carta++)
							{
								cartasActivas[carta] = false;
								cartasResaltadas[carta] = false;
							}
							refrescar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[(mano+3)%4].elegirCarta(3, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[(mano+3)%4].tirarCarta(temp);
						this->tirarCarta((mano+3)%4, 
							indiceOriginal(cartaTemp, 
							mazosOriginales[(mano+3)%4]), cartaTemp, 3, mesa);
						mesa.ponerCarta(cartaTemp, (mano+3)%4);
					}
				}
				resaltarJugador(0, false);
				resaltarJugador(1, false);
				resaltarJugador(2, false);
				resaltarJugador(3, false);
				mesa.organizarBaza();
				mano = mesa.getJugadorMano();
				esperar(tiempoMesa);
				this->organizarBaza(mesa);
				esperar(tiempoMesa);
				if (mesa.getAlguienCinco())
				{
					if (i <= 4 && !anunciadoNoCinco && 
						(mesa.getNumBazas1() > 0 && mesa.getNumBazas2() > 0))
					{
						mesa.cumpleCinco(false);
						this->cumpleCinco(false, mesa);
						esperar(tiempoMesa);
						anunciadoNoCinco = true;
					}
					if (i == 4)
					{					
						if (mesa.getNumBazas1() == 5 || mesa.getNumBazas2() == 5)
						{
							mesa.cumpleCinco(true);
							this->cumpleCinco(true, mesa);
							esperar(tiempoMesa);
							if (usuarioJuega && mano == 0)
							{
								activarBotonesTodas();
								pausar();
							}
							if (jugadores[mano].pedirTodas(mesa, usuarioPideTodas))
							{
								this->pideTodas(mano);
								esperar(tiempoJugadores);
								mesa.pideTodas(mano);
								seguir = true;
							}
						}
					}
				}
				if (i > 4 && mesa.getAlguienTodas() && 
					(mesa.getNumBazas1() > 0 && mesa.getNumBazas2() > 0))
				{
					mesa.cumpleTodas(false);
					this->cumpleTodas(false, mesa);
					esperar(tiempoMesa);
					seguir = false;
				}
				if (i == 7 && mesa.getAlguienTodas())
				{
					if (mesa.getNumBazas1() == 8 || mesa.getNumBazas2() == 8)
					{
						mesa.cumpleTodas(true);
						this->cumpleTodas(true, mesa);
						esperar(tiempoMesa);
					}
				}
				if (!seguir && (mesa.getNumBazas1() >= 5 || mesa.getNumBazas2() >= 5))
					break;
			}
			mesa.pedirEstuche();
			this->pedirEstuche(mesa);
			esperar(tiempoMesa);
			this->organizarPiedras(mesa);
			esperar(tiempoMesa);
			mesa.organizarPiedras();
			this->limpiarMesa();
			this->mostrarBaraja(mesa.getJugadorManoPrimero());
			this->anunciarMano(mesa, (mesa.getJugadorManoPrimero()+1)%4);
			esperar(tiempoMesa);
			mesa.setJugadorManoPrimero((mesa.getJugadorManoPrimero() + 1) % 4);			
			esperar(tiempoMesa);						
			this->anunciarPiedras(mesa);
			//numManos++;
			this->finMano(numManos, mesa);		
			esperar(tiempoMesa);

			// SIGUIENTES MANOS

			while (true)
			{
				anunciadoNoCinco = false;
				seguir = false;
				this->usuarioFrasePrimero = juego;
				this->usuarioFraseDespues = juegoTambien;
				this->usuarioFraseZanga = juegoZanga;
				this->usuarioTriunfo = bastos;
				this->usuarioAceptaSolo = false;
				this->usuarioPideCinco= false;
				this->usuarioPideTodas= false;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 4; j++)
						cartasNoTiradas[j, i] = true;
				}
				this->comienzoMano(numManos);
				numManos++;
				esperar(tiempoMesa);
				mesa.barajar(baraja);		
				this->barajar((mesa.getJugadorManoPrimero()+3)%4);
				esperar(tiempoMesa);
				this->cortar((mesa.getJugadorManoPrimero()+2)%4);
				esperar(tiempoMesa);
				mesa.repartir(baraja, jugadores);
				this->anunciarRepartir((mesa.getJugadorManoPrimero()+3)%4);
				this->actualizarCartasJugadores(jugadores, mesa.getJugadorManoPrimero());
				this->mostrarZanga((mesa.getJugadorManoPrimero()+3)%4);
				// Chapuza
				for (int i = 0; i < 4; i++)
				{
					mazosOriginales[i] = jugadores[i].getMazo();
				}
				esperar(tiempoMesa);

				mano = mesa.getJugadorManoPrimero();
				// Hablar
				resaltarJugador((mano+0)%4, true);
				resaltarJugador((mano+3)%4, false);
				if (usuarioJuega && mano == 0)
				{
					activarBotonesHablaPrimero(mesa);
					pausar();
				}
				else
				{
					esperar(tiempoJugadores);
				}
				frasePrimero = jugadores[mano].hablarPrimero(mesa, usuarioFrasePrimero);	
				if (frasePrimero == juego)
				{
					this->juega(mano);
					mesa.juega(mano);
					resaltarJugador((mano+1)%4, true);
					resaltarJugador((mano+0)%4, false);
					if (usuarioJuega && (mano+1)%4 == 0)
					{
						activarBotonesHablaDespues();
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					fraseDespues = jugadores[(mano+1)%4].hablarDespues(mesa, usuarioFraseDespues);
					if (fraseDespues == juegoTambien)
					{
						this->juega((mano+1)%4);
						mesa.juega((mano+1)%4);
						resaltarJugador((mano+2)%4, true);
						resaltarJugador((mano+1)%4, false);
						if (usuarioJuega && (mano+2)%4 == 0)
						{
							activarBotonesHablaDespues();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa, usuarioFraseDespues);
						if (fraseDespues == juegoTambien)
						{
							this->juega((mano+2)%4);
							mesa.juega((mano+2)%4);
							resaltarJugador((mano+3)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarBotonesHablaDespues();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
							if (fraseDespues == juegoTambien)
							{
								this->juega((mano+3)%4);
								mesa.juega((mano+3)%4);
							}
							else
							{
								this->mandaSolo((mano+3)%4, mano);
								mesa.mandaSolo((mano+3)%4, mano);
								resaltarJugador((mano+0)%4, true);
								resaltarJugador((mano+3)%4, false);
								if (usuarioJuega && mano == 0)
								{
									activarBotonesAceptaSolo();
									pausar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								if (jugadores[mano].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
								{
									this->vaSolo(mano, meVoyYo, mesa);
									mesa.vaSolo(mano, meVoyYo);
								}
								else
								{
									this->vaSolo((mano+3)%4, vayaUsted, mesa);									 
									mesa.vaSolo((mano+3)%4, vayaUsted);
								}
							}
						}
						else
						{
							this->mandaSolo((mano+2)%4, mano);
							mesa.mandaSolo((mano+2)%4, mano);
							resaltarJugador((mano+0)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && mano == 0)
							{
								activarBotonesAceptaSolo();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							if (jugadores[mano].aceptarSolo((mano+2)%4, mesa, usuarioAceptaSolo))
							{
								this->vaSolo(mano, meVoyYo, mesa);
								mesa.vaSolo(mano, meVoyYo);
							}
							else
							{
								this->vaSolo((mano+2)%4, vayaUsted, mesa);
								mesa.vaSolo((mano+2)%4, vayaUsted);
							}
						}
					} 
					else 
					{
						this->mandaSolo((mano+1)%4, mano);
						mesa.mandaSolo((mano+1)%4, mano);
						resaltarJugador((mano+0)%4, true);
						resaltarJugador((mano+1)%4, false);
						if (usuarioJuega && mano == 0)
						{
							activarBotonesAceptaSolo();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						if (jugadores[mano].aceptarSolo((mano+1)%4, mesa, usuarioAceptaSolo))
						{
							this->vaSolo(mano, meVoyYo, mesa);
							mesa.vaSolo(mano, meVoyYo);
						}
						else
						{
							this->vaSolo((mano+1)%4, vayaUsted, mesa);
							mesa.vaSolo((mano+1)%4, vayaUsted);
						}
					}
				} 
				else if (frasePrimero == paso)
				{
					this->pasa(mano, mesa);
					mesa.pasa(mano);
					resaltarJugador((mano+1)%4, true);
					resaltarJugador((mano+0)%4, false);
					if (usuarioJuega && (mano+1)%4 == 0)
					{
						activarBotonesHablaPrimero(mesa);
						pausar();
					}
					else
					{
						esperar(tiempoJugadores);
					}
					frasePrimero = jugadores[(mano+1)%4].hablarPrimero(mesa, usuarioFrasePrimero);
					if (frasePrimero == juego)
					{
						this->juega((mano+1)%4);
						mesa.juega((mano+1)%4);
						resaltarJugador((mano+2)%4, true);
						resaltarJugador((mano+1)%4, false);
						if (usuarioJuega && (mano+2)%4 == 0)
						{
							activarBotonesHablaDespues();
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						fraseDespues = jugadores[(mano+2)%4].hablarDespues(mesa, usuarioFraseDespues);
						if (fraseDespues == juegoTambien)
						{
							this->juega((mano+2)%4);
							mesa.juega((mano+2)%4);
							resaltarJugador((mano+3)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarBotonesHablaDespues();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
							if (fraseDespues == juegoTambien)
							{
								this->juega((mano+3)%4);
								mesa.juega((mano+3)%4);
							}
							else
							{
								this->mandaSolo((mano+3)%4, (mano+1)%4);
								mesa.mandaSolo((mano+3)%4, (mano+1)%4);
								resaltarJugador((mano+1)%4, true);
								resaltarJugador((mano+3)%4, false);
								if (usuarioJuega && (mano+1)%4 == 0)
								{
									activarBotonesAceptaSolo();
									pausar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								if (jugadores[(mano+1)%4].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
								{
									this->vaSolo((mano+1)%4, meVoyYo, mesa);
									mesa.vaSolo((mano+1)%4, meVoyYo);
								}
								else
								{
									this->vaSolo((mano+3)%4, vayaUsted, mesa);
									mesa.vaSolo((mano+3)%4, vayaUsted);
								}
							}
						} 
						else
						{
							this->mandaSolo((mano+2)%4, (mano+1)%4);
							mesa.mandaSolo((mano+2)%4, (mano+1)%4);
							resaltarJugador((mano+1)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && (mano+1)%4 == 0)
							{
								activarBotonesAceptaSolo();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							if (jugadores[(mano+1)%4].aceptarSolo((mano+2)%4, mesa, usuarioAceptaSolo))
							{
								this->vaSolo((mano+1)%4, meVoyYo, mesa);
								mesa.vaSolo((mano+1)%4, meVoyYo);
							}
							else
							{
								this->vaSolo((mano+2)%4, vayaUsted, mesa);
								mesa.vaSolo((mano+2)%4, vayaUsted);
							}
						}
					} 
					else if (frasePrimero == paso)
					{
						this->pasa((mano+1)%4, mesa);
						mesa.pasa((mano+1)%4);
						resaltarJugador((mano+2)%4, true);
						resaltarJugador((mano+1)%4, false);
						if (usuarioJuega && (mano+2)%4 == 0)
						{
							activarBotonesHablaPrimero(mesa);
							pausar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						frasePrimero = jugadores[(mano+2)%4].hablarPrimero(mesa, usuarioFrasePrimero);
						if (frasePrimero == juego)
						{
							this->juega((mano+2)%4);
							mesa.juega((mano+2)%4);
							resaltarJugador((mano+3)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarBotonesHablaDespues();
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							fraseDespues = jugadores[(mano+3)%4].hablarDespues(mesa, usuarioFraseDespues);
							if (fraseDespues == juegoTambien)
							{
								this->juega((mano+3)%4);
								mesa.juega((mano+3)%4);
							}
							else
							{
								this->mandaSolo((mano+3)%4, (mano+2)%4);
								mesa.mandaSolo((mano+3)%4, (mano+2)%4);
								resaltarJugador((mano+1)%2, true);
								resaltarJugador((mano+3)%4, false);
								if (usuarioJuega && (mano+2)%4 == 0)
								{
									activarBotonesAceptaSolo();
									pausar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								if (jugadores[(mano+2)%4].aceptarSolo((mano+3)%4, mesa, usuarioAceptaSolo))
								{
									this->vaSolo((mano+2)%4, meVoyYo, mesa);
									mesa.vaSolo((mano+2)%4, meVoyYo);
								}
								else
								{
									this->vaSolo((mano+3)%4, vayaUsted, mesa);
									mesa.vaSolo((mano+3)%4, vayaUsted);
								}
							}
						}
						else if (frasePrimero == paso)
						{
							this->pasa((mano+2)%4, mesa);
							mesa.pasa((mano+2)%4);
							resaltarJugador((mano+3)%4, true);
							resaltarJugador((mano+2)%4, false);
							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarBotonesHablaPrimero(mesa);
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							frasePrimero = jugadores[(mano+3)%4].hablarPrimero(mesa, usuarioFrasePrimero);
							if (frasePrimero == paso)
							{
								this->cambiaPorZanga(jugadores, (mano+3)%4, mesa);
								mesa.cambiaPorZanga(jugadores, (mano+3)%4);
								esperar(tiempoMesa);
								this->actualizarCartasJugador(jugadores, (mano+3)%4);
								mazosOriginales[(mano+3)%4] = jugadores[(mano+3)%4].getMazo();
								if (usuarioJuega && (mano+3)%4 == 0)
								{
									activarBotonesHablaZanga();
									pausar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								fraseZanga = jugadores[(mano+3)%4].hablarZanga(mesa, usuarioFraseZanga);
								if (fraseZanga == juegoZanga)
								{
									this->juega((mano+3)%4);
									mesa.juega((mano+3)%4);
								}
								else if (fraseZanga == meVoySoloZanga)
								{
									this->vaSolo((mano+3)%4, meVoy, mesa);	
									mesa.vaSolo((mano+3)%4, meVoy);	
								}
								else
								{
									this->recambiaSusCartas(jugadores, (mano+3)%4, mesa);
									mesa.recambiaSusCartas(jugadores, (mano+3)%4);
									esperar(tiempoMesa);
									this->actualizarCartasJugador(jugadores, (mano+3)%4);
									mazosOriginales[(mano+3)%4] = jugadores[(mano+3)%4].getMazo();

									if (usuarioJuega && (mano+3)%4 == 0)
									{
										activarBotonesHablaRecambio();
										pausar();
									}
									else
									{
										esperar(tiempoJugadores);
									}
									fraseRecambio = jugadores[(mano+3)%4].hablarRecambio(mesa, usuarioFraseRecambio);
									if (fraseRecambio == juegoRecambio)
									{
										this->juega((mano+3)%4);	
										mesa.juega((mano+3)%4);
									}
									else
									{
										this->vaSolo((mano+3)%4, meVoy, mesa);	
										mesa.vaSolo((mano+3)%4, meVoy);
									}
								}
							} 
							else if (frasePrimero == juego)
							{
								this->juega((mano+3)%4);	
								mesa.juega((mano+3)%4);	
							}
							else
							{
								this->vaSolo((mano+3)%4, meVoy, mesa);	
								mesa.vaSolo((mano+3)%4, meVoy);					
							}
						}
						else
						{
							this->vaSolo((mano+2)%4, meVoy, mesa);
							mesa.vaSolo((mano+2)%4, meVoy);
						}
					}
					else
					{
						this->vaSolo((mano+1)%4, meVoy, mesa);
						mesa.vaSolo((mano+1)%4, meVoy);
					}
				}
				else
				{
					this->vaSolo(mano, meVoy, mesa);
					mesa.vaSolo(mano, meVoy);
				}						
				resaltarJugador((mano+3)%4, false);
				resaltarJugador(mesa.getJugadorTriunfo(), true);
				if (usuarioJuega && mesa.getJugadorTriunfo() == 0)
				{
					activarBotonesTriunfo();
					pausar();
				}
				else
				{
					esperar(tiempoJugadores);
				}			
				mesa.setTriunfo(jugadores[mesa.getJugadorTriunfo()].triunfar(usuarioTriunfo));
				this->setTriunfo(mesa);
				resaltarJugador(0, false);
				resaltarJugador(1, false);
				resaltarJugador(2, false);
				resaltarJugador(3, false);

				esperar(tiempoMesa);
				mesa.comprobarEstuche(jugadores);			

				// Tirar
				//this->cambiarLabelProximoMano("Jugador " 
				//	+ System::Convert::ToString(1+(mesa.getJugadorManoPrimero()+1)%4));
				for (int i = 0; i < 8; i++)
				{
					this->usuarioCartaElegida = 0;
					for (int carta = 0; carta < 8; carta++)
					{
						cartasActivas[carta] = false;
						cartasResaltadas[carta] = false;
					}
					mano = mesa.getJugadorMano();
					if (i == 2 && (mesa.getNumBazas1() == 2 || mesa.getNumBazas2() == 2))
					{
						resaltarJugador(mano, true);
						resaltarJugador((mano+3)%4, false);
						if (usuarioJuega && mano == 0)
						{
							activarBotonesCinco();
							pausar();
						} 
						else 
						{
							esperar(tiempoJugadores);
						}
						if (jugadores[mano].pedirCinco(mesa, usuarioPideCinco))
						{						
							this->pideCinco(mano);						
							mesa.pideCinco(mano);
						}
					}				
					if (!mesa.getAlguienSolo())
					{	
						resaltarJugador(mano, true);
						resaltarJugador((mano+3)%4, false);
						if (usuarioJuega && mano == 0)
						{
							activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
							pausar();
							for (int carta = 0; carta < 8; carta++)
							{
								cartasActivas[carta] = false;
								cartasResaltadas[carta] = false;
							}
							refrescar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[mano].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[mano].tirarCarta(temp);
						this->tirarCarta(mano, 
							indiceOriginal(cartaTemp, mazosOriginales[mano]), cartaTemp, 0, mesa); 						
						mesa.ponerCarta(cartaTemp, mano);


						resaltarJugador((mano+1)%4, true);
						resaltarJugador(mano, false);
						if (usuarioJuega && (mano+1)%4 == 0)
						{
							activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
							pausar();
							for (int carta = 0; carta < 8; carta++)
							{
								cartasActivas[carta] = false;
								cartasResaltadas[carta] = false;
							}
							refrescar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[(mano+1)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
						this->tirarCarta((mano+1)%4, 
							indiceOriginal(cartaTemp, mazosOriginales[(mano+1)%4]), cartaTemp, 1, mesa);
						mesa.ponerCarta(cartaTemp, (mano+1)%4);

						resaltarJugador((mano+2)%4, true);
						resaltarJugador((mano+1)%4, false);
						if (usuarioJuega && (mano+2)%4 == 0)
						{
							activarCartas(2, mazosOriginales[0], jugadores[0], mesa);
							pausar();
							for (int carta = 0; carta < 8; carta++)
							{
								cartasActivas[carta] = false;
								cartasResaltadas[carta] = false;
							}
							refrescar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[(mano+2)%4].elegirCarta(2, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
						this->tirarCarta((mano+2)%4, 
							indiceOriginal(cartaTemp, mazosOriginales[(mano+2)%4]), cartaTemp, 2, mesa);
						mesa.ponerCarta(cartaTemp, (mano+2)%4);

						resaltarJugador((mano+3)%4, true);
						resaltarJugador((mano+2)%4, false);
						if (usuarioJuega && (mano+3)%4 == 0)
						{
							activarCartas(3, mazosOriginales[0], jugadores[0], mesa);
							pausar();
							for (int carta = 0; carta < 8; carta++)
							{
								cartasActivas[carta] = false;
								cartasResaltadas[carta] = false;
							}
							refrescar();
						}
						else
						{
							esperar(tiempoJugadores);
						}
						temp = jugadores[(mano+3)%4].elegirCarta(3, mesa, usuarioCartaElegida, mazosOriginales[0]);
						cartaTemp = jugadores[(mano+3)%4].tirarCarta(temp);
						this->tirarCarta((mano+3)%4, 
							indiceOriginal(cartaTemp, mazosOriginales[(mano+3)%4]), cartaTemp, 3, mesa);
						mesa.ponerCarta(cartaTemp, (mano+3)%4);
					}
					else
					{				
						resaltarJugador((mano+3)%4, false);
						if (jugadores[mano].getNumero() != (mesa.getJugadorSolo()+2)%4)
						{
							resaltarJugador((mano+0)%4, true);						
							if (usuarioJuega && mano == 0)
							{
								activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
								pausar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[mano].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[mano].tirarCarta(temp);
							this->tirarCarta(mano, indiceOriginal(cartaTemp, 
								mazosOriginales[mano]), cartaTemp, 0, mesa); 
							if (!usuarioJuega || (mano+1)%4 != 0)
								esperar(tiempoJugadores);
							mesa.ponerCarta(cartaTemp, mano);
						}
						resaltarJugador((mano+0)%4, false);
						if (jugadores[(mano+1)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
						{				
							resaltarJugador((mano+1)%4, true);

							if (jugadores[mano].getNumero() == (mesa.getJugadorSolo()+2)%4)
							{
								if (usuarioJuega && (mano+1)%4 == 0)
								{
									activarCartas(0, mazosOriginales[0], jugadores[0], mesa);
									pausar();
									for (int carta = 0; carta < 8; carta++)
									{
										cartasActivas[carta] = false;
										cartasResaltadas[carta] = false;
									}
									refrescar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								temp = jugadores[(mano+1)%4].elegirCarta(0, mesa, usuarioCartaElegida, mazosOriginales[0]);
								cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
								this->tirarCarta((mano+1)%4, indiceOriginal(cartaTemp, 
									mazosOriginales[(mano+1)%4]), cartaTemp, 0, mesa);
							}
							else
							{
								if (usuarioJuega && (mano+1)%4 == 0)
								{
									activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
									pausar();
									for (int carta = 0; carta < 8; carta++)
									{
										cartasActivas[carta] = false;
										cartasResaltadas[carta] = false;
									}
									refrescar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								temp = jugadores[(mano+1)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
								cartaTemp = jugadores[(mano+1)%4].tirarCarta(temp);
								this->tirarCarta((mano+1)%4, indiceOriginal(cartaTemp, 
									mazosOriginales[(mano+1)%4]), cartaTemp, 1, mesa);
							}
							mesa.ponerCarta(cartaTemp, (mano+1)%4);
						}
						resaltarJugador((mano+1)%4, false);
						if (jugadores[(mano+2)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
						{				
							resaltarJugador((mano+2)%4, true);

							if (jugadores[mano].getNumero() == (mesa.getJugadorSolo()+2)%4 ||
								jugadores[(mano+1)%4].getNumero() == (mesa.getJugadorSolo()+2)%4)
							{
								if (usuarioJuega && (mano+2)%4 == 0)
								{
									activarCartas(1, mazosOriginales[0], jugadores[0], mesa);
									pausar();
									for (int carta = 0; carta < 8; carta++)
									{
										cartasActivas[carta] = false;
										cartasResaltadas[carta] = false;
									}
									refrescar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								temp = jugadores[(mano+2)%4].elegirCarta(1, mesa, usuarioCartaElegida, mazosOriginales[0]);
								cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
								this->tirarCarta((mano+2)%4, indiceOriginal(cartaTemp, 
									mazosOriginales[(mano+2)%4]), cartaTemp, 1, mesa);
							}
							else
							{
								if (usuarioJuega && (mano+2)%4 == 0)
								{
									activarCartas(2, mazosOriginales[0], jugadores[0], mesa);
									pausar();
									for (int carta = 0; carta < 8; carta++)
									{
										cartasActivas[carta] = false;
										cartasResaltadas[carta] = false;
									}
									refrescar();
								}
								else
								{
									esperar(tiempoJugadores);
								}
								temp = jugadores[(mano+2)%4].elegirCarta(2, mesa, usuarioCartaElegida, mazosOriginales[0]);
								cartaTemp = jugadores[(mano+2)%4].tirarCarta(temp);
								this->tirarCarta((mano+2)%4, indiceOriginal(cartaTemp, 
									mazosOriginales[(mano+2)%4]), cartaTemp, 2, mesa);
							}
							mesa.ponerCarta(cartaTemp, (mano+2)%4);
						}	
						resaltarJugador((mano+2)%4, false);
						if (jugadores[(mano+3)%4].getNumero() != (mesa.getJugadorSolo()+2)%4)
						{
							resaltarJugador((mano+3)%4, true);

							if (usuarioJuega && (mano+3)%4 == 0)
							{
								activarCartas(3, mazosOriginales[0], jugadores[0], mesa);
								pausar();
								for (int carta = 0; carta < 8; carta++)
								{
									cartasActivas[carta] = false;
									cartasResaltadas[carta] = false;
								}
								refrescar();
							}
							else
							{
								esperar(tiempoJugadores);
							}
							temp = jugadores[(mano+3)%4].elegirCarta(3, mesa, usuarioCartaElegida, mazosOriginales[0]);
							cartaTemp = jugadores[(mano+3)%4].tirarCarta(temp);
							this->tirarCarta((mano+3)%4, 
								indiceOriginal(cartaTemp, 
								mazosOriginales[(mano+3)%4]), cartaTemp, 3, mesa);
							mesa.ponerCarta(cartaTemp, (mano+3)%4);
						}
					}
					resaltarJugador(0, false);
					resaltarJugador(1, false);
					resaltarJugador(2, false);
					resaltarJugador(3, false);
					mesa.organizarBaza();
					mano = mesa.getJugadorMano();
					esperar(tiempoMesa);
					this->organizarBaza(mesa);
					esperar(tiempoMesa);
					if (mesa.getAlguienCinco())
					{
						if (i <= 4 && !anunciadoNoCinco && 
							(mesa.getNumBazas1() > 0 && mesa.getNumBazas2() > 0))
						{
							mesa.cumpleCinco(false);
							this->cumpleCinco(false, mesa);
							esperar(tiempoMesa);
							anunciadoNoCinco = true;
						}
						if (i == 4)
						{					
							if (mesa.getNumBazas1() == 5 || mesa.getNumBazas2() == 5)
							{
								mesa.cumpleCinco(true);
								this->cumpleCinco(true, mesa);
								esperar(tiempoMesa);
								if (usuarioJuega && mano == 0)
								{
									activarBotonesTodas();
									pausar();
								}
								if (jugadores[mano].pedirTodas(mesa, usuarioPideTodas))
								{
									this->pideTodas(mano);
									esperar(tiempoJugadores);
									mesa.pideTodas(mano);
									seguir = true;
								}
							}
						}
					}
					if (i > 4 && mesa.getAlguienTodas() && 
						(mesa.getNumBazas1() > 0 && mesa.getNumBazas2() > 0))
					{
						mesa.cumpleTodas(false);
						this->cumpleTodas(false, mesa);
						esperar(tiempoMesa);
						seguir = false;
					}
					if (i == 7 && mesa.getAlguienTodas())
					{
						if (mesa.getNumBazas1() == 8 || mesa.getNumBazas2() == 8)
						{
							mesa.cumpleTodas(true);
							this->cumpleTodas(true, mesa);
							esperar(tiempoMesa);
						}
					}
					if (!seguir && (mesa.getNumBazas1() >= 5 || mesa.getNumBazas2() >= 5))
						break;
				}
				mesa.pedirEstuche();
				this->pedirEstuche(mesa);
				esperar(tiempoMesa);
				this->organizarPiedras(mesa);
				esperar(tiempoMesa);				
				mesa.organizarPiedras();				
				this->limpiarMesa();
				if (mesa.getNumPiedras1() == 32 || mesa.getNumPiedras2() == 32)
				{
					this->mostrarBaraja(0);
					break;
				}
				this->mostrarBaraja(mesa.getJugadorManoPrimero());
				this->anunciarMano(mesa, (mesa.getJugadorManoPrimero()+1)%4);
				esperar(tiempoMesa);
				mesa.setJugadorManoPrimero((mesa.getJugadorManoPrimero() + 1) % 4);			
				esperar(tiempoMesa);						
				this->anunciarPiedras(mesa);				
				this->finMano(numManos, mesa);		
				esperar(tiempoMesa);
			}
			final = System::DateTime::Now;
			transcurrido = final - principio;
			this->anunciarVictoria(numManos, mesa, transcurrido);
			if (mesa.getNumPiedras1() > mesa.getNumPiedras2())
				partidasGanadas1++;
			else
				partidasGanadas2++;
			cambiarLabel(labelPartidas, partidasGanadas1 + " - " + partidasGanadas2);
			cambiarLabel(labelProgreso, "(Partida " + 
				System::Convert::ToString(partidasGanadas1+partidasGanadas2+1) +
				" de " + numPartidas + ")");
			this->cambiarBotonComenzar("Comenzar");
			this->ocultarBarajas();
			this->ocultarBarajasCortar();
			this->mostrarBaraja(0);
			}
			double coef = ((double)partidasGanadas1 - (double)partidasGanadas2)/
				(double)(partidasGanadas1+partidasGanadas2);
			escribirMensaje("Resultado total: " + partidasGanadas1 + " a " 
				+ partidasGanadas2 + ". Coeficiente: " + 
				System::Convert::ToString(coef)+ ".\n");
			System::Media::SoundPlayer simpleSound("c:\\Windows\\Media\\chimes.wav");
			simpleSound.Play();
		}

		void esperar(int tiempo)
		{
			//hiloSuspendido = true;
			Thread::Sleep(tiempo);
			//hiloSuspendido = false;		
		}


		void pausar()
		{
			if (!hiloSuspendido)
			{
				hiloSuspendido = true;
				hiloJuego->Suspend();
			}
		}

		void reanudar()
		{
			if (hiloSuspendido)
			{
				hiloSuspendido = false;
				hiloJuego->Resume();
			}
		}

		void barajar(int jugador) 
		{
			/*this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1)
				+ " baraja las cartas.\n");*/
		}

		void cortar(int jugador) 
		{
			/*this->ocultarBarajas();
			this->esperar(tiempoGraficos);
			this->mostrarBaraja(jugador);
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);			
			this->mostrarBarajaCortada(jugador);
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);
			this->ocultarBarajas();
			this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1)
				+ " corta.\n");
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);
			this->esperar(tiempoGraficos);*/
		}

		void anunciarRepartir(int jugador) 
		{
			/*this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1)
				+ " reparte las cartas.\n");
			this->ocultarBarajas();
			this->ocultarBarajasCortar();*/
		}
		void actualizarCartasJugadores(Jugador jugadores[], int mano)
		{
			/*array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
				{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
				cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
				{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
				cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
				{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
				cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
				{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
				cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			};
			String^ nombreImagen = "";
			int jugadorTemp;
			for (int jugador = 0; jugador < 4; jugador++)
			{
				jugadorTemp = (mano + jugador)%4;
				for (int carta = 0; carta < 4; carta++)
				{					
					esperar(tiempoGraficos);
					if (usuarioJuega && jugadorTemp != 0)
					{
						if (jugadorTemp == 2)
							this->actualizarImagen(cartasJugadores[jugadorTemp,carta], "trasera", ".bmp");
						else
							this->actualizarImagen(cartasJugadores[jugadorTemp,carta], "trasera hor", ".bmp");
					}
					else
					{
						nombreImagen = 
							jugadores[jugadorTemp].getMazo().getCarta(carta).nombreArchivo();
						this->actualizarImagen(cartasJugadores[jugadorTemp,carta], nombreImagen, ".gif");
					}
				}
			}
			for (int jugador = 0; jugador < 4; jugador++)
			{
				jugadorTemp = (mano + jugador)%4;
				for (int carta = 4; carta < 8; carta++)
				{
					esperar(tiempoGraficos);
					if (usuarioJuega && jugadorTemp != 0)
					{
						if (jugadorTemp == 2)
							this->actualizarImagen(cartasJugadores[jugadorTemp,carta], "trasera", ".bmp");
						else
							this->actualizarImagen(cartasJugadores[jugadorTemp,carta], "trasera hor", ".bmp");
					}
					else
					{
						nombreImagen = 
							jugadores[jugadorTemp].getMazo().getCarta(carta).nombreArchivo();
						this->actualizarImagen(cartasJugadores[jugadorTemp,carta], nombreImagen, ".gif");
					}
				}
			}*/
		}

		void actualizarCartasJugador(Jugador jugadores[], int jugador)
		{
			/*array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
				{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
				cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
				{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
				cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
				{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
				cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
				{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
				cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			};
			String^ nombreImagen = "";
			for (int carta = 0; carta < 8; carta++)
			{
				if (usuarioJuega && jugador != 0)
					{
						if (jugador == 2)
							this->actualizarImagen(cartasJugadores[jugador,carta], "trasera", ".bmp");
						else
							this->actualizarImagen(cartasJugadores[jugador,carta], "trasera hor", ".bmp");
					}
					else
					{
						nombreImagen = 
							jugadores[jugador].getMazo().getCarta(carta).nombreArchivo();
						this->actualizarImagen(cartasJugadores[jugador,carta], nombreImagen, ".gif");
					}
			}*/
		}

		void mostrarZanga(int jugadorQueReparte) 
		{
			/*if (jugadorQueReparte == 0 || jugadorQueReparte == 3)				 
				cambiarVisibilidad(zangaAbajoIzquierda, true);		
			else
				cambiarVisibilidad(zangaArribaDerecha, true);*/		
		}

		void tieneEspadas(int jugador, String^ carta) 
		{
			//this->escribirMensaje("El jugador " + jugador + " tiene el " + carta + ".\n");
		}

		void comienzaPartida() 
		{
			//this->escribirMensaje("Comienza la partida de zanga.\n");
		}

		void anunciarMano(Mesa mesa, int jugadorManoPrimero) 
		{
			/*int piedras;

			if (jugadorManoPrimero == 0 || jugadorManoPrimero == 2)	
			{
				piedras = mesa.getNumPiedras1();
				if (piedras >= 4)
				{
					this->escribirMensaje("El jugador "
						+ System::Convert::ToString(jugadorManoPrimero+1)
						+ " es el proximo mano y mete 4 vales.\n");		
					this->ponerPiedrasCentro(4);
					this->quitarPiedras1(4);
				}
				else
				{
					this->escribirMensaje("El jugador "
						+ System::Convert::ToString(jugadorManoPrimero+1)
						+ " es el proximo mano y mete " + piedras + " vales.\n");
					this->ponerPiedrasCentro(piedras);
					this->quitarPiedras1(piedras);
				}
			}
			else
			{
				piedras = mesa.getNumPiedras2();
				if (piedras >= 4)
				{
					this->escribirMensaje("El jugador "
						+ System::Convert::ToString(jugadorManoPrimero+1)
						+ " es el proximo mano y mete 4 vales.\n");		
					this->ponerPiedrasCentro(4);
					this->quitarPiedras2(4);
				}
				else
				{
					this->escribirMensaje("El jugador "
						+ System::Convert::ToString(jugadorManoPrimero+1)
						+ " es el proximo mano y mete " + piedras + " vales.\n");
					this->ponerPiedrasCentro(piedras);
					this->quitarPiedras2(piedras);
				}
			}				 */
		}

		void ponerPiedras1(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedras1 = {
				piedraUno0, piedraUno1, piedraUno2, piedraUno3,
				piedraUno4, piedraUno5, piedraUno6, piedraUno7,
				piedraUno8, piedraUno9, piedraUno10, piedraUno11,
				piedraUno12, piedraUno13, piedraUno14, piedraUno15,
				piedraUno16, piedraUno17, piedraUno18, piedraUno19,
				piedraUno20, piedraUno21, piedraUno22, piedraUno23,
				piedraUno24, piedraUno25, piedraUno26, piedraUno27,
				piedraUno28, piedraUno29, piedraUno30, piedraUno31,
			};
			for (int i = piedrasGraficas1; i < piedrasGraficas1+piedras; i++)
			{
				cambiarVisibilidad(piedras1[i], true);
			}
			piedrasGraficas1 += piedras;
			this->cambiarLabel(labelPiedras1, System::Convert::ToString(piedrasGraficas1));
			if (piedrasGraficas1 > 0)
				cambiarVisibilidadLabel(labelPiedras1, true);*/
		}

		void quitarPiedras1(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedras1 = {
				piedraUno0, piedraUno1, piedraUno2, piedraUno3,
				piedraUno4, piedraUno5, piedraUno6, piedraUno7,
				piedraUno8, piedraUno9, piedraUno10, piedraUno11,
				piedraUno12, piedraUno13, piedraUno14, piedraUno15,
				piedraUno16, piedraUno17, piedraUno18, piedraUno19,
				piedraUno20, piedraUno21, piedraUno22, piedraUno23,
				piedraUno24, piedraUno25, piedraUno26, piedraUno27,
				piedraUno28, piedraUno29, piedraUno30, piedraUno31,
			};
			for (int i = piedrasGraficas1-1; i >= piedrasGraficas1-piedras; i--)
			{
				if (i < 0)
				{
					pausar();
				}
				cambiarVisibilidad(piedras1[i], false);
			}
			piedrasGraficas1 -= piedras;
			this->cambiarLabel(labelPiedras1, System::Convert::ToString(piedrasGraficas1));
			if (piedrasGraficas1 == 0)
				cambiarVisibilidadLabel(labelPiedras1, false);*/
		}

		void ponerPiedras2(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedras2 = {
				piedraDos0, piedraDos1, piedraDos2, piedraDos3,
				piedraDos4, piedraDos5, piedraDos6, piedraDos7,
				piedraDos8, piedraDos9, piedraDos10, piedraDos11,
				piedraDos12, piedraDos13, piedraDos14, piedraDos15,
				piedraDos16, piedraDos17, piedraDos18, piedraDos19,
				piedraDos20, piedraDos21, piedraDos22, piedraDos23,
				piedraDos24, piedraDos25, piedraDos26, piedraDos27,
				piedraDos28, piedraDos29, piedraDos30, piedraDos31,
			};
			for (int i = piedrasGraficas2; i < (piedrasGraficas2+piedras); i++)
			{
				cambiarVisibilidad(piedras2[i], true);
			}
			piedrasGraficas2 += piedras;
			this->cambiarLabel(labelPiedras2, System::Convert::ToString(piedrasGraficas2));
			if (piedrasGraficas2 > 0)
				cambiarVisibilidadLabel(labelPiedras2, true);*/
		}

		void quitarPiedras2(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedras2 = {
				piedraDos0, piedraDos1, piedraDos2, piedraDos3,
				piedraDos4, piedraDos5, piedraDos6, piedraDos7,
				piedraDos8, piedraDos9, piedraDos10, piedraDos11,
				piedraDos12, piedraDos13, piedraDos14, piedraDos15,
				piedraDos16, piedraDos17, piedraDos18, piedraDos19,
				piedraDos20, piedraDos21, piedraDos22, piedraDos23,
				piedraDos24, piedraDos25, piedraDos26, piedraDos27,
				piedraDos28, piedraDos29, piedraDos30, piedraDos31,
			};
			for (int i = piedrasGraficas2-1; i >= (piedrasGraficas2-piedras); i--)
			{
				if (i < 0)
				{
					pausar();
				}
				cambiarVisibilidad(piedras2[i], false);
			}
			piedrasGraficas2 -= piedras;
			this->cambiarLabel(labelPiedras2, System::Convert::ToString(piedrasGraficas2));
			if (piedrasGraficas2 == 0)
				cambiarVisibilidadLabel(labelPiedras2, false);*/
		}

		void ponerPiedrasCentro(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedrasCentro = {
				piedraCentro0, piedraCentro1, piedraCentro2, piedraCentro3,
				piedraCentro4, piedraCentro5, piedraCentro6, piedraCentro7,
				piedraCentro8, piedraCentro9, piedraCentro10, piedraCentro11,
				piedraCentro12, piedraCentro13, piedraCentro14, piedraCentro15,
				piedraCentro16, piedraCentro17, piedraCentro18, piedraCentro19,
				piedraCentro20, piedraCentro21, piedraCentro22, piedraCentro23,
				piedraCentro24, piedraCentro25, piedraCentro26, piedraCentro27,
				piedraCentro28, piedraCentro29, piedraCentro30, piedraCentro31,
			};
			for (int i = piedrasGraficasCentro; i < piedrasGraficasCentro+piedras; i++)
			{
				cambiarVisibilidad(piedrasCentro[i], true);
			}
			piedrasGraficasCentro += piedras;
			this->cambiarLabel(labelPiedrasCentro, 
				System::Convert::ToString(piedrasGraficasCentro));
			if (piedrasGraficasCentro > 0)
				cambiarVisibilidadLabel(labelPiedrasCentro, true);*/
		}

		void quitarPiedrasCentro(int piedras)
		{
			/*array<System::Windows::Forms::PictureBox^>^piedrasCentro = {
				piedraCentro0, piedraCentro1, piedraCentro2, piedraCentro3,
				piedraCentro4, piedraCentro5, piedraCentro6, piedraCentro7,
				piedraCentro8, piedraCentro9, piedraCentro10, piedraCentro11,
				piedraCentro12, piedraCentro13, piedraCentro14, piedraCentro15,
				piedraCentro16, piedraCentro17, piedraCentro18, piedraCentro19,
				piedraCentro20, piedraCentro21, piedraCentro22, piedraCentro23,
				piedraCentro24, piedraCentro25, piedraCentro26, piedraCentro27,
				piedraCentro28, piedraCentro29, piedraCentro30, piedraCentro31,
			};
			for (int i = piedrasGraficasCentro-1; i >= piedrasGraficasCentro-piedras; i--)
			{
				if (i < 0)
				{
					pausar();
				}
				cambiarVisibilidad(piedrasCentro[i], false);
			}
			piedrasGraficasCentro -= piedras;
			this->cambiarLabel(labelPiedrasCentro, 
				System::Convert::ToString(piedrasGraficasCentro));
			if (piedrasGraficasCentro == 0)
				cambiarVisibilidadLabel(labelPiedrasCentro, false);*/
		}

		void pasa(int jugador, Mesa mesa)
		{
			/*this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) + " pasa y mete un vale.\n");
			if (jugador == 0 || jugador == 2)
			{
				this->ponerPiedrasCentro(1);
				this->quitarPiedras1(1);
			}
			else
			{
				this->ponerPiedrasCentro(1);
				this->quitarPiedras2(1);
			}*/
		}

		void juega(int jugador)
		{
			//this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) + " juega.\n");
		}

		void mandaSolo(int mandador, int mandado)
		{
			/*this->escribirMensaje("El jugador " + System::Convert::ToString(mandador+1) + " manda solo al jugador "
				+ System::Convert::ToString(mandado+1) + ".\n");*/
		}

		void vaSolo(int jugador, formasSolo forma, Mesa mesa)
		{
			/*int jugadorTriunfo = mesa.getJugadorTriunfo();
			switch (forma)
			{
			case meVoy:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) + " se va solo.\n");
				break;
			case meVoyYo:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) + 
					" acepta y se va solo.\n");
				break;
			default:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugadorTriunfo+1) + 
					" no acepta y el jugador " + System::Convert::ToString(jugador+1) + " se va solo.\n");
			}		
			this->cambiarSolo(true);
			this->limpiarCartasJugador((jugador+2)%4);*/
		}

		void cambiaPorZanga(Jugador jugadores[4], int jugador, Mesa mesa)
		{		
			//this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1)
			//	+ " pasa y cambia sus cartas por la zanga.\n");
			//Mazo mazoTemp;
			//if (jugador == 0 || jugador == 2)
			//{
			//	this->ponerPiedrasCentro(1);
			//	this->quitarPiedras1(1);
			//	// Se supone que 1 tiene mas de 2
			//	if (mesa.getNumPiedras2() > 2)
			//	{
			//		this->ponerPiedrasCentro(4);
			//		this->quitarPiedras1(2);
			//		this->quitarPiedras2(2);			
			//	} 
			//	else
			//	{
			//		this->ponerPiedrasCentro(2+mesa.getNumPiedras2());
			//		this->quitarPiedras1(2);
			//		this->quitarPiedras2(mesa.getNumPiedras2());			
			//	}			
			//}
			//else
			//{
			//	this->ponerPiedrasCentro(1);
			//	this->quitarPiedras2(1);
			//	// Se supone que 1 tiene mas de 2
			//	if (mesa.getNumPiedras1() > 2)
			//	{
			//		this->ponerPiedrasCentro(4);
			//		this->quitarPiedras2(2);
			//		this->quitarPiedras1(2);			
			//	} 
			//	else
			//	{
			//		this->ponerPiedrasCentro(2+mesa.getNumPiedras1());
			//		this->quitarPiedras2(2);
			//		this->quitarPiedras1(mesa.getNumPiedras1());			
			//	}
			//}
		}

		void recambiaSusCartas(Jugador jugadores[4], int jugador, Mesa mesa)
		{
			//this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) +
			//	" vuelve a coger sus cartas originales.\n");
			//Mazo mazoTemp;
			//// ACORDARSE DE QUE DEBE CONSIDERAR SUS CARTAS ANTERIORES PARA EL RECAMBIO
			//if (jugador == 0 || jugador == 2)
			//{		
			//	this->ponerPiedras2(mesa.getPiedrasCambioZanga());
			//	this->quitarPiedrasCentro(mesa.getPiedrasCambioZanga());
			//}
			//else
			//{
			//	this->ponerPiedras1(mesa.getPiedrasCambioZanga());
			//	this->quitarPiedrasCentro(mesa.getPiedrasCambioZanga());
			//}
		}

		void setTriunfo(Mesa mesa)
		{
			/*int jugadorTriunfo = mesa.getJugadorTriunfo();
			switch(mesa.getTriunfo())
			{
			case bastos:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugadorTriunfo+1)
					+ " triunfa a Bastos.\n");
				break;
			case copas:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugadorTriunfo+1)
					+ " triunfa a Copas.\n");
				break;
			case espadas:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugadorTriunfo+1)
					+ " triunfa a Espadas.\n");
				break;
			default:
				this->escribirMensaje("El jugador " + System::Convert::ToString(jugadorTriunfo+1)
					+ " triunfa a Oros.\n");		
				break;
			}
			this->cambiarLabelTriunfos((int)mesa.getTriunfo());
			this->cambiarLabelTriunfa("Jugador " 
				+ System::Convert::ToString(mesa.getJugadorTriunfo()+1));*/
		}

		void comienzoMano(int numManos)
		{
			//this->escribirMensaje("Comienzo de la mano " + System::Convert::ToString(numManos+1) + ".\n");
		}
		void finMano(int numManos, Mesa mesa)
		{				 
			//this->escribirMensaje("Fin de la mano " + System::Convert::ToString(numManos) + ".\n");				 
		}

		void anunciarPiedras(Mesa mesa)
		{
			//this->escribirMensaje("Vales: " + mesa.getNumPiedras1() 
			//	+ " - " + mesa.getNumPiedrasCentro() + " - " 
			//	+ mesa.getNumPiedras2() + ".\n");
			/*this->escribirMensaje("Piedras gráficas: " + piedrasGraficas1 
			+ " - " + piedrasGraficasCentro + " - " 
			+ piedrasGraficas2 + ".\n");*/
		}
		void pideCinco(int jugador)
		{
			//this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
			//	+ " pide Cinco.\n");
			//this->cambiarCinco(true);
		}

		void pideTodas(int jugador)
		{
			//this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
			//	+ " pide Todas.\n");
			//this->cambiarTodas(true);
		}

		void tirarCarta(int jugador, int numCarta, Carta carta, int turno, Mesa mesa)
		{

			/*array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
				{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
				cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
				{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
				cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
				{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
				cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
				{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
				cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			};
			array<System::Windows::Forms::PictureBox^>^cartasMesa =
			{cartaMesa0, cartaMesa1, cartaMesa2, cartaMesa3};

			if ((carta.getPalo() == mesa.getTriunfo() || carta.numeroJuego(bastos, bastos) == 39
				|| carta.numeroJuego(bastos, bastos) == 37) && turno == 0) 
			{
				if (carta.getValor() == sota || carta.numeroJuego(bastos, bastos) == 39
					|| carta.numeroJuego(bastos, mesa.getTriunfo()) == 38)
					this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
					+ " arrastra con la " +	carta.nombreZanga(mesa.getTriunfo()) + ".\n");
				else
					this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
					+ " arrastra con el " +	carta.nombreZanga(mesa.getTriunfo()) + ".\n");
			}
			else
			{
				if (carta.getValor() == sota || carta.numeroJuego(bastos, bastos) == 39
					|| carta.numeroJuego(bastos, mesa.getTriunfo()) == 38)
					this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
					+ " tira la " +	carta.nombreZanga(mesa.getTriunfo()) + ".\n");
				else
					this->escribirMensaje("El jugador " + System::Convert::ToString(jugador+1) 
					+ " tira el " +	carta.nombreZanga(mesa.getTriunfo()) + ".\n");
			}					

			this->actualizarImagen(cartasJugadores[jugador, numCarta], "gris", ".bmp");
			this->cambiarVisibilidad(cartasMesa[jugador], true);
			this->actualizarImagen(cartasMesa[jugador], carta.nombreArchivo(), ".GIF");
			if (usuarioJuega && jugador == 0)
				cartasNoTiradas[jugador, numCarta] = false;*/
		}

		void organizarBaza (Mesa mesa) 
		{
			/*array<System::Windows::Forms::PictureBox^>^cartasMesa =
			{cartaMesa0, cartaMesa1, cartaMesa2, cartaMesa3};
			array<System::Windows::Forms::PictureBox^>^bazas1 =
			{bazaAbajo0, bazaAbajo1, bazaAbajo2, bazaAbajo3,
			bazaAbajo4, bazaAbajo5, bazaAbajo6, bazaAbajo7};
			array<System::Windows::Forms::PictureBox^>^bazas2 =
			{bazaIzquierda0, bazaIzquierda1, bazaIzquierda2, bazaIzquierda3,
			bazaIzquierda4, bazaIzquierda5, bazaIzquierda6, bazaIzquierda7};

			for (int i = 0; i < 4; i++) 
			{
				this->actualizarImagen(cartasMesa[i], "tapete", ".bmp");
			}
			if (mesa.getJugadorMano() == 0 || mesa.getJugadorMano() == 2)
			{
				this->cambiarVisibilidad(bazas1[mesa.getNumBazas1()-1], true);
				this->traerAlFrente(bazas1[mesa.getNumBazas1()-1]);
				this->cambiarVisibilidadLabel(labelBazas1, true);
				this->cambiarLabel(labelBazas1, 
					System::Convert::ToString(mesa.getNumBazas1()));
			}
			else
			{
				this->cambiarVisibilidad(bazas2[mesa.getNumBazas2()-1], true);
				this->traerAlFrente(bazas2[mesa.getNumBazas2()-1]);
				this->cambiarVisibilidadLabel(labelBazas2, true);
				this->cambiarLabel(labelBazas2, 
					System::Convert::ToString(mesa.getNumBazas2()));
			}
			this->escribirMensaje("Baza ganada por el jugador " 
				+ System::Convert::ToString(mesa.getJugadorMano() + 1) + ".\n");
			this->limpiarTapete();*/
		}

		void cumpleCinco(bool cumple, Mesa mesa)
		{
			/*if (cumple)
			{
				if (mesa.getJugadorCinco() == 0 || mesa.getJugadorCinco() == 2)
				{
					this->escribirMensaje("La pareja 1 cumple las Cinco.\n");
				} 
				else
				{
					this->escribirMensaje("La pareja 2 cumple las Cinco.\n");
				}
			}
			else
			{		
				if (mesa.getJugadorCinco() == 0 || mesa.getJugadorCinco() == 2)
				{
					this->escribirMensaje("La pareja 1 no cumple las Cinco.\n");
				} 
				else
				{
					this->escribirMensaje("La pareja 2 no cumple las Cinco.\n");
				}
			}*/
		}

		void cumpleTodas(bool cumple, Mesa mesa)
		{
			/*if (cumple)
			{
				if (mesa.getJugadorTodas() == 0 || mesa.getJugadorTodas() == 2)
				{
					this->escribirMensaje("La pareja 1 cumple Todas.\n");
				} 
				else
				{
					this->escribirMensaje("La pareja 2 cumple Todas.\n");
				}
			}
			else
			{		
				if (mesa.getJugadorTodas() == 0 || mesa.getJugadorTodas() == 2)
				{
					this->escribirMensaje("La pareja 1 no cumple Todas.\n");
				} 
				else
				{
					this->escribirMensaje("La pareja 2 no cumple Todas.\n");
				}
			}*/
		}

		void organizarPiedras(Mesa mesa)
		{
			//int temp;
			//piedrasGraficas1 = mesa.getNumPiedras1();
			//piedrasGraficas2 = mesa.getNumPiedras2();
			//piedrasGraficasCentro = mesa.getNumPiedrasCentro();
			//if (mesa.getAlguienCinco())
			//{
			//	if (mesa.getJugadorCinco() == 0 || mesa.getJugadorCinco() == 2)
			//	{
			//		if (mesa.getCumplioCinco())
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasCinco(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasCinco(), piedrasGraficas2));
			//			this->escribirMensaje("La pareja 1 ha conseguido Cinco y cobra "
			//				+ this->min(mesa.getPiedrasCinco(), piedrasGraficas2) + " vales.\n");
			//		}
			//		else
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasCinco(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasCinco(), piedrasGraficas1));
			//			this->escribirMensaje("La pareja 1 no ha conseguido Cinco y paga "
			//				+ this->min(mesa.getPiedrasCinco(), piedrasGraficas1) + " vales.\n");
			//		}
			//	}
			//	else
			//	{
			//		if (mesa.getCumplioCinco())
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasCinco(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasCinco(), piedrasGraficas1));
			//			this->escribirMensaje("La pareja 2 ha conseguido Cinco y cobra "
			//				+ this->min(mesa.getPiedrasCinco(), piedrasGraficas1) + " vales.\n");
			//		}
			//		else
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasCinco(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasCinco(), piedrasGraficas2));
			//			this->escribirMensaje("La pareja 2 no ha conseguido Cinco y paga "
			//				+ this->min(mesa.getPiedrasCinco(), piedrasGraficas2) + " vales.\n");
			//		}
			//	}
			//}
			//if (mesa.getAlguienTodas())
			//{
			//	if (mesa.getJugadorTodas() == 0 || mesa.getJugadorTodas() == 2)
			//	{
			//		if (mesa.getCumplioTodas())
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasTodas(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasTodas(), piedrasGraficas2));
			//			this->escribirMensaje("La pareja 1 ha conseguido Todas y cobra "
			//				+ this->min(mesa.getPiedrasTodas(), piedrasGraficas2) + " vales.\n");
			//		}
			//		else
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasTodas(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasTodas(), piedrasGraficas1));
			//			this->escribirMensaje("La pareja 1 no ha conseguido Todas y paga "
			//				+ this->min(mesa.getPiedrasTodas(), piedrasGraficas1) + " vales.\n");
			//		}
			//	}
			//	else
			//	{
			//		if (mesa.getCumplioTodas())
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasTodas(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasTodas(), piedrasGraficas1));
			//			this->escribirMensaje("La pareja 2 ha conseguido Todas y cobra "
			//				+ this->min(mesa.getPiedrasTodas(), piedrasGraficas1) + " vales.\n");
			//		}
			//		else
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasTodas(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasTodas(), piedrasGraficas2));
			//			this->escribirMensaje("La pareja 2 no ha conseguido Todas y paga "
			//				+ this->min(mesa.getPiedrasTodas(), piedrasGraficas2) + " vales.\n");
			//		}
			//	}
			//}
			//if (mesa.getNumBazas1() > mesa.getNumBazas2())
			//{
			//	if (mesa.getAlguienEstuche())
			//	{
			//		this->ponerPiedras1(this->min(mesa.getPiedrasEstuche(), piedrasGraficas2));
			//		this->quitarPiedras2(this->min(mesa.getPiedrasEstuche(), piedrasGraficas2));
			//		if (mesa.getParejaEstuche() == 1)
			//			this->escribirMensaje("La pareja " + mesa.getParejaEstuche() + 
			//			" tiene estuche y cobra " +  mesa.getPiedrasEstuche() + " vales.\n");
			//		else
			//			this->escribirMensaje("La pareja " + mesa.getParejaEstuche()
			//			+ " tiene estuche en contra y paga " +  mesa.getPiedrasEstuche() 
			//			+ " vales.\n");
			//	}
			//	if (mesa.getJugadorTriunfo() == 0 || mesa.getJugadorTriunfo() == 2)
			//	{
			//		this->ponerPiedras1(piedrasGraficasCentro);
			//		this->quitarPiedrasCentro(piedrasGraficasCentro);
			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->escribirMensaje("El jugador " + System::Convert::ToString(mesa.getJugadorSolo()+1) 
			//				+ " ha ganado por " 
			//				+ mesa.getNumBazas1() + " a " + mesa.getNumBazas2() + ". Ha sido Sacada y cobra "
			//				+ mesa.getPiedrasSolo() + " por haberse ido solo.\n");
			//		}
			//		else
			//		{
			//			this->escribirMensaje("La pareja 1 ha ganado por " + mesa.getNumBazas1() + " a " +
			//				mesa.getNumBazas2() + ". Ha sido Sacada.\n");
			//		}				
			//	}
			//	else
			//	{
			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->escribirMensaje("La pareja 1 ha ganado por " + mesa.getNumBazas1() + " a "
			//				+ mesa.getNumBazas2() + ". Ha sido Codillo y cobra " + mesa.getPiedrasSolo()
			//				+ " porque el jugador " + 
			//				System::Convert::ToString(mesa.getJugadorSolo()+1) + " se fue solo.\n");
			//		}
			//		else
			//			this->escribirMensaje("La pareja 1 ha ganado por " + mesa.getNumBazas1() + " a "
			//			+ mesa.getNumBazas2() + ". Ha sido Codillo.\n");
			//		temp = piedrasGraficasCentro;
			//		if (piedrasGraficas2 > piedrasGraficasCentro)
			//		{
			//			this->quitarPiedras2(piedrasGraficasCentro);
			//			this->ponerPiedrasCentro(piedrasGraficasCentro);		
			//		}
			//		else
			//		{
			//			this->ponerPiedrasCentro(piedrasGraficas2);
			//			this->quitarPiedras2(piedrasGraficas2);
			//		}
			//		this->quitarPiedrasCentro(temp);
			//		this->ponerPiedras1(temp);
			//	}
			//}
			//else if (mesa.getNumBazas2() > mesa.getNumBazas1())
			//{
			//	if (mesa.getAlguienEstuche())
			//	{
			//		this->ponerPiedras2(this->min(mesa.getPiedrasEstuche(), piedrasGraficas1));
			//		this->quitarPiedras1(this->min(mesa.getPiedrasEstuche(), piedrasGraficas1));
			//		if (mesa.getParejaEstuche() == 2)
			//			this->escribirMensaje("La pareja " + mesa.getParejaEstuche() + 
			//			" tiene estuche y cobra " +  mesa.getPiedrasEstuche() + " vales.\n");
			//		else
			//			this->escribirMensaje("La pareja " + mesa.getParejaEstuche()
			//			+ " tiene estuche en contra y paga " +  mesa.getPiedrasEstuche() 
			//			+ " vales.\n");
			//	}
			//	if (mesa.getJugadorTriunfo() == 1 || mesa.getJugadorTriunfo() == 3)
			//	{
			//		this->ponerPiedras2(piedrasGraficasCentro);
			//		this->quitarPiedrasCentro(piedrasGraficasCentro);

			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));

			//			this->escribirMensaje("El jugador " + System::Convert::ToString(mesa.getJugadorSolo()+1)
			//				+ " ha ganado por " 
			//				+ mesa.getNumBazas1() + " a " + mesa.getNumBazas2() + ". Ha sido Sacada y cobra "
			//				+ mesa.getPiedrasSolo() + " por haberse ido solo.\n");
			//		}
			//		else
			//		{
			//			this->escribirMensaje("La pareja 2 ha ganado por " + mesa.getNumBazas1() + " a " +
			//				mesa.getNumBazas2() + ". Ha sido Sacada.\n");
			//		}				
			//	}
			//	else
			//	{
			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));
			//			this->escribirMensaje("La pareja 2 ha ganado por " + mesa.getNumBazas1() + " a "
			//				+ mesa.getNumBazas2() + ". Ha sido Codillo y cobra " + mesa.getPiedrasSolo()
			//				+ " porque el jugador " + System::Convert::ToString(mesa.getJugadorSolo()+1)
			//				+ " se fue solo.\n");
			//		}
			//		else
			//		{
			//			this->escribirMensaje("La pareja 2 ha ganado por " + mesa.getNumBazas1() + " a "
			//				+ mesa.getNumBazas2() + ". Ha sido Codillo.\n");
			//		}
			//		temp = piedrasGraficasCentro;
			//		if (piedrasGraficas1 > piedrasGraficasCentro)
			//		{
			//			this->quitarPiedras1(piedrasGraficasCentro);
			//			this->ponerPiedrasCentro(piedrasGraficasCentro);		
			//		}
			//		else
			//		{
			//			this->ponerPiedrasCentro(piedrasGraficas1);
			//			this->quitarPiedras1(piedrasGraficas1);
			//		}
			//		this->quitarPiedrasCentro(temp);
			//		this->ponerPiedras2(temp);
			//	}
			//}
			//else // Puestas
			//{
			//	if (mesa.getJugadorTriunfo() == 0 || mesa.getJugadorTriunfo() == 2)
			//	{
			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));
			//			this->quitarPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas1));
			//			this->escribirMensaje("Ha habido puestas y la pareja 2 cobra " + mesa.getPiedrasSolo()
			//				+ " porque el jugador " + mesa.getJugadorSolo() + " se fue solo.\n");
			//		}
			//		else
			//			this->escribirMensaje("Ha habido puestas.\n");
			//		if (piedrasGraficas1 > piedrasGraficasCentro)
			//		{
			//			this->quitarPiedras1(piedrasGraficasCentro);
			//			this->ponerPiedrasCentro(piedrasGraficasCentro);					
			//		}
			//		else
			//		{
			//			this->ponerPiedrasCentro(piedrasGraficas1);
			//			this->quitarPiedras1(piedrasGraficas1);							 
			//		}
			//	}
			//	else
			//	{
			//		if (mesa.getAlguienSolo())
			//		{
			//			this->ponerPiedras1(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->quitarPiedras2(this->min(mesa.getPiedrasSolo(), piedrasGraficas2));
			//			this->escribirMensaje("Ha habido puestas y la pareja 1 cobra " + mesa.getPiedrasSolo()
			//				+ " porque el jugador " + mesa.getJugadorSolo() + " se fue solo.\n");
			//		} 
			//		else
			//			this->escribirMensaje("Ha habido puestas.\n");
			//		if (piedrasGraficas2 > piedrasGraficasCentro)
			//		{
			//			this->quitarPiedras2(piedrasGraficasCentro);
			//			this->ponerPiedrasCentro(piedrasGraficasCentro);					
			//		}
			//		else
			//		{
			//			this->ponerPiedrasCentro(piedrasGraficas2);
			//			this->quitarPiedras2(piedrasGraficas2);
			//		}
			//	}
			//}	
		}

		void limpiarMesa()
		{
			//array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
			//	{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
			//	cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
			//	{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
			//	cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
			//	{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
			//	cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
			//	{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
			//	cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			//};
			//array<System::Windows::Forms::PictureBox^>^cartasMesa =
			//{cartaMesa0, cartaMesa1, cartaMesa2, cartaMesa3};
			//array<System::Windows::Forms::PictureBox^>^bazas1 =
			//{bazaAbajo0, bazaAbajo1, bazaAbajo2, bazaAbajo3,
			//bazaAbajo4, bazaAbajo5, bazaAbajo6, bazaAbajo7};
			//array<System::Windows::Forms::PictureBox^>^bazas2 =
			//{bazaIzquierda0, bazaIzquierda1, bazaIzquierda2, bazaIzquierda3,
			//bazaIzquierda4, bazaIzquierda5, bazaIzquierda6, bazaIzquierda7};

			//for (int jugador = 0; jugador < 4; jugador++)
			//{
			//	this->cambiarVisibilidad(cartasMesa[jugador], false);
			//	esperar(tiempoGraficos);
			//}
			//this->cambiarVisibilidadLabel(labelBazas1, false);
			//this->cambiarVisibilidadLabel(labelBazas2, false);
			//this->cambiarLabel(labelBazas1, "0");
			//this->cambiarLabel(labelBazas2, "0");
			//for (int carta = 0; carta < 8; carta++)
			//{			
			//	this->cambiarVisibilidad(bazas1[carta], false);
			//	esperar(tiempoGraficos);
			//}

			//for (int carta = 0; carta < 8; carta++)
			//{
			//	this->cambiarVisibilidad(bazas2[carta], false);
			//	esperar(tiempoGraficos);
			//}
			//for (int jugador = 0; jugador < 4; jugador++)
			//{
			//	for (int carta = 0; carta < 8; carta++)
			//	{
			//		if (cartasNoTiradas[jugador, carta])
			//		{
			//			this->actualizarImagen(cartasJugadores[jugador, carta], "gris", ".bmp");			
			//			esperar(tiempoGraficos);
			//		}
			//	}
			//}
			//this->cambiarVisibilidad(zangaArribaDerecha, false);
			//esperar(tiempoGraficos);
			//this->cambiarVisibilidad(zangaAbajoIzquierda, false);
			//esperar(tiempoGraficos);
			//this->cambiarSolo(false);
			//this->cambiarCinco(false);
			//this->cambiarTodas(false);
			///*this->cambiarVisibilidad(labelPiedras1, false);
			//this->cambiarVisibilidad(labelPiedras2, false);
			//this->cambiarVisibilidad(labelPiedrasCentro, false);*/			
		}



		void mostrarNumerosBazas()
		{
			/*this->cambiarVisibilidadLabel(labelBazas1, true);
			this->cambiarVisibilidadLabel(labelBazas2, true);*/
		}

		void mostrarNumerosPiedras()
		{
			/*this->cambiarVisibilidadLabel(labelPiedras1, true);
			this->cambiarVisibilidadLabel(labelPiedras2, true);
			if (piedrasGraficasCentro > 0)
				this->cambiarVisibilidadLabel(labelPiedrasCentro, true);*/
		}

		void limpiarMesaRapido()
		{
			//array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
			//	{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
			//	cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
			//	{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
			//	cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
			//	{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
			//	cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
			//	{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
			//	cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			//};
			//array<System::Windows::Forms::PictureBox^>^cartasMesa =
			//{cartaMesa0, cartaMesa1, cartaMesa2, cartaMesa3};
			//array<System::Windows::Forms::PictureBox^>^bazas1 =
			//{bazaAbajo0, bazaAbajo1, bazaAbajo2, bazaAbajo3,
			//bazaAbajo4, bazaAbajo5, bazaAbajo6, bazaAbajo7};
			//array<System::Windows::Forms::PictureBox^>^bazas2 =
			//{bazaIzquierda0, bazaIzquierda1, bazaIzquierda2, bazaIzquierda3,
			//bazaIzquierda4, bazaIzquierda5, bazaIzquierda6, bazaIzquierda7};

			//for (int jugador = 0; jugador < 4; jugador++)
			//{
			//	this->cambiarVisibilidad(cartasMesa[jugador], false);
			//}
			//for (int carta = 0; carta < 8; carta++)
			//{			
			//	this->cambiarVisibilidad(bazas1[carta], false);
			//}

			//for (int carta = 0; carta < 8; carta++)
			//{
			//	this->cambiarVisibilidad(bazas2[carta], false);
			//}
			//for (int jugador = 0; jugador < 4; jugador++)
			//{
			//	for (int carta = 0; carta < 8; carta++)
			//	{
			//		this->actualizarImagen(cartasJugadores[jugador, carta], "gris", ".bmp");			
			//	}
			//}
			//this->cambiarVisibilidad(zangaArribaDerecha, false);
			//this->cambiarVisibilidad(zangaAbajoIzquierda, false);
			//this->cambiarSolo(false);
			//this->cambiarCinco(false);
			//this->cambiarTodas(false);
			///*this->cambiarVisibilidad(labelPiedras1, false);
			//this->cambiarVisibilidad(labelPiedras2, false);
			//this->cambiarVisibilidad(labelPiedrasCentro, false);*/
			//this->cambiarVisibilidadLabel(labelBazas1, false);
			//this->cambiarVisibilidadLabel(labelBazas2, false);
			//this->cambiarLabel(labelBazas1, "0");
			//this->cambiarLabel(labelBazas2, "0");
		}

		void limpiarTapete()
		{
			/*array<System::Windows::Forms::PictureBox^>^cartasMesa =
			{cartaMesa0, cartaMesa1, cartaMesa2, cartaMesa3};
			for (int jugador = 0; jugador < 4; jugador++)
			{
				this->cambiarVisibilidad(cartasMesa[jugador], false);
			}*/
		}

		void limpiarPiedras()
		{
			/*array<System::Windows::Forms::PictureBox^>^piedras1 = {
				piedraUno0, piedraUno1, piedraUno2, piedraUno3,
				piedraUno4, piedraUno5, piedraUno6, piedraUno7,
				piedraUno8, piedraUno9, piedraUno10, piedraUno11,
				piedraUno12, piedraUno13, piedraUno14, piedraUno15,
				piedraUno16, piedraUno17, piedraUno18, piedraUno19,
				piedraUno20, piedraUno21, piedraUno22, piedraUno23,
				piedraUno24, piedraUno25, piedraUno26, piedraUno27,
				piedraUno28, piedraUno29, piedraUno30, piedraUno31,
			};
			array<System::Windows::Forms::PictureBox^>^piedras2 = {
				piedraDos0, piedraDos1, piedraDos2, piedraDos3,
				piedraDos4, piedraDos5, piedraDos6, piedraDos7,
				piedraDos8, piedraDos9, piedraDos10, piedraDos11,
				piedraDos12, piedraDos13, piedraDos14, piedraDos15,
				piedraDos16, piedraDos17, piedraDos18, piedraDos19,
				piedraDos20, piedraDos21, piedraDos22, piedraDos23,
				piedraDos24, piedraDos25, piedraDos26, piedraDos27,
				piedraDos28, piedraDos29, piedraDos30, piedraDos31,
			};
			array<System::Windows::Forms::PictureBox^>^piedrasCentro = {
				piedraCentro0, piedraCentro1, piedraCentro2, piedraCentro3,
				piedraCentro4, piedraCentro5, piedraCentro6, piedraCentro7,
				piedraCentro8, piedraCentro9, piedraCentro10, piedraCentro11,
				piedraCentro12, piedraCentro13, piedraCentro14, piedraCentro15,
				piedraCentro16, piedraCentro17, piedraCentro18, piedraCentro19,
				piedraCentro20, piedraCentro21, piedraCentro22, piedraCentro23,
				piedraCentro24, piedraCentro25, piedraCentro26, piedraCentro27,
				piedraCentro28, piedraCentro29, piedraCentro30, piedraCentro31,
			};
			for (int i = 0; i < 32; i++)
			{
				this->cambiarVisibilidad(piedras1[i], false);	
			}
			for (int i = 0; i < 32; i++)
			{
				this->cambiarVisibilidad(piedras2[i], false);	
			}
			for (int i = 0; i < 32; i++)
			{
				this->cambiarVisibilidad(piedrasCentro[i], false);	
			}
			piedrasGraficas1 = 0;
			piedrasGraficas2 = 0;
			piedrasGraficasCentro = 0;*/
		}

		void limpiarEtiquetas()
		{
			//this->cambiarLabelTriunfa("");
			//this->cambiarLabelTriunfos(20); // No pone nada
			//this->cambiarLabelProximoMano("");
		}


		int indiceOriginal(Carta carta, Mazo mazoOriginal)
		{
			int i;
			for (i = 0; i < 8; i++)
			{
				if (carta == mazoOriginal.getCarta(i))
					return i;
			}
			return 0;
		}


		void mostrarBaraja(int jugadorReparte)
		{
			/*array<System::Windows::Forms::PictureBox^>^barajas =
			{imagenBaraja0, imagenBaraja1, imagenBaraja2, imagenBaraja3};
			this->cambiarVisibilidad(barajas[jugadorReparte], true);*/
		}

		void mostrarBarajaCortada(int jugadorCorta)
		{
			/*array<System::Windows::Forms::PictureBox^>^barajasCortar =
			{barajaCortar0, barajaCortar1, barajaCortar2, barajaCortar3};
			this->cambiarVisibilidad(barajasCortar[jugadorCorta], true);*/
		}

		void ocultarBarajas()
		{
			/*array<System::Windows::Forms::PictureBox^>^barajas =
			{imagenBaraja0, imagenBaraja1, imagenBaraja2, imagenBaraja3};			
			for (int i = 0; i < 4; i++)
			{
				this->cambiarVisibilidad(barajas[i], false);
			}*/
		}

		void ocultarBarajasCortar()
		{
			/*array<System::Windows::Forms::PictureBox^>^barajasCortar =
			{barajaCortar0, barajaCortar1, barajaCortar2, barajaCortar3};
			for (int i = 0; i < 4; i++)
			{
				this->cambiarVisibilidad(barajasCortar[i], false);
			}*/
		}


		void anunciarVictoria(int numManos, Mesa mesa, System::TimeSpan^ tiempo)
		{
			/*int m = (int)tiempo->Minutes;
			int s = (int)tiempo->Seconds;
			if (mesa.getNumPiedras2() == 0)
			{
				if (m > 0)
					this->escribirMensaje("La pareja 1 gana en " + numManos 
					+ " manos y un tiempo de " + m + " minutos y "
					+ s + " segundos.\n");
				else
					this->escribirMensaje("La pareja 1 gana en " + numManos 
					+ " manos y un tiempo de " + s + " segundos.\n");
			}
			else
			{
				if (m > 0)
					this->escribirMensaje("La pareja 2 gana en " + numManos 
					+ " manos y un tiempo de " + m + " minutos y "
					+ s + " segundos.\n");
				else
					this->escribirMensaje("La pareja 2 gana en " + numManos 
					+ " manos y un tiempo de " + s + " segundos.\n");
			}*/
		}

		void limpiarCartasJugador(int jugador)
		{
			/*array<System::Windows::Forms::PictureBox^, 2>^cartasJugadores = {
				{cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
				cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7}, 
				{cartaDerecha0, cartaDerecha1, cartaDerecha2, cartaDerecha3, 
				cartaDerecha4, cartaDerecha5, cartaDerecha6, cartaDerecha7}, 
				{cartaArriba0, cartaArriba1, cartaArriba2, cartaArriba3, 
				cartaArriba4, cartaArriba5, cartaArriba6, cartaArriba7}, 
				{cartaIzquierda0, cartaIzquierda1, cartaIzquierda2, cartaIzquierda3, 
				cartaIzquierda4, cartaIzquierda5, cartaIzquierda6, cartaIzquierda7}
			};
			for (int carta = 0; carta < 8; carta++)
			{
				this->actualizarImagen(cartasJugadores[jugador, carta], "gris", ".bmp");			
				esperar(tiempoGraficos);
			}*/

		}

		int min(int a, int b)
		{
			if (a <= b)
				return a;
			else
				return b;
		}

		void pedirEstuche(Mesa mesa)
		{
			/*if (mesa.getAlguienEstuche())
			{
				if (mesa.getParejaEstuche() == 1)
				{
					if (mesa.getNumBazas1() > mesa.getNumBazas2())
						this->escribirMensaje("La pareja 1 canta Estuche.");
					else
						this->escribirMensaje("La pareja 2 canta Estuche en contra.");
				}
				else
				{
					if (mesa.getNumBazas2() > mesa.getNumBazas1())
						this->escribirMensaje("La pareja 2 canta Estuche.");
					else
						this->escribirMensaje("La pareja 1 canta Estuche en contra.");
				}
			}*/
		}

		void activarBotonesHablaPrimero(Mesa mesa)
		{
			situacion = primero;
			cambiarEstadoBoton(this->botonJuego, true);			
			cambiarEstadoBoton(this->botonMeVoySolo, true);		
			if (mesa.getNumPiedras1() > 0)
				cambiarEstadoBoton(this->botonPaso, true);											
		}

		void activarBotonesHablaDespues()
		{
			situacion = despues;
			cambiarEstadoBoton(this->botonJuego, true);
			cambiarEstadoBoton(this->botonVayaSolo, true);
		}

		void activarBotonesAceptaSolo()
		{
			situacion = aceptarSolo;
			cambiarEstadoBoton(this->botonMeVoySolo, true);
			cambiarEstadoBoton(this->botonVayaUsted, true);
		}

		void activarBotonesHablaZanga()
		{
			situacion = primeroZanga;
			cambiarEstadoBoton(this->botonJuego, true);
			cambiarEstadoBoton(this->botonMeVoySolo, true);
			cambiarEstadoBoton(this->botonRechazoZanga, true);			
		}

		void activarBotonesTriunfo()
		{
			cambiarEstadoBoton(this->botonEspadas, true);
			cambiarEstadoBoton(this->botonBastos, true);
			cambiarEstadoBoton(this->botonOros, true);	
			cambiarEstadoBoton(this->botonCopas, true);	

		}

		void activarBotonesCinco()
		{
			cambiarEstadoBoton(this->botonCinco, true);			
			cambiarEstadoBoton(this->botonJuego, true);		
			situacion = cincoPedir;
		}

		void activarBotonesTodas()
		{
			cambiarEstadoBoton(this->botonTodas, true);		
			cambiarEstadoBoton(this->botonJuego, true);		
			situacion = todasPedir;
		}


		void activarBotonesHablaRecambio()
		{
			situacion = primeroRecambio;
			cambiarEstadoBoton(this->botonJuego, true);
			cambiarEstadoBoton(this->botonMeVoySolo, true);
		}

		void activarCartas(int turno, Mazo mazoOriginal, Jugador usuario, Mesa mesa)
		{
			if (turno == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					if (cartasNoTiradas[0, i])
					{
						//cartasResaltadas[carta] = true;
						cartasActivas[i] = true;
					}
				}
				//refrescar();
			}
			else
			{
				for (int i = 0; i < 8; i++)
				{
					if (cartasNoTiradas[0, i])
					{
						if (usuario.esLegal(mazoOriginal.getCarta(i), 
							mesa.getCarta(mesa.getJugadorMano()), mesa.getTriunfo()))
						{
							//cartasResaltadas[carta] = true;
							cartasActivas[i] = true;
						}
					}
					//refrescar();
				}
			}		
		}

		void desactivarBotones()
		{
			cambiarEstadoBoton(this->botonJuego, false);		
			cambiarEstadoBoton(this->botonPaso, false);		
			cambiarEstadoBoton(this->botonMeVoySolo, false);		
			cambiarEstadoBoton(this->botonVayaSolo, false);		
			cambiarEstadoBoton(this->botonVayaUsted, false);		
			cambiarEstadoBoton(this->botonRechazoZanga, false);		
			cambiarEstadoBoton(this->botonCinco, false);		
			cambiarEstadoBoton(this->botonTodas, false);
			cambiarEstadoBoton(this->botonBastos, false);
			cambiarEstadoBoton(this->botonEspadas, false);
			cambiarEstadoBoton(this->botonOros, false);
			cambiarEstadoBoton(this->botonCopas, false);

		}

		void desactivarCartas()
		{
			for (int i = 0; i < 8; i++)
			{
				//cartasResaltadas[i] = false;
				cartasActivas[i] = false;
			}
		}



		void dibujarRectangulo(PaintEventArgs^ e, int carta)
		{
			array<System::Windows::Forms::PictureBox^>^cartasUsuario = {
				cartaAbajo0, cartaAbajo1, cartaAbajo2, cartaAbajo3, 
				cartaAbajo4, cartaAbajo5, cartaAbajo6, cartaAbajo7};
				System::Drawing::Rectangle bordes = cartasUsuario[carta]->Bounds;
				Pen^ linea = gcnew Pen(System::Drawing::Color::Red, 5.0f);


				// Set the LineJoin property.
				linea->LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;

				// Draw a rectangle.
				e->Graphics->DrawRectangle(linea, bordes);
				delete(linea);
		}



		void resaltarJugador(int jugador, bool resaltado)
		{
			/*array<Label^>^ jugadores = 
			{labelJugador0, labelJugador1, labelJugador2, labelJugador3};
			if (resaltado)
				cambiarColor(jugadores[jugador], System::Drawing::Color::Red);
			else
				cambiarColor(jugadores[jugador], System::Drawing::Color::Black);*/

		}
		//// FUNCIONES QUE REQUIEREN DELEGATES

		delegate void escribirMensajeDelegate(String^ mensaje);

		void escribirMensaje(String^ mensaje)
		{	
			if (salida->InvokeRequired == false)
			{

				salida->AppendText("[" + System::DateTime::Now.ToLongTimeString()
					+ "] " + mensaje);
			}
			else 
			{					 
				escribirMensajeDelegate^ myThreadDelegate =
					gcnew escribirMensajeDelegate(this, &ZangaGraficoDefinitivo::Form1::escribirMensaje);
				array<Object^>^arrayObjects = {mensaje};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void actualizarImagenDelegate(PictureBox^ imagen, String^ nombreImagen,
			String^ extension);

		void actualizarImagen(PictureBox^ imagen, String^ nombreImagen, String^ extension)
		{	
			String^ nombreFichero = "Baraja española\\";
			if (imagen->InvokeRequired == false)
			{			
				nombreFichero += nombreImagen;
				imagen->Image = System::Drawing::Image::FromFile(nombreFichero + extension);
			}
			else 
			{					 
				actualizarImagenDelegate^ myThreadDelegate =
					gcnew actualizarImagenDelegate(this, &ZangaGraficoDefinitivo::Form1::actualizarImagen);
				array<Object^>^arrayObjects = {imagen, nombreImagen, extension};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarVisibilidadDelegate(PictureBox^ imagen, bool visible);

		void cambiarVisibilidad(PictureBox^ imagen, bool visible)
		{	
			if (imagen->InvokeRequired == false)
			{			
				imagen->Visible = visible;
			}
			else 
			{					 
				cambiarVisibilidadDelegate^ myThreadDelegate =
					gcnew cambiarVisibilidadDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarVisibilidad);
				array<Object^>^arrayObjects = {imagen, visible};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarVisibilidadLabelDelegate(Label^ imagen, bool visible);

		void cambiarVisibilidadLabel(Label^ imagen, bool visible)
		{	
			if (imagen->InvokeRequired == false)
			{			
				imagen->Visible = visible;
			}
			else 
			{					 
				cambiarVisibilidadLabelDelegate^ myThreadDelegate =
					gcnew cambiarVisibilidadLabelDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarVisibilidadLabel);
				array<Object^>^arrayObjects = {imagen, visible};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarSoloDelegate(bool estado);

		void cambiarSolo(bool estado)
		{	
			if (checkBoxSolo->InvokeRequired == false)
			{
				if (estado)
					checkBoxSolo->CheckState = CheckState::Checked;
				else
					checkBoxSolo->CheckState = CheckState::Unchecked;
			}
			else 
			{					 
				cambiarSoloDelegate^ myThreadDelegate =
					gcnew cambiarSoloDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarSolo);
				array<Object^>^arrayObjects = {estado};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarCincoDelegate(bool estado);

		void cambiarCinco(bool estado)
		{	
			if (checkBoxCinco->InvokeRequired == false)
			{			
				if (estado)
					checkBoxCinco->CheckState = CheckState::Checked;
				else
					checkBoxCinco->CheckState = CheckState::Unchecked;
			}
			else 
			{					 
				cambiarCincoDelegate^ myThreadDelegate =
					gcnew cambiarCincoDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarCinco);
				array<Object^>^arrayObjects = {estado};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarTodasDelegate(bool estado);

		void cambiarTodas(bool estado)
		{	
			if (checkBoxTodas->InvokeRequired == false)
			{			
				if (estado)
					checkBoxTodas->CheckState = CheckState::Checked;
				else
					checkBoxTodas->CheckState = CheckState::Unchecked;
			}
			else 
			{					 
				cambiarTodasDelegate^ myThreadDelegate =
					gcnew cambiarTodasDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarTodas);
				array<Object^>^arrayObjects = {estado};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarLabelTriunfosDelegate(int triunfo);

		void cambiarLabelTriunfos(int triunfo)
		{	
			if (labelTriunfos->InvokeRequired == false)
			{	
				switch(triunfo)
				{
				case (int)bastos:
					{
						labelTriunfos->Text = "Bastos";
						labelTriunfos->ForeColor = System::Drawing::Color::Green;
						break;
					}
				case (int)copas:
					{
						labelTriunfos->Text = "Copas";
						labelTriunfos->ForeColor = System::Drawing::Color::Red;
						break;
					}
				case (int)espadas:
					{
						labelTriunfos->Text = "Espadas";
						labelTriunfos->ForeColor = System::Drawing::Color::Blue;
						break;
					}
				case (int) oros:
					{
						labelTriunfos->Text = "Oros";
						labelTriunfos->ForeColor = System::Drawing::Color::Yellow;
						break;
					}
				default:
					{
						labelTriunfos->Text = "";
						break;
					}
				}					 
			}
			else 
			{					 
				cambiarLabelTriunfosDelegate^ myThreadDelegate =
					gcnew cambiarLabelTriunfosDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarLabelTriunfos);
				array<Object^>^arrayObjects = {triunfo};
				this->Invoke(myThreadDelegate, arrayObjects);
			}				 
		}

		delegate void cambiarLabelTriunfaDelegate(String^ texto);

		void cambiarLabelTriunfa(String^ texto)
		{	
			if (labelTriunfa->InvokeRequired == false)
			{			
				labelTriunfa->Text = texto;
			}
			else 
			{					 
				cambiarLabelTriunfaDelegate^ myThreadDelegate =
					gcnew cambiarLabelTriunfaDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarLabelTriunfa);
				array<Object^>^arrayObjects = {texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarLabelProximoManoDelegate(String^ texto);

		void cambiarLabelProximoMano(String^ texto)
		{	
			if (labelProximoMano->InvokeRequired == false)
			{			
				labelProximoMano->Text = texto;
			}
			else 
			{					 
				cambiarLabelProximoManoDelegate^ myThreadDelegate =
					gcnew cambiarLabelProximoManoDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarLabelProximoMano);
				array<Object^>^arrayObjects = {texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void traerAlFrenteDelegate(PictureBox^ imagen);
		void traerAlFrente(PictureBox^ imagen)
		{
			if (imagen->InvokeRequired == false)
			{			
				imagen->BringToFront();
			}
			else 
			{					 
				traerAlFrenteDelegate^ myThreadDelegate =
					gcnew traerAlFrenteDelegate(this, &ZangaGraficoDefinitivo::Form1::traerAlFrente);
				array<Object^>^arrayObjects = {imagen};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void limpiarSalidaDelegate();
		void limpiarSalida()
		{
			if (salida->InvokeRequired == false)
			{			
				salida->Clear();
			}
			else 
			{					 
				limpiarSalidaDelegate^ myThreadDelegate =
					gcnew limpiarSalidaDelegate(this, &ZangaGraficoDefinitivo::Form1::limpiarSalida);
				array<Object^>^arrayObjects = {};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void cambiarBotonComenzarDelegate(String^ texto);
		void cambiarBotonComenzar(String^ texto)
		{	
			if (botonComenzar->InvokeRequired == false)
			{			
				botonComenzar->Text = texto;
			}
			else 
			{					 
				cambiarBotonComenzarDelegate^ myThreadDelegate =
					gcnew cambiarBotonComenzarDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarBotonComenzar);
				array<Object^>^arrayObjects = {texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarLabelDelegate(Label^ label, String^ texto);

		void cambiarLabel(Label^ label, String^ texto)
		{	
			if (label->InvokeRequired == false)
			{			
				label->Text = texto;
			}
			else 
			{					 
				cambiarLabelDelegate^ myThreadDelegate =
					gcnew cambiarLabelDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarLabel);
				array<Object^>^arrayObjects = {label, texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarEstadoBotonDelegate(Button^ boton, bool activado);

		void cambiarEstadoBoton(Button^ boton, bool activado)
		{
			if (boton->InvokeRequired == false)
			{			
				boton->Enabled = activado;
			}
			else 
			{					 
				cambiarEstadoBotonDelegate^ myThreadDelegate =
					gcnew cambiarEstadoBotonDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarEstadoBoton);
				array<Object^>^arrayObjects = {boton, activado};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void refrescarDelegate();
		void refrescar()
		{
			if (this->InvokeRequired == false)
			{			
				this->Refresh();
			}
			else 
			{					 
				refrescarDelegate^ myThreadDelegate =
					gcnew refrescarDelegate(this, &ZangaGraficoDefinitivo::Form1::refrescar);
				array<Object^>^arrayObjects = {};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}




		delegate void cambiarColorDelegate(Label^ label, System::Drawing::Color color);
		void cambiarColor(Label^ label, System::Drawing::Color color)
		{
			if (label->InvokeRequired == false)
			{			
				label->ForeColor = color;
			}
			else 
			{					 
				cambiarColorDelegate^ myThreadDelegate =
					gcnew cambiarColorDelegate(this, &ZangaGraficoDefinitivo::Form1::cambiarColor);
				array<Object^>^arrayObjects = {label, color};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}



		//// MANEJADORES DE EVENTOS

		System::Void botonComenzar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->botonComenzar->Text = "Reiniciar";			
			if (hiloJuego->IsAlive)
			{
				reanudar();
				hiloJuego->Abort();							
			}
			ThreadStart ^myThreadDelegate = 
				gcnew ThreadStart(this, &ZangaGraficoDefinitivo::Form1::mainHiloJuego);
			hiloJuego = gcnew Thread(myThreadDelegate);
			hiloJuego->IsBackground = true;
			hiloSuspendido = false;
			this->limpiarMesaRapido(); 
			this->limpiarPiedras();
			this->limpiarEtiquetas();
			this->limpiarSalida();
			this->ocultarBarajas();
			this->ocultarBarajasCortar();
			hiloJuego->Start();
		}

	private: System::Void botonSalir_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Application::Exit();
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ThreadStart ^myThreadDelegate = 
					 gcnew ThreadStart(this, &ZangaGraficoDefinitivo::Form1::mainHiloJuego);
				 hiloJuego = gcnew Thread(myThreadDelegate);
				 hiloJuego->IsBackground = true;				 
				 piedrasGraficas1 = 0;
				 piedrasGraficas2 = 0;
				 piedrasGraficasCentro = 0;
				 botonComenzar->Focus();
				 // Chapuza
				 cartasActivas = gcnew array<bool>(8);
				 cartasNoTiradas = gcnew array<bool, 2>(4, 8);
				 cartasResaltadas = gcnew array<bool>(8);
				 for (int i = 0; i < 8; i++)
				 {
					 cartasActivas[i] = false;
					 for (int j = 0; j < 4; j++)
					cartasNoTiradas[j, i] = true;
					 cartasResaltadas[i] = false;
				 }
				 this->usuarioCartaElegida = 0;
				 this->usuarioFrasePrimero = juego;
				 this->usuarioFraseDespues = juegoTambien;
				 this->usuarioFraseZanga = juegoZanga;
				 this->usuarioTriunfo = bastos;
				 this->usuarioAceptaSolo = false;
				 this->usuarioPideCinco = false;
				 this->usuarioPideTodas = false;
				 situacion = primero;
				 hiloSuspendido = false;
			 }
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			 {
				 if (hiloJuego->IsAlive)
				 {
					 reanudar();
					 hiloJuego->Abort();							
				 }
			 }


	private: System::Void botonJuego_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 switch (situacion)
				 {
				 case primero:
					 usuarioFrasePrimero = juego;
					 desactivarBotones();
					 reanudar();
					 break;
				 case despues:
					 usuarioFraseDespues = juegoTambien;
					 desactivarBotones();
					 reanudar();
					 break;
				 case primeroRecambio:
					 usuarioFraseRecambio = juegoRecambio;
					 desactivarBotones();
					 reanudar();
					 break;
				 case cincoPedir:
					 usuarioPideCinco = false;
					 desactivarBotones();
					 reanudar();
					 break;
				 case todasPedir:
					usuarioPideTodas = false;
					 desactivarBotones();
					 reanudar();
					 break;
				 default:
					 usuarioFraseZanga = juegoZanga;
					 desactivarBotones();
					 reanudar();
					 break;
				 }

			 }

	private: System::Void botonPaso_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioFrasePrimero = paso;
				 desactivarBotones();
				 reanudar();				 
			 }
	private: System::Void botonMeVoySolo_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 switch (situacion)
				 {
				 case primero:
					 usuarioFrasePrimero = meVoySolo;
					 desactivarBotones();
					 reanudar();
					 break;
				 case aceptarSolo:
					 usuarioAceptaSolo = true;
					 desactivarBotones();
					 reanudar();
					 break;
				 case primeroRecambio:
					 usuarioFraseRecambio = meVoySoloRecambio;
					 desactivarBotones();
					 reanudar();
					 break;
				 default:
					 usuarioFraseZanga = meVoySoloZanga;
					 desactivarBotones();
					 reanudar();
					 break;
				 }

			 }
	private: System::Void botonVayaSolo_Click(System::Object^  sender, System::EventArgs^  e) {
				 usuarioFraseDespues = vayaSolo;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonVayaUsted_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioAceptaSolo = false;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonRechazoZanga_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioFraseZanga = rechazoZanga;
				 desactivarBotones();
				 reanudar();

			 }
	private: System::Void botonCinco_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioPideCinco = true;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonTodas_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioPideTodas = true;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void cartaAbajo0_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (usuarioJuega && cartasActivas[0])
				 {
					 usuarioCartaElegida = 0;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (usuarioJuega && cartasActivas[1])
				 {
					 usuarioCartaElegida = 1;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[2])
				 {
					 usuarioCartaElegida = 2;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo3_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[3])
				 {
					 usuarioCartaElegida = 3;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[4])
				 {
					 usuarioCartaElegida = 4;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo5_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[5])
				 {
					 usuarioCartaElegida = 5;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo6_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[6])
				 {
					 usuarioCartaElegida = 6;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void cartaAbajo7_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (usuarioJuega && cartasActivas[7])
				 {
					 usuarioCartaElegida = 7;
					 desactivarCartas();
					 reanudar();
				 }
			 }
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			 {
				 for (int carta = 0; carta < 8; carta++)
				 {
					 if (cartasResaltadas[carta])
						 dibujarRectangulo(e, carta);
				 }
			 }
	private: System::Void botonEspadas_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 usuarioTriunfo = espadas;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonBastos_Click(System::Object^  sender, System::EventArgs^  e) {
				 usuarioTriunfo = bastos;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonOros_Click(System::Object^  sender, System::EventArgs^  e) {
				 usuarioTriunfo = oros;
				 desactivarBotones();
				 reanudar();
			 }
	private: System::Void botonCopas_Click(System::Object^  sender, System::EventArgs^  e) {
				 usuarioTriunfo = copas;
				 desactivarBotones();
				 reanudar();
			 }
	};
}

