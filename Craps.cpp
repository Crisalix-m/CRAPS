#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

int main(){
    //Primer usuario
    string dni1;
    int edad1, jugadas1=0;
    double salario1=0, credito_cas1=0,apuesta1=0;
	bool quiere_jugar1= true;
	
    //Segundo usuario
    string dni2;
    int edad2, jugadas2=0;
    double salario2=0, credito_cas2=0,apuesta2=0;
	bool quiere_jugar2= true;
	
	//Verificación edad
	char ver_edad;
	//Verificación dni
	bool dni_validado= false;
	
    //Casino y juego
    int fondo_in_mesa=0, fondo_mesa=0;
    bool juego_terminado= false;
    int d1=0, d2=0;
    int sum_dado=0, punto=0;
    char opcion_salida;
    bool continuar_jugadas;

    //Tiempo random
    srand(time(0));

    //Proceso inicial del programa
    cout<<"=================================================="<< endl;
    cout<<"       ¡¡¡¡   BIENVENIDOS AL CASINO    !!!!       "<< endl;
    cout<<"=================================================="<< endl;
    
    //Ingresando datos jugador 1
    cout<<"----REGISTRO DEL PRIMER JUGADOR---"<< endl;
    cout<<"Ingresar DNI(8 digitos): ";
    getline(cin,dni1);
	do{
		if(dni1.length() != 8){
			cout<<"-> Ingrese un dni valido."<< endl;
			dni_validado= false;
		}
		else{
			dni_validado= true;
			for(int i=0; i< dni1.length(); i++){
				if(!isdigit(dni1[i])){	//aqui se verifica que es un numero del 0 al 9
					dni_validado= false;
					break;
				}
			}
			if(!dni_validado){
				cout<<"-> Ingrese un dni valido."<< endl;
			}
		}
		
		if(!dni_validado){
			cout<<"Ingresar DNI(8 digitos): ";
			getline(cin,dni1);
		}
	}while(!dni_validado);
	dni_validado= false;
	
    cout<<"Ingresar EDAD: "; cin>>edad1;    
    if(edad1 < 18){
    do{
    	cout<<"-> ¿Esta es tu edad real?(s/n): "; cin>>ver_edad;
    	cin.ignore(10000, '\n');
    } while(ver_edad != 'S' && ver_edad != 's' && ver_edad != 'N' && ver_edad != 'n');
    
		if(ver_edad== 'S' || ver_edad== 's'){
			cout<<">>>Edad del primer jugador invalida.[JUEGO TERMINADO]"<<endl;
			return 0;
		}
		
		if(ver_edad== 'N'|| ver_edad== 'n'){
			cout<<"Ingresa tu verdadera edad: "; cin>>edad1;
			if(edad1 < 18){
				cout<<">>>Edad del primer jugador invalida.[JUEGO TERMINADO]<<<"<<endl;
        		return 0;
			}
		}
    }
    cout<<"--> JUGADOR 1 AUTORIZADO A JUGAR \n"<<endl;
    cin.ignore(10000, '\n');

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

    //Ingresando datos jugador 2
    cout<<"\n----REGISTRO DEL SEGUNDO JUGADOR---"<< endl;
    cout<<"Ingresar DNI(8 digitos): ";
    getline(cin,dni2);
	do{
		if(dni2.length() != 8){
			cout<<"-> Ingrese un dni valido."<< endl;
			dni_validado= false;
		}
		else{
			dni_validado= true;
			for(int i=0; i< dni2.length(); i++){
				if(!isdigit(dni2[i])){	//aqui se verifica que es un numero del 0 al 9
					dni_validado= false;
					break;
				}
			}
			if(!dni_validado){
				cout<<"-> Ingrese un dni valido."<< endl;
			}
			else{
				if(dni1==dni2){
				cout<<"[REGISTRAR OTRO USUARIO]: El DNI no puede ser igual al del Jugador 1."<< endl;
                dni_validado = false;
            	}
			}
		}
		
		if(!dni_validado){
			cout<<"Ingresar DNI(8 digitos): ";
			getline(cin,dni2);
		}
	}while(!dni_validado);

    cout<<"Ingresar EDAD: "; cin>>edad2;
    if(edad2 < 18){
        do{
    	cout<<"-> ¿Esta es tu edad real?(s/n): "; cin>>ver_edad;
    	cin.ignore(10000, '\n');
    } while(ver_edad != 'S' && ver_edad != 's' && ver_edad != 'N' && ver_edad != 'n');
    
		if(ver_edad== 'S' || ver_edad== 's'){
			cout<<">>>Edad del segundo jugador invalida.[JUEGO TERMINADO]"<<endl;
			return 0;
		}
		
		if(ver_edad== 'N'|| ver_edad== 'n'){
			cout<<"Ingresa tu verdadera edad: "; cin>>edad2;
			if(edad2 < 18){
				cout<<">>>Edad del primer jugador invalida.[JUEGO TERMINADO]<<<"<<endl;
        		return 0;
			}
		}
    }
    cout<<"--> JUGADOR 2 AUTORIZADO A JUGAR\n"<< endl;
    
    cout<<"________ COMIENZA EL JUEGO ________"<< endl;
    
    //Ingreso de salarios
    //Salario de jugador 1
    do{
        cout<<"(JUGADOR 1) Ingresar su credito inicial(soles): "; cin>> salario1;
        if(salario1<=0){
            cout<<"Ingresar un monto valido"<< endl;
        }
    }while(salario1<=0);
    credito_cas1=salario1;
    
    //Salario de jugador 2
    do{
        cout<<"(JUGADOR 2) Ingresar su credito inicial(soles): "; cin>> salario2;
        if(salario2<=0){
            cout<<"Ingresar un monto valido"<< endl;
        }
    }while(salario2<=0);
    credito_cas2=salario2;

    //Inicialización de la mesa
    fondo_in_mesa=10*(salario1+salario2);
    fondo_mesa=fondo_in_mesa;
    cout<<"\nMesa inicial configurada - [FONDO DE LA BANCA(MESA): "<<fondo_in_mesa<<" soles]\n"<< endl;
    
    //SE COMIENZA AQUÍ EL BUCLE DEL JUEGO DEL CASINO JUNTO CON SUS REGLAS
    while(juego_terminado == false){
        
        //Turno Jugador 1 (Juega si quiere, tiene fondos y la mesa está activa)
        if(quiere_jugar1 && credito_cas1 > 0 && fondo_mesa > 0){
            cout<<"--------------------------------------------"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"TURNO JUGADOR 1"<<" [DNI:"<<dni1<<"]"<<endl;
            cout<<"Credito actual: "<<credito_cas1<<" || Fondo de la mesa: "<<fondo_mesa<<endl;
            
            do{
                cout<<"Elija el monto a apostar: "; cin>>apuesta1;
                if(apuesta1<= 0 || apuesta1> credito_cas1 || apuesta1> fondo_mesa){
                    cout<<"--ERROR--\n[APUESTA FUERA DE RANGO]: Ingresar un valor valido."<<endl;
                }
            }while(apuesta1<= 0 || apuesta1> credito_cas1 || apuesta1> fondo_mesa);
        
            //LANZAMOS DADOOOOOSSSSS
            d1=(rand()%6)+1;
            d2=(rand()%6)+1;
            sum_dado=d1+d2;
            jugadas1++;
            
            cout<<"\nLANZAMIENTO INICIAL ==> Dados:["<<d1<<"]["<<d2<<"] | Suma: "<<sum_dado<<endl;
            
            if(sum_dado== 7 || sum_dado== 11){
                cout<<"[GANASTE!!!]"<< endl;
                credito_cas1+= apuesta1;
                fondo_mesa-= apuesta1;
            }
            else if(sum_dado== 2 || sum_dado== 3 || sum_dado== 12){
                cout<<"[OH NO. PERDISTE...]"<< endl;
                credito_cas1-= apuesta1;
                fondo_mesa+= apuesta1;
            }   
            else{
                //ESTABLECEMOS EL PUNTO
                punto = sum_dado;
                cout<<"-> SE ESTABLECIO EL PUNTO EN: "<<punto<<". Se continua lanzando el dado...\n"<< endl;
                continuar_jugadas=true;
                
                while(continuar_jugadas){
                    d1=(rand()%6)+1;
                    d2=(rand()%6)+1;
                    sum_dado= d1+d2;
                    jugadas1++;
                    cout<<"LANZAMOS NUEVAMENTE ==> Dados:["<<d1<<"]["<<d2<<"] | Suma: "<<sum_dado<< endl;
                    if(sum_dado== punto){
                        cout<<"[GANASTE!!]: LOGRASTE EL PUNTO."<< endl;
                        credito_cas1+= apuesta1;
                        fondo_mesa-= apuesta1;
                        continuar_jugadas= false;
                    }
                    else if(sum_dado== 7){
                        cout<<"[PERDISTE]: OBTUVISTE UN 7."<< endl;
                        credito_cas1-= apuesta1;
                        fondo_mesa+= apuesta1;
                        continuar_jugadas= false;
                    }
                }   
            }
        }
            
        //TURNO JUGADOR 2 (Juega si quiere, tiene fondos y la mesa está activa)
        if(juego_terminado == false && quiere_jugar2 && credito_cas2 > 0 && fondo_mesa > 0){
            cout<<"--------------------------------------------"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"TURNO JUGADOR 2"<<" [DNI:"<<dni2<<"]"<<endl;
            cout<<"Credito actual: "<<credito_cas2<<"|| Fondo de la mesa: "<<fondo_mesa<<endl; 
            
            do{
                cout<<"Elija el monto a apostar: "; cin>>apuesta2;
                if(apuesta2<= 0 || apuesta2> credito_cas2 || apuesta2> fondo_mesa){
                    cout<<"--ERROR--\n[APUESTA FUERA DE RANGO]: Ingresar un valor valido."<<endl;
                }
            }while(apuesta2<= 0 || apuesta2> credito_cas2 || apuesta2> fondo_mesa);
            
            d1=(rand()%6)+1;
            d2=(rand()%6)+1;
            sum_dado=d1+d2;
            jugadas2++;
            
            cout<<"\nLANZAMIENTO INICIAL ==> Dados:["<<d1<<"]["<<d2<<"] | Suma: "<<sum_dado<<endl;
            
            if(sum_dado== 7 || sum_dado== 11){
                cout<<"[GANASTE!!!]"<< endl;
                credito_cas2+= apuesta2;
                fondo_mesa-= apuesta2;
            }
            else if(sum_dado== 2 || sum_dado== 3 || sum_dado== 12){
                cout<<"[OH NO. PERDISTE...]"<< endl;
                credito_cas2-= apuesta2;
                fondo_mesa+= apuesta2;
            }
            else{
                //ESTABLECEMOS EL PUNTO
                punto = sum_dado;
                cout<<"-> SE ESTABLECIO EL PUNTO EN: "<<punto<<". Se continua lanzando el dado...\n"<< endl;
                continuar_jugadas=true;
                
                while(continuar_jugadas){
                    d1=(rand()%6)+1;
                    d2=(rand()%6)+1;
                    sum_dado= d1+d2;
                    jugadas2++;
                    cout<<"LANZAMOS NUEVAMENTE ==> Dados:["<<d1<<"]["<<d2<<"] | Suma: "<<sum_dado<< endl;
                    if(sum_dado== punto){
                        cout<<"[GANASTE!!]: LOGRASTE EL PUNTO."<< endl;
                        credito_cas2+= apuesta2;
                        fondo_mesa-= apuesta2;
                        continuar_jugadas= false;
                    }
                    else if(sum_dado== 7){
                        cout<<"[PERDISTE]: OBTUVISTE UN 7."<< endl;
                        credito_cas2-= apuesta2;
                        fondo_mesa+= apuesta2;
                        continuar_jugadas= false;
                    }
                }   
            }
        }

        // EVALUACIÓN DE FINALIZACIÓN O GESTIÓN DE CONTINUACIÓN INDIVIDUAL
        if(fondo_mesa <= 0){
        	cout<<"[JUEGO TERMINADO]: LA MESA QUEBRÓ.";
            juego_terminado = true;
        }
        else if(credito_cas1 <= 0 && credito_cas2 <= 0){
            cout << "\n[FIN DEL JUEGO]: Ambos usuarios han quedado en quiebra absoluta." << endl;
            juego_terminado = true;
        }
        else{
            cout << "\n-----------------------------------------------------" << endl;
            cout << "|||||| GESTION DE CONTINUACION DE RONDA |||||||" << endl;
            cout << "-----------------------------------------------------" << endl;


            // Preguntar al Jugador 1 si quiere seguir y no ha quebrado
            if(quiere_jugar1 && credito_cas1 > 0){
                do {
                    cout << "¿Jugador 1, desea continuar jugando la siguiente ronda? (S/N): ";
                    cin >> opcion_salida;
                    cin.ignore(10000, '\n');	
                    
                    if(opcion_salida == 'N' || opcion_salida == 'n'){
                        quiere_jugar1 = false;
                        cout << "-> Jugador 1 ha decidido retirarse." << endl;
                    }
                } while(opcion_salida != 'S' && opcion_salida != 's' && opcion_salida != 'N' && opcion_salida != 'n');
            } else if (credito_cas1 <= 0 && quiere_jugar1) {
                quiere_jugar1 = false; // Quiebra automática sin preguntar
                cout<<"-> Jugador 1 ha quebrado y no puede continuar."<< endl;
            }

            // Preguntar al Jugador 2 solo si quiere seguir y no ha quebrado
            if(quiere_jugar2 && credito_cas2 > 0){
                do {
                    cout << "¿Jugador 2, desea continuar jugando la siguiente ronda? (S/N): ";
                    cin >> opcion_salida;
                    cin.ignore(10000, '\n');	
                    
                    if(opcion_salida == 'N' || opcion_salida == 'n'){
                        quiere_jugar2 = false;
                        cout << "-> Jugador 2 ha decidido retirarse." << endl;
                    }
                } while(opcion_salida != 'S' && opcion_salida != 's' && opcion_salida != 'N' && opcion_salida != 'n');
            } else if (credito_cas2 <= 0 && quiere_jugar2) {
                quiere_jugar2 = false; // Quiebra automática sin preguntar
                cout<<"-> Jugador 2 ha quebrado y no puede continuar."<< endl;
            }

            // Si ninguno de los dos puede o quiere seguir, finaliza el juego por completo
            if(!quiere_jugar1 && !quiere_jugar2){
                cout << "\nNINGUN JUGADOR CONTINUA JUGANDO." << endl;
                juego_terminado = true;
            }
        }               
    }
    
    //resumen
    cout<<"\n====================================="<< endl;
    cout<<"     RESUMEN DE LAS JUGADAS"<< endl;
    cout<<"====================================="<< endl;
    cout<<"Total de lanzamientos de dados: "<<jugadas1+jugadas2<<endl;
    cout<<"-------------------------------------"<< endl;
    cout<<"[JUGADOR 1] (DNI: "<<dni1<<")"<< endl;
    cout<<"- Tiros realizados   : "<<jugadas1<< endl;
    cout<<"- Credito inicial    : "<<salario1<<" soles"<< endl;
    cout<<"- Credito final      : "<<credito_cas1<<" soles"<< endl;
    cout<<"- Balance neto       : "<<credito_cas1-salario1<<" soles"<< endl;
    cout<<"--------------------------------"<< endl;
    cout<<"[JUGADOR 2] (DNI: " << dni2 <<")"<< endl;
    cout<<"- Tiros realizados   : "<<jugadas2<< endl;
    cout<<"- Credito Inicial    : "<<salario2<<" soles" << endl;
    cout<<"- Credito Final      : "<<credito_cas2<< " soles"<< endl;
    cout<<"- Balance Neto       : "<<credito_cas2-salario2<< " soles"<< endl;
    cout<<"--------------------------------"<< endl;
    cout<< "ESTADO DE LA BANCA (MESA):"<< endl;
    cout<<" - Fondos Iniciales  : "<<fondo_in_mesa<<" soles"<< endl;
    cout<<" - Fondos Finales    : "<<fondo_mesa<<" soles"<< endl;
    cout<<" - Balance de Banca  : "<<fondo_mesa-fondo_in_mesa<<" soles"<< endl;
    cout<<"--------------------------------"<< endl;

    return 0;
}