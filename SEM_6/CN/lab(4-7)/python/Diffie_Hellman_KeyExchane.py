import random
import math

def isPrime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def getPrimeNumber(r1, r2):
    while True:
        n = random.randint(r1, r2)
        if isPrime(n):
            return n
        
p=getPrimeNumber(2,100)
print('Chosen prime number p=',p)
g=int(input('Enter the generator of order p-1:'))

x = random.randint(2, p - 2)
R1 = pow(g,x) % p
print('Alice choosen a large random number x=',x,' and computed R1=',R1)

y = random.randint(2, p - 2)
R2 = pow(g,y) % p
print('Bob choosen a large random number y=',y,' and computed R2=',R2)

K_Alice = pow(R2,x) % p
K_Bob   = pow(R1,y) % p
print('Alice\'s Computed Shared Key is:',K_Alice)
print('Bob\'s   Computed Shared Key is:',K_Bob)

if K_Alice == K_Bob:
  print('Key Exchange Successful...')
else:
  print('Key Exchange not Successful...')


"""
Chosen prime number p= 53
Enter the generator of order p-1:42
Alice choosen a large random number x= 3  and computed R1= 47
Bob choosen a large random number y= 41  and computed R2= 15
Alice's Computed Shared Key is: 36
Bob's   Computed Shared Key is: 36
Key Exchange Successful...
"""