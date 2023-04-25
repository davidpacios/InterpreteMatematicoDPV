# InterpreteMatematicoDPV: Intérprete matemático programado en C con Flex y Bison

Intérprete matemático programado en C con Flex y Bison, diseñado para la materia de 3º año de la carrera de  Ingeniería Informática de la Universidad de Santiago de Compostela. 

## Descripción
El interprete obtiene los lexemas(expresiones) a través del uso de la herramienta de software *FLEX*, posteriormente los analiza sintácticamente con *BISON* y finalmente los ejecuta. El programa permite la ejecución de expresiones matemáticas, la asignación de variables, la importación de funciones de librerías y la ejecución de comandos. Además de controlar la salida de los resultados de las expresiones matemáticas. Para la ejecución del programa se ha utilizado el sistema operativo Linux.

## Ejecución
Para la ejecución debes tener el compilador de C, gcc, flex y bison instalados en tu sistema operativo. Posteriormente, debes ejecuar el siguiente comando en la terminal:

```./FlexBisonScript.sh```

Con el que se compilarán los ficheros .l de flex y .y de bison, generando los archivos ```lexicalAnalysis.yy.h``` y ```syntacticParser.tab.h``` en la carpeta ```include```, y los archivos ```lexicalAnalysis.yy.c``` y ```syntacticParser.tab.c``` en la carpeta ```src```. Una vez generados los archivos, debes ejecutar el siguiente comando:

```make```

Esto compilará el programa y generará un ejecutable llamado ```InterpreteMatematicoDPV_cmd```. Para ejecutarlo, debes ejecutar el siguiente comando:

```./InterpreteMatematicoDPV_cmd```

El programa se ejecutará con su proprio prompt, donde podrás introducir diferentes comando y/o expresiones matemáticas. Para salir del programa, debes introducir el comando ```exit```.

## Opciones
Para valorar todos los comandos y funcionalidades permitidas por el programa, debes ejecutar el siguiente comando en el prompt:

```help```
        >>>DPV>>>help
        >>>DPV>>>Help:
        >>>DPV>>>This is a simple calculator that can do basic operations and comparisons.
        >>>DPV>>>You can assign values to variables and use them in the future.
        >>>DPV>>>You can use functions, at the start you can only use ^. To add more use import command.
        >>>DPV>>>You can use the following commands:
        >>>DPV>>>   echo: Turn on/off the echo.
        >>>DPV>>>   load <file.dpv>: Load a file.
        >>>DPV>>>   import <library.so> <function>: Import a function from a library.(Ex:import libm.so.6 cos).
        >>>DPV>>>   workspace: Print the current workspace.
        >>>DPV>>>   clean workspace: Clean the current workspace.
        >>>DPV>>>   clean <var>: Clean a variable.
        >>>DPV>>>   clear: Clear the screen.
        >>>DPV>>>   help: Print this help.
        >>>DPV>>>   exit: Exit the program.
        >>>DPV>>>

## Analisis con Valgrind
Para analizar el programa con Valgrind, debes ejecutar el siguiente comando:

```valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./InterpreteMatematicoDPV_cmd``` o ```valgrind -s ./InterpreteMatematicoDPV_cmd```

La salida de Valgrind con respecto a la memoria del HEAP es muy variable ya que depende de la cantidad de expresiones matemáticas que se introduzcan en el programa.
```

## Autor
* **David Pacios Vázquez** - [David Pacios Vázquez]
