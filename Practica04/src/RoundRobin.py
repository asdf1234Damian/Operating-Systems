from proc import Process as pr
from circularQ import CircularQ as cq
from queue import Queue as q
from os import system
import time
## brief Programa driverpara la simulacion de round robin
## Cola de procesos que no han entrado al round robin
prcssQ = q()
## Cola circular de round robin
round = cq()
with open('src/input.txt','r') as file:
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
        while prcssQ.head != None and prcssQ.head.start == cycl:
            p=prcssQ.dequeue()
            round.queue(p)
        print(''.center(63,'-'))
        print('|'+'Procesos pendientes'.center(40)+'|'+('Ciclo: '+str(cycl)).center(20) + '|')
        print(''.center(63,'-'))
        print('|'+str(prcssQ).center(61)+'|')
        print(''.center(63,'-'))
        print('|'+'Round Robin'.center(61)+'|')
        print(''.center(63,'-'))
        print(round)
        time.sleep(1)
        cycl+=1
        currP+=1
        if currP>chunkSize:
            round.rotate()
            currP=0
    print('End of program')
