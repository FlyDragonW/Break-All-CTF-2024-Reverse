#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//g++ main.cpp -o main -s

void Encrypt(const std::string& inputFile, const std::string& outputFile, const std::vector<uint8_t>& key) {
    std::ifstream inFile(inputFile, std::ios::binary);
    if (!inFile) {
        return;
    }

    std::vector<char> header(5);
    inFile.read(header.data(), 5);
    if (inFile.gcount() < 5) {
        return;
    }

    std::string headerStr(header.begin(), header.end());
    if (headerStr != "Fl4g:") {
        return;
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    size_t keySize = key.size();
    for (size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] ^= key[i % keySize];
    }

    std::ofstream outFile(outputFile, std::ios::binary);
    if (!outFile) {
        return;
    }
    outFile.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
    outFile.close();

}

int main() {
    std::string inputFile = "input";
    std::string outputFile = "output";
    std::vector<uint8_t> key = {0x79, 0x65, 0x74, 0x61, 0x6e, 0x6f, 0x74, 0x68, 0x65, 0x72, 0x6b, 0x65, 0x79}; 

    Encrypt(inputFile, outputFile, key);

    return 0;
}
