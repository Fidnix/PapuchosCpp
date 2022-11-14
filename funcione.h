#ifndef FUNCIONE_H
#define FUNCIONE_H

/**
* Sirve para obtener los datos de todos los papuchos
* @param papuchos - (struct PapitoLindo *) es el arreglo que tiene a todos nuestros papuchos
* @param cantPapu - (int &) es el número de papuchos disponibles
*/
void llenaPapucho( struct PapitoLindo *, int &);
void calculaProbabilidaDeQueterobe(struct PapitoLindo *, int, double *);
void crearReporte( struct PapitoLindo *, int, double *);
void imprimirLinea( ofstream &, char);
#endif // FUNCIONE_H