class Process:
    id = 0
    def __init__(self,start,dur):
        self.id = Process.id
        Process.id += 1
        self.start = start
        self.dur = dur

    def __str__(self):
        return '[P'+str(self.id).ljust(2)+'|'+str(self.dur).ljust(2)+']'
