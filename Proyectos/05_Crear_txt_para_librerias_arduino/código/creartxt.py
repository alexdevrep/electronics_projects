'''
    Script en python que crea un archivo .txt donde se vuelca el contenido 
    necesario para incluir las keywords de una librería de tal manera de que
    sean reconocibles para el IDE de Arduino.

    Más contenido interesante en:
        -GitHub: https://www.github.com/alexdevrep
        -Instagram: https://www.instagram.com/alexdevrep/
        -WordPress: https://eltallerdealexdevrep.com
    	-Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA

'''

#Creamos las listas que forman el documento

#Lista de contenido 1
lista_cabecera= [
        "########################################### \n",
        "# Syntax Coloring Map For Example \n",
        "########################################### \n",
        " \n",
        "########################################### \n",
        "# Datatypes (KEYWORD1) \n",
        "########################################### \n",
        " \n",
        "Example	KEYWORD1 \n",
        " \n",
        "########################################### \n",
        "# Methods and Functions (KEYWORD2) \n",
        "########################################### \n",
        " \n"
        ]

#Lista de métodos y funciones a añadir
lista_metodos= []

#Lista de contenido 2
lista_const= [ 
        "########################################### \n",
        "# Constants (LITERAL1) \n",
        "########################################### \n"
        ]
#Lista de constantes a añadir 
const_values=[]


#Bucle de control para añadir los métodos y las constantes necesarias
#Función para añadir palabras clave 
def keywords(accion):
    global lista_metodos, const_values
    if accion == 'metodo':
        metodo= input("Añada un método a la lista: ")
        lista_metodos.append(metodo)
    
    elif accion == 'constantes':
        constantes= input ("Añada una constante a la lista: ")
        const_values.append(constantes)
    
    elif accion == 'modificar':
        nombre_libreria = input ("Escriba el nombre de la librería: ")
        lista_cabecera[1]=f'# Syntax Coloring Map For {nombre_libreria} \n'
        lista_cabecera[8]=f'{nombre_libreria}	KEYWORD1 \n'
          
while True:
    print("Funciones disponibles: metodo , salir , constantes, modificar")
    accion= input("Escriba una de las opciones disponibles: ")
    keywords(accion)

    if accion == 'salir':
        break


#Creamos el archivo txt
archivo = open("keywords.txt","x")#Añade la ruta de tu archivo
archivo.close()

#Cambiamos el archivo a modo escritura
archivo=open("keywords.txt","w")

#Iteramos cada lista creada y volcamos los elementos en el archivo
for elemento in lista_cabecera:
    archivo.writelines(elemento)

for metodo in lista_metodos:
    archivo.writelines(f'{metodo} 	    KEYWORD2 \n')

for texto in lista_const:
    archivo.writelines(texto)

for constante in const_values:
    archivo.writelines(f'{constante} 	    LITERAL1 \n')

#Cerramos el archivo
archivo.close()






