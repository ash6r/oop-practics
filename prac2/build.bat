@echo off

setlocal EnableDelayedExpansion

chcp 65001 >nul

set "std_module=%VCToolsInstallDir%\modules\std.ixx"

if not exist ".build\" (
  mkdir ".build"
)

echo ----------------------
echo СБОРКА МОДУЛЯ std
echo ----------------------
if not exist ".build\std.ifc" (
  echo Компиляция std.ixx...
  cl /std:c++23preview /EHsc /utf-8 /c "%std_module%" /Fo:.build\
  if %errorlevel% == 0 (
    echo OK
  ) else (
    echo ОШИБКА сборки модуля std
    exit /b 1
  )
) 

echo.
echo ----------------------
echo СБОРКА ЗАДАЧ
echo ----------------------

for /d %%d in (task*) do (
  if exist "%%d\main.cpp" (
    echo Сборка %%d...
    cl /std:c++23preview /EHsc /utf-8 ^
      /reference .build\std.ifc ^
      /Fo:.build\ ^
      /Fe:.build\%%d.exe ^
      "%%d\main.cpp" ^
      .build\std.obj
    if !errorlevel! == 0 (
      echo   OK: .build\%%d.exe
    ) else (
      echo   ОШИБКА в %%d
    )
    echo.
  )
)

echo ----------------------
echo ГОТОВО
echo ----------------------
echo.
echo Для запуска: .build\taskX.exe

