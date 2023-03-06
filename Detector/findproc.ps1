$process = Get-Process -Name "keylogger"
if ($process) {
    Write-Host "found, PID $($process.Id)"
} else {
    Write-Host "not found"
    }