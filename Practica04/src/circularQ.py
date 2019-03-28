from node import node
## Cola circular, utiliza node como base para hacer una lista simplemente ligada
class CircularQ:
    ##Constructor, crea dos variables que apuntan al frente y fin de la cola
    def __init__(self):
        ##Frente de la cola
        self.front = None
        ##Frente de la cola
        self.rear = None

    ## Crea un nodo y lo agrega a la cola
    #@param self apuntador a objeto
    #@param val valor a agregar en la cola
    def queue(self,val):
        t = node(val,self.front)
        if self.front ==  None:
            self.front = t
            self.front.sNext(self.front)
            self.rear = self.front
        elif(self.rear == self.front):
            self.front.next = t
            self.rear = t
        else:
            self.rear.sNext(t)
            self.rear = t

    ## Quita el nodo 'front' de la cola
    #@param self apuntador a objeto
    def dequeue(self):
        if self.front == self.rear:
            self.front=None
            self.rear=None
            return
        res = self.front
        self.front = self.front.next
        self.rear.sNext(self.front)
        return self.front

    ## Mueve los apuntadores de frente y fin de la cola para que el frente sea el nuevo fin y el segundo elemento sea el nuevo frent
    #@param self apuntador a objeto
    def rotate(self):
        if self.front != self.rear:
            self.rear= self.front
            self.front = self.front.next

    ## Representacion en cadena del objeto
    #@param self apuntador a objeto
    def __str__(self):
        if self.front == None:
            return '||'
        res = str(self.front.value) + '->'
        currNode = self.front.next
        while currNode != self.front:
            res+=str(currNode.value)+'->'
            currNode = currNode.next
        return (res +'/')
