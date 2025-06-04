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

def encrypt(P,e,n):
  C=pow(P,e)%n
  return C

def decrypt(C,d,n):
  P=pow(C,d)%n
  return P

e=n=d=0
e,n,d = keyGeneration()
print('e=',e,'n=',n,'d=',d)

P=int(input('Enter plaintext (integer):'))
C=encrypt(P,e,n)
print('Cipertext=',C)
P1=decrypt(C,d,n)
print('Decrypted plaintext=',P1)

PP=input('Enter plaintext:')
PP=PP.lower().replace(" ","")
print('Plaintext is:',PP)
CC=""
CC_list=[]
for i in range(len(PP)):
  ch=ord(PP[i])-ord('a')
  tmp=encrypt(ch,e,n)
  CC_list.append(tmp)
for i in CC_list:
  CC+=str(i)
print('Cipertext=',CC)

PP1=""
for i in CC_list:
  ch=decrypt(i,d,n)
  ch=chr(97+ch)
  PP1+=str(ch)

print('Decrypted plaintext=',PP1)

"""
Enter 1st large prime p:7
Enter 2nd large prime q:11
Randomly choose e between 1 and phi_n:37
e= 37 n= 77 d= 673
Enter plaintext (integer):5
Cipertext= 47
Decrypted plaintext= 5
Enter plaintext:Hello world
Plaintext is: helloworld
Cipertext= 28601111422242521131
Decrypted plaintext= helloworld
"""