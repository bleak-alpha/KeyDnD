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
-> LinLogger_Alpha(), highjacking xserver process for intercepting keyboard event handler                    
-> WinLogger() logs keystrokes into an external log file (log.txt)                  
~~-> LinLogger() implemented in main() during alpha stage~~ //event handler issue, keyboard event handler not responding                          


#### To Do:                   
->LinLogger_Alpha() //build 0.1.1                                       
            -setting up logging                                             
            -exporting logs                                                                   
            ~~-key mapper~~                        
            ~~-alloting signal handler~~ //using signal handler instead of event handler, ring-0 exploit potential                     
            ~~-alloting display tracker~~                                                                             
<sub>Keeping on hold right now, event handler issue</sub>                             
->LinLogger() for linux                
            -character mapping           
            -log storage      
            ~~-detect keystrokes~~              

->Create KeyDetector() (for both OS if possible)            

->Make code chunks inheritable and modular      

->Wrap code around a front-end      

~->Detect Special Keys in WinLogger()~               
            ~~-[ESC]~~          
            ~~-[WIN]~~          
            ~~-[SPACE]~~      
            ~~-[INS]~~         
            ~~-[DEL]~~         
            ~~-[END]~~        
            ~~-[PGUP]~~        
            ~~-[PGDW]~~       
            ~~-[PRTSCR]~~   
            ~~-[SCRLK]~~                
            ~~-[PAUBRK]~~    
            ~~-[SCRDW]~~                
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
            ~~-[F1-F12]~~              
#### Bugs:
~~-> running LinLogger.main() by sudo freezes keyboard event handler and crashing vm~~                               
~~-> Double alphanumeric input detected in WinLogger()~~  
