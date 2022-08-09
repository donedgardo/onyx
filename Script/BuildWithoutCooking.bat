set engineLocation=%~1
set workspace=%~2
set projectFilename=%~3


"%engineLocation%\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="%workspace%\%projectFilename%" -noP4 -platform=Win64 -clientconfig=Development -build