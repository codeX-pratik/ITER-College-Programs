def vigenere_encrypt(plaintext, key):
    encrypted_text = []
    key_length = len(key)
    for i, char in enumerate(plaintext):
        if char.isalpha():
            shift = ord(key[i % key_length].upper()) - ord('A')
            if char.isupper():
                encrypted_char = chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
            else:
                encrypted_char = chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            encrypted_text.append(encrypted_char)
        else:
            encrypted_text.append(char)
    return ''.join(encrypted_text)

def vigenere_decrypt(ciphertext, key):
    decrypted_text = []
    key_length = len(key)
    for i, char in enumerate(ciphertext):
        if char.isalpha():
            shift = ord(key[i % key_length].upper()) - ord('A')
            if char.isupper():
                decrypted_char = chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
            else:
                decrypted_char = chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
            decrypted_text.append(decrypted_char)
        else:
            decrypted_text.append(char)
    return ''.join(decrypted_text)

choice = input("Enter 'E' for encryption or 'D' for decryption: ").upper()
if choice == 'E':
    plaintext = input("Enter the plaintext: ")
    key = input("Enter the key: ")
    ciphertext = vigenere_encrypt(plaintext, key)
    print("Encrypted text:", ciphertext)
elif choice == 'D':
    ciphertext = input("Enter the ciphertext: ")
    key = input("Enter the key: ")
    plaintext = vigenere_decrypt(ciphertext, key)
    print("Decrypted text:", plaintext)
else:
    print("Invalid choice")