# Bypassing Windows 10 with mock folder and DLL Hijacking  
## Menual

**Steps:**
1. Create a "C:\Windows \System32" folder, note the space between "Windows" and the "\".
2. Copy the binary from the legit System32 folder into the mock folder.
3. Copy your DLL into the folder
4. Launch the binary (which will launch your DLL)

To create a mock directory, you can simply use a PowerShell command like:

```powershell
New-Item "\\?\C:\Windows \System32" -ItemTypee Directory
```

The binary that I'll copy from the legit System32 will be the "ComputerDefaults.exe"

![image](https://user-images.githubusercontent.com/52316309/134849643-f383c736-69ef-4726-83a4-02a613fc3458.png)

Create DLL lilke this:

![image](https://user-images.githubusercontent.com/52316309/134849707-87f62b8e-f3c8-4160-b228-318f20505da9.png)

Rename the DLL to "secur32.dll"

Copy the DLL to the mock folder.
Start the "ComputerDefaults.exe" (in our mock folder) will Start cmd with UAC privilege!!
