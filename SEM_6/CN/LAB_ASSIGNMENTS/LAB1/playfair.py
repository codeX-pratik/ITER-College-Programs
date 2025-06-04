def prepare_key(key):
    key = key.replace(" ", "").upper()
    key_matrix = []
    for char in key:
        if char not in key_matrix and char != 'J':
            key_matrix.append(char)
    for char in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if char not in key_matrix:
            key_matrix.append(char)
    return [key_matrix[i:i+5] for i in range(0, 25, 5)]

def prepare_text(text):
    text = text.replace(" ", "").upper()
    text = text.replace("J", "I")
    prepared = []
    i = 0
    while i < len(text):
        if i == len(text) - 1:
            prepared.append(text[i] + 'X')
            i += 1
        elif text[i] == text[i+1]:
            prepared.append(text[i] + 'X')
            i += 1
        else:
            prepared.append(text[i] + text[i+1])
            i += 2
    return prepared

def find_position(matrix, char):
    for row in range(5):
        for col in range(5):
            if matrix[row][col] == char:
                return row, col
    return -1, -1

def encrypt_pair(matrix, pair):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])
    if row1 == row2:
        return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:
        return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
    else:
        return matrix[row1][col2] + matrix[row2][col1]

def decrypt_pair(matrix, pair):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])
    if row1 == row2:
        return matrix[row1][(col1 - 1) % 5] + matrix[row2][(col2 - 1) % 5]
    elif col1 == col2:
        return matrix[(row1 - 1) % 5][col1] + matrix[(row2 - 1) % 5][col2]
    else:
        return matrix[row1][col2] + matrix[row2][col1]

def encrypt(plaintext, key):
    matrix = prepare_key(key)
    pairs = prepare_text(plaintext)
    ciphertext = ""
    for pair in pairs:
        ciphertext += encrypt_pair(matrix, pair)
    return ciphertext

def decrypt(ciphertext, key):
    matrix = prepare_key(key)
    pairs = [ciphertext[i:i+2] for i in range(0, len(ciphertext), 2)]
    plaintext = ""
    for pair in pairs:
        plaintext += decrypt_pair(matrix, pair)
    return plaintext

def main():
    choice = input("Enter 'E' for encryption or 'D' for decryption: ").upper()
    if choice == 'E':
        plaintext = input("Enter the plaintext: ")
        key = input("Enter the key: ")
        ciphertext = encrypt(plaintext, key)
        print("Encrypted text:", ciphertext)
    elif choice == 'D':
        ciphertext = input("Enter the ciphertext: ")
        key = input("Enter the key: ")
        plaintext = decrypt(ciphertext, key)
        print("Decrypted text:", plaintext)
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()