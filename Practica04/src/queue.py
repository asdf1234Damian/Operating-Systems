class Queue:
    def __init__(self):
        self.head = None
        self.next = None

    def queue(self,val):
        if self.head == None:
            self.head = val
            self.next = Queue()
        else:
            self.next.queue(val)

    def dequeue(self):
        res = self.head
        if self.head != None:
            # print(self.head,self.next)
            self.head = self.next.head
            self.next = self.next.next
        return res
    def __str__(self):
        res = ''
        if self.head != None:
            res+=str(self.head) + '->'
            return (res + str(self.next))
        else:
            return ('||')
