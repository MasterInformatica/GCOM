#ifndef Revolucion_H_
#define Revolucion_H_

#include "Malla.h"
#include "PuntoVector3D.h"

#define PI 3.14159265359

/* Dado un perfil en la constructora, crea una Malla de revoluci�n a trav�s
 * del m�todo revoluciona(float, int, bool).
*/
class Revolucion : public Malla {
public:
	Revolucion() {};
	Revolucion(PuntoVector3D** perfil, int nPuntos);
	virtual ~Revolucion();

	/* Revoluciona el perfil dado en la constructora en el eje y.
	 *  Revoluciona grados (en grados, no radianes), comenzando en el eje X.
	 *  El giro se realiza en sentido antihorario.
	 * El parametro divisiones especifica el n�mero de perfiles intermedios, y el 
	 * par�metro cerrado(bool) indica si hay que unir el primer punto de cada perfil
	 * con el ultimo de ese mismo perfil (i.e. La cara interna del perfil)
	 */
	void revoluciona(float grados, int divisiones, bool cerrado);

protected:
	PuntoVector3D** perfil;
	int nPuntosPerfil;
};


#endif //Revolucion_H_