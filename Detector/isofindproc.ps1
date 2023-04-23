# Get the current time
$now = Get-Date

# Get the process list and filter out system processes
$processes = Get-Process | Where-Object { $_.Name -notin @("Idle", "System") }

# Filter the process list by start time (within the last 10 minutes)
$recent_processes = $processes | Where-Object { $now.Subtract($_.StartTime).TotalMinutes -lt 10 }

# Set the process name to search for
$process_name = "brave.exe"

# Loop through the recent process list and check if the process name is present
foreach ($process in $recent_processes) {
    if ($process.Name -eq $process_name) {
        # Output all details of the found process
        try {
            $process_details = $process | Select-Object *
            $process_details
        }
        catch {
            Write-Warning "Error occurred while retrieving process details for $($process.Name): $_"
        }
    }
}
