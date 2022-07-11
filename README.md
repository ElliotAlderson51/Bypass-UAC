# Bypassing Windows 10 with mock folder and DLL Hijacking  

**Hey, I make two projects to bypass UAC:**

1. Manual
2. Auto

You will find in each folder (Munual/Auto) a README.md file with explanation!

### How it works?

The program will create a "Windows " folder and the windows will think that this is the original "Windows" folder. The program will copy the "ComputerDefaults.exe" into the "Windows /System32" and then Extract the DLL from the PE section into the "Windows /System32" with the name "Secur32.dll". Start the ComputerDefaults.exe, and this will perform a DLL Hijacking and BypassUAC. The DLL will start whatever you want.. it can be a CMD or the program that do all of this automatically.  

##

This project is for EDUCATIONAL PURPOSES ONLY.       
You are the only responsable for your actions! Happy Hacking (;
