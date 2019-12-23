#include "hash.h"

/*Estructura en la que almacenamos nuestras tablas hash, tanto la local como la global
y la flaglocal para saber en cuál de ellas estamos. */
struct _tablas_simbolos {
  hashtable_t *hash_global;
  hashtable_t *hash_local;
  int flaglocal;
};

typedef struct _tablas_simbolos tablas_simbolos;

int cerrarAmbito( tablas_simbolos *hashes);
int insertarTabla( tablas_simbolos *hashes, char *key, SIMBOLO *valor);
SIMBOLO *buscarTabla( tablas_simbolos *hashes, char *key);
