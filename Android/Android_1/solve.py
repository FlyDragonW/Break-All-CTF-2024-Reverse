def xor_bytes(input_bytes, key):
    return bytes([(b ^ key) for b in input_bytes])  

def convert_java_bytes(java_bytes):
    return [(b + 256) if b < 0 else b for b in java_bytes]

def brute_force_key(target_bytes):
    target_bytes_unsigned = bytes(convert_java_bytes(target_bytes)) 
    for key in range(256):  
        if b"flag" in xor_bytes(target_bytes_unsigned, key):  
            print(f"Found key: {key}")
            print(xor_bytes(target_bytes_unsigned, key).decode('utf-8'))
            return

if __name__ == "__main__":
    target_bytes = [76, 70, 75, 77, 81, 78, 79, 73, 26, -59, -110, -91, -56, -87, -119, 71, 67, 70, 79, 117, -38, -75, -81, -102, 90, -59, -110, -91, 65, -38, -75, -114, -71, 127, 126, 108, 7, 18, 87]
    brute_force_key(target_bytes)
