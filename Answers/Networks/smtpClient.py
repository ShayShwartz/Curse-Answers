from socket import *

try:
    s = socket(AF_INET, SOCK_STREAM)

    s.connect((raw_input("Insert SMTP Server: "), 25))
    #s.connect(('mail.013.net',25))
    data = s.recv(1000)
    print data
    if data[:3] != '220':
        raw_input("ERROR: Press any key to continue...")
        exit(1)
    
    s.sendall("HELO " + raw_input("Insert Domain name: ") + "\n")
    data = s.recv(1000)
    print data
    if data[:3] != '250':
        raw_input("ERROR: Press any key to continue...")
        exit(1)

    s.sendall("MAIL FROM:"+ raw_input("Insert your mail adrress: ") + "\n")
    data = s.recv(1000)
    print data
    if data[:3] != '250':
        raw_input("ERROR: Press any key to continue...")
        exit(1)

    s.sendall("RCPT TO:" + raw_input("Insert recipient address:") + "\n")
    data = s.recv(1000)
    print data
    if data[:3] != '250':
        raw_input("ERROR: Press any key to continue...")
        exit(1)

    s.sendall("DATA\n")
    data = s.recv(1000)
    print data
    if data[:3] != '354':
        raw_input("ERROR: Press any key to continue...")
        exit(1)

    mail = raw_input("Insert your message (end with a single '.'):\n")
    while(mail != '.'):
        s.sendall(mail + "\n")
        mail = raw_input("")
    s.sendall(".\n")
    print "OK\n"
    data = s.recv(1000)
    print data
    if data[:3] != '250':
        raw_input("ERROR: Press any key to continue...")
        exit(1)

    s.sendall("QUIT")
    data = s.recv(1000)
    print data
    if data[:3] != '221':
        raw_input("ERROR: Press any key to continue...")
        exit(1)
    
except Exception as e:
    print e
    raw_input("Press any key to exit...")

s.shutdown(SHUT_RDWR)
s.close()
