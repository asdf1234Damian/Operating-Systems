class node:
    def __init__(self, val,next):
        self.value = val
        self.next = next

    def sNext(self, next):
        self.next = next

    def gNext(self,next):
        return self.next
