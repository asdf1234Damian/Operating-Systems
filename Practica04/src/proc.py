
##Esta clase se encarga de almacenar los datos de cada proceso; id, inicio y duracion, asi como de dar formato a travez del metodo ___str__ para que se pueda usar en print()

class Process:
    ## Variable estatica de la clase para asignar un id unico a cada proceso
    id = 0
    ## Constructor de la clase, se encarga de generar el proceso con id unico tomado de la variable de clase Process.id
    #@param self el apuntador al objeto
    #@param start el ciclo en el que el proceso comenzará
    #@param dur la duracion del proceso antes de terminar.
    def __init__(self,start,dur):
        ## id del proceos
        self.id = Process.id
        Process.id += 1
        ## ciclo en el que llega el proceso al round robin
        self.start = start
        ## duracion del proceso en ciclos
        self.dur = dur
    ## Representacion en cadena de un objeto.
    #@param self el apuntador al objeto
    def __str__(self):
        return '[P'+str(self.id).ljust(2)+'|'+str(self.dur).ljust(2)+']'
