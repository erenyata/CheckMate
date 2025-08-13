# test.ps1

# Start with a clean todo.txt
if (Test-Path "todo.txt") { Remove-Item "todo.txt" }

Write-Host "=== ADD TODO ==="
.\todoCLI.exe add "Study homework"
.\todoCLI.exe add "Go shopping"

Write-Host "`n=== LIST TODO ==="
.\todoCLI.exe list

Write-Host "`n=== MARK DONE 1 ==="
.\todoCLI.exe done 1
.\todoCLI.exe list

Write-Host "`n=== MARK UNDONE 1 ==="
.\todoCLI.exe undone 1
.\todoCLI.exe list

Write-Host "`n=== DELETE 2 ==="
.\todoCLI.exe delete 2
.\todoCLI.exe list
