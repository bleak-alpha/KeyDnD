function get-new-process-names {
    $processes = Get-Process
    $new_processes = @()

    foreach ($process in $processes) {
        if ($process.Id -gt $last_pid) {
            $new_processes += $process.Name
        }
    }

    return $new_processes
}