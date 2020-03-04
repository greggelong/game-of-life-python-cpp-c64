import os
from time import sleep

oldworld = [[0,0,0,0,0,0,0,0,0,0],   ## global
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,1,1,1,0,0,0,0],
            [0,0,0,0,0,1,0,0,0,0],
            [0,0,0,0,1,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0]]

cols = 10
rows = 10
            
clear = lambda: os.system('clear')       #lambda function to clear    

def showWorld():
    global oldworld
    for y in oldworld:        
        line =""
        for x in y:
            if x == 0:
                line+="."
            else:
                line+="*"
        print(line)
       # print(''.join(str(e) for e in y))  # convert int to string first then join
  

def countNeighbors(y, x):
    global oldworld, cols, rows
    sum = 0;
    for j in range(-1,2):
        for i in range(-1,2):
            row = (y + j + rows) % rows
            col = (x + i + cols) % cols  #using modulo to count over 
             
            sum += oldworld[row][col]

    sum -= oldworld[y][x]
    return sum


def nextGen():
    global oldworld
    #newworld = [[]]
    newworld = [[0 for i in range(cols)] for j in range(rows)]
    #print(type(newworld))
    for y in range(rows):
        for x in range(cols):
            #print(newworld)
            nei = countNeighbors(y,x) # make sure you get your x's and y's straight
            if nei == 3:
                newworld[y][x] = 1   # live or dead if three neighbors next gen will be live or 1
                
            elif nei == 2:    #live or dead if two neighbors the next gen will be the same as this one
                newworld[y][x] = oldworld[y][x]
                
            
            else:     # else live or dead any other number of neighbors next gen is dead or 0
                
                newworld[y][x] = 0
                
    oldworld = [x[:] for x in newworld] # clone this gen to next gen          

showWorld()
sleep(0.2)
print(type(oldworld[0][0]))

print(countNeighbors(1,1))

for g in range(50):
    
    nextGen()
    clear()
    showWorld()
    print("Generation",g)
    sleep(0.2)