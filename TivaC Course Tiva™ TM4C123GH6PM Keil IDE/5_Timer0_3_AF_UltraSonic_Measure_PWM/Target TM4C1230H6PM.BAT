SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Python38\Scripts\;C:\Python38\;c:\Mingw\bin;c:\Mingw\libexec\gcc\x86_64-w64-mingw32\9.2.0;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32\WBEM;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Users\Ahmad\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Java\jdk12\bin;C:\Program Files\Java\jre1\bin;C:\Program Files\Git\cmd;C:\MinGW\bin;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Users\Ahmad\.windows-build-tools\python27;C:\Program Files (x86)\GNU Arm Embedded Toolchain\9 2020-q2-update\bin;C:\Program Files (x86)\GNU Tools ARM Embedded\8 2019-q3-update\bin;C:\Ruby26-x64\bin;C:\Users\Ahmad\AppData\Local\Microsoft\WindowsApps;C:\Users\Ahmad\AppData\Local\Programs\Microsoft VS Code\bin;C:\Users\Ahmad\AppData\Local\GitHubDesktop\bin;C:\Users\Ahmad\AppData\Roaming\npm
SET CPU_TYPE=TM4C1230H6PM
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=Target TM4C1230H6PM
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_tm4c123._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\system_tm4c123.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\UltraSonic.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\UltraSonic.axf" --i32combined --output ".\Objects\UltraSonic.hex"
