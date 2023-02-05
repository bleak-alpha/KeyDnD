# Get the current list of processes
$before = Get-Process

# Wait for a period of time
Start-Sleep -Seconds 5

# Get the list of processes after the wait period
$after = Get-Process

# Compare the two lists and print the new processes
Write-Host "New processes:"
$newProcesses = Compare-Object $before $after | Where-Object { $_.SideIndicator -eq '=>' }
$newProcesses | Select-Object -Property ProcessName, Id, StartTime