<#$process = Get-Process -Name "keylogger"
if ($process) {
    Write-Host "$($process.Id)"
} else {
    Write-Host "`0"
    }#>

. "isoproc.ps1"

try {
    # code that might throw an exception
    $file = Get-Item "C:\NonexistentFile.txt"
    Write-Output "File found: $($file.FullName)"
} catch {
    # handle the exception
    Write-Error "An error occurred: $($_.Exception.Message)"
} finally {
    # code that runs whether or not an exception was thrown
    Write-Output "Cleanup code"
}
try {
    $process = Get-Process -Name "keylogger"
} catch {
    # handle the exception
    Write-Error "An error occurred: $($_.Exception.Message)"
}