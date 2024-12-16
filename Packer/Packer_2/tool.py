def remove_substring_from_binary(input_file, output_file, substrings):
    with open(input_file, "rb") as f:
        binary_data = f.read()
    
    modified_data = binary_data
    for substring in substrings:
        modified_data = modified_data.replace(substring, b"abc")
    
    # 將結果寫回檔案
    with open(output_file, "wb") as f:
        f.write(modified_data)

def recover_substring_from_binary(input_file, output_file, substring):
    with open(input_file, "rb") as f:
        binary_data = f.read()
    
    modified_data = binary_data
    modified_data = modified_data.replace(b"abc", substring)
    
    # 將結果寫回檔案
    with open(output_file, "wb") as f:
        f.write(modified_data)

# 使用範例
input_file = "main_upx"   # 輸入的二進位檔案
output_file = "Packer_2"   # 輸出的結果檔案
substrings_to_remove = [b"UPX", b"upx"] # 要移除的字串

#remove_substring_from_binary(input_file, output_file, substrings_to_remove)
recover_substring_from_binary(output_file, "Packer_2_recover", b"UPX")