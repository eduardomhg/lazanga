
#include "stdafx.h"

#ifndef _CARTA_H_
#include "Carta.h"
#endif 

Carta::Carta(){}

Carta::Carta(const Carta% carta)
{
	valor = carta.valor;
	palo = carta.palo;
}

Carta::Carta(valores valor, palos palo)
{
	this->valor = valor;
	this->palo = palo;
}

valores Carta::getValor()
{
	return this->valor;
}

bool Carta::operator==(const Carta% carta)
{
	return (carta.valor == this->valor) && 
		(carta.palo == this->palo);
}

Carta% Carta::operator =(const Carta% carta)
{
	this->valor = carta.valor;
	this->palo = carta.palo;
	return *this;
}

System::String^ Carta::strValor()
{
	switch(valor)
	{
	case as:
		{
			return "As";
			break;
		}
	case dos:
		{
			return "Dos";
			break;
		}
	case tres:
		{
			return "Tres";
			break;
		}
	case cuatro:
		{
			return "Cuatro";
			break;
		}
	case cinco:
		{
			return "Cinco";
			break;
		}
	case seis:
		{
			return "Seis";
			break;
		}
	case siete:
		{
			return "Siete";
			break;
		}
	case sota:
		{
			return "Sota";
			break;
		}
	case caballo:
		{
			return "Caballo";
			break;
		}
	default:
		{
			return "Rey";
			break;
		}
	}
}

palos Carta::getPalo()
{
	return this->palo;
}

System::String^ Carta::strPalo()
{
	switch(palo)
	{
	case bastos:
		{
			return "Bastos";
			break;
		}
	case copas:
		{
			return "Copas";
			break;
		}
	case espadas:
		{
			return "Espadas";
			break;
		}
	default:
		{
			return "Oros";
			break;
		}
	}
}		

System::String^ Carta::nombreArchivo()
{
	System::String^ nombre = "";
	switch(valor)
	{
	case as:
		{
			nombre += "a";
			break;
		}
	case dos:
		{
			nombre += "2";
			break;
		}
	case tres:
		{
			nombre += "3";
			break;
		}
	case cuatro:
		{
			nombre += "4";
			break;
		}
	case cinco:
		{
			nombre += "5";
			break;
		}
	case seis:
		{
			nombre += "6";
			break;
		}
	case siete:
		{
			nombre += "7";
			break;
		}
	case sota:
		{
			nombre += "s";
			break;
		}
	case caballo:
		{
			nombre += "c";
			break;
		}
	default:
		{
			nombre += "r";
			break;
		}
	}
	switch(palo)
	{
	case bastos:
		{
			nombre += "b";
			break;
		}
	case copas:
		{
			nombre += "c";
			break;
		}
	case espadas:
		{
			nombre += "e";
			break;
		}
	default:
		{
			nombre += "o";
			break;
		}
	}
	return nombre;

}

System::String^ Carta::nombre()
{
	return this->strValor() + " de " + this->strPalo();
}

System::String^ Carta::nombreZanga(palos triunfo)
{
	if (this->numeroJuego(bastos, triunfo) < 36)
		return this->nombre();
	else
	{
		switch(this->numeroJuego(bastos, triunfo))
		{
		case 39:			
				return "Espadilla";			
		case 37:			
				return "Bastillo";			
		case 38:			
				return "Malilla de " + this->strPalo();
				break;			
		default:			
				if (palo == oros || palo == copas)
					return "Punto de " + this->strPalo();
				else
					return this->nombre();
		}
	}
	
}

int Carta::numeroOrden()
{
	return 8*(int)palo + (int)valor;
}

int Carta::numeroJuego(palos paloInicial, palos triunfo)
{		
	switch(triunfo)
	{
	case bastos:			
		switch(paloInicial)
		{
		case bastos:
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					return 37;									
				case dos:									
					return 38;									
				default:									
					return 36 - (int)valor;									
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:									
					return 28 - (int)valor;									
				default:									
					return 25 - (9-int(valor));									
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:									
					return 39;									
				default:									
					return 18 - (int)valor;									
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:									
					return 9 - (int)valor;									
				default:									
					return 6 - (9-int(valor));									
				}
				break;												
			}
			break;
		case copas:
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:									
					return 37;									
				case dos:									
					return 38;									
				default:
					return 36 - (int)valor;
				}								
				break;
			case copas:
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					return 28 - (int)valor;
				default:
					return 25 - (9-int(valor));
				}
				break;
			case espadas:							
				switch(this->valor)
				{		
				case as:
					return 39;
				default:
					return 18 - (int)valor;
				}
				break;
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					return 9 - (int)valor;
				default:
					return 6 - (9-int(valor));
				}
				break;				
			}
			break;
		case espadas:
			switch(this->palo)
			{
			case bastos:
				switch(this->valor)
				{
				case as:
					return 37;
				case dos:
					return 38;
				default:
					return 36 - (int)valor;
				}
				break;
			case copas:
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					return 19 - (int)valor;
				default:
					return 16 - (9-int(valor));
				}
				break;
			case espadas:
				switch(this->valor)
				{		
				case as:
					return 39;
				default:
					return 28 - (int)valor;
				}
				break;
			default:
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					return 9 - (int)valor;
				default:
					return 6 - (9-int(valor));
				}
				break;				
			}
			break;
		default:
			switch(this->palo)
			{
			case bastos:
				switch(this->valor)
				{
				case as:						
					return 37;						
				case dos:						
					return 38;						
				default:						
					return 36 - (int)valor;						
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:						
					return 9 - (int)valor;						
				default:						
					return 6 - (9-int(valor));						
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:						
					return 39;						
				default:						
					return 18 - (int)valor;						
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:						
					return 28 - (int)valor;						
				default:						
					return 25 - (9-int(valor));						
				}
				break;											
			}
			break;				
		}
		break;
	case copas:			
		switch(paloInicial)
		{
		case bastos:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;												
			}
			break;					
		case copas:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			case copas:					
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;												
			}
			break;					
		case espadas:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;											
			}
			break;					
		default:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 17 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 8 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 27 - (int)valor;
					}
				default:
					{
						return 24 - (9-int(valor));
					}
				}
				break;												
			}
			break;								
		}
		break;
	case espadas:			
		switch(paloInicial)
		{
		case bastos:					
			switch(this->palo)
			{				
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}
				default:
					{
						return 28 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 19 - (int)valor;
					}
				default:
					{
						return 16 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:
					{
						return 39;
					}
				case dos:
					{
						return 38;
					}
				default:
					{
						return 36 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;												
			}
			break;					
		case copas:					
			switch(this->palo)
			{				
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 28 - (int)valor;
					}
				default:
					{
						return 25 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:
					{
						return 39;
					}
				case dos:
					{
						return 38;
					}
				default:
					{
						return 36 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;												
			}
			break;			
		case espadas:					
			switch(this->palo)
			{				
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}
				default:
					{
						return 28 - (int)valor;
					}
				}
				break;						
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 19 - (int)valor;
					}
				default:
					{
						return 16 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:
					{
						return 39;
					}
				case dos:
					{
						return 38;
					}
				default:
					{
						return 36 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;												
			}
			break;					
		default:					
			switch(this->palo)
			{				
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{		
				case as:
					{
						return 39;
					}
				case dos:
					{
						return 38;
					}
				default:
					{
						return 36 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{							
				case sota:
				case caballo:
				case rey:
					{
						return 28 - (int)valor;
					}
				default:
					{
						return 25 - (9-int(valor));
					}
				}
				break;												
			}
			break;					
		}		
		break;
	default:			
		switch(paloInicial)
		{
		case bastos:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 18 - (int)valor;
					}
				default:
					{
						return 15 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 8 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}							
				}
				break;												
			}
			break;					
		case copas:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 17 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 27 - (int)valor;
					}
				default:
					{
						return 24 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 8 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}							
				}
				break;												
			}
			break;					
		case espadas:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 18 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 9 - (int)valor;
					}
				default:
					{
						return 6 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}							
				}
				break;											
			}
			break;					
		default:					
			switch(this->palo)
			{
			case bastos:							
				switch(this->valor)
				{
				case as:
					{
						return 37;
					}			
				default:
					{
						return 27 - (int)valor;
					}
				}
				break;							
			case copas:							
				switch(this->valor)
				{
				case sota:
				case caballo:
				case rey:
					{
						return 18 - (int)valor;
					}
				default:
					{
						return 15 - (9-int(valor));
					}
				}
				break;							
			case espadas:							
				switch(this->valor)
				{							
				case as:
					{
						return 39;
					}			
				default:
					{
						return 8 - (int)valor;
					}
				}
				break;							
			default:							
				switch(this->valor)
				{
				case siete:
					{
						return 38;
					}
				case as:
					{
						return 36;
					}
				case sota:
				case caballo:
				case rey:
					{
						return 35 - (int)valor;
					}
				default:
					{
						return 32 - (8-int(valor));
					}							
				}
				break;												
			}
			break;					
		}	
		break;
	}
}		


