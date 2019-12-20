/* Read this comment first: https://gist.github.com/tonious/1377667#gistcomment-2277101
 * 2017-12-05
 *
 *  -- T.
 */
 #include "hash.h"

struct entry_s {
	char *key;
	SIMBOLO value;
	struct entry_s *next;
};


struct hashtable_s {
	int size;
	struct entry_s **table;
};

SIMBOLO *new_simbolo(char *identificador, int cat_simbolo, int tipo, int categoria, int valor, int longitud, int num_parametros, int posicion, int num_var_locales) {
  SIMBOLO *new;
  new = calloc(1, sizeof(SIMBOLO));
  strcpy(new->identificador, identificador);
  new->cat_simbolo = cat_simbolo;
  new->tipo = tipo;
  new->categoria = categoria;
  new->valor = valor;
  new->longitud = longitud;
  new->num_parametros = num_parametros;
  new->posicion = posicion;
  new->num_var_locales = num_var_locales;
  return new;
}

/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {

	hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	/* Allocate the table itself. */
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;
}

/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {

	unsigned long int hashval;
	int i = 0;

	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

/* Create a key-value pair. */
entry_t *ht_newpair( char *key, SIMBOLO *value ) {
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	strcpy( newpair->value.identificador, value->identificador);
  newpair->value.cat_simbolo = value->cat_simbolo;
  newpair->value.tipo = value->tipo;
  newpair->value.categoria = value->categoria;
  newpair->value.valor = value->valor;
  newpair->value.longitud = value->longitud;
  newpair->value.num_parametros = value->num_parametros;
  newpair->value.posicion = value->posicion;
  newpair->value.num_var_locales = value->num_var_locales;

	newpair->next = NULL;

	return newpair;
}

/* Insert a key-value pair into a hash table. */
int ht_set( hashtable_t *hashtable, char *key, SIMBOLO *value ) {

	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Error. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
    printf("Encontrado duplicado en el set.\n");
    fflush(stdout);
		return -1;

	/* Nope, could't find it.  Time to grow a pair. */
	} else {

		newpair = ht_newpair( key, value );


		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;

		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;

		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	printf("Insertado por primera vez el set.\n");
	return 0;
	}
}

/* Retrieve a key-value pair from a hash table. */
SIMBOLO *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
      printf("No encontrado en get\n");
		return NULL;

	} else {
		return &pair->value;
	}

}

//
// int main( int argc, char **argv ) {
//
// 	hashtable_t *hashtable = ht_create( 65536 );
//
// 	ht_set( hashtable, "key1", "inky" );
// 	ht_set( hashtable, "key2", "pinky" );
// 	ht_set( hashtable, "key3", "blinky" );
// 	ht_set( hashtable, "key4", "floyd" );
//
// 	printf( "%s\n", ht_get( hashtable, "key1" ) );
// 	printf( "%s\n", ht_get( hashtable, "key2" ) );
// 	printf( "%s\n", ht_get( hashtable, "key3" ) );
// 	printf( "%s\n", ht_get( hashtable, "key4" ) );
//
// 	return 0;
// }
