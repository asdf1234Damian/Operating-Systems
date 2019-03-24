from node import node
class CircularQ:
    def __init__(self):
        self.front = None
        self.rear = None

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

    def dequeue(self):
        if self.front == self.rear:
            self.front=None
            self.rear=None
            return
        res = self.front
        self.front = self.front.next
        self.rear.sNext(self.front)
        return self.front


    def rotate(self):
        if self.front != self.rear:
            self.rear= self.front
            self.front = self.front.next

    def __str__(self):
        if self.front == None:
            return '||'
        res = str(self.front.value) + '->'
        currNode = self.front.next
        while currNode != self.front:
            res+=str(currNode.value)+'->'
            currNode = currNode.next
        return (res +'/')
