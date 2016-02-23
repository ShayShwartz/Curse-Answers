from socket import *

PORT = 80
rootDir = raw_input("Insert base path to the website: ")
try:
    s = socket(AF_INET, SOCK_STREAM)
    s.bind(('localhost', PORT))
    s.listen(5)
    print "listening on port " + str(PORT) + ".."
    
    
    (client_socket, client_addr) = s.accept()
    print "Connected to " + str(client_addr[0])
    client_socket.sendall("Connected on port " + str(PORT) + "\n\r")

    
    client_data = client_socket.recv(1000)
    print client_data
    client_command = client_data.split(' ')    
    if client_command[0] != "GET":
        raw_input("ERROR: Not a valid command.\nPress any key to continue...")
        exit(1)
    else:
        requestedFileName = rootDir+'\\'+client_command[1]
        f = open(requestedFileName, "r")
        #client_socket.sendall("Requseted file: " + requestedFileName + ".\n")
        #client_socket.sendall("Printing file:\n")
        if f == None:
            client_socket.sendall("HTTP/1.0 404 Not Found\n\r")
        else:
            fileData = f.read()
            client_socket.sendall("HTTP/1.0 200 Document follows\nContent-Lengh: "+str(len(fileData))+"\n\n")
            client_socket.sendall(fileData)
        client_socket.close()


    

        
    s.close()
    
    
except Exception as e:
    print e
    raw_input("ERROR: Press any key to continue...")
    exit(1)

s.close()
