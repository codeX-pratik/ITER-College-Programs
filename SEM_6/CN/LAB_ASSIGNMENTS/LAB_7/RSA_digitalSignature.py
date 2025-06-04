import math
import random

def keyGeneration():
    p=int(input('Enter 1st large prime p:'))
    q=int(input('Enter 2nd large prime q:'))
    n=p*q
    phi_n=(p-1)*(q-1)
    e=int(input('Randomly choose e between 1 and phi_n:'))
    while(math.gcd(e,phi_n)!=1 and (1<e and e<phi_n)):
        e=int(input('Randomly choose e between 1 and phi_n:'))

    k=random.randint(1,1000)
    while((k*phi_n+1)%e != 0):
        k=random.randint(1,1000)
    d=int((k*phi_n+1)/e)

    return e,n,d

def generate_signature(M,d,n):
    S=pow(M,d)%n
    return S

def verify_signature(S,M,e,n):
    M1=pow(S,e)%n
    print('The receiver is now verifying..... It generated the message M1=',M1)
    if M == M1:
        return True
    return False

e=n=d=0
e,n,d = keyGeneration()
print('e=',e,'n=',n,'d=',d)

M=int(input('Enter message M to sign:'))
S=generate_signature(M,e,n)
print('Signature generated')
print('Sending signature S=',S,' and message M=',M)
res=verify_signature(S,M,d,n)
if res==True:
    print('Message Accepted...')
else:
    print('Message Rejected...')


"""
Enter 1st large prime p:63
Enter 2nd large prime q:77
Randomly choose e between 1 and phi_n:53
e= 53 n= 4851 d= 35829
Enter message M to sign:23
Signature generated
Sending signature S= 452  and message M= 23
The receiver is now verifying..... It generated the message M1= 1772
Message Rejected...
"""