<#function get-new-process-names {
    $processes = Get-Process
    $new_processes = @()

    foreach ($process in $processes) {
        if ($process.Id -gt $last_pid) {
            $new_processes += $process.Name
        }
    }

    return $new_processes
}#>

<#
# Set the time range for process start time
$start_time = (Get-Date).AddMinutes(-10)

# Get all running processes
$processes = Get-Process

# Filter out system processes and processes that started before $start_time
$new_processes = $processes | Where-Object {
    $_.StartTime -gt $start_time -and $_.Name -notmatch '^System|^Idle$'
}

# Store the process names in an array
$process_names = $new_processes.Name

# Output the process names
#Write-Output "New processes in the last 10 minutes: $($process_names -join ', ')"
#>
<#-------------------------------------------------------------------------------------------------------#>
# Get the current time
$now = Get-Date

# Get the process list and filter out system processes
$processes = Get-Process | Where-Object { $_.Name -notin @("Idle", "System") }

# Filter the process list by start time (within the last 10 minutes)
$ProcessList = $processes | Where-Object { $now.Subtract($_.StartTime).TotalMinutes -lt 10 }

# Pass the recent process list to script2.ps1
.\findproc.ps1 -ProcessList $ProcessList