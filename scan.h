#ifndef SCAN_H
#define SCAN_H

int esAcotadoI (int num, int minimo);
int esAcotadoM (int num, int maximo);
int esAcotado (int num, int minimo, int maximo);
int dEsAcotadoI (double num, double minimo, int infimo);
int dEsAcotadoM (double num, double maximo, int supremo);
int dEsAcotado (double num, double minimo, int infimo, double maximo, int supremo);
int nextInt ();
int nextIntAcotadoI (int minimo);
int nextIntAcotadoM (int maximo);
int nextIntAcotado (int minimo, int maximo);
double nextDoubleAcotadoI (double minimo, int infimo);
double nextDoubleAcotadoM (double maximo, int supremo);
//void nextText(char * cadena);



#endif