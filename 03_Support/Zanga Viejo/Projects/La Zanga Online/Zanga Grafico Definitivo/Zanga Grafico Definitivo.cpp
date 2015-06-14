// Zanga Grafico Definitivo.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "FormEntrada.h"
#include "FormMulti.h"
#include <vcclr.h>

using namespace ZangaGraficoDefinitivo;

gcroot<FormEntrada^> fe; 

System::Void ZangaGraficoDefinitivo::FormMulti::formMultiBotonMenuPrincipal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close(); 	
}

System::Void ZangaGraficoDefinitivo::Form1::form1BotonMenuPrincipal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close(); 	
}

System::Void ZangaGraficoDefinitivo::FormMulti::FormMulti_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	if (e->CloseReason == System::Windows::Forms::CloseReason::UserClosing)
	{
		fe->Show();
	}	
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
		{
			hiloCliente->Abort();
			cliente->Close();
		}
	}
}

System::Void ZangaGraficoDefinitivo::Form1::Form1_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	if (this->hiloJuego->IsAlive)
	{
		this->reanudar();
		this->hiloJuego->Abort();							
	}
	if (e->CloseReason == System::Windows::Forms::CloseReason::UserClosing)
	{
		fe->Show();
	}
}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	fe = gcnew FormEntrada();
	Application::Run(fe);
	return 0;
}
