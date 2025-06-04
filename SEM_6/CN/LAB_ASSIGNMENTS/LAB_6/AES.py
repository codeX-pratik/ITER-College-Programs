# pip install pycryptodome

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
import base64

class AESEncryptor:
    def __init__(self, key=None):
        if key:
            if len(key) not in [16, 24, 32]:
                raise ValueError("Key must be 16, 24, or 32 bytes long")
            self.key = key
        else:
            self.key = get_random_bytes(32)
    
    def encrypt(self, plaintext):
        iv = get_random_bytes(AES.block_size)
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        padded_plaintext = pad(plaintext.encode('utf-8'), AES.block_size)
        ciphertext = cipher.encrypt(padded_plaintext)
        return base64.b64encode(iv + ciphertext).decode('utf-8')
    
    def decrypt(self, ciphertext):
        raw_data = base64.b64decode(ciphertext)
        iv = raw_data[:AES.block_size]
        ciphertext = raw_data[AES.block_size:]
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        decrypted_data = unpad(cipher.decrypt(ciphertext), AES.block_size)
        return decrypted_data.decode('utf-8')

if __name__ == "__main__":
    encryptor = AESEncryptor()
    message = input("Enter a message: ")
    print(f"Original message: {message}")
    encrypted = encryptor.encrypt(message)
    print(f"Encrypted message: {encrypted}")
    decrypted = encryptor.decrypt(encrypted)
    print(f"Decrypted message: {decrypted}")
    if message == decrypted:
        print("Encryption/Decryption successful!")
    else:
        print("Something went wrong!")

"""
Enter a message: AES ENCRYPT AND DECRYPT
Original message: AES ENCRYPT AND DECRYPT
Encrypted message: 42l2OlZRoLbKGa7TaeUrOM4y3CfeBgI/rmLyu7dcDPJdgi3CKQo98FduKVF4I3Q+
Decrypted message: AES ENCRYPT AND DECRYPT
Encryption/Decryption successful!
"""