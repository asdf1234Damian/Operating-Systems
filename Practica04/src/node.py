## Estructura base para la cola circular
class node:
    ##Constructor
    #@param self apuntador al objeto
    #@param val valor del nodo
    #@param next apuntador al siguiente elemento
    def __init__(self, val,next):
        ##valor del nodo
        self.value = val
        ## apuntador al siguiente elemento
        self.next = next
    ##Modifica el apuntador al siguiente objeto
    def sNext(self, next):
        self.next = next
    ##Regresa el elemento siguiente del objeto
    def gNext(self,next):
        return self.next
