# Keylogger Deployment and Detection
Final Year Project based upon working and exploitation of keylogger software

## Table of Contents

- [About](#about)
- [Progress Report](#progress)


## About <a name = "about"></a>

#### This project works on two fronts:
##### 1. Keylogger Deployment-
Deploys a keylogger discretly within the target system and logs the keystrokes in logfile or exports them to a remote server
            
##### 2. Keylogger Detection-
Detects keylogger by doing memory consumption analysis and outputs potential keylogger proccesses


## Progress Report <a name = "progress"></a>

#### Dev Notes:
-> WinLogger() logs keystrokes into an external log file (log.txt)


#### To Do:
->Detect Special Keys in WinLogger()
-[ESC]
-[WIN]
-[SPACE]
-[INS]
-[DEL]
-[END]
-[PGUP]
-[PGDW]
-[PRTSCR]
-[SCRLK]
-[PAUBRK]
-[SCRDW]
~~-[ALT]~~
~~-[ENTER]~~
~~-[BACKSPACE]~~
~~-[LTCLK]~~
~~-[RTCLK]~~
~~-[SCRUP]~~
~~-[TAB]~~
~~-[CAPS]~~
~~-[SHIFT]~~
~~-[CTRL]~~
                   
->Create LinLogger() for linux


#### Bugs:
~~-> Double alphanumeric input detected in WinLogger()~~
