def encrypt(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            base = 'a' if char.islower() else 'A'
            encrypted_text += chr((ord(char) - ord(base) + shift) % 26 + ord(base))
        else:
            encrypted_text += char
    return encrypted_text

def decrypt(text, shift):
    return encrypt(text, -shift)

def main():
    shift = int(input("Enter shift value: "))
    operation = input("Enter operation (encrypt or decrypt): ")
    text = input("Enter text: ")
    
    if operation.lower() == "encrypt":
        print("Encrypted text:", encrypt(text, shift))
    elif operation.lower() == "decrypt":
        print("Decrypted text:", decrypt(text, shift))
    else:
        print("Invalid operation.")

if __name__ == "__main__":
    main()
