# pip install pycryptodome

from Crypto.Cipher import DES
import binascii

def pad(text):
    while len(text) % 8 != 0:
        text += " "
    return text.encode()

def encryption(des, plaintext):
    padded_text = pad(plaintext)
    ciphertext = des.encrypt(padded_text)
    return binascii.hexlify(ciphertext).decode()

def decryption(des, ciphertext):
    binary_data = binascii.unhexlify(ciphertext)
    plaintext = des.decrypt(binary_data).decode().strip()
    return plaintext

key = input("Enter key: ")
plaintext = input("Enter plaintext: ")
print("Plaintext is:", plaintext)

if len(key) != 8:
    print("Key must be 8 bytes long")
else:
    key = key.encode()
    des_cipher = DES.new(key, DES.MODE_ECB)
    
    ciphertext = encryption(des_cipher, plaintext)
    print("Ciphertext after encryption:", ciphertext)
    
    decrypted_text = decryption(des_cipher, ciphertext)
    print("Decrypted text:", decrypted_text)


"""
Enter key: 10101010
Enter plaintext: 11110000
Plaintext is: 11110000
Ciphertext after encryption: 54e3eccc65a871a5
Decrypted text: 11110000
"""