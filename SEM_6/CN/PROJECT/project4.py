import random
import math

# Check if a number is prime.
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Compute the greatest common divisor of a and b.
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Extended Euclidean Algorithm to find the modular inverse.
def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

# Compute the modular inverse of e modulo phi.
def mod_inverse(e, phi):
    gcd, x, _ = extended_gcd(e, phi)
    if gcd != 1:
        raise ValueError("Inverse doesn't exist")
    else:
        return x % phi
    
# Encrypt the plaintext using the public key (e, n).
def encrypt(plaintext, e, n):
    ciphertext = []
    for char in plaintext:
        ascii_value = ord(char)
        encrypted_value = pow(ascii_value, e, n)
        ciphertext.append(encrypted_value)
    return ciphertext

# Decrypt the ciphertext using the private key (d, n).
def decrypt(ciphertext, d, n):
    plaintext = ""
    for encrypted_value in ciphertext:
        decrypted_value = pow(encrypted_value, d, n)
        plaintext += chr(decrypted_value)
    return plaintext

# Generate RSA public and private keys.
def generate_keys():
    while True:
        try:
            p = int(input("Enter a prime number p: "))
            q = int(input("Enter a prime number q: "))
            if is_prime(p) and is_prime(q) and p != q:
                break
            else:
                print("Both numbers must be distinct prime numbers.")
        except ValueError:
            print("Invalid input. Please enter valid integers.")
    
    n = p * q
    
    phi = (p - 1) * (q - 1)
    
    e = random.randint(2, phi - 1)
    while gcd(e, phi) != 1:
        e = random.randint(2, phi - 1)
    
    d = mod_inverse(e, phi)
    
    return (e, n), (d, n)

def main():
    public_key, private_key = generate_keys()
    
    print("Public Key (e, n):", public_key)
    print("Private Key (d, n):", private_key)
    
    plaintext = input("Enter the plaintext: ")
    
    ciphertext = encrypt(plaintext, public_key[0], public_key[1])
    print("Ciphertext:", ciphertext)
    
    decrypted_text = decrypt(ciphertext, private_key[0], private_key[1])
    print("Decrypted Text:", decrypted_text)

if __name__ == "__main__":
    main()


"""
// Example Output

--> string input
Enter a prime number p: 17
Enter a prime number q: 19
Public Key (e, n): (161, 323)
Private Key (d, n): (161, 323)
Enter the plaintext: CN Project
Ciphertext: [135, 10, 117, 233, 114, 196, 140, 16, 252, 48]
Decrypted Text: CN Project

--> integer input
Enter a prime number p: 17
Enter a prime number q: 19
Public Key (e, n): (65, 323)
Private Key (d, n): (257, 323)
Enter the plaintext: 20252026
Ciphertext: [84, 14, 84, 155, 84, 14, 84, 275]
Decrypted Text: 20252026

--> string and integer input
Enter a prime number p: 17
Enter a prime number q: 19
Public Key (e, n): (53, 323)
Private Key (d, n): (125, 323)
Enter the plaintext: CN Project 2025   
Ciphertext: [135, 295, 155, 309, 190, 25, 140, 16, 233, 29, 155, 84, 97, 84, 185]
Decrypted Text: CN Project 2025

"""