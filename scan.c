#include <stdlib.h>
#include <stdio.h>

static int controlling = 1;

int esAcotadoI(int num, int minimo){
	return(num>=minimo);
}

int esAcotadoM(int num, int maximo){
	return(num<=maximo);
}

int esAcotado(int num, int minimo, int maximo){
    return(esAcotadoI(num, minimo) && esAcotadoM(num, maximo));
}

int dEsAcotadoI(double num, double minimo, int infimo){
	if(num>minimo){
		return 1;
	}
	else if(num==minimo && infimo){
		return 1;
	}
	return 0;
}

int dEsAcotadoM(double num, double maximo, int supremo){
	if(num<maximo){
		return 1;
	}
	else if(num==maximo && supremo){
		return 1;
	}
	return 0;
}

int dEsAcotado(double num, double minimo, int infimo, double maximo, int supremo){
    return(dEsAcotadoI(num, minimo, infimo) && dEsAcotadoM(num, maximo, supremo));
}

//Ints
int nextInt (){
    int controlling = 1;
    int resultado;
    char a[12];;/*Creo el array de char donde vamos a guardar la entrada, 
                el tamaño es 10 ya que el int maximo no tiene más digitos,
                necesitamos otro más que contiene \0 y otro para contemplar números negativos*/
    char pos;//Para saber lo que contiene la posición del array
    char pos2;
    int ii;//Para tener controlado el indice del array
    int cont;//Para que no nos pasemos de los 10 digitos del array
    int signo;//Lo necesitaremos para contemplar numeros negativos
    char peta[10] = {8, 5, 8, 9, 9, 3, 4, 5, 9, 1};//Si el número que nos da el usuario es mayor que este, desbordará por segunda vez.
    while(controlling){
        ii = 0;
        cont = 13;
        signo = 1;
        scanf("%s", a);
        pos = a[0];//inicializamos con el primer valor del array
        if((pos == '-') && esAcotado(a[1], 48, 57)){
            signo = -1;
            a[0]='0';
            pos = a[0];
            cont++;
        }
        while((pos != '\0') && cont){/*Evaluamos cada posición de la cadena, debe estar entre 48 y 57 que son los caracteres de los números.
                                    Si no es un numero o no contiene \0 (han introducido demasiados caracteres), explota y volvemos a pedir.*/
            if(!esAcotado(pos, 48, 57)){//Comprobamos que es un numero
                cont = 1;//No es un valor valido, salimos el bucle y volvemos a empezar, ponemos 1 porque despues decrementamos
                printf("No has introducido un valor valido, prueba otra vez.\n");               
            }
            ii++;
            cont--;
            pos = a[ii];
        }
        resultado = atoi(a);//Todo está casi en orden, pasamos la cadena a int y vamos a comprobar que no desborde.
        if(cont <= 3 && resultado>=0){
            if(signo<0){
                ii = 1;
            }
            else{
                ii = 0;
            }
            while(ii<10){
                pos = a[ii];
                pos2 = peta[ii];
                if(pos <= pos2){

                }
                else{
                    cont = 0;//Ha desbordado y ponemos el resultado a -1 para que salga el mensaje
                    resultado = -1;
                }
                ii++;
            }
        }
        if(cont && (resultado>=0)){
            resultado = resultado*signo;
            return resultado;
        }
        else if(resultado<0){
            printf("El valor introducido desborda, prueba otra vez\n");
        }   
    }
    return 0;
}

int nextIntAcotadoI(int minimo){//Scanea un int acotado inferiormente siempre coge la cota
	int num = 0;
	while(controlling){
    	scanf("%i", &num);
    	if(esAcotadoI(num, minimo)){
    		return num;
    	}
    	else{
    		printf("El número esta por debajo de %i, mete un número correcto\n", minimo);
    	}
	}
	return num;
}

int nextIntAcotadoM(int maximo){
	int num = 0;
	while(controlling){
    	scanf("%i", &num);
    	if(esAcotadoM(num, maximo)){
    		return num;
    	}
    	else{
    		printf("El número está por encima de %i, mete un número correcto\n", maximo);
    	}
	}
	return num;
}

int nextIntAcotado(int minimo, int maximo){
    int num = 0;
    while(controlling){
        scanf("%i", &num);
        if(esAcotadoM(num, maximo) && esAcotadoI(num, minimo)){
            return num;
        }
        else{
            printf("El número debe estar comprendido entre %i y %i, mete un número correcto\n", minimo, maximo);
        }
    }
    return num;
}

/*
int nextInt_Intervalo(int min, int max){//Scanea ints en un intervalo
	int aux = 0;

	while (controlling){
		
		
		try{
			Scanner sc = new Scanner(System.in);
			aux = sc.nextInt();
			rango(aux, min, max);
			return aux;
		
		
		}
		catch(InputMismatchException ex){
			System.out.println("Creia que sabias lo que era un número entero");
			System.out.println("Intentalo otra vez anda");
		}
		catch(ExceptionIntervalo ex){
			System.out.println("Si tu respuesta esta en el intervalo lógico de mi pregunta estaria genial");
		}
	}
	return aux;
}
*/

/*ROTO
double nextDouble_Intervalo(double min, double max, int infimo, int supremo){//Scanea doubles en un intervalo
	double aux = 0;

	while (controlling){
		
		
		try{
			Scanner sc = new Scanner(System.in);
			aux = sc.nextDouble();
			rango(aux, min, max);
			return aux;
		
		
		}
		catch(InputMismatchException ex){
			System.out.println("Creia que sabias lo que era un número entero");
			System.out.println("Intentalo otra vez anda");
		}
		catch(ExceptionIntervalo ex){
			System.out.println("Si tu respuesta esta en el intervalo lógico de mi pregunta estaria genial");
		}
		
	}
	return aux;
}

*/

//Doubles
/*
double nextDouble(){//Scanea Doubles de forma segura
	double num = 0;
	while (controlling){
		
		
		try{
			scanf("%i", &num);
			return num;
		
		
		}
		catch(InputMismatchException ex){
			System.out.println("Creia que sabias lo que era un número real");
			System.out.println("Intentalo otra vez anda");
		}
	}
	return num;
}
*/
double nextDoubleAcotadoI(double minimo, int infimo){//Scanea un double acotado inferiormente. HACER PARA SUPERIOr, INTERVALO ACOTADO Y LO MISMO PARA INTS
	double num = 0;
	while(controlling){
    	scanf("%lf", &num);
    	if(dEsAcotadoI(num, minimo, infimo)){
    		return num;
    	}	
    	else{
    		printf("El número esta por debajo de la cota, mete un número correcto\n");
    	}
	}
	return num;
}

double nextDoubleAcotadoM(double maximo, int supremo){//Scanea un double acotado inferiormente. HACER PARA SUPERIOr, INTERVALO ACOTADO Y LO MISMO PARA INTS
	double num = 0;
	while(controlling){
    	scanf("%lf", &num);
    	if(dEsAcotadoM(num, maximo, supremo)){
    		return num;
    	}	
    	else{
    		printf("El número esta por debajo de la cota, mete un número correcto\n");
    	}
	}
	return num;
}


//Strings
/*
char[] next(){//Recoger un String facilmente
	Scanner sc = new Scanner(System.in);
	String respuesta = sc.next();
	return respuesta;
}
*/


/*
void nextText(char * cadena){//Recoger un texto facilmente
	scanf("%[^'\n']s",cadena);
}
*/


/*
char[] nextMultiple(){//Recoger varios Strings. Este metodo puede dar problemas si pretendes usarlo repetidamente en un mismo array
	char [] aux = nextText();
	String delimitadores= " ";
	String[] palabrasSeparadas = aux.split(delimitadores);
	return palabrasSeparadas;
}
*/
/* Se rompe en consecuencia
int nextCharConcreto(char a, int importanMayus){
	if(importanMayus){
		return(next().equals(a));
	}
	return(next().equalsIgnoreCase(a));
}	
*/