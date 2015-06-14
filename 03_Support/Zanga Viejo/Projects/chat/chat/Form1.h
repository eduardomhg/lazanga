#pragma once


namespace chat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 168);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(38, 206);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Enviar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Location = System::Drawing::Point(38, 21);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(209, 130);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(147, 168);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Thread^ hiloServidor;



		void mainHiloServidor()
		{
			// Set the TcpListener on port 13000.
			Int32 port = 13001;
			IPAddress^ localAddr = IPAddress::Parse("127.0.0.1");

			// TcpListener* server = new TcpListener(port);
			TcpListener^ server = gcnew TcpListener(localAddr, port);

			// Start listening for client requests.
			server->Start();

			// Buffer for reading data
			array<unsigned char, 1>^ bytes = gcnew array<unsigned char,1>(256);
			String^ data;
			escribirMensaje("Waiting for a connection...");

			// Enter the listening loop.
			while (true) {
				

				// Perform a blocking call to accept requests.
				// You could also user server.AcceptSocket() here.
				TcpClient^ client = server->AcceptTcpClient();            
				//escribirMensaje("Connected!");

				data = String::Empty;

				//// Get a stream Object* for reading and writing
				NetworkStream^ stream = client->GetStream();

				Int32 i;

				//// Loop to receive all the data sent by the client.
				while (i = stream->Read(bytes, 0, bytes->Length)) {   
				//	// Translate data bytes to a ASCII String*.
					data = System::Text::Encoding::ASCII->GetString(bytes, 0, i);
					escribirMensaje(String::Format("Received by server: " + data));

				//	// Process the data sent by the client.
					data = data->ToUpper();

					array<unsigned char, 1>^ msg = 
					System::Text::Encoding::ASCII->GetBytes(data);

				////	// Send back a response.
				//	stream->Write(msg, 0, msg->Length);
				//	escribirMensaje(String::Format("Sent by server: " + 
				//	 System::Text::Encoding::ASCII->GetString(msg)));           
				}

				// Shutdown and end connection
				client->Close();
			}
		}

		delegate void escribirMensajeDelegate(String^ mensaje);

		void escribirMensaje(String^ mensaje)
		{	
			if (textBox2->InvokeRequired == false)
			{
				textBox2->AppendText(mensaje + "\n");
			}
			else 
			{					 
				escribirMensajeDelegate^ myThreadDelegate =
					gcnew escribirMensajeDelegate(this, &chat::Form1::escribirMensaje);
				array<Object^>^arrayObjects = {mensaje};
				this->Invoke(myThreadDelegate, arrayObjects);			
			}				 
		}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 ThreadStart ^myThreadDelegate = 
					 gcnew ThreadStart(this, &chat::Form1::mainHiloServidor);
				 hiloServidor = gcnew Thread(myThreadDelegate);
				 hiloServidor->IsBackground = true;
				 hiloServidor->Start();
			 }
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			 {
				 if (hiloServidor->IsAlive)
				 {
					 hiloServidor->Abort();							
				 }
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 // Create a TcpClient.
				 // Note, for this client to work you need to have a TcpServer 
				 // connected to the same address as specified by the server, port
				 // combination.
				 Int32 port = 13000;
				 TcpClient^ client = gcnew TcpClient(textBox3->Text, port);
				 String^ message = textBox1->Text;

				 //// Translate the passed message into ASCII and store it as a Byte array.
				 array<Byte>^data = System::Text::Encoding::ASCII->GetBytes(message);

				 //// Get a client stream for reading and writing.

				 NetworkStream^ stream = client->GetStream();

				 //// Send the message to the connected TcpServer. 
				 stream->Write(data, 0, data->Length);

				 escribirMensaje(String::Format("Sent by client: " + 
					 System::Text::Encoding::ASCII->GetString(data)));

				 //// Receive the TcpServer::response.

				 ////// Buffer to store the response bytes.
				 data = gcnew array<Byte>(256);

				 ////// String to store the response ASCII representation.
				 String^ responseData = String::Empty;

				 ////// Read the first batch of the TcpServer response bytes.
				 /*Int32 bytes = stream->Read( data, 0, data->Length );
				 responseData = System::Text::Encoding::ASCII->GetString( data, 0, bytes );
				 escribirMensaje(String::Format("Received by client: " + 
					System::Text::Encoding::ASCII->GetString(data, 0, bytes)));*/

				 // Close everything.
				 client->Close();

			 }
	};
}

