import string
from collections import Counter

# 生成字母表
ALPHABET = string.ascii_uppercase + string.ascii_lowercase

# 替換式密碼加密
def encrypt(plaintext, key):
    #plaintext = plaintext.upper().replace(" ", "")  # 忽略空格並轉大寫
    cipher_text = ""
    for char in plaintext:
        if char in ALPHABET:
            cipher_text += key[ALPHABET.index(char)]
        else:
            cipher_text += char  # 保留非字母字符
    return cipher_text

# 替換式密碼解密
def decrypt(ciphertext, key):
    plaintext = ""
    for char in ciphertext:
        if char in key:
            plaintext += ALPHABET[key.index(char)]
        else:
            plaintext += char  # 保留非字母字符
    return plaintext

# 自動破解：字頻分析
def frequency_analysis(ciphertext):
    # 統計密文字母頻率
    ciphertext = ciphertext.upper().replace(" ", " ")
    letter_count = Counter(ciphertext)
    total_letters = sum(letter_count.values())
    
    # 計算頻率
    freq_table = {char: count / total_letters for char, count in letter_count.items()}
    
    # 根據英文標準字頻對比（簡化版）
    english_freq_order = "ETAOINSHRDLCUMWFGYPBVKJXQZ" # 英文字母頻率排序
    sorted_cipher_letters = sorted(freq_table, key=freq_table.get, reverse=True)
    
    # 嘗試替換
    decryption_map = {cipher_letter: english_letter 
                      for cipher_letter, english_letter in zip(sorted_cipher_letters, english_freq_order)}
    
    # 生成解密結果
    decrypted_text = "".join(decryption_map.get(char, char) for char in ciphertext)
    return decrypted_text, decryption_map

# 測試代碼
if __name__ == "__main__":
    # 自定義加密密鑰 (替換字母順序)
    #key = "QWERTYUIOPLKJHGFDSAZXCVBNM"  # 任意排列的 26 個字母
    key = "WALKDRGONXYZQBCFUMHJESTVIP"+"WALKDRGONXYZQBCFUMHJESTVIP".lower()  # 任意排列的 26 個字母
    print("密鑰:", key)
    
    # 加密與解密測試
    plaintext = "flydragon this is a schtask that create a FAKE flag for you i am wondering that can you crack this substitution cipher flag{DLL_create_/sc_DAILY_/st_07:00}"
    ciphertext = encrypt(plaintext, key)
    print("原文:", plaintext)
    print("密文:", ciphertext)
    
    decrypted_text = decrypt(ciphertext, key)
    print("解密後:", decrypted_text)
    
    # 破解測試（假設密鑰未知）
    #cracked_text, mapping = frequency_analysis(ciphertext)
    #print("\n破解結果:")
    #print("猜測的解密文本:", cracked_text)
    #print("猜測的替換表:", mapping)
