$ErrorActionPreference = 'Stop'
$wordReviewRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$wordReviewFiles = @('Memoria_Laboratorio_3_X72', 'Guion_capturas_Practica_3_X72')
$wordReviewApp = $null
try {
    $wordReviewApp = New-Object -ComObject Word.Application
    $wordReviewApp.Visible = $false
    $wordReviewApp.DisplayAlerts = 0
    $wordReviewApp.AutomationSecurity = 3
    foreach ($wordReviewName in $wordReviewFiles) {
        $wordReviewDocument = $null
        try {
            $wordReviewPath = Join-Path $wordReviewRoot ($wordReviewName + '.docx')
            $wordReviewPdfPath = Join-Path $wordReviewRoot ('tmp\word\' + $wordReviewName + '.pdf')
            $wordReviewParent = Split-Path -Parent $wordReviewPdfPath
            New-Item -ItemType Directory -Path $wordReviewParent -Force | Out-Null
            $wordReviewDocument = $wordReviewApp.Documents.Open($wordReviewPath, $false, $true, $false)
            $wordReviewDocument.Repaginate()
            $wordReviewDocument.ExportAsFixedFormat($wordReviewPdfPath, 17)
            Write-Output ($wordReviewName + ': abierto correctamente en Word, ' + $wordReviewDocument.ComputeStatistics(2) + ' paginas; proteccion=' + $wordReviewDocument.ProtectionType)
        }
        finally {
            if ($null -ne $wordReviewDocument) {
                $wordReviewDocument.Close(0)
                [System.Runtime.InteropServices.Marshal]::ReleaseComObject($wordReviewDocument) | Out-Null
            }
        }
    }
}
finally {
    if ($null -ne $wordReviewApp) {
        $wordReviewApp.Quit(0)
        [System.Runtime.InteropServices.Marshal]::ReleaseComObject($wordReviewApp) | Out-Null
    }
}
