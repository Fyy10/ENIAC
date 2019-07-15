@echo off
:loop
    data.exe %random% > data.in
    prog.exe < data.in > progout.out
    std.exe < data.in > stdout.out
    fc progout.out stdout.out
if not errorlevel 1 goto loop
pause
goto loop
