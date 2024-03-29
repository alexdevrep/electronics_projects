# Uso de la librería 74hc595

## Índice

1. Descarga e instalación
2. Clases
3. Métodos
4. Ejemplos de Uso

---

### Descarga e instalación

- En este mismo directorio nos vamos al botón ```code``` y descargamos el archivo comprimido .zip
- Una vez descargado copiamos ese archivo en el directorio Arduino => libraries
- Descomprimimos el archivo
- Dentro encontramos dos programas de ejemplo uno para displays de ánodo común y otro para displays de cátodo común
- Para comprobar el funcionamiento del programa podemos abrir uno de los dos ejemplos según el tipo de display que tengamos y lo cargamos a nuestra tarjeta de Arduino.

Puedes Comprobar el esquema de conexionado para ambos displays en:

- <a href="https://eltallerdealexdevrep.000webhostapp.com/presentacion-de-la-libreria-74hc595-h/">Entrada de la librería</a>


---

### Clases 

En el archivo ```75hc595.h``` hemos declarado dos clases:

- HC595CC para displays de cátodo común (Common cathode)
- HC595CA para displays de ánodo común (Common anode)

Ambas clases tienen los mismos métodos pero manejan diferentes constantes:

    const byte CC_numero0
    const byte AC_numero0

Como podemos observar las constantes que empiezan por ```"CC"``` son las utilizadas para los displays de cátodo común y las constantes que empiezan por ```"AC"``` son utilizadas para los displays de ánodo común.

---

### Métodos

Los métodos de las clases de esta librería son los siguientes:
  
- ```.begin()```: Inicializa la clase, no requiere parámetros adicionales. 
- ```.escribirNumero(int numero)```: Este método es el que permite que se muestre en el display el número decimal cuyo valor es igual a la variable, espera un parámetro que es la variable número.
- ```.error(const byte CC_error/AC_error)```: Este método espera la combinación de bytes que forman la letra ```E``` que solo se da cuando la variable de control número es menor que 0 o mayor que 9.

---

### Ejemplos de Uso 

La librería trae 2 ejemplos de uso donde se ven todos los métodos disponibles 
un ejemplo para displays de ánodo común y otro para displays de cátodo común.

Puedes verlo y descargarlo directamente pinchando en el siguiente enlace:
- <a href="https://github.com/alexdevrep/electronics_projects/edit/main/Librer%C3%ADas/74hc595/ejemplos">Ejemplos de uso</a>
