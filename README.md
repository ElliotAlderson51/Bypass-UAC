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
