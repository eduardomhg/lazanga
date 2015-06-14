
#include "Form1.h"
//#define  _AFXDLL
//#include "afxinet.h"

#ifndef _TIPOS_H_
#include "tipos.h"
#endif 

#ifndef _JUGADOR_H_
  #include "Jugador.h"
#endif

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

namespace ZangaGraficoDefinitivo {

	/// <summary>
	/// Summary for FormMulti
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormMulti : public System::Windows::Forms::Form
	{
	public:
		FormMulti(void)
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
		~FormMulti()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  botonCrearServer;
	private: System::Windows::Forms::Button^  botonUnirse;
	private: System::Windows::Forms::Label^  labelIP;
	private: System::Windows::Forms::TextBox^  textBoxIP;
	private: System::Windows::Forms::TextBox^  textBoxChat;
	private: System::Windows::Forms::TextBox^  textBoxEnviar;
	private: System::Windows::Forms::Button^  botonEnviar;
	private: System::Windows::Forms::ComboBox^  comboBoxJug1;
	private: System::Windows::Forms::Label^  labelJug1;
	private: System::Windows::Forms::Label^  labelJug2;
	private: System::Windows::Forms::ComboBox^  comboBoxJug2;
	private: System::Windows::Forms::Label^  labelJug3;
	private: System::Windows::Forms::ComboBox^  comboBoxJug3;
	private: System::Windows::Forms::Label^  labelJug4;
	private: System::Windows::Forms::ComboBox^  comboBoxJug4;
	private: System::Windows::Forms::Button^  botonComenzar;
	private: System::Windows::Forms::Button^  botonMenuPrincipal;
	private: System::Windows::Forms::Button^  botonDesconectarServidor;

	private: System::Windows::Forms::TextBox^  textBoxMiIP;

	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;

	private: System::Windows::Forms::Panel^  panel4;

	private: System::Windows::Forms::TextBox^  textBoxMiNombre;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  botonDesconectarCliente;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  botonBorrar;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente0Write;


	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente2Write;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente3Write;


	private: System::Windows::Forms::CheckBox^  checkBoxCliente1Write;





	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBoxMiVoz;
	private: System::Windows::Forms::TextBox^  textBoxJug3;
	private: System::Windows::Forms::TextBox^  textBoxJug1;
	private: System::Windows::Forms::TextBox^  textBoxJug4;
	private: System::Windows::Forms::TextBox^  textBoxJug2;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente2Read;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente3Read;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente1Read;
	private: System::Windows::Forms::CheckBox^  checkBoxCliente0Read;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMulti::typeid));
			this->botonCrearServer = (gcnew System::Windows::Forms::Button());
			this->botonUnirse = (gcnew System::Windows::Forms::Button());
			this->labelIP = (gcnew System::Windows::Forms::Label());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->textBoxChat = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEnviar = (gcnew System::Windows::Forms::TextBox());
			this->botonEnviar = (gcnew System::Windows::Forms::Button());
			this->comboBoxJug1 = (gcnew System::Windows::Forms::ComboBox());
			this->labelJug1 = (gcnew System::Windows::Forms::Label());
			this->labelJug2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxJug2 = (gcnew System::Windows::Forms::ComboBox());
			this->labelJug3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxJug3 = (gcnew System::Windows::Forms::ComboBox());
			this->labelJug4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxJug4 = (gcnew System::Windows::Forms::ComboBox());
			this->botonComenzar = (gcnew System::Windows::Forms::Button());
			this->botonMenuPrincipal = (gcnew System::Windows::Forms::Button());
			this->botonDesconectarServidor = (gcnew System::Windows::Forms::Button());
			this->textBoxMiIP = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->botonDesconectarCliente = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBoxJug3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJug1 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBoxJug4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJug2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMiNombre = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->botonBorrar = (gcnew System::Windows::Forms::Button());
			this->checkBoxCliente0Write = (gcnew System::Windows::Forms::CheckBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->checkBoxCliente2Read = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente3Read = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente1Read = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente0Read = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBoxCliente2Write = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente3Write = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCliente1Write = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxMiVoz = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// botonCrearServer
			// 
			this->botonCrearServer->Location = System::Drawing::Point(21, 28);
			this->botonCrearServer->Name = L"botonCrearServer";
			this->botonCrearServer->Size = System::Drawing::Size(112, 35);
			this->botonCrearServer->TabIndex = 0;
			this->botonCrearServer->Text = L"Crear un Servidor";
			this->botonCrearServer->UseVisualStyleBackColor = true;
			this->botonCrearServer->Click += gcnew System::EventHandler(this, &FormMulti::botonCrearServer_Click);
			// 
			// botonUnirse
			// 
			this->botonUnirse->Location = System::Drawing::Point(21, 28);
			this->botonUnirse->Name = L"botonUnirse";
			this->botonUnirse->Size = System::Drawing::Size(112, 35);
			this->botonUnirse->TabIndex = 1;
			this->botonUnirse->Text = L"Unirse a una Partida";
			this->botonUnirse->UseVisualStyleBackColor = true;
			this->botonUnirse->Click += gcnew System::EventHandler(this, &FormMulti::botonUnirse_Click);
			// 
			// labelIP
			// 
			this->labelIP->Location = System::Drawing::Point(18, 79);
			this->labelIP->Name = L"labelIP";
			this->labelIP->Size = System::Drawing::Size(76, 35);
			this->labelIP->TabIndex = 2;
			this->labelIP->Text = L"IP del Servidor";
			this->labelIP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(110, 87);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(152, 20);
			this->textBoxIP->TabIndex = 3;
			// 
			// textBoxChat
			// 
			this->textBoxChat->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxChat->Location = System::Drawing::Point(59, 228);
			this->textBoxChat->Multiline = true;
			this->textBoxChat->Name = L"textBoxChat";
			this->textBoxChat->ReadOnly = true;
			this->textBoxChat->Size = System::Drawing::Size(588, 332);
			this->textBoxChat->TabIndex = 4;
			// 
			// textBoxEnviar
			// 
			this->textBoxEnviar->Enabled = false;
			this->textBoxEnviar->Location = System::Drawing::Point(59, 583);
			this->textBoxEnviar->Name = L"textBoxEnviar";
			this->textBoxEnviar->Size = System::Drawing::Size(588, 20);
			this->textBoxEnviar->TabIndex = 5;
			// 
			// botonEnviar
			// 
			this->botonEnviar->Enabled = false;
			this->botonEnviar->Location = System::Drawing::Point(59, 622);
			this->botonEnviar->Name = L"botonEnviar";
			this->botonEnviar->Size = System::Drawing::Size(150, 35);
			this->botonEnviar->TabIndex = 6;
			this->botonEnviar->Text = L"Enviar";
			this->botonEnviar->UseVisualStyleBackColor = true;
			this->botonEnviar->Click += gcnew System::EventHandler(this, &FormMulti::botonEnviar_Click);
			// 
			// comboBoxJug1
			// 
			this->comboBoxJug1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxJug1->FormattingEnabled = true;
			this->comboBoxJug1->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Ordenador"});
			this->comboBoxJug1->Location = System::Drawing::Point(24, 45);
			this->comboBoxJug1->Name = L"comboBoxJug1";
			this->comboBoxJug1->Size = System::Drawing::Size(175, 21);
			this->comboBoxJug1->TabIndex = 7;
			this->comboBoxJug1->Visible = false;
			this->comboBoxJug1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMulti::comboBoxJug1_SelectedIndexChanged);
			// 
			// labelJug1
			// 
			this->labelJug1->AutoSize = true;
			this->labelJug1->Location = System::Drawing::Point(21, 20);
			this->labelJug1->Name = L"labelJug1";
			this->labelJug1->Size = System::Drawing::Size(54, 13);
			this->labelJug1->TabIndex = 8;
			this->labelJug1->Text = L"Jugador 1";
			// 
			// labelJug2
			// 
			this->labelJug2->AutoSize = true;
			this->labelJug2->Location = System::Drawing::Point(19, 18);
			this->labelJug2->Name = L"labelJug2";
			this->labelJug2->Size = System::Drawing::Size(54, 13);
			this->labelJug2->TabIndex = 10;
			this->labelJug2->Text = L"Jugador 2";
			// 
			// comboBoxJug2
			// 
			this->comboBoxJug2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxJug2->FormattingEnabled = true;
			this->comboBoxJug2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Ordenador"});
			this->comboBoxJug2->Location = System::Drawing::Point(22, 43);
			this->comboBoxJug2->Name = L"comboBoxJug2";
			this->comboBoxJug2->Size = System::Drawing::Size(175, 21);
			this->comboBoxJug2->TabIndex = 9;
			this->comboBoxJug2->Visible = false;
			this->comboBoxJug2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMulti::comboBoxJug2_SelectedIndexChanged);
			// 
			// labelJug3
			// 
			this->labelJug3->AutoSize = true;
			this->labelJug3->Location = System::Drawing::Point(21, 91);
			this->labelJug3->Name = L"labelJug3";
			this->labelJug3->Size = System::Drawing::Size(54, 13);
			this->labelJug3->TabIndex = 12;
			this->labelJug3->Text = L"Jugador 3";
			// 
			// comboBoxJug3
			// 
			this->comboBoxJug3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxJug3->FormattingEnabled = true;
			this->comboBoxJug3->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Ordenador"});
			this->comboBoxJug3->Location = System::Drawing::Point(24, 116);
			this->comboBoxJug3->Name = L"comboBoxJug3";
			this->comboBoxJug3->Size = System::Drawing::Size(175, 21);
			this->comboBoxJug3->TabIndex = 11;
			this->comboBoxJug3->Visible = false;
			this->comboBoxJug3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMulti::comboBoxJug3_SelectedIndexChanged);
			// 
			// labelJug4
			// 
			this->labelJug4->AutoSize = true;
			this->labelJug4->Location = System::Drawing::Point(19, 94);
			this->labelJug4->Name = L"labelJug4";
			this->labelJug4->Size = System::Drawing::Size(54, 13);
			this->labelJug4->TabIndex = 14;
			this->labelJug4->Text = L"Jugador 4";
			// 
			// comboBoxJug4
			// 
			this->comboBoxJug4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxJug4->FormattingEnabled = true;
			this->comboBoxJug4->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Ordenador"});
			this->comboBoxJug4->Location = System::Drawing::Point(22, 119);
			this->comboBoxJug4->Name = L"comboBoxJug4";
			this->comboBoxJug4->Size = System::Drawing::Size(175, 21);
			this->comboBoxJug4->TabIndex = 13;
			this->comboBoxJug4->Visible = false;
			this->comboBoxJug4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMulti::comboBoxJug4_SelectedIndexChanged);
			// 
			// botonComenzar
			// 
			this->botonComenzar->Enabled = false;
			this->botonComenzar->Location = System::Drawing::Point(683, 622);
			this->botonComenzar->Name = L"botonComenzar";
			this->botonComenzar->Size = System::Drawing::Size(102, 35);
			this->botonComenzar->TabIndex = 15;
			this->botonComenzar->Text = L"Comenzar";
			this->botonComenzar->UseVisualStyleBackColor = true;
			this->botonComenzar->Click += gcnew System::EventHandler(this, &FormMulti::botonComenzar_Click);
			// 
			// botonMenuPrincipal
			// 
			this->botonMenuPrincipal->Location = System::Drawing::Point(816, 622);
			this->botonMenuPrincipal->Name = L"botonMenuPrincipal";
			this->botonMenuPrincipal->Size = System::Drawing::Size(102, 35);
			this->botonMenuPrincipal->TabIndex = 16;
			this->botonMenuPrincipal->Text = L"Menú Principal";
			this->botonMenuPrincipal->UseVisualStyleBackColor = true;
			this->botonMenuPrincipal->Click += gcnew System::EventHandler(this, &FormMulti::formMultiBotonMenuPrincipal_Click);
			// 
			// botonDesconectarServidor
			// 
			this->botonDesconectarServidor->Enabled = false;
			this->botonDesconectarServidor->Location = System::Drawing::Point(150, 28);
			this->botonDesconectarServidor->Name = L"botonDesconectarServidor";
			this->botonDesconectarServidor->Size = System::Drawing::Size(112, 35);
			this->botonDesconectarServidor->TabIndex = 17;
			this->botonDesconectarServidor->Text = L"Desconectar";
			this->botonDesconectarServidor->UseVisualStyleBackColor = true;
			this->botonDesconectarServidor->Click += gcnew System::EventHandler(this, &FormMulti::botonDesconectar_Click);
			// 
			// textBoxMiIP
			// 
			this->textBoxMiIP->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxMiIP->Location = System::Drawing::Point(110, 87);
			this->textBoxMiIP->Name = L"textBoxMiIP";
			this->textBoxMiIP->ReadOnly = true;
			this->textBoxMiIP->Size = System::Drawing::Size(152, 20);
			this->textBoxMiIP->TabIndex = 19;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(30, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 35);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Mi IP";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBoxMiIP);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->botonDesconectarServidor);
			this->panel1->Controls->Add(this->botonCrearServer);
			this->panel1->Location = System::Drawing::Point(59, 29);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(285, 135);
			this->panel1->TabIndex = 22;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->botonDesconectarCliente);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->textBoxIP);
			this->panel2->Controls->Add(this->labelIP);
			this->panel2->Controls->Add(this->botonUnirse);
			this->panel2->Location = System::Drawing::Point(362, 29);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(285, 135);
			this->panel2->TabIndex = 23;
			// 
			// botonDesconectarCliente
			// 
			this->botonDesconectarCliente->Enabled = false;
			this->botonDesconectarCliente->Location = System::Drawing::Point(150, 28);
			this->botonDesconectarCliente->Name = L"botonDesconectarCliente";
			this->botonDesconectarCliente->Size = System::Drawing::Size(112, 35);
			this->botonDesconectarCliente->TabIndex = 4;
			this->botonDesconectarCliente->Text = L"Desconectar";
			this->botonDesconectarCliente->UseVisualStyleBackColor = true;
			this->botonDesconectarCliente->Click += gcnew System::EventHandler(this, &FormMulti::botonDesconectarCliente_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(150, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 35);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Unirse a una Partida";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->labelJug3);
			this->panel3->Controls->Add(this->comboBoxJug3);
			this->panel3->Controls->Add(this->labelJug1);
			this->panel3->Controls->Add(this->comboBoxJug1);
			this->panel3->Controls->Add(this->textBoxJug3);
			this->panel3->Controls->Add(this->textBoxJug1);
			this->panel3->Location = System::Drawing::Point(683, 29);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(235, 172);
			this->panel3->TabIndex = 24;
			// 
			// textBoxJug3
			// 
			this->textBoxJug3->Location = System::Drawing::Point(24, 116);
			this->textBoxJug3->Name = L"textBoxJug3";
			this->textBoxJug3->ReadOnly = true;
			this->textBoxJug3->Size = System::Drawing::Size(175, 20);
			this->textBoxJug3->TabIndex = 14;
			// 
			// textBoxJug1
			// 
			this->textBoxJug1->Location = System::Drawing::Point(24, 45);
			this->textBoxJug1->Name = L"textBoxJug1";
			this->textBoxJug1->ReadOnly = true;
			this->textBoxJug1->Size = System::Drawing::Size(175, 20);
			this->textBoxJug1->TabIndex = 13;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->labelJug4);
			this->panel4->Controls->Add(this->comboBoxJug4);
			this->panel4->Controls->Add(this->labelJug2);
			this->panel4->Controls->Add(this->comboBoxJug2);
			this->panel4->Controls->Add(this->textBoxJug4);
			this->panel4->Controls->Add(this->textBoxJug2);
			this->panel4->Location = System::Drawing::Point(683, 228);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(235, 172);
			this->panel4->TabIndex = 26;
			// 
			// textBoxJug4
			// 
			this->textBoxJug4->Location = System::Drawing::Point(22, 119);
			this->textBoxJug4->Name = L"textBoxJug4";
			this->textBoxJug4->ReadOnly = true;
			this->textBoxJug4->Size = System::Drawing::Size(175, 20);
			this->textBoxJug4->TabIndex = 16;
			// 
			// textBoxJug2
			// 
			this->textBoxJug2->Location = System::Drawing::Point(22, 43);
			this->textBoxJug2->Name = L"textBoxJug2";
			this->textBoxJug2->ReadOnly = true;
			this->textBoxJug2->Size = System::Drawing::Size(175, 20);
			this->textBoxJug2->TabIndex = 15;
			// 
			// textBoxMiNombre
			// 
			this->textBoxMiNombre->Location = System::Drawing::Point(170, 190);
			this->textBoxMiNombre->Name = L"textBoxMiNombre";
			this->textBoxMiNombre->Size = System::Drawing::Size(151, 20);
			this->textBoxMiNombre->TabIndex = 29;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(89, 182);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 35);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Mi Nombre";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// botonBorrar
			// 
			this->botonBorrar->Enabled = false;
			this->botonBorrar->Location = System::Drawing::Point(497, 622);
			this->botonBorrar->Name = L"botonBorrar";
			this->botonBorrar->Size = System::Drawing::Size(150, 35);
			this->botonBorrar->TabIndex = 30;
			this->botonBorrar->Text = L"Borrar";
			this->botonBorrar->UseVisualStyleBackColor = true;
			this->botonBorrar->Click += gcnew System::EventHandler(this, &FormMulti::botonBorrar_Click);
			// 
			// checkBoxCliente0Write
			// 
			this->checkBoxCliente0Write->AutoSize = true;
			this->checkBoxCliente0Write->Location = System::Drawing::Point(60, 47);
			this->checkBoxCliente0Write->Name = L"checkBoxCliente0Write";
			this->checkBoxCliente0Write->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente0Write->TabIndex = 31;
			this->checkBoxCliente0Write->UseVisualStyleBackColor = true;
			this->checkBoxCliente0Write->Visible = false;
			this->checkBoxCliente0Write->CheckedChanged += gcnew System::EventHandler(this, &FormMulti::checkBoxCliente0_CheckedChanged);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->checkBoxCliente2Read);
			this->panel5->Controls->Add(this->checkBoxCliente3Read);
			this->panel5->Controls->Add(this->checkBoxCliente1Read);
			this->panel5->Controls->Add(this->checkBoxCliente0Read);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->checkBoxCliente2Write);
			this->panel5->Controls->Add(this->checkBoxCliente3Write);
			this->panel5->Controls->Add(this->checkBoxCliente1Write);
			this->panel5->Controls->Add(this->checkBoxCliente0Write);
			this->panel5->Location = System::Drawing::Point(683, 431);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(235, 172);
			this->panel5->TabIndex = 32;
			// 
			// checkBoxCliente2Read
			// 
			this->checkBoxCliente2Read->AutoCheck = false;
			this->checkBoxCliente2Read->AutoSize = true;
			this->checkBoxCliente2Read->Location = System::Drawing::Point(60, 105);
			this->checkBoxCliente2Read->Name = L"checkBoxCliente2Read";
			this->checkBoxCliente2Read->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente2Read->TabIndex = 37;
			this->checkBoxCliente2Read->UseVisualStyleBackColor = true;
			// 
			// checkBoxCliente3Read
			// 
			this->checkBoxCliente3Read->AutoCheck = false;
			this->checkBoxCliente3Read->AutoSize = true;
			this->checkBoxCliente3Read->Location = System::Drawing::Point(60, 134);
			this->checkBoxCliente3Read->Name = L"checkBoxCliente3Read";
			this->checkBoxCliente3Read->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente3Read->TabIndex = 38;
			this->checkBoxCliente3Read->UseVisualStyleBackColor = true;
			// 
			// checkBoxCliente1Read
			// 
			this->checkBoxCliente1Read->AutoCheck = false;
			this->checkBoxCliente1Read->AutoSize = true;
			this->checkBoxCliente1Read->Location = System::Drawing::Point(60, 76);
			this->checkBoxCliente1Read->Name = L"checkBoxCliente1Read";
			this->checkBoxCliente1Read->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente1Read->TabIndex = 36;
			this->checkBoxCliente1Read->UseVisualStyleBackColor = true;
			// 
			// checkBoxCliente0Read
			// 
			this->checkBoxCliente0Read->AutoCheck = false;
			this->checkBoxCliente0Read->AutoSize = true;
			this->checkBoxCliente0Read->Location = System::Drawing::Point(60, 47);
			this->checkBoxCliente0Read->Name = L"checkBoxCliente0Read";
			this->checkBoxCliente0Read->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente0Read->TabIndex = 35;
			this->checkBoxCliente0Read->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Estoy listo";
			// 
			// checkBoxCliente2Write
			// 
			this->checkBoxCliente2Write->AutoSize = true;
			this->checkBoxCliente2Write->Location = System::Drawing::Point(60, 105);
			this->checkBoxCliente2Write->Name = L"checkBoxCliente2Write";
			this->checkBoxCliente2Write->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente2Write->TabIndex = 33;
			this->checkBoxCliente2Write->UseVisualStyleBackColor = true;
			this->checkBoxCliente2Write->Visible = false;
			this->checkBoxCliente2Write->CheckedChanged += gcnew System::EventHandler(this, &FormMulti::checkBoxCliente2_CheckedChanged);
			// 
			// checkBoxCliente3Write
			// 
			this->checkBoxCliente3Write->AutoSize = true;
			this->checkBoxCliente3Write->Location = System::Drawing::Point(60, 134);
			this->checkBoxCliente3Write->Name = L"checkBoxCliente3Write";
			this->checkBoxCliente3Write->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente3Write->TabIndex = 34;
			this->checkBoxCliente3Write->UseVisualStyleBackColor = true;
			this->checkBoxCliente3Write->Visible = false;
			this->checkBoxCliente3Write->CheckedChanged += gcnew System::EventHandler(this, &FormMulti::checkBoxCliente3_CheckedChanged);
			// 
			// checkBoxCliente1Write
			// 
			this->checkBoxCliente1Write->AutoSize = true;
			this->checkBoxCliente1Write->Location = System::Drawing::Point(60, 76);
			this->checkBoxCliente1Write->Name = L"checkBoxCliente1Write";
			this->checkBoxCliente1Write->Size = System::Drawing::Size(15, 14);
			this->checkBoxCliente1Write->TabIndex = 32;
			this->checkBoxCliente1Write->UseVisualStyleBackColor = true;
			this->checkBoxCliente1Write->Visible = false;
			this->checkBoxCliente1Write->CheckedChanged += gcnew System::EventHandler(this, &FormMulti::checkBoxCliente1_CheckedChanged);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(398, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 35);
			this->label4->TabIndex = 33;
			this->label4->Text = L"Mi Voz";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBoxMiVoz
			// 
			this->comboBoxMiVoz->Enabled = false;
			this->comboBoxMiVoz->FormattingEnabled = true;
			this->comboBoxMiVoz->Location = System::Drawing::Point(460, 189);
			this->comboBoxMiVoz->Name = L"comboBoxMiVoz";
			this->comboBoxMiVoz->Size = System::Drawing::Size(151, 21);
			this->comboBoxMiVoz->TabIndex = 15;
			// 
			// FormMulti
			// 
			this->AcceptButton = this->botonEnviar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 681);
			this->Controls->Add(this->comboBoxMiVoz);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->botonBorrar);
			this->Controls->Add(this->textBoxMiNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->botonMenuPrincipal);
			this->Controls->Add(this->botonComenzar);
			this->Controls->Add(this->botonEnviar);
			this->Controls->Add(this->textBoxEnviar);
			this->Controls->Add(this->textBoxChat);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FormMulti";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"La Zanga 1.0";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormMulti::FormMulti_FormClosed);
			this->Load += gcnew System::EventHandler(this, &FormMulti::FormMulti_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void ZangaGraficoDefinitivo::FormMulti::formMultiBotonMenuPrincipal_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void FormMulti_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);

	private:
		Thread^ hiloServidorRequests;
		array<Thread^>^ hilosServidorRead;
		Thread^ hiloCliente;
		const static Int32 puerto = 13000;
		TcpClient^ cliente;
		TcpListener^ servidor;
		array<TcpClient^>^ clientesConectados;
		array<bool>^ conectados;
		array<String^>^ nombres;
		array<int>^ voces;
		bool modoServidor;

		void mainHiloServidorRequests()
		{
			array<unsigned char, 1>^ bufferLectura = gcnew array<unsigned char,1>(256);
			Int32 bytesLeidos;
			NetworkStream^ stream;
			array<array<unsigned char>^>^ mensajesRecibidos;

			escribirMensaje("Esperando conexiones entrantes...");
			nombres[0] = textBoxMiNombre->Text;
			clientesConectados = gcnew array<TcpClient^>(4);
			servidor = gcnew TcpListener(puerto);
			servidor->Start();	
			int primLibre;
			bool inicializado = false;
			while(true)
			{
				primLibre = primeroLibre();
				// Si hay algún hueco libre
				if (primLibre >= 0)
				{
					// Acepto la conexión
					clientesConectados[primLibre] = servidor->AcceptTcpClient();
					// Recibo su nombre
					stream = clientesConectados[primLibre]->GetStream();
					bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);
					// Si lo recibo bien
					if (bytesLeidos > 0 && bufferLectura[0] == 2)
					{					
						conectados[primLibre] = true;
						mensajesRecibidos = subArrays(bufferLectura, bytesLeidos);
						for (int i = 0; i < mensajesRecibidos->Length; i++)
						{
							procesarMensaje(mensajesRecibidos[i], primLibre);
						}
						// Consigo la IP del cliente conectado
						IPEndPoint^ maquinaRemota = (IPEndPoint^)clientesConectados[primLibre]->
							Client->RemoteEndPoint;
						String^ direccionIP = maquinaRemota->Address->ToString();
						escribirMensaje(nombres[primLibre+1] + " conectado con IP "
							+ direccionIP);						
						// Aviso a los demás que se ha conectado
						array<Object^>^ info = {primLibre, nombres[primLibre+1]};
						bufferLectura = empaquetarMensaje(numeroNombre, info);
						for (int i = 0; i < 3; i++)
						{
							if (conectados[i])
							{
								stream = clientesConectados[i]->GetStream();
								stream->Write(bufferLectura, 0, bufferLectura->Length);
							}
						}
						// Le aviso a él de todos los que están conectados y de mi nombre
						info = gcnew array<Object^>{primLibre, nombres[primLibre+1]};
						bufferLectura = empaquetarMensaje(numeroNombre, info);
						stream = clientesConectados[primLibre]->GetStream();
						stream->Write(bufferLectura, 0, bufferLectura->Length);
						for (int i = 0; i < 3 && i != primLibre; i++)
						{
							if (conectados[i])
							{
								info = gcnew array<Object^>{i, nombres[i+1]};
								bufferLectura = empaquetarMensaje(numeroNombre, info);
								stream = clientesConectados[primLibre]->GetStream();
								stream->Write(bufferLectura, 0, bufferLectura->Length);
							}
						}
						info = gcnew array<Object^>{-1, nombres[0]};
						bufferLectura = empaquetarMensaje(numeroNombre, info);
						stream = clientesConectados[primLibre]->GetStream();
						stream->Write(bufferLectura, 0, bufferLectura->Length);

						// CHAPUZA
						if (!inicializado)
						{
							visibilizarControl(textBoxJug1, false);
							visibilizarControl(textBoxJug2, false);
							visibilizarControl(textBoxJug3, false);
							visibilizarControl(textBoxJug4, false);
							activarControl(comboBoxJug1, true);
							activarControl(comboBoxJug2, true);
							activarControl(comboBoxJug3, true);
							visibilizarControl(comboBoxJug4, true);
							visibilizarControl(comboBoxJug1, true);
							visibilizarControl(comboBoxJug2, true);
							visibilizarControl(comboBoxJug3, true);
							visibilizarControl(comboBoxJug4, true);
							visibilizarControl(checkBoxCliente0Read, false);
							visibilizarControl(checkBoxCliente0Write, true);
							cambiarComboBox(comboBoxJug1, 1);
							cambiarComboBox(comboBoxJug2, 2);
							cambiarComboBox(comboBoxJug3, 0);
							cambiarComboBox(comboBoxJug4, 0);
							inicializado = true;
						}

						// Arranco su thread de lectura
						ParameterizedThreadStart^ myParamThreadDelegate = gcnew ParameterizedThreadStart(this, 
							&ZangaGraficoDefinitivo::FormMulti::mainHiloServidorRead);
						hilosServidorRead[primLibre] = gcnew Thread(myParamThreadDelegate);
						hilosServidorRead[primLibre]->IsBackground = true;						
						hilosServidorRead[primLibre]->Start(primLibre);						
					}
					else
					{
						clientesConectados[primLibre]->Close();
					}
				}

			}						
		}

		void mainHiloServidorRead(Object^ numCliente)
		{
			bool salir = false;
			array<unsigned char, 1>^ bufferLectura = gcnew array<unsigned char,1>(256);
			String^ mensaje;	
			NetworkStream^ stream;
			Int32 bytesLeidos;	
			array<array<unsigned char>^>^ mensajesRecibidos;
			if (conectados[(int)numCliente])
			{
				mensaje = String::Empty;
				stream = clientesConectados[(int)numCliente]->GetStream();
				bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);
				while (bytesLeidos > 0) 
				{   
					mensajesRecibidos = subArrays(bufferLectura, bytesLeidos);
					for (int i = 0; i < mensajesRecibidos->Length; i++)
					{
						procesarMensaje(mensajesRecibidos[i], (int)numCliente);
						if (safe_cast<mensajesMulti>(mensajesRecibidos[i][0]) == comenzar)
						{
							salir = true;
							break;
						}
					} 
					if (salir) break;
					bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);					
				}
			}			
			escribirMensaje("Servidor: " + nombres[(int)numCliente+1] + " desconectado.");  
			//stream->Close();
			switch((int)numCliente)
			{
			case 0:
				cambiarTextoCheckBox(checkBoxCliente3Read, "");
				cambiarCheckBox(checkBoxCliente1Read, false);
				break;
			case 1:
				cambiarTextoCheckBox(checkBoxCliente3Read, "");
				cambiarCheckBox(checkBoxCliente3Read, false);
				break;
			default:
				cambiarTextoCheckBox(checkBoxCliente3Read, "");
				cambiarCheckBox(checkBoxCliente3Read, false);
				break;

			}
			//clientesConectados[(int)numCliente]->Close();
			//conectados[(int)numCliente] = false;
		}

		void mainHiloCliente()
		{
			bool salir = false;
			escribirMensaje("Conectándose al servidor...");
			try
			{
				cliente = gcnew TcpClient(textBoxIP->Text, puerto);
				escribirMensaje("Conectado a " + textBoxIP->Text);				

				String^ data = String::Empty;;
				Int32 bytesLeidos;
				array<array<unsigned char>^>^ mensajesRecibidos;
				NetworkStream^ stream = cliente->GetStream();				

				// Envío al servidor mi nombre
				array<Object^>^ info = {textBoxMiNombre->Text};
				array<unsigned char>^ mensajeNombre = empaquetarMensaje(nombre, info);
				stream->Write(mensajeNombre, 0, mensajeNombre->Length);				

				// Recibo del servidor mi nombre y mi número
				array<unsigned char, 1>^ bufferLectura = gcnew array<unsigned char,1>(256);
				bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);
				if (bytesLeidos > 0)
				{
					mensajesRecibidos = subArrays(bufferLectura, bytesLeidos);
					for (int i = 0; i < mensajesRecibidos->Length; i++)
					{
						procesarMensaje(mensajesRecibidos[i], 0);					
						switch(mensajesRecibidos[0][2])
						{
						case 0:
							visibilizarControl(checkBoxCliente1Read, false);
							visibilizarControl(checkBoxCliente1Write, true);
							cambiarTextoCheckBox(checkBoxCliente1Write, 
								nombres[mensajesRecibidos[0][2]+1]);
							break;
						case 1:
							visibilizarControl(checkBoxCliente2Read, false);
							visibilizarControl(checkBoxCliente2Write, true);
							cambiarTextoCheckBox(checkBoxCliente2Write, 
								nombres[mensajesRecibidos[0][2]+1]);
							break;
						default:
							visibilizarControl(checkBoxCliente3Read, false);
							visibilizarControl(checkBoxCliente3Write, true);
							cambiarTextoCheckBox(checkBoxCliente3Write, 
								nombres[mensajesRecibidos[0][2]+1]);
							break;
						}
					}
				}
				// Monitorizo todos los demás paquetes entrantes												
				bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);
				while (bytesLeidos > 0) 
				{   
					mensajesRecibidos = subArrays(bufferLectura, bytesLeidos);
					for (int i = 0; i < mensajesRecibidos->Length; i++)
					{
						procesarMensaje(mensajesRecibidos[i], 0);
						if (safe_cast<mensajesMulti>(mensajesRecibidos[i][0]) == comenzar)
						{
							salir = true;
							break;
						}
					} 
					if (salir) break;
					bytesLeidos = stream->Read(bufferLectura, 0, bufferLectura->Length);
				}
				escribirMensaje("Desconectado del servidor.");	
			}
			catch(SocketException^ e)
			{
				escribirMensaje(e->Message); 
				activarControl(botonCrearServer, true);
				activarControl(botonUnirse, true);
				activarControl(textBoxIP, true);
				activarControl(textBoxEnviar, false);
				activarControl(botonEnviar, false);
				activarControl(botonDesconectarServidor, false);
				activarControl(botonDesconectarCliente, false);
			}
		}			

		delegate void escribirMensajeDelegate(String^ mensaje);
		void escribirMensaje(String^ mensaje)
		{	
			if (textBoxChat->InvokeRequired == false)
			{
				textBoxChat->AppendText("[" + System::DateTime::Now.ToLongTimeString()
					+ "] " + mensaje + "\n");
			}
			else 
			{					 
				escribirMensajeDelegate^ myThreadDelegate =
					gcnew escribirMensajeDelegate(this, &ZangaGraficoDefinitivo::FormMulti::escribirMensaje);
				array<Object^>^arrayObjects = {mensaje};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void activarControlDelegate(Control^ control, bool activo);
		void activarControl(Control^ control, bool activo)
		{	
			if (control->InvokeRequired == false)
			{
				control->Enabled = activo;
			}
			else 
			{					 
				activarControlDelegate^ myThreadDelegate =
					gcnew activarControlDelegate(this, &ZangaGraficoDefinitivo::FormMulti::activarControl);
				array<Object^>^arrayObjects = {control, activo};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void visibilizarControlDelegate(Control^ control, bool activo);
		void visibilizarControl(Control^ control, bool activo)
		{	
			if (control->InvokeRequired == false)
			{
				control->Visible = activo;
			}
			else 
			{					 
				visibilizarControlDelegate^ myThreadDelegate =
					gcnew visibilizarControlDelegate(this, &ZangaGraficoDefinitivo::FormMulti::visibilizarControl);
				array<Object^>^arrayObjects = {control, activo};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void cambiarTextBoxDelegate(TextBox^ tb, String^ texto);
		void cambiarTextBox(TextBox^ tb, String^ texto)
		{	
			if (tb->InvokeRequired == false)
			{
				tb->Text = texto;
			}
			else 
			{					 
				cambiarTextBoxDelegate^ myThreadDelegate =
					gcnew cambiarTextBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::cambiarTextBox);
				array<Object^>^arrayObjects = {tb, texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

		delegate void anyadirComboBoxDelegate(ComboBox^ cb, String^ texto);
		void anyadirComboBox(ComboBox^ cb, String^ texto)
		{
			if (cb->InvokeRequired == false)
			{
				cb->Items->Add(texto);
			}
			else 
			{					 
				anyadirComboBoxDelegate^ myThreadDelegate =
					gcnew anyadirComboBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::anyadirComboBox);
				array<Object^>^arrayObjects = {cb, texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void quitarComboBoxDelegate(ComboBox^ cb, String^ texto);
		void quitarComboBox(ComboBox^ cb, String^ texto)
		{
			if (cb->InvokeRequired == false)
			{
				cb->Items->Remove(texto);
			}
			else 
			{					 
				quitarComboBoxDelegate^ myThreadDelegate =
					gcnew quitarComboBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::quitarComboBox);
				array<Object^>^arrayObjects = {cb, texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void cambiarComboBoxDelegate(ComboBox^ cb, int indice);
		void cambiarComboBox(ComboBox^ cb, int indice)
		{
			if (cb->InvokeRequired == false)
			{
				cb->SelectedIndex = indice;
			}
			else 
			{					 
				cambiarComboBoxDelegate^ myThreadDelegate =
					gcnew cambiarComboBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::cambiarComboBox);
				array<Object^>^arrayObjects = {cb, indice};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate int getIndiceComboBoxDelegate(ComboBox^ cb);

		int getIndiceComboBox(ComboBox^ cb)
		{
			if (cb->InvokeRequired == false)
			{
				return cb->SelectedIndex;
			}
			else 
			{					 
				getIndiceComboBoxDelegate^ myThreadDelegate =
					gcnew getIndiceComboBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::getIndiceComboBox);
				array<Object^>^arrayObjects = {cb};
				return (int)this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate bool getCheckedCheckBoxDelegate(CheckBox^ cb);

		bool getCheckedCheckBox(CheckBox^ cb)
		{
			if (cb->InvokeRequired == false)
			{
				return cb->Checked;
			}
			else 
			{					 
				getCheckedCheckBoxDelegate^ myThreadDelegate =
					gcnew getCheckedCheckBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::getCheckedCheckBox);
				array<Object^>^arrayObjects = {cb};
				return (bool)this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void cambiarCheckBoxDelegate(CheckBox^ cb, bool estado);

		void cambiarCheckBox(CheckBox^ cb, bool estado)
		{
			if (cb->InvokeRequired == false)
			{
				cb->Checked = estado;
			}
			else 
			{					 
				cambiarCheckBoxDelegate^ myThreadDelegate =
					gcnew cambiarCheckBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::cambiarCheckBox);
				array<Object^>^arrayObjects = {cb, estado};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void cambiarTextoCheckBoxDelegate(CheckBox^ cb, String^ texto);

		void cambiarTextoCheckBox(CheckBox^ cb, String^ texto)
		{
			if (cb->InvokeRequired == false)
			{
				cb->Text = texto;
			}
			else 
			{					 
				cambiarTextoCheckBoxDelegate^ myThreadDelegate =
					gcnew cambiarTextoCheckBoxDelegate(this, &ZangaGraficoDefinitivo::FormMulti::cambiarTextoCheckBox);
				array<Object^>^arrayObjects = {cb, texto};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		delegate void cambiarVentanaDelegate(int numCliente);

		void cambiarVentana(int numCliente)
		{
			if (this->InvokeRequired == false)
			{
				array<Jugador^>^ jugadores = gcnew array<Jugador^>(4);
				if (modoServidor)
				{
					int clienteJug1 = comboBoxJug1->SelectedIndex-2;
					int clienteJug2 = comboBoxJug2->SelectedIndex-2;
					int clienteJug3 = comboBoxJug3->SelectedIndex-2;
					int clienteJug4 = comboBoxJug4->SelectedIndex-2;
					if (System::String::Equals(comboBoxJug1->SelectedItem, 
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)comboBoxJug1->SelectedItem, 0, 10, 0, 0);
						if (System::String::Equals(comboBoxJug2->SelectedItem,"Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)comboBoxJug2->SelectedItem, 1, 10, 0, clienteJug2);
						}
						if (System::String::Equals(comboBoxJug3->SelectedItem,"Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)comboBoxJug3->SelectedItem, 2, 10, 0, clienteJug3);
						}
						if (System::String::Equals(comboBoxJug4->SelectedItem,"Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)comboBoxJug4->SelectedItem, 3, 10, 0, clienteJug4);
						}						
					}
					else if (System::String::Equals(comboBoxJug2->SelectedItem,
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)comboBoxJug2->SelectedItem, 0, 10, 0, 0);
						if (System::String::Equals(comboBoxJug3->SelectedItem,"Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)comboBoxJug3->SelectedItem, 1, 10, 0, clienteJug3);
						}
						if (System::String::Equals(comboBoxJug4->SelectedItem,"Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)comboBoxJug4->SelectedItem, 2, 10, 0, clienteJug4);
						}
						if (System::String::Equals(comboBoxJug1->SelectedItem,"Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)comboBoxJug1->SelectedItem, 3, 10, 0, clienteJug1);
						}
					}
					else if (System::String::Equals(comboBoxJug3->SelectedItem, 
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)comboBoxJug3->SelectedItem, 0, 10, 0, 0);
						if (System::String::Equals(comboBoxJug4->SelectedItem,"Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)comboBoxJug4->SelectedItem, 1, 10, 0, clienteJug4);
						}
						if (System::String::Equals(comboBoxJug1->SelectedItem,"Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)comboBoxJug1->SelectedItem, 2, 10, 0, clienteJug1);
						}
						if (System::String::Equals(comboBoxJug2->SelectedItem,"Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)comboBoxJug2->SelectedItem, 3, 10, 0, clienteJug2);
						}
					}
					else
					{
						jugadores[0] = gcnew Jugador((String^)comboBoxJug4->SelectedItem, 0, 10, 0, 0);
						if (System::String::Equals(comboBoxJug1->SelectedItem,"Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)comboBoxJug1->SelectedItem, 1, 10, 0, clienteJug1);
						}
						if (System::String::Equals(comboBoxJug2->SelectedItem,"Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)comboBoxJug2->SelectedItem, 2, 10, 0, clienteJug2);
						}
						if (System::String::Equals(comboBoxJug3->SelectedItem,"Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)comboBoxJug3->SelectedItem, 3, 10, 0, clienteJug3);
						}
					}
				}
				else
				{
					if (System::String::Equals(textBoxJug1->Text,
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)textBoxJug1->Text, 0, 10, 0, 0);
						if (System::String::Equals(textBoxJug2->Text, "Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)textBoxJug2->Text, 1, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug3->Text, "Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)textBoxJug3->Text, 2, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug4->Text, "Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)textBoxJug4->Text, 3, 10, 0, 0);
						}
					}
					else if (System::String::Equals(textBoxJug2->Text,
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)textBoxJug2->Text, 0, 10, 0, 0);
						if (System::String::Equals(textBoxJug3->Text, "Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)textBoxJug3->Text, 1, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug4->Text, "Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)textBoxJug4->Text, 2, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug1->Text, "Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)textBoxJug1->Text, 3, 10, 0, 0);
						}
					}
					else if (System::String::Equals(textBoxJug3->Text,
						textBoxMiNombre->Text))
					{
						jugadores[0] = gcnew Jugador((String^)textBoxJug3->Text, 0, 10, 0, 0);
						if (System::String::Equals(textBoxJug4->Text, "Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)textBoxJug4->Text, 1, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug1->Text, "Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)textBoxJug1->Text, 2, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug2->Text, "Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)textBoxJug2->Text, 3, 10, 0, 0);
						}
					}
					else
					{
						jugadores[0] = gcnew Jugador((String^)textBoxJug4->Text, 0, 10, 0, 0);
						if (System::String::Equals(textBoxJug1->Text, "Ordenador"))
						{
							jugadores[1] = gcnew Jugador("Ordenador 2", 1, 4, 0, 0);
						}
						else
						{
							jugadores[1] = gcnew Jugador((String^)textBoxJug1->Text, 1, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug2->Text, "Ordenador"))
						{
							jugadores[2] = gcnew Jugador("Ordenador 3", 2, 4, 0, 0);
						}
						else
						{
							jugadores[2] = gcnew Jugador((String^)textBoxJug2->Text, 2, 10, 0, 0);
						}
						if (System::String::Equals(textBoxJug3->Text, "Ordenador"))
						{
							jugadores[3] = gcnew Jugador("Ordenador 4", 3, 4, 0, 0);
						}
						else
						{
							jugadores[3] = gcnew Jugador((String^)textBoxJug3->Text, 3, 10, 0, 0);
						}
					}
				}	
				/*if (modoServidor)
				{
				for (int i = 0; i < 3; i++)
				{
					if (conectados[i])
					{
						clientesConectados[i]->GetStream()->Close();						
					}
				}
				}
				else
				{
					cliente->GetStream()->Close();
				}*/
				Form1^ f1;
				if (modoServidor)
				{
				f1= gcnew Form1(jugadores, modoServidor, servidor, 
					clientesConectados, cliente, 0);
				}
				else
				{
					int jugadorServidor, jugadorYo;
					if (System::String::Equals(textBoxJug1->Text,nombres[0]))
					{
						jugadorServidor = 0;
					}
					else if (System::String::Equals(textBoxJug2->Text,nombres[0]))
					{
						jugadorServidor = 1;
					}
					else if (System::String::Equals(textBoxJug3->Text,nombres[0]))
					{
						jugadorServidor = 2;
					} 
					else
					{
						jugadorServidor = 3;
					}
					if (System::String::Equals(textBoxJug1->Text,
						nombres[numCliente+1]))
					{
						jugadorYo = 0;
					}
					else if (System::String::Equals(textBoxJug2->Text,
						nombres[numCliente+1]))
					{
						jugadorYo = 1;
					}
					else if (System::String::Equals(textBoxJug3->Text,
						nombres[numCliente+1]))
					{
						jugadorYo = 2;
					} 
					else
					{
						jugadorYo = 3;
					}
					f1= gcnew Form1(jugadores, modoServidor, servidor, 
					clientesConectados, cliente, (4+jugadorServidor-jugadorYo)%4);
				}
				f1->Show();
				if (hiloServidorRequests->IsAlive)
					hiloServidorRequests->Abort();/*
				for (int i = 0; i < 3; i++)
				{
				if (hilosServidorRead[i]->IsAlive)
					hilosServidorRead[i]->Abort();
				}
				if (hiloCliente->IsAlive)
					hiloCliente->Abort();*/
				this->Hide();
			}
			else 
			{					 
				cambiarVentanaDelegate^ myThreadDelegate =
					gcnew cambiarVentanaDelegate(this, &ZangaGraficoDefinitivo::FormMulti::cambiarVentana);
				array<Object^>^arrayObjects = {numCliente};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}
		}

		System::Void botonComenzar_Click(System::Object^  sender, System::EventArgs^  e) 
		{			
			array<Object^>^ info = {};
			array<unsigned char>^ bufferEscritura = empaquetarMensaje(comenzar, info);
			NetworkStream^ stream;
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			//cambiarVentana();			  
		}	

		System::Void botonCrearServer_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ThreadStart ^myThreadDelegate = gcnew ThreadStart(this, 
				&ZangaGraficoDefinitivo::FormMulti::mainHiloServidorRequests);
			hiloServidorRequests = gcnew Thread(myThreadDelegate);
			hiloServidorRequests->IsBackground = true;
			hiloServidorRequests->Start();			
			botonCrearServer->Enabled = false;
			botonUnirse->Enabled = false;
			textBoxIP->Enabled = false;
			textBoxEnviar->Enabled = true;
			botonEnviar->Enabled = true;
			botonBorrar->Enabled = true;
			botonDesconectarServidor->Enabled = true;
			textBoxMiNombre->Enabled = false;
			modoServidor = true;
			/*textBoxJug1->Visible = false;
			textBoxJug2->Visible = false;
			textBoxJug3->Visible = false;
			textBoxJug4->Visible = false;
			comboBoxJug1->Enabled = true;
			comboBoxJug2->Enabled = true;
			comboBoxJug3->Enabled = true;
			comboBoxJug4->Enabled = true;
			comboBoxJug1->Visible = true;
			comboBoxJug2->Visible = true;
			comboBoxJug3->Visible = true;
			comboBoxJug4->Visible = true;
			checkBoxCliente0Read->Visible = false;
			checkBoxCliente0Write->Visible = true;*/
			checkBoxCliente0Write->Text = textBoxMiNombre->Text;
			checkBoxCliente0Read->Text = textBoxMiNombre->Text;
			comboBoxJug1->Items->Add(textBoxMiNombre->Text);
			comboBoxJug2->Items->Add(textBoxMiNombre->Text);
			comboBoxJug3->Items->Add(textBoxMiNombre->Text);
			comboBoxJug4->Items->Add(textBoxMiNombre->Text);
		}

		System::Void botonUnirse_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ThreadStart ^myThreadDelegate = 
				gcnew ThreadStart(this, &ZangaGraficoDefinitivo::FormMulti::mainHiloCliente);
			hiloCliente = gcnew Thread(myThreadDelegate);
			hiloCliente->IsBackground = true;
			hiloCliente->Start();
			botonCrearServer->Enabled = false;
			botonUnirse->Enabled = false;
			textBoxIP->Enabled = false;
			textBoxEnviar->Enabled = true;
			botonEnviar->Enabled = true;
			botonBorrar->Enabled = true;
			textBoxMiNombre->Enabled = false;
			botonDesconectarCliente->Enabled = true;
			modoServidor = false;
			textBoxJug1->Visible = true;
			textBoxJug2->Visible = true;
			textBoxJug3->Visible = true;
			textBoxJug4->Visible = true;
			comboBoxJug1->Enabled = true;
			comboBoxJug2->Enabled = true;
			comboBoxJug3->Enabled = true;
			comboBoxJug4->Enabled = true;
			comboBoxJug1->Visible = false;
			comboBoxJug2->Visible = false;
			comboBoxJug3->Visible = false;
			comboBoxJug4->Visible = false;
		}

		System::Void botonEnviar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			String^ texto;
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			if (modoServidor)
			{
				texto = textBoxMiNombre->Text + ": " + textBoxEnviar->Text;
				array<Object^>^ info = {texto};
				bufferEscritura = empaquetarMensaje(chat, info);
				escribirMensaje(texto); 
				for (int i = 0; i < 3; i++)
				{
					if (conectados[i])
					{
						stream = clientesConectados[i]->GetStream();
						stream->Write(bufferEscritura, 0, bufferEscritura->Length);
					}
				}
			}
			else
			{
				texto = textBoxMiNombre->Text + ": " + textBoxEnviar->Text;
				array<Object^>^ info = {texto};
				bufferEscritura = empaquetarMensaje(chat, info);
				escribirMensaje(texto); 
				stream = cliente->GetStream();
				stream->Write(bufferEscritura, 0, bufferEscritura->Length);					 
			}
			textBoxEnviar->Clear();
		}

		System::Void comboBoxJug1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			String^ texto = safe_cast<String^>(comboBoxJug1->SelectedItem);
			array<Object^>^ info = {1, texto};
			bufferEscritura = empaquetarMensaje(cambioJugador, info); 
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;	
		}

		System::Void comboBoxJug3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			String^ texto = safe_cast<String^>(comboBoxJug3->SelectedItem);
			array<Object^>^ info = {3, texto};
			bufferEscritura = empaquetarMensaje(cambioJugador, info); 
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;	
		}

		System::Void comboBoxJug2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			String^ texto = safe_cast<String^>(comboBoxJug2->SelectedItem);
			array<Object^>^ info = {2, texto};
			bufferEscritura = empaquetarMensaje(cambioJugador, info); 
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;	
		}

		System::Void comboBoxJug4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			String^ texto = safe_cast<String^>(comboBoxJug4->SelectedItem);
			array<Object^>^ info = {4, texto};
			bufferEscritura = empaquetarMensaje(cambioJugador, info); 
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;	
		}

		System::Void checkBoxCliente0_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			bool estado = checkBoxCliente0Write->Checked;
			array<Object^>^ info = {safe_cast<Object^>(0), estado};
			bufferEscritura = empaquetarMensaje(cambioListo, info); 
			for (int i = 0; i < 3; i++)
			{
				if (conectados[i])
				{
					stream = clientesConectados[i]->GetStream();
					stream->Write(bufferEscritura, 0, bufferEscritura->Length);
				}
			}
			array<int>^ indices = {getIndiceComboBox(comboBoxJug1), getIndiceComboBox(comboBoxJug2),
				getIndiceComboBox(comboBoxJug3), getIndiceComboBox(comboBoxJug4)};
			array<bool>^ listos = {getCheckedCheckBox(checkBoxCliente0Write), 
				getCheckedCheckBox(checkBoxCliente1Read),
				getCheckedCheckBox(checkBoxCliente2Read), getCheckedCheckBox(checkBoxCliente3Read)};
			if (sePuedeComenzar(indices, listos))
				activarControl(botonComenzar, true);
			else
				activarControl(botonComenzar, false);
		}

		System::Void checkBoxCliente1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			bool estado = checkBoxCliente1Write->Checked;
			array<Object^>^ info = {1, estado};
			bufferEscritura = empaquetarMensaje(cambioListo, info); 
			stream = cliente->GetStream();
			stream->Write(bufferEscritura, 0, bufferEscritura->Length);
		}

		System::Void checkBoxCliente2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			bool estado = checkBoxCliente2Write->Checked;
			array<Object^>^ info = {2, estado};
			bufferEscritura = empaquetarMensaje(cambioListo, info); 
			stream = cliente->GetStream();
			stream->Write(bufferEscritura, 0, bufferEscritura->Length);
		}

		System::Void checkBoxCliente3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			array<Byte>^ bufferEscritura;
			NetworkStream^ stream;				 
			bool estado = checkBoxCliente3Write->Checked;
			array<Object^>^ info = {3, estado};
			bufferEscritura = empaquetarMensaje(cambioListo, info); 
			stream = cliente->GetStream();
			stream->Write(bufferEscritura, 0, bufferEscritura->Length);
		}

		System::Void botonDesconectar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (modoServidor)
			{
				if (hiloServidorRequests->IsAlive)
				{
					hiloServidorRequests->Abort();
					servidor->Stop();
				}
				for (int i = 0; i < 3; i++)
				{
					if (hilosServidorRead[i]->IsAlive)
					{
						hilosServidorRead[i]->Abort();						
						for (int j = 0; j < 3; j++)
						{
							if (conectados[i])
								clientesConectados[i]->Close();
						}
					}
				}
			}
			else
			{
				if (hiloCliente->IsAlive)
					hiloCliente->Abort();
				cliente->Close();
			}
			botonCrearServer->Enabled = true;
			botonUnirse->Enabled = true;
			textBoxIP->Enabled = true;
			textBoxEnviar->Enabled = false;
			botonEnviar->Enabled = false;
			botonBorrar->Enabled = false;
			botonDesconectarServidor->Enabled = false;
			textBoxMiNombre->Enabled = true;
			textBoxJug1->Clear();
			textBoxJug2->Clear();
			textBoxJug3->Clear();
			textBoxJug4->Clear();
			textBoxJug1->Visible = true;
			textBoxJug2->Visible = true;
			textBoxJug3->Visible = true;
			textBoxJug4->Visible = true;
			comboBoxJug1->Enabled = true;
			comboBoxJug2->Enabled = true;
			comboBoxJug3->Enabled = true;
			comboBoxJug4->Enabled = true;
			comboBoxJug1->Visible = false;
			comboBoxJug2->Visible = false;
			comboBoxJug3->Visible = false;
			comboBoxJug4->Visible = false;
			for (int i = 1; i < comboBoxJug1->Items->Count; i++)
			{
				comboBoxJug1->Items->RemoveAt(i);
				comboBoxJug2->Items->RemoveAt(i);
				comboBoxJug3->Items->RemoveAt(i);
				comboBoxJug4->Items->RemoveAt(i);
			}
			checkBoxCliente0Read->Visible = true;
			checkBoxCliente0Write->Visible = false;
			checkBoxCliente0Read->Text = "";
			checkBoxCliente1Read->Text = "";
			checkBoxCliente2Read->Text = "";
			checkBoxCliente3Read->Text = "";
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Text = "";
			checkBoxCliente1Write->Text = "";
			checkBoxCliente2Write->Text = "";
			checkBoxCliente3Write->Text = "";
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;			
		}

		System::Void botonDesconectarCliente_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (modoServidor)
			{
				if (hiloServidorRequests->IsAlive)
				{
					hiloServidorRequests->Abort();
					servidor->Stop();
				}
				for (int i = 0; i < 3; i++)
				{
					if (hilosServidorRead[i]->IsAlive)
					{
						hilosServidorRead[i]->Abort();						
						for (int j = 0; j < 3; j++)
						{
							if (conectados[i])
								clientesConectados[i]->Close();
						}
					}
				}
			}
			else
			{
				if (hiloCliente->IsAlive)
					hiloCliente->Abort();
				cliente->Close();
				escribirMensaje("Desconectado del servidor.");
			}
			botonCrearServer->Enabled = true;
			botonUnirse->Enabled = true;
			textBoxIP->Enabled = true;
			textBoxEnviar->Enabled = false;
			botonEnviar->Enabled = false;
			botonBorrar->Enabled = false;
			botonDesconectarCliente->Enabled = false;
			textBoxMiNombre->Enabled = true;
			textBoxJug1->Clear();
			textBoxJug2->Clear();
			textBoxJug3->Clear();
			textBoxJug4->Clear();
			textBoxJug1->Visible = true;
			textBoxJug2->Visible = true;
			textBoxJug3->Visible = true;
			textBoxJug4->Visible = true;
			comboBoxJug1->Enabled = true;
			comboBoxJug2->Enabled = true;
			comboBoxJug3->Enabled = true;
			comboBoxJug4->Enabled = true;
			comboBoxJug1->Visible = false;
			comboBoxJug2->Visible = false;
			comboBoxJug3->Visible = false;
			comboBoxJug4->Visible = false;
			for (int i = 1; i < comboBoxJug1->Items->Count; i++)
			{
				comboBoxJug1->Items->RemoveAt(i);
				comboBoxJug2->Items->RemoveAt(i);
				comboBoxJug3->Items->RemoveAt(i);
				comboBoxJug4->Items->RemoveAt(i);
			}
			checkBoxCliente1Read->Visible = true;
			checkBoxCliente1Write->Visible = false;
			checkBoxCliente2Read->Visible = true;
			checkBoxCliente2Write->Visible = false;
			checkBoxCliente3Read->Visible = true;
			checkBoxCliente3Write->Visible = false;
			checkBoxCliente0Read->Text = "";
			checkBoxCliente1Read->Text = "";
			checkBoxCliente2Read->Text = "";
			checkBoxCliente3Read->Text = "";
			checkBoxCliente0Read->Checked = false;
			checkBoxCliente1Read->Checked = false;
			checkBoxCliente2Read->Checked = false;
			checkBoxCliente3Read->Checked = false;
			checkBoxCliente0Write->Text = "";
			checkBoxCliente1Write->Text = "";
			checkBoxCliente2Write->Text = "";
			checkBoxCliente3Write->Text = "";
			checkBoxCliente0Write->Checked = false;
			checkBoxCliente1Write->Checked = false;
			checkBoxCliente2Write->Checked = false;
			checkBoxCliente3Write->Checked = false;

		}

		System::Void FormMulti_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			clientesConectados = gcnew array<TcpClient^>(3);
			conectados = gcnew array<bool>(3);
			hilosServidorRead = gcnew array<Thread^>(3);
			nombres = gcnew array<String^>(4);
			for (int i = 0; i < 4; i++)
				nombres[i] = "";
			voces = gcnew array<int>(3);

			for (int i = 0; i < 3; i++)
				conectados[i] = false;

			ThreadStart ^myThreadDelegate = 
				gcnew ThreadStart(this, &ZangaGraficoDefinitivo::FormMulti::mainHiloCliente);
			hiloCliente = gcnew Thread(myThreadDelegate);
			hiloCliente->IsBackground = true;

			myThreadDelegate = gcnew ThreadStart(this, 
				&ZangaGraficoDefinitivo::FormMulti::mainHiloServidorRequests);
			hiloServidorRequests = gcnew Thread(myThreadDelegate);
			hiloServidorRequests->IsBackground = true;

			ParameterizedThreadStart ^myParamThreadDelegate;
			for (int i = 0; i < 3; i++)
			{
				myParamThreadDelegate = gcnew ParameterizedThreadStart(this, 
					&ZangaGraficoDefinitivo::FormMulti::mainHiloServidorRead);
				hilosServidorRead[i] = gcnew Thread(myParamThreadDelegate);
				hilosServidorRead[i]->IsBackground = true;
			}

			String^ sHostName = Dns::GetHostName();
			IPHostEntry^ ipE = Dns::GetHostByName(sHostName);
			array<IPAddress^>^ ipA = ipE->AddressList;
			cambiarTextBox(textBoxMiIP, ipA[0]->ToString());

			//char httpBuff[20]; //"xxx.xxx.xxx.xxx" -> give me 15 chars

			//CInternetSession session;
			//// session.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, 1000);
			//// session.SetOption(INTERNET_OPTION_CONNECT_RETRIES, 3);
			//CFile *remoteFile = session.OpenURL(L"www.whatismyip.com", 1 ,
			//INTERNET_FLAG_TRANSFER_BINARY | INTERNET_FLAG_RELOAD);

			//int numBytes = remoteFile->Read(httpBuff, 20);

			//CString ip;

			//for (int i=0; i < numBytes ;i++) {
			//ip.Insert(i,httpBuff[i]);
			//}
			//String^ lalala = System::Convert::ToString(httpBuff);
		}

		int primeroLibre()
		{
			for (int i = 0; i < 3; i++)
			{
				if (!conectados[i])
					return i;
			}
			return -1;
		}
		System::Void botonBorrar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			textBoxEnviar->Clear();
		}

		array<unsigned char>^ empaquetarMensaje(mensajesMulti tipoMensaje, 
			array<Object^>^ info)
		{
			array<unsigned char>^ msj;
			array<unsigned char>^ aux;
			int a;
			switch(tipoMensaje)
			{
			case (numeroNombre):
				aux = System::Text::Encoding::ASCII->GetBytes(safe_cast<String^>(info[1]));
				msj = gcnew array<unsigned char>(aux->Length + 3);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				a = safe_cast<int>(info[0]);
				msj[2] = safe_cast<unsigned char>(a);
				for (int i = 0; i < aux->Length; i++)
				{
					msj[i+3] = aux[i];
				}
				msj[1] = safe_cast<unsigned char>(1+1+1+aux->Length);
				break;
			case (desconectado):
				msj = gcnew array<unsigned char>(2);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				a = safe_cast<int>(info[0]);
				msj[2] = safe_cast<unsigned char>(a);
				msj[1] = safe_cast<unsigned char>(1+1+1);
				break;
			case(nombre):
				aux = System::Text::Encoding::ASCII->GetBytes(safe_cast<String^>(info[0]));
				msj = gcnew array<unsigned char>(aux->Length + 2);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				for (int i = 0; i < aux->Length; i++)
				{
					msj[i+2] = aux[i];
				}
				msj[1] = safe_cast<unsigned char>(1+1+aux->Length);
				break;
			case(voz):
				msj = gcnew array<unsigned char>(2);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				a = safe_cast<int>(info[0]);
				msj[2] = safe_cast<unsigned char>(a);
				msj[1] = safe_cast<unsigned char>(1+1+1);
				break;
			case(chat):
				aux = System::Text::Encoding::ASCII->GetBytes(safe_cast<String^>(info[0]));
				msj = gcnew array<unsigned char>(aux->Length + 2);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				for (int i = 0; i < aux->Length; i++)
				{
					msj[i+2] = aux[i];
				}
				msj[1] = safe_cast<unsigned char>(1+1+aux->Length);
				break;
			case(cambioJugador):
				aux = System::Text::Encoding::ASCII->GetBytes(safe_cast<String^>(info[1]));
				msj = gcnew array<unsigned char>(aux->Length+3);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				a = safe_cast<int>(info[0]);
				msj[2] = safe_cast<unsigned char>(a);
				for (int i = 0; i < aux->Length; i++)
				{
					msj[i+3] = aux[i];
				}
				msj[1] = safe_cast<unsigned char>(1+1+1+aux->Length);
				break;
			case(cambioListo):
				msj = gcnew array<unsigned char>(4);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);
				a = safe_cast<int>(info[0]);
				msj[2] = safe_cast<unsigned char>(a);
				if (safe_cast<bool>(info[1]))
					msj[3] = 1;
				else
					msj[3] = 0;
				msj[1] = safe_cast<unsigned char>(1+1+1+1);
				break;
			default:
				msj = gcnew array<unsigned char>(2);
				msj[0] = safe_cast<unsigned char>(tipoMensaje);	
				msj[1] = safe_cast<unsigned char>(1+1);
			}
			return msj;
		}	

		void procesarMensaje(array<unsigned char>^ mensaje, int numCliente)
		{
			mensajesMulti tipoMensaje = safe_cast<mensajesMulti>(mensaje[0]);
			array<unsigned char>^ aux;
			String^ texto;
			int numero, cliente, indice, jugador;
			NetworkStream^ stream;
			array<Object^>^ info = {};
			switch(tipoMensaje)
			{
			case (numeroNombre):
				numero = safe_cast<int>(mensaje[2]);
				aux = gcnew array<unsigned char>(mensaje->Length - 3);
				for (int i = 0; i < mensaje->Length-3; i++)
				{
					aux[i] = mensaje[i+3];
				}
				if (numero == 255) numero = -1;
				texto = System::Text::Encoding::ASCII->GetString(aux);
				nombres[numero+1] = texto;
				if (numero >= 0)
				{
					conectados[numero] = true;
				}
				anyadirComboBox(comboBoxJug1, texto);
				anyadirComboBox(comboBoxJug2, texto);
				anyadirComboBox(comboBoxJug3, texto);
				anyadirComboBox(comboBoxJug4, texto);
				switch(numero)
				{
				case -1:
					cambiarTextoCheckBox(checkBoxCliente0Read, texto);
					break;
				case 0:
					cambiarTextoCheckBox(checkBoxCliente1Read, texto);
					break;
				case 1:
					cambiarTextoCheckBox(checkBoxCliente2Read, texto);
					break;
				default:
					cambiarTextoCheckBox(checkBoxCliente3Read, texto);
					break;
				}
				break;
			case (desconectado):
				cliente = safe_cast<int>(mensaje[2]);
				conectados[cliente] = false;
				quitarComboBox(comboBoxJug1, nombres[cliente+1]);
				quitarComboBox(comboBoxJug2, nombres[cliente+1]);
				quitarComboBox(comboBoxJug3, nombres[cliente+1]);
				quitarComboBox(comboBoxJug4, nombres[cliente+1]);
				break;
			case(nombre):
				aux = gcnew array<unsigned char>(mensaje->Length - 2);
				for (int i = 0; i < mensaje->Length-2; i++)
				{
					aux[i] = mensaje[i+2];
				}
				texto = System::Text::Encoding::ASCII->GetString(aux);
				nombres[numCliente+1] = texto;
				anyadirComboBox(comboBoxJug1, texto);
				anyadirComboBox(comboBoxJug2, texto);
				anyadirComboBox(comboBoxJug3, texto);
				anyadirComboBox(comboBoxJug4, texto);
				switch(numCliente)
				{
				case 0:
					cambiarTextoCheckBox(checkBoxCliente1Read, texto);
					break;
				case 1:
					cambiarTextoCheckBox(checkBoxCliente2Read, texto);
					break;
				default:
					cambiarTextoCheckBox(checkBoxCliente3Read, texto);
					break;
				}
				break;
			case(voz):
				indice = safe_cast<int>(mensaje[2]);
				voces[numCliente] = indice;
				break;
			case(chat):
				if (modoServidor)
				{
					aux = gcnew array<unsigned char>(mensaje->Length - 2);
					for (int i = 0; i < mensaje->Length-2; i++)
					{
						aux[i] = mensaje[i+2];
					}
					texto = System::Text::Encoding::ASCII->GetString(aux);
					escribirMensaje(texto);  
					for (int j = 0; j < 3 && j != numCliente; j++)
					{
						if (conectados[j])
						{
							stream = clientesConectados[j]->GetStream();
							stream->Write(mensaje, 0, mensaje->Length);
						}
					}
				}
				else
				{
					aux = gcnew array<unsigned char>(mensaje->Length - 2);
					for (int i = 0; i < mensaje->Length-2; i++)
					{
						aux[i] = mensaje[i+2];
					}
					String^ texto = System::Text::Encoding::ASCII->GetString(aux);
					escribirMensaje(texto);
				}
				break;
			case(cambioJugador):
				jugador = safe_cast<int>(mensaje[2]);
				aux = gcnew array<unsigned char>(mensaje->Length - 3);
				for (int i = 0; i < mensaje->Length-3; i++)
				{
					aux[i] = mensaje[i+3];
				}
				texto = System::Text::Encoding::ASCII->GetString(aux);
				switch(jugador)
				{
				case 1:
					cambiarTextBox(textBoxJug1, texto);
					break;
				case 2:
					cambiarTextBox(textBoxJug2, texto);
					break;
				case 3:
					cambiarTextBox(textBoxJug3, texto);
					break;
				default:
					cambiarTextBox(textBoxJug4, texto);
					break;
				}
				cambiarCheckBox(checkBoxCliente0Read, false);
				cambiarCheckBox(checkBoxCliente1Read, false);
				cambiarCheckBox(checkBoxCliente2Read, false);
				cambiarCheckBox(checkBoxCliente3Read, false);
				cambiarCheckBox(checkBoxCliente0Write, false);
				cambiarCheckBox(checkBoxCliente1Write, false);
				cambiarCheckBox(checkBoxCliente2Write, false);
				cambiarCheckBox(checkBoxCliente3Write, false);
				break;
			case(cambioListo):
				cliente = safe_cast<int>(mensaje[2]);
				switch(cliente)
				{
				case 0:
					cambiarCheckBox(checkBoxCliente0Read, safe_cast<bool>(mensaje[3]));
					break;
				case 1:
					cambiarCheckBox(checkBoxCliente1Read, safe_cast<bool>(mensaje[3]));
					break;
				case 2:
					cambiarCheckBox(checkBoxCliente2Read, safe_cast<bool>(mensaje[3]));
					break;
				default:
					cambiarCheckBox(checkBoxCliente3Read, safe_cast<bool>(mensaje[3]));
					break;
				}
				if (modoServidor)
				{
					array<int>^ indices = {getIndiceComboBox(comboBoxJug1), getIndiceComboBox(comboBoxJug2),
						getIndiceComboBox(comboBoxJug3), getIndiceComboBox(comboBoxJug4)};
					array<bool>^ listos = {getCheckedCheckBox(checkBoxCliente0Write), 
						getCheckedCheckBox(checkBoxCliente1Read),
						getCheckedCheckBox(checkBoxCliente2Read), getCheckedCheckBox(checkBoxCliente3Read)};
					if (sePuedeComenzar(indices, listos))
						activarControl(botonComenzar, true);
					else
						activarControl(botonComenzar, false);
				} 
				break;
			default:
				if (!modoServidor)
				{
					stream = this->cliente->GetStream();
					aux = empaquetarMensaje(comenzar, info);
					stream->Write(aux, 0, aux->Length);
				}
				cambiarVentana(numCliente);							
			}
		}	

		array<unsigned char>^ subArray(array<unsigned char>^ input, int low, int high)
		{
			array<unsigned char>^ output = gcnew array<unsigned char>(high-low);
			for (int i = low; i < high; i++)
			{
				output[i-low] = input[i];
			}
			return output;
		}

		array<array<unsigned char>^>^ subArrays(array<unsigned char>^ input, int size)
		{
			array<array<unsigned char>^>^ output = gcnew array<array<unsigned char>^>(256);
			array<unsigned char>^ restante = subArray(input, 0, size);
			array<unsigned char>^ temp;
			int numSubs = 0;
			int totalBytes = 0;
			while (totalBytes < size)
			{
				temp = gcnew array<unsigned char>((int)restante[1]);
				for (int i = 0; i < (int)restante[1]; i++)
				{
					temp[i] = restante[i];
				}
				totalBytes += (int)restante[1];
				restante = subArray(restante, (int)restante[1], restante->Length);
				output[numSubs] = temp;
				numSubs++;				
			}
			Array::Resize(output,numSubs);
			return output;
		}

		bool sePuedeComenzar(array<int>^ indices, array<bool>^ listos)
		{
			array<bool>^ juegan = {false, false, false, false};
			if (!listos[0])
			{
				return false;
			}
			for (int i = 1; i < 4; i++)
			{
				if (!listos[i] && conectados[i-1])
					return false;
			}
			for (int i = 0; i < 4; i++)
			{
				if (indices[i] == 1)
				{
					if (!juegan[0])
						juegan[0] = true;
					else
						return false;
				}
				else if (indices[i] != 0)
				{
					if (!juegan[indices[i]-1])
						juegan[indices[i]-1] = true;
					else
						return false;
				}
			}
			if (!juegan[0])
				return false;
			for (int i = 1; i < 4; i++)
			{
				if (conectados[i-1] && !juegan[i])
					return false;
			}
			return true;
		}
	};
}