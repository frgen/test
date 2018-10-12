#define FULL 1
#define EMPTY 0
#define FIRED -1

typedef struct
{
    int idOwner;
    char name[30];
    char lastName[30];
    char address[30];
    char cardNumber[30];
    int state;
}eOwner;

/** \brief Inicializa el array de propietarios
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \return 0 si esta OK
 *
 */
int initOwners(eOwner*, int);

int initOwnersHardCode(eOwner*, int);

/** \brief Agrega un nuevo propietario
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \return 0 si esta OK
 *
 */
int addOwner(eOwner*, int);

/** \brief Busca un propietario por ID
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \param  ID del propietario
 * \return ID encontrado
 *
 */
int findOwnerById(eOwner*, int, int);

/** \brief Elimina un propietario por ID
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \return 0 si esta OK
 *
 */
int removeOwner(eOwner*, int);

/** \brief Muestra el listado de propietarios
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \return 0 si esta OK
 *
 */
int printOwners(eOwner*, int);

/** \brief Modifica un propietario por ID
 *
 * \param eOwner Array de propietarios
 * \param int Longitud del array
 * \return 0 si esta OK
 *
 */
int editOwner(eOwner*, int);

int sortOwners(eOwner*, int, int);
