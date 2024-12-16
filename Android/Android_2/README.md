## Challenge Name
```
Android_2
```
## Challenge
There are only two types of people in this world...  

Author: Flydragon
```
## File
- app.apk
## Flag
```
flag{u_R_Sta7Ic_0r_d14nMic?}
```
## Solve
```
1. adb root; adb push frida-server /data/local/tmp/; adb shell chmod 755 /data/local/tmp/frida-server; ./data/local/tmp/frida-server &
2. frida -U --no-pause -l script.js -f "com.example.break_all_ctf_2"
```
