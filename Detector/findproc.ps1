<#$process = Get-Process -Name "keylogger"
if ($process) {
    Write-Host "$($process.Id)"
} else {
    Write-Host "`0"
    }#>


<#. "isoproc.ps1"

$proc = "notepad.exe"

try {
    # Get all running processes
    $processes = Get-Process

    # Search for the specified process name
    for ($i = 0; $i -lt $processes.Count; $i++) {
        if ($processes[$i].Name -eq $proc) {
            # Output details for the found process
            Write-Output "Process name: $($processes[$i].Name)"
            Write-Output "Process ID: $($processes[$i].Id)"
            Write-Output "Start time: $($processes[$i].StartTime)"
            Write-Output "Path: $($processes[$i].Path)"
            Write-Output "Memory usage: $($processes[$i].WorkingSet64) bytes"
            break
        }
    }

    if ($i -eq $processes.Count) {
        Write-Output "$proc is not running"
    }
}
catch {
    Write-Error "Error occurred: $($_.Exception.Message)"
}
#>

<#-------------------------------------------------------------#>

[CmdletBinding()]
param (
    [Parameter(Mandatory=$true)]
    [ScriptBlock]$ProcessList
)

$process_name = "notepad.exe"

try {
    # Call the script block to retrieve the process list
    $processes = Invoke-Command -ScriptBlock $ProcessList

    # Search for the specified process name
    for ($i = 0; $i -lt $processes.Count; $i++) {
        if ($processes[$i].Name -eq $process_name) {
            # Output details for the found process
            Write-Output "Process name: $($processes[$i].Name)"
            Write-Output "Process ID: $($processes[$i].Id)"
            Write-Output "Start time: $($processes[$i].StartTime)"
            Write-Output "Path: $($processes[$i].Path)"
            Write-Output "Memory usage: $($processes[$i].WorkingSet64) bytes"
            break
        }
    }

    if ($i -eq $processes.Count) {
        Write-Output "$process_name is not running"
    }
}
catch {
    Write-Error "Error occurred: $($_.Exception.Message)"
}
