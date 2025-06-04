import math

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def keyGeneration():
    while True:
        p = int(input('Enter 1st large prime p: '))
        if is_prime(p):
            break
        print("Invalid input. Please enter a prime number.")
    
    while True:
        q = int(input('Enter 2nd large prime q: '))
        if is_prime(q) and q != p:
            break
        print("Invalid input. Please enter a different prime number than p.")
    
    n = p * q
    phi_n = (p - 1) * (q - 1)
    
    coprimes = [e for e in range(2, phi_n) if math.gcd(e, phi_n) == 1]
    print(f"Possible e values (coprimes to φ(n)={phi_n}):")
    print(coprimes[:10], "...")
    
    while True:
        e = int(input(f'Choose e (coprime to {phi_n}): '))
        if 1 < e < phi_n and math.gcd(e, phi_n) == 1:
            break
        print("Invalid e. Must be 1 < e < φ(n) and coprime to φ(n).")
    
    def extended_gcd(a, b):
        if a == 0:
            return (b, 0, 1)
        else:
            g, y, x = extended_gcd(b % a, a)
            return (g, x - (b // a) * y, y)
    
    g, x, y = extended_gcd(e, phi_n)
    if g != 1:
        raise ValueError('Modular inverse does not exist')
    d = x % phi_n
    
    return e, n, d

def encrypt(P, e, n):
    if P >= n:
        raise ValueError("Plaintext must be smaller than n")
    return pow(P, e, n)

def decrypt(C, d, n):
    return pow(C, d, n)

def process_text(input_text, e, n, d, mode):
    result = []
    if mode == "encrypt":
        input_text = input_text.lower().replace(" ", "")
        for ch in input_text:
            num = ord(ch) - ord('a')
            if 0 <= num <= 25:
                result.append(str(encrypt(num, e, n)))
    elif mode == "decrypt":
        numbers = list(map(int, input_text.split()))
        for num in numbers:
            decrypted_num = decrypt(num, d, n)
            if 0 <= decrypted_num <= 25:
                result.append(chr(decrypted_num + ord('a')))
            else:
                result.append('?')
    return ' '.join(result) if mode == "encrypt" else ''.join(result)


e, n, d = keyGeneration()
print(f"Public key (e, n): ({e}, {n})")
print(f"Private key d: {d}")
choice = input("Encrypt/Decrypt integer or text? (i/t): ").lower()    
if choice == 'i':
    P = int(input('Enter integer (must be < n): '))
    C = encrypt(P, e, n)
    print(f'Ciphertext: {C}')
    P1 = decrypt(C, d, n)
    print(f'Decrypted integer: {P1}')
elif choice == 't':
    direction = input("Encrypt or decrypt? (e/d): ").lower()
    if direction == 'e':
        text = input('Enter text to encrypt: ')
        encrypted = process_text(text, e, n, d, "encrypt")
        print(f'Ciphertext: {encrypted}')
    elif direction == 'd':
        cipher = input('Enter numbers to decrypt (space-separated): ')
        decrypted = process_text(cipher, e, n, d, "decrypt")
        print(f'Decrypted text: {decrypted}')


"""
// integer input
Enter 1st large prime p: 7
Enter 2nd large prime q: 11
Possible e values (coprimes to φ(n)=60):
[7, 11, 13, 17, 19, 23, 29, 31, 37, 41] ...
Choose e (coprime to 60): 37
Public key (e, n): (37, 77)
Private key d: 13
Encrypt/Decrypt integer or text? (i/t): i
Enter integer (must be < n): 5
Ciphertext: 47
Decrypted integer: 5

// text input
Enter 1st large prime p: 7
Enter 2nd large prime q: 11
Possible e values (coprimes to φ(n)=60):
[7, 11, 13, 17, 19, 23, 29, 31, 37, 41] ...
Choose e (coprime to 60): 37
Public key (e, n): (37, 77)
Private key d: 13
Encrypt/Decrypt integer or text? (i/t): t
Encrypt or decrypt? (e/d): e
Enter text to encrypt: Hello world
Ciphertext: 28 60 11 11 42 22 42 52 11 31
"""