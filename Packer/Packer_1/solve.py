import os

def decrypt(input_file: str, key: bytes):
    """ 解密輸入的檔案，並將解密的內容寫入輸出檔案 """
    if not os.path.exists(input_file):
        print(f"無法找到檔案: {input_file}")
        return
    
    try:
        # 讀取加密的檔案內容
        with open(input_file, 'rb') as inFile:
            encrypted_data = inFile.read()
        
        # XOR 解密（與加密過程一樣）
        key_size = len(key)
        decrypted_data = bytearray(len(encrypted_data))
        for i in range(len(encrypted_data)):
            decrypted_data[i] = encrypted_data[i] ^ key[i % key_size]

        print(f"解密完成，解密內容: {decrypted_data.decode('utf-8')}")

    except Exception as e:
        print(f"解密過程中發生錯誤: {e}")


if __name__ == "__main__":
    input_file = 'output'  # 要解密的檔案
    output_file = 'flag'  # 解密後的輸出檔案
    key = bytes(b"flydragonsxorkey")  # 與 C++ 中相同的密鑰
    
    decrypt(input_file, key)
