def vigenere_xor_decrypt(ciphertext, key):
    decrypted_text = []
    key_length = len(key)
    key_as_int = [ord(i) for i in key]
    ciphertext_int = [i for i in ciphertext]
    
    for i in range(len(ciphertext_int)):
        value = ciphertext_int[i] ^ key_as_int[i % key_length]
        decrypted_text.append(chr(value))
    
    return ''.join(decrypted_text)

hexstring = "1B06310903180000" 
ciphertext = bytearray.fromhex(hexstring)[::-1]
hexstring = "150404012B530E0D"
ciphertext += bytearray.fromhex(hexstring)[::-1]
hexstring = "11470B1C"
ciphertext += bytearray.fromhex(hexstring)[::-1]

key = "flydragon"
decrypted_message = vigenere_xor_decrypt(ciphertext, key)
print("flag:", decrypted_message)