## Implementacion de una cola simplemente ligada.
class Queue:
    ##Constructor
    #@param self apuntador al objeto
    def __init__(self):
        ## Contenido del nodo de la lista
        self.head = None
        ## Apuntador al siguiente nodo de la lista
        self.next = None

    ##Metodo para agregar elementos a la lista
    #@param self apuntador al objeto
    #@param val valor del elemento a insertar en la list
    def queue(self,val):
        if self.head == None:
            self.head = val
            self.next = Queue()
        else:
            self.next.queue(val)

    ##Metodo para meter el primer elemento de la lista
    #@param self apuntador al objeto
    def dequeue(self):
        res = self.head
        if self.head != None:
            self.head = self.next.head
            self.next = self.next.next
        return res

    ##Presentacion en cadena de un objeto
    #@param self xapuntador al objeto
    def __str__(self):
        res = ''
        if self.head != None:
            res+=str(self.head) + '->'
            return (res + str(self.next))
        else:
            return ('||')
