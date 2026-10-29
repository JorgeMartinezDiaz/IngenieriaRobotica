param([string]$Documento = 'Memoria_Laboratorio3_actualizada.docx')
$ErrorActionPreference = 'Stop'
$reviewRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$reviewWord = $null
$reviewDocument = $null
try {
    $reviewWord = New-Object -ComObject Word.Application
    $reviewWord.Visible = $false
    $reviewWord.DisplayAlerts = 0
    $reviewWord.AutomationSecurity = 3
    $reviewSource = Join-Path $reviewRoot $Documento
    $reviewPdf = Join-Path $reviewRoot 'Memoria_Laboratorio3_actualizada.pdf'
    $reviewDocument = $reviewWord.Documents.Open($reviewSource, $false, $true, $false)
    $reviewDocument.Repaginate()
    $reviewDocument.ExportAsFixedFormat($reviewPdf, 17)
    Write-Output ('Word: documento abierto correctamente; paginas=' + $reviewDocument.ComputeStatistics(2) + '; proteccion=' + $reviewDocument.ProtectionType)
}
finally {
    if ($null -ne $reviewDocument) {
        $reviewDocument.Close(0)
        [System.Runtime.InteropServices.Marshal]::ReleaseComObject($reviewDocument) | Out-Null
    }
    if ($null -ne $reviewWord) {
        $reviewWord.Quit(0)
        [System.Runtime.InteropServices.Marshal]::ReleaseComObject($reviewWord) | Out-Null
    }
}
