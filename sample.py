from serialProcess import *
Port = open_serial_port('COM7')
set_global_port(Port)

def readFile():
    i=0
    Counter = 0
    #send reprog_begin
    write("reprog_begin\n")
    time.sleep(1)
    #initialData = initialData.strip(':')

    print "----------------------------------------------------------------------"
    print "                  START ADDRESS       size"
    with open('C:\Users\colab\Documents\GitHub\ItsHexFileFlash\hexFile.lss','r') as lssFile:
        for lineLss in lssFile:
            if ".WRAPPERFUNCS" in lineLss:
                wrapperList = lineLss.split()
                wrapperFuncSize = wrapperList[2]
                wrapperFuncStartAddr = wrapperList[3]

                wrapperFuncSize = int(wrapperFuncSize,16)
                wrapperFuncStartAddr = wrapperFuncStartAddr.lstrip('0')  #strips leading zeros from the string
                print ".WRAPPERFUNCS@    " + wrapperFuncStartAddr + "                " + str(wrapperFuncSize)

                if wrapperFuncSize%16 == 0:
                    wrapperFuncSize = wrapperFuncSize/16
                else:
                    wrapperFuncSize = wrapperFuncSize/16 + 1

            if ".USERCODE_TEXT" in lineLss:
                usercodeList = lineLss.split()
                usercodeSize = usercodeList[2]
                usercodeStartAddr = usercodeList[3]

                usercodeSize = int(usercodeSize,16)
                usercodeStartAddr = usercodeStartAddr.lstrip('0')       #strips leading zeros from the string
                print ".USERCODE_TEXT@   " + usercodeStartAddr+ "                " + str(usercodeSize)
                
                if usercodeSize%16 == 0:
                    usercodeSize = usercodeSize/16
                else:
                    usercodeSize = usercodeSize/16 + 1                

                break
        
    print "----------------------------------------------------------------------"
    print ""
    flag = -1
    with open('C:\Users\colab\Documents\GitHub\ItsHexFileFlash\hexFile.txt','r') as fob:
        for line in fob:
            dat = []
            line = line.strip(':')

            #the loop runs based on the flag value        
            if line[2:6] == wrapperFuncStartAddr.upper():   # upper is used to convert the hex string to upper case alphabets ex: c000 to C000
                flag = wrapperFuncSize
                

            if line[2:6] == usercodeStartAddr.upper():   # upper is used to convert the hex string to upper case alphabets ex: c200 to C200
                flag = usercodeSize
    

            if flag > 0:
                flag = flag-1
                line = '! ' + line[0:6]+line[8:]
                write(line)
                time.sleep(0.2)   # we need to add this delay for the receiver
                                  # to receve data completely

                #print line
                if Counter %32 ==0 and Counter >0:
                    time.sleep(1)
                    
                Counter = Counter + 1
                
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

                                
                    
                
