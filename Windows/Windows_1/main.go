package main

//go build -ldflags="-s -w" -o main.exe

import (
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
	"os"
	"path/filepath"
)

/*
func Encrypt(key []byte, plaintext string) (string, error) {
	block, err := aes.NewCipher(key)
	if err != nil {
		return "", err
	}

	nonce := []byte("bbbbbbbbbbbb")

	aesGCM, err := cipher.NewGCM(block)
	if err != nil {
		return "", err
	}

	ciphertext := aesGCM.Seal(nil, nonce, []byte(plaintext), nil)

	return base64.StdEncoding.EncodeToString(append(nonce, ciphertext...)), nil
}
*/

func Decrypt() string {
	key := []byte("flydragonaeskey!")
	data, err := base64.StdEncoding.DecodeString("YmJiYmJiYmJiYmJilvzkR9DvtlIkoDTqo88O/JNaoM4YM1JfKEA0k94MpKy/kAeEAMu/BudE")
	if err != nil {
		return ""
	}

	nonce, ciphertext := data[:12], data[12:]

	block, err := aes.NewCipher(key)
	if err != nil {
		return ""
	}

	aesGCM, err := cipher.NewGCM(block)
	if err != nil {
		return ""
	}

	plaintext, err := aesGCM.Open(nil, nonce, ciphertext, nil)
	if err != nil {
		return ""
	}

	return string(plaintext)
}

func ensureDir(path string) error {
	dir := filepath.Dir(path)
	return os.MkdirAll(dir, os.ModePerm)
}

func xorBytes(key byte) string {
	//C:\\Users\\Public\\flydragon\\flag.txt
	input := []byte{0x49, 0x30, 0x56, 0x5f, 0x79, 0x6f, 0x78, 0x79, 0x56, 0x5a, 0x7f, 0x68, 0x66, 0x63, 0x69, 0x56, 0x6c, 0x66, 0x73, 0x6e, 0x78, 0x6b, 0x6d, 0x65, 0x64, 0x56, 0x6c, 0x66, 0x6b, 0x6d, 0x24, 0x7e, 0x72, 0x7e}
	for i := range input {
		input[i] ^= key
	}
	return string(input)
}

func writeToFile(path string) error {
	ensureDir(path)

	content := Decrypt()
	file, err := os.Create(path)
	if err != nil {
		return err
	}
	defer file.Close()

	file.WriteString(content)
	return nil
}

func main() {
	writeToFile(xorBytes(10))
	os.Remove(xorBytes(10))
}
