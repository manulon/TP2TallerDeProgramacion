# TP2TallerDeProgramacion
# TP2-Web Crawler
# Alumno: Manuel Longo Elia
# Padrón: 102425

En este trabajo se implementa un programa que emula un *Web Crawler*. Para agilizar este proceso, se busca trabajar de manera concurrente, haciendo que distintos hilos vayan realizando el algoritmo de web crawling, para esto se busco hacer un programa *thread safe*.

# DISEÑO

Antes de implementar la solución, se empezó por diseñarla, planteando las diferentes estructuras del programa y cómo iban a relacionarse entre sí. 

El diseño se pensó usando como base la programación orientada a objetos.

Se plantearon los siguientes:

- BLOCKING QUEUE: Es la cola bloqueante, esta contendra como elementos un *pair* de elementos de tipo *string*, donde el primer elemento represente a la url a procesar y el segundo su estado. Esta clase realiza los metodos clasicos de cualquier cola `pop` y `push`, y al ser bloqueante tiene el metodo `close()` que notifica al programa que la cola esta cerrada y no se podra ingresar ni sacar ningun elemento.

- FILE READER: Esta clase fue creada para delegar la lectura de los archivos y el llenado inicial de la cola y la lista (luego sera explicada). Esta clase tiene dos metodos que llenaran las colecciones mencionadas anteriormente con los archivos que fueron pasado por parametro al inciar el programa.

- LIST MONITOR: Esta clase fue creada para que la lista que posee las url *allowed* sea *thread safe*, se han creado metodos para asegurar este comportamiento en la ya mencionada lista.

- MAP MONITOR: Al igual que la clase de arriba, se creo para que el mapa que contiene a las url indexadas sea *thread safe*. Tiene como parametro un *Protected index map* (sera explicado luego) y todos sus metodos son para que las *critical sections* esten encapsuladas y asegurar un buen comportamiento del programa.

- PROTECTED INDEX MAP: Esta clase contiene al mapa del index. Tiene los metodos necesarios para que el web crawler pueda hacer su trabajo concurrente de manera segura, para que luego el monitor los encapsule.

- WEB CRAWLER: Esta clase es el "corazon" del programa. Se encarga de realizar todo el algoritmo de crawling, delegando sus tareas a pequeños metodos privados para obtener una mayor legibilidad y mayor comprension del programa. Contiene como atributos a las colecciones mencionadas anteriormente que poseen los datos para realizar el algoritmo.

# IMPLEMENTACIÓN

Para la implementacion se busco siempre cumplir con el paradigma de programacion orientada a objetos. En todo momento se intento no romper con el encapsulamiento y delegar comportamientos. Asimismo tambien cumplir con los principios SOLID.

# Diagrama de clases representativo de la solución final:
*ACLARACION:* Este diagrama no muestra todas los metodos implementados en la solucion. Solo muestra los mas importantes para que viendo el diagrama se pueda dar un entendimiento del programa. Lo mismo sucede con los constructores y destructores de las clases
![Captura de pantalla de 2021-05-16 00-38-11](https://user-images.githubusercontent.com/45469722/118384743-0b7ce100-b5df-11eb-8ea2-61a9913cce81.png)
