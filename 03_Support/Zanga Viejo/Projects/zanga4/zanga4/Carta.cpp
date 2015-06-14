
#ifndef _CARTA_H_
  #include "Carta.h"
#endif 

Carta::Carta(){}

Carta::Carta(valores valor, palos palo)
{
	this->valor = valor;
	this->palo = palo;
}

valores Carta::getValor()
{
	return this->valor;
}

bool Carta::operator==(Carta carta)
{
	return (carta.getValor() == this->getValor()) && 
		(carta.getPalo() == this->getPalo());
}

string Carta::strValor()
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

string Carta::strPalo()
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

string Carta::nombre()
{
	return this->strValor() + " de " + this->strPalo();
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


