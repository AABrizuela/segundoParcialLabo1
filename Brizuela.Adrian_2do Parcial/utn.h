#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/**\brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt();

/**\brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat();

/**\brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar();

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char *str);

/**
 * \brief Verifica si el valor recibido es numérico y tiene guiones
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esCuit(char str[]);

/**
 * \brief Verifica si el valor recibido tiene formato fecha
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esFecha(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras, números y guion bajo
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esTipoFoto(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *str);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida con un rango
 * \param requestMessage char[] Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage char[] Es el mensaje a ser mostrado en caso de error
 * \param lowLimit int Limite inferior para la comparacion
 * \param hiLimit int Limite maximo para la comparacion
 * \return El número ingresado por el usuario
 *
 */
int getValidIntRango(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);

/** \brief Cambia las primeras letras a mayusculas
 *
 * \param input[] Cadena a modificar
 * \return void
 *
 */
void corregirMayusculas(char input[]);

/** \brief Obtiene y valida una cadena de caracteres
 *
 * \param requestMessage[] Mensaje a mostrar
 * \param errorMessage[] Mensaje de error
 * \param input[] variable de retorno por referencia
 * \param tamanio cantidd de caracteres permitidos
 * \return void
 *
 */
void getValidStringRango(char requestMessage[],char errorMessage[], char input[], int tamanio);

/** \brief Obtiene un string
 *
 * \param mensaje[] Mensaje a mostrar
 * \param input[] variable de retorno por referencia
 * \param tamanio cantidd de caracteres permitidos
 * \return int (1) si es solo letras - (0) si no lo es
 *
 */
int getStringLetrasRango(char mensaje[],char input[], int tamanio);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[]);

/** \brief retorna un caracter validado con 2 comparaciones
 *
 * \param requestMessage[] char mensaje solicitando ingreso de datos
 * \param errorMessage[] char mensaje de error
 * \param comparacionA char primera comparacion
 * \param comparacionB char primera comparacion
 * \return char caracter valido
 *
 */
char getValidChar(char requestMessage[], char errorMessage[], char comparacionA, char comparacionB);

/** \brief Solicita un numero, lo valida y lo retorna
 *
 * \param requestMessage[] Mensaje solicitando numero
 * \param errorMessage[] Mnsaje error
 * \return float El numero validado
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida con un comparando con 2 numeros
 * \param requestMessage char[] Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage char[] Es el mensaje a ser mostrado en caso de error
 * \param comparacionA int Primera comparacion
 * \param comparacionA int Segunda comparacion
 * \return El número ingresado por el usuario
 *
 */
int getValidIntOpcion(char requestMessage[],char errorMessage[], int comparacionA, int comparacionB);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/** \brief Funcion similar a tolower
 *
 * \param s char*
 * \return char*
 *
 */
char* strlwr(char* s);

/** \brief Funcion similar a system("pause")
 *
 * \return void
 *
 */
void pause();
#endif // UTN_H_INCLUDED
