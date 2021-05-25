# TP2TallerDeProgramacion
# TP2-Web Crawler
# Alumno: Manuel Longo Elia
# Padrón: 102425

En este trabajo se implementa un programa que emula un *Web Crawler*. Para agilizar este proceso, se busca trabajar de manera concurrente, haciendo que distintos hilos vayan realizando el algoritmo de web crawling, para esto se busco hacer un programa *thread safe*.

# DISEÑO

Antes de implementar la solución, se empezó por diseñarla, planteando las diferentes estructuras del programa y cómo iban a relacionarse entre sí. 

El diseño se pensó usando como base la programación orientada a objetos.

Se plantearon los siguientes:

- BLOCKING QUEUE: Es la cola bloqueante, esta contendra como elementos instancias de `Page`. Esta clase realiza los metodos clasicos de cualquier cola `pop` y `push`, y al ser bloqueante tiene el metodo `close()` que notifica al programa que la cola esta cerrada y no se podra ingresar ni sacar ningun elemento.

- FILE READER: Esta clase fue creada para delegar la lectura de los archivos y el llenado inicial de la cola y la lista. Esta clase tiene dos metodos que llenaran las colecciones mencionadas anteriormente con los archivos que fueron pasado por parametro en el constructor del mismo.

- MAP MONITOR: Esta clase se creo para que el mapa que contiene a las url indexadas sea *thread safe*. Tiene como parametro un *Protected map* (sera explicado luego) y todos sus metodos son para que las *critical sections* esten encapsuladas y asegurar un buen comportamiento del programa.

- PROTECTED MAP: Esta clase contiene al mapa. Tiene los metodos necesarios para que los workers puedan hacer su trabajo concurrente de manera segura, para que luego el monitor los encapsule.

- PAGE FETCHER: Esta clase fue creada para delegar el comportamiento del *fetch* de las paginas web. Es decir buscar en el archivo pages nuevas paginas para seguir con el *crawling*.

- PAGE: Esta clase representa a las paginas web.

- THREAD WORKER: Esta clase representa a un hilo *worker*, el cual es el encargado de realizar todo el *web crawlling*. Esta clase es una clase hijo de la clase *Thread* y tiene el metodo `run` que es el que ejecuta el algoritmo mencionado anteriormente.

- THREAD: Esta clase contiende al hilo de la libreria estandar, que sera usado por *Thread Worker*, contiene tambien la sobrecarga de operadores para que se pueda realizar el trabajo de manera correcta.

- WEB CRAWLER: Esta clase es el "corazon" del programa. Se encarga de realizar todo el algoritmo de crawling, delegando sus tareas a los hilos *workers*. Contiene como atributos a las colecciones mencionadas anteriormente que poseen los datos para realizar el algoritmo.

# IMPLEMENTACIÓN

Para la implementacion se busco siempre cumplir con el paradigma de programacion orientada a objetos. En todo momento se intento no romper con el encapsulamiento y delegar comportamientos. Asimismo tambien cumplir con los principios SOLID.

# CAMBIOS EN LA REENTREGA

Para esta entrega se han realizado los siguientes cambios:

- Se cambio el metodo de pasaje de parametros a pasaje por referencia cuando este era requerido. Para generar una mayor performance del programa
- Para mejorar la performance del programa, tambien, se hizo uso de la *member initialization list* en las clases `Web Crawler`, `Page`, `Page Fetcher`, `Blocking Queue` y `File Reader`
- Tambien en `Web Crawler` se hizo uso de la funcion `stoi` ya que `atoi` en algunos casos puede llegar a ser peligrosa.
- Para respetar la convencion, se han cambiado la respondabilidades de los metodos `run` y `start` de los hilos.
- Para reservar espacio y evitar reallocaciones internas, se hizo uso de la funcion `reserve` para el vector de hilos.
- Se mejoro el encapsulamiento de la clase `Web Crawler`. Se crearon las clases `Thread Worker`, `Page` y `Page Fetcher` para que el `Web Crawler` no este sobrecargado de responsabilidades y darle una tonada mas orientada a objetos del proyecto.
- Tambien, se soluciono el motivo principal de la desaprobacion del trabajo, que los *threads workers* leia el archivo target y lo encolaba. Ahora esto es responsabilidad del `Web Crawler` y se realiza todo en el hilo main.
- Se han añadido nuevas critical sections debido a que el programa se ha modificado, tambien se han removido mutex de lugares que no eran secciones de riesgo.
- Para reservar espacio en el buffer que guardara lo leido por el archivo pages, se hizo uso de una estructura de datos mejor al calloc. Esta es un `std::vector<char>` el cual es *RAII* y tiene la particularidad que se puede acceder a el mediante el metodo `data`.
- Se hizo generica la clase `Protected Map` para que pueda ser utilizada tanto en el mapa final como en el mapa index. La unica diferencia que estos poseen es que en el mapa index no se da importancia al *state* de las paginas y en el mapa final no se le da importancia al *offset* y al *size*.
- Se dejo de llamar a los metodos `open` y `close` de `ifstream` ya que esta clase es una clase *RAII*. Estos archivos se abren en el constructor y se cierran en el destructor. Lo que si se hizo para chequear que los archivos fueron abiertos correctamente es crear excepciones que chequeen dichos problemas para poder tratarlas adecuadamente.
- Se elimino la clase `List Monitor` ya que esta clase no era necesaria porque no habia que encapsular las *critical sections* en monitores debido a que la lista solo iba a ser manipulada por el hilo *main*.


# Diagrama de clases representativo de la solución final:
*ACLARACION:* Este diagrama no muestra todas los metodos implementados en la solucion. Solo muestra los mas importantes para que viendo el diagrama se pueda dar un entendimiento del programa. Lo mismo sucede con los constructores y destructores de las clases
![Captura de pantalla de 2021-05-16 00-38-11](https://user-images.githubusercontent.com/45469722/118384743-0b7ce100-b5df-11eb-8ea2-61a9913cce81.png)
