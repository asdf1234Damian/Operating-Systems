from proc import Process as pr
from circularQ import CircularQ as cq
from queue import Queue as q
from os import system
import time
prcssQ = q()
round = cq()
# print(round)
with open('input.txt','r') as file:
    file = file.readlines()
    chunkSize = int(file[0])
    for line in file[1:]:
        start, dur = [int(x) for x in line.split()]
        Pn = pr(start, dur)
        prcssQ.queue(Pn)
    cycl = 0
    currP = 0
    while prcssQ.head != None or round.front != None:
        if round.front != None:
            if round.front.value.dur>0:
                round.front.value.dur-=1
            else:
                currP = 0
                round.dequeue()
        system('clear')
        print(''.center(63,'-'))
        print('|'+'Procesos pendientes'.center(40)+'|'+('Ciclo: '+str(cycl)).center(20) + '|')
        print(''.center(63,'-'))
        print('|'+str(prcssQ).center(61)+'|')
        print(''.center(63,'-'))
        print('|'+'Round Robin'.center(61)+'|')
        print(''.center(63,'-'))
        print(round)
        while prcssQ.head != None and prcssQ.head.start == cycl:
            p=prcssQ.dequeue()
            round.queue(p)
        time.sleep(2)
        cycl+=1
        currP+=1
        if currP>chunkSize:
            round.rotate()
            currP=0
    print('End of program')
