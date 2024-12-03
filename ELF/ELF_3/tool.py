# 定義要寫入的 bytes
data = b'flag{\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00}'

# 指定要寫入的檔案名稱
file_name = 'flag.txt'

# 打開檔案並寫入 bytes
with open(file_name, 'wb') as file:
    file.write(data)

print(f"已將資料寫入 {file_name}")
