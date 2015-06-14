//#ifndef _FORMENTRADA_H_
//#define _FORMENTRADA_H_

#ifndef _FORM1_H_
#include "Form1.h"
#endif 
#ifndef _FORMMULTI_H_
#include "FormMulti.h"
#endif 

ref class Form1;

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;



namespace ZangaGraficoDefinitivo {

	/// <summary>
	/// Summary for FormEntrada
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormEntrada : public System::Windows::Forms::Form
	{
	public:
		FormEntrada(void)
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
		~FormEntrada()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  botonUnJugador;
	protected: 
	private: System::Windows::Forms::Button^  botonMultijugador;
	private: System::Windows::Forms::Button^  botonSimulador;
	private: System::Windows::Forms::Button^  botonSalir;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormEntrada::typeid));
			this->botonUnJugador = (gcnew System::Windows::Forms::Button());
			this->botonMultijugador = (gcnew System::Windows::Forms::Button());
			this->botonSimulador = (gcnew System::Windows::Forms::Button());
			this->botonSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// botonUnJugador
			// 
			this->botonUnJugador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonUnJugador->Location = System::Drawing::Point(273, 111);
			this->botonUnJugador->Name = L"botonUnJugador";
			this->botonUnJugador->Size = System::Drawing::Size(410, 110);
			this->botonUnJugador->TabIndex = 0;
			this->botonUnJugador->Text = L"Un Jugador";
			this->botonUnJugador->UseVisualStyleBackColor = true;
			this->botonUnJugador->Click += gcnew System::EventHandler(this, &FormEntrada::botonUnJugador_Click);
			// 
			// botonMultijugador
			// 
			this->botonMultijugador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonMultijugador->Location = System::Drawing::Point(273, 227);
			this->botonMultijugador->Name = L"botonMultijugador";
			this->botonMultijugador->Size = System::Drawing::Size(410, 110);
			this->botonMultijugador->TabIndex = 1;
			this->botonMultijugador->Text = L"Multijugador";
			this->botonMultijugador->UseVisualStyleBackColor = true;
			this->botonMultijugador->Click += gcnew System::EventHandler(this, &FormEntrada::botonMultijugador_Click);
			// 
			// botonSimulador
			// 
			this->botonSimulador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonSimulador->Location = System::Drawing::Point(273, 343);
			this->botonSimulador->Name = L"botonSimulador";
			this->botonSimulador->Size = System::Drawing::Size(410, 110);
			this->botonSimulador->TabIndex = 2;
			this->botonSimulador->Text = L"Simulador";
			this->botonSimulador->UseVisualStyleBackColor = true;
			this->botonSimulador->Click += gcnew System::EventHandler(this, &FormEntrada::botonSimulador_Click);
			// 
			// botonSalir
			// 
			this->botonSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->botonSalir->Location = System::Drawing::Point(273, 459);
			this->botonSalir->Name = L"botonSalir";
			this->botonSalir->Size = System::Drawing::Size(410, 110);
			this->botonSalir->TabIndex = 3;
			this->botonSalir->Text = L"Salir";
			this->botonSalir->UseVisualStyleBackColor = true;
			this->botonSalir->Click += gcnew System::EventHandler(this, &FormEntrada::botonSalir_Click);
			// 
			// FormEntrada
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 681);
			this->Controls->Add(this->botonSalir);
			this->Controls->Add(this->botonSimulador);
			this->Controls->Add(this->botonMultijugador);
			this->Controls->Add(this->botonUnJugador);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FormEntrada";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"La Zanga 1.0";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonUnJugador_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 array<Jugador^>^ jugadores = {
					 gcnew Jugador("Jugador", 0, 10, 0, 0),
					 gcnew Jugador("Ordenador 1", 1, 4, 0, 0),
					 gcnew Jugador("Ordenador 2", 2, 4, 0, 0),
					 gcnew Jugador("Ordenador 3", 3, 4, 0, 0)};

				 Form1^ f1 = gcnew Form1(jugadores);
				 this->Hide();
				 f1->Show();
			 }
	private: System::Void botonSalir_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /*Carta^ a = gcnew Carta(cinco, espadas);
				 Carta^ b = a;
				 Carta^ c = gcnew Carta();
				 *c = *a;*/
				 Application::Exit();
			 }
	private: System::Void botonMultijugador_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 FormMulti^ fm = gcnew FormMulti();
				 this->Hide();
				 fm->Show();
			 }
	private: System::Void botonSimulador_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 array<Jugador^>^ jugadores = {
					 gcnew Jugador("Ordenador 0", 0, 4, 0, 0),
					 gcnew Jugador("Ordenador 1", 1, 4, 0, 0),
					 gcnew Jugador("Ordenador 2", 2, 4, 0, 0),
					 gcnew Jugador("Ordenador 3", 3, 4, 0, 0)};
					 Form1^ f1 = gcnew Form1(jugadores);
					 this->Hide();
					 f1->Show();
			 }
	};
}