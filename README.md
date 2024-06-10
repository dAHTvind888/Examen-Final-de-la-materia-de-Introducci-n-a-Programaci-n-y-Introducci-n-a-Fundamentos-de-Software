# Examen-Final-de-la-materia-de-Introducción-a-Programación-y-Introducción-a-Fundamentos-de-Software
Nuestra empresa en la que estamos trabajando necesita una base de datos simple para poder almacenar fechas y eventos, por ello se nos solicito realizar una investigación de las bases de datos existentes para realizar una comparativa y elegir la más adecuada para poder implementarla.

Bases de Datos Existentes

Según su flexibilidad de modificación

Bases de datos dinámicas: Son aquellas donde los datos pueden actualizarse o incluso modificarse. La mayoría puede ser actualizada en tiempo real.

Bases de datos estáticas: Son bases de datos de consulta cuyos datos no pueden modificarse.

Según su forma de organización

	Bases de datos transaccionales: Están diseñadas para el envío y recepción de datos a grandes velocidades y de forma continua. Su único fin es la recepción y envío de información, pero la gestión de almacenamiento o redundancia está fuera de su propósito.

	Bases de datos jerárquicas: Las bases de datos jerárquicas son aquellas organizadas en forma de un árbol al revés. Almacenan la información en forma de registros dentro de una estructura jerárquica, es de aquí que proviene su nombre. 
Cada registro de este "árbol" es llamado nodo. Nodos son registros que contienen alguna información de interés y a partir del nodo raíz son enlazados los otros nodos descendientes: padres e hijos. Cada nodo padre puede tener varios nodos hijos, pero cada nodo hijo solo puede tener un solo nodo padre.

Este tipo de base de datos se recomienda para administrar grandes volúmenes de informaciones, pero actualmente no se utiliza mucho.

        Las principales características de la base de datos jerárquica son:
        
•	Diferentes usuarios pueden accederla y compartir información.

•	Los datos son independientes.

•	Es una estructura rígida por lo que es difícil modificar.

•	Requiere gran conocimiento de las unidades de información.

•	Los nodos distantes del nodo raíz son de difícil acceso por lo que se requiere tiempo.

	Bases de datos en red: Esta base de datos es una variación de la anterior. La diferencia está en que en la base de datos jerárquica un nodo hijo no puede tener varios padres y aquí sí.
Las características de estas bases de datos son semejantes a las de las bases de datos jerárquicas, aunque estas son mucho más potentes y complejas

	Bases de datos relacionales: Las bases de datos relacionales son las más usadas actualmente para administrar datos de forma dinámica. Permite crear todo tipo de datos y relacionarlos entre sí.
Los datos son almacenados en registros que son organizados en tablas, de esta forma pueden asociarse los elementos entre sí muy fácilmente, además se pueden cruzar sin ninguna dificultad.

        Sus principales características son:
        
•	Pueden ser utilizadas por cualquier persona.

•	Son de fácil gestión.

•	Se pueden acceder a los datos con rapidez.

•	Garantiza la total consistencia de los datos, sin posibilidad de error.

•	No son muy eficaces con datos gráficos, CAD, sistema de información geográfica ni datos en multimedia.

	Bases de datos orientadas a objetos (No SQL): Han surgido como concepto tras la aparición de los sistemas de programación orientada a objetos.
La información está representada mediante objetos, como los presentes en la programación orientada a objetos. Al integrarse las características de una base de datos con las de un lenguaje de programación orientado a objetos (POO), se obtiene como resultado un sistema gestor de base de datos orientada a objetos (ODBMS), que hace que los objetos de la base de datos aparezcan como objetos de un lenguaje de programación (pudiendo dar soporte a uno o más de este tipo de lenguajes, como, por ejemplo, Visual Basic, C++ o Java).

	Bases de datos deductivas: Conocidas también como bases de datos lógicas. Se utilizan generalmente en buscadores, pero pueden usarse de otras formas.
Permiten almacenar los datos y consultarlos a través de búsquedas que utilizan reglas y normas previamente almacenadas.

        Sus principales características son:
        
•	Permite expresar consultas por medio de reglas lógicas.

•	Soporta conjuntos de datos complejos.

•	Se puede inferir información a través de los datos almacenados.

•	Usan fórmulas matemáticas o algoritmos lógicos.

	Bases de datos documentales: Están especializadas en el almacenamiento de textos completos, lo que facilita el tratamiento informatizado de grandes cadenas de caracteres.

	Bases de datos multidimensionales: Estas bases de datos utilizan conceptualmente la idea de un cubo de datos. Donde las informaciones se almacenan en la intersección de tres o más atributos. Esta concepción puede ser algo compleja pero su uso es bastante simple.

       Algunas de sus principales características son:
       
•	No emplean ninguna jerarquía.

•	Facilita tanto la búsqueda como la modificación posterior.

•	Utiliza un espacio menor de almacenamiento.

•	Tiene acceso a grandes cantidades de información.

	Bases de datos NoSQL: son sistemas de almacenamiento de información que no cumplen con el esquema entidad–relación. Tampoco utilizan una estructura de datos en forma de tabla donde se van almacenando los datos sino que para el almacenamiento hacen uso de otros formatos como clave–valor, mapeo de columnas o grafos.

        Sus principales características son:
        
•	Se ejecutan en máquinas con pocos recursos: Estos sistemas, a diferencia de los sistemas basados en SQL, no requieren de apenas computación, por lo que se pueden montar en máquinas de un coste más reducido.

•	Escalabilidad horizontal: Para mejorar el rendimiento de estos sistemas simplemente se consigue añadiendo más nodos, con la única operación de indicar al sistema cuáles son los nodos que están disponibles.

•	Pueden manejar gran cantidad de datos: Esto es debido a que utiliza una estructura distribuida, en muchos casos mediante tablas Hash.

•	No genera cuellos de botella: El principal problema de los sistemas SQL es que necesitan transcribir cada sentencia para poder ser ejecutada, y cada sentencia compleja requiere además de un nivel de ejecución aún más complejo, lo que constituye un punto de entrada en común, que ante muchas peticiones puede ralentizar el sistema.

Estos tipos de datos de base se subdividen en tres:

	Bases de datos clave – valor: Son el modelo de base de datos NoSQL más popular, además de ser la más sencilla en cuanto a funcionalidad. En este tipo de sistema, cada elemento está identificado por una llave única, lo que permite la recuperación de la información de forma muy rápida, información que habitualmente está almacenada como un objeto binario (BLOB). Se caracterizan por ser muy eficientes tanto para las lecturas como para las escrituras.
Algunos ejemplos de este tipo son Cassandra, BigTable o HBase.

	Bases de datos documentales: Este tipo almacena la información como un documento, generalmente utilizando para ello una estructura simple como JSON o XML y donde se utiliza una clave única para cada registro. Este tipo de implementación permite, además de realizar búsquedas por clave–valor, realizar consultas más avanzadas sobre el contenido del documento.
Son las bases de datos NoSQL más versátiles. Se pueden utilizar en gran cantidad de proyectos, incluyendo muchos que tradicionalmente funcionarían sobre bases de datos relacionales.
Algunos ejemplos de este tipo son MongoDB o CouchDB.

	Bases de datos en grafo: En este tipo de bases de datos, la información se representa como nodos de un grafo y sus relaciones con las aristas del mismo, de manera que se puede hacer uso de la teoría de grafos para recorrerla. Para sacar el máximo rendimiento a este tipo de bases de datos, su estructura debe estar totalmente normalizada, de forma que cada tabla tenga una sola columna y cada relación dos.
Este tipo de bases de datos ofrece una navegación más eficiente entre relaciones que en un modelo relacional.
Algunos ejemplos de este tipo son Neo4j, InfoGrid o Virtuoso.

Al analizar todos estos distintos tipos de bases de datos, se llego a una conclusión de que la mejor opción para implementar al problema de la empresa sería usar una base de datos dinámica tipo no SQL de referencia clave-valor debido a que el lenguaje de programación en el que será creado será c++ y es la más optima para los procesos que se requiere, además de las ventajas que presentan.

Funciones

-	Agregar Evento: Al agregar un evento, la BD recordará y mostrará durante la búsqueda, Si el evento especificado para una fecha determinada ya existe, se ignorará la repetición de su adición. En caso de una entrada correcta, el programa no mostrará nada en la pantalla.

El formato de agregar será Add Fecha Evento (Tomar en cuenta el formato de fecha Año – Mes – Día, los meses y días no deben ser números negativos, los meses deben ser de 1-12 y los días del 1-31)

Ejemplos

Entrada:

Add 2024-01-01 event1 (correcto)

Add 2024--02--01 event2 (incorrecto)

Add 2024-01-01 event1 (ignorado)

Add -2025-01-01 event2 (correcto)

Add 2024-13-01 event1 (incorrecto)

Add 2024-01-00 event1 (incorrecto)

-	Eliminar evento: El comando debe eliminar un evento agregado anteriormente con el nombre especificado en la fecha indicada, si existe. Si el evento se encuentra y se elimina, el programa mostrará la línea Deleted successfully. Si no se encuentra el evento en la fecha especificada, el programa mostrará la línea Event not found.
	
El formato de eliminar un evento será Del Fecha Evento (Tomar en cuenta el formato de fecha Año – Mes – Día, los meses y días no deben ser números negativos, los meses deben ser de 1-12 y los días del 1-31)

Ejemplos

Entrada:
Add 2024-01-01 event1 

Del 2024-01-01 event2

Del 2024-01-01 event1

Salida

Event not found

Deleted successfully

-	Eliminar varios eventos: El comando elimina todos los eventos previamente agregados para la fecha indicada. El programa siempre mostrará una línea en el formato "Deleted cantidad_de_eventos events", la cantidad_de_eventos será 0 si no hay ningún elemento en la fecha indicada.
	
El formato de eliminar varios eventos será Del Fecha (Tomar en cuenta el formato de fecha Año – Mes – Día, los meses y días no deben ser números negativos, los meses deben ser de 1-12 y los días del 1-31)

Ejemplos

Entrada:

Add 2024-01-01 event1 

Add 2024-01-01 event2

Del 2025-01-01 

Del 2024-01-01 


Salida

Deleted 0 events

Deleted 2 events

-	Buscar Eventos: Encuentra e imprime los eventos en orden uno por línea previamente agregados en la fecha indicada. 

El formato de buscar eventos será Find Fecha (Tomar en cuenta el formato de fecha Año – Mes – Día, los meses y días no deben ser números negativos, los meses deben ser de 1-12 y los días del 1-31)

Ejemplos

Entrada:

Add 2024-01-01 event2 

Add 2024-01-01 event1

Find 2024-01-01

Salida:

event1

event2

-	Mostar Eventos: mostrará todo el contenido de nuestra base de datos en orden ascendente, no se mostrarán las fechas con años negativos.

El formato de mostrar eventos será Print

Ejemplos

Entrada

Add 2024-01-01 event2 

Add 2024-01-01 event1

Print

Salida

2024-01-01 event1 

2024-01-01 event2

-	Errores:
El programa se detendrá si se ingresa un comando incorrecto, o una fecha que no esté en el formato año, mes, día o que los datos de meses o días no correspondan al rango. 



Estructura del código

Es un bucle que contiene:
-----------------------------------------------------------------------------------------------------------------------------------------

Ingresar Comando – Fecha – Nombre Del evento.

Verifica que todo lo ingresado este correcto, sino se detiene.

Dependiendo del comando
[

Add = Añade;

Del (solamente fecha) = Elimina todos los eventos de una fecha;

Del (Completo) = Elimina el evento;

Find = Busca los eventos; 

Print = Muestra los eventos;
]
-----------------------------------------------------------------------------------------------------------------------------------------

Pseudocódigo



Referencias

Calendario de Samsung: es una herramienta útil para administrar y organizar tus horarios de manera eficiente.
En el cual se elige (en nuestro caso se introduce la fecha) y se escribe el recordatorio (en nuestro caso eventos).

Cassandra: Es un software NoSQL distribuido y basado en un modelo de almacenamiento «tabular», de código abierto que está escrito en Java. Permite grandes volúmenes de datos en forma distribuida. Por ejemplo, lo usa Twitter para su plataforma.

https://www.ionos.es/digitalguide/hosting/cuestiones-tecnicas/apache-cassandra/


Herramientas

Visual Studio Code: Fundamental para la codificación del código del lenguaje de c++ y para compilar y verificar que todo este funcionado correctamente.

Google: Herramienta eficaz para investigar errores o revisar la documentación de las distintas librerías de c++, la base de la operación de la codificación de la base de datos.

Chat GPT: herramienta de investigación auxiliar, también en caso de la documentación este desactualizada

