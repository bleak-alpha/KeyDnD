$process = Get-Process -Name "notepad"
if ($process) {
    Write-Host "found, PID $($process.Id)"
} else {
    Write-Host "not found"
    <#$process = Start-Process -FilePath "notepad.exe" -PassThru
    if ($process) {
        Write-Host "started with PID $($process.Id)"
    } else {
        Write-Host "Failed to start"
    }#> <# starts proc if not found #>
}