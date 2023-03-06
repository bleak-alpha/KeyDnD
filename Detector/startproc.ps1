process = Start-Process -FilePath "notepad.exe" -PassThru 

Write-Host "started with PID $($process.Id)"