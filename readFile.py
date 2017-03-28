from serialProcess import *
Port = open_serial_port('COM3')
set_global_port(Port)

def readFile():
    i=0
    Counter = 0
    #send reprog_begin
    write("reprog_begin\n")
    time.sleep(1)
    #initialData = initialData.strip(':')
    
    with open('C:\Users\colab\Documents\GitHub\ItsHexFileFlash\hexFile.txt','r') as fob:
        #print "Starting the reprogramming stuff"
        #previous = next(fob)
        for line in fob:
            #print previous,line
            #previous = line
            dat = []
            line = line.strip(':')

            if line[2:8] == "C20000":
                #print nextline
                line = '! ' + line[0:6]+line[8:]
                write(line)
                time.sleep(0.2)   # we need to add this delay for the receiver
                                  # to receve data completely

                if Counter %32 ==0 and Counter >0:
                    time.sleep(1)
                    
                Counter = Counter + 1
                print Counter
                while (dat != 'Done'):
                    while(Port.inWaiting() > 0):
                        dat = Port.readline()
                        dat = dat.strip()
                        print dat
                        if dat == 'Done':
                            break
    #send reprog_end
    #time.sleep(1)
        write("reprog_end\n")

readFile()
cleanup()

                                
                    
                
