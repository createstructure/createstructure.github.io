$ErrorActionPreference = 'Stop'; # stop on all errors
$toolsDir   = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"
$fileLocation = Join-Path $toolsDir 'createstructure-setup.exe'

$packageArgs = @{
	packageName   = $env:ChocolateyPackageName
	fileType      = 'EXE'
	file         = $fileLocation

	softwareName  = 'createstructure*'
	validExitCodes= @(0, 3010, 1605, 1614, 1641)
	silentArgs   = 'uninstall'
}

$uninstalled = $false
[array]$key = Get-UninstallRegistryKey -SoftwareName $packageArgs['softwareName']

if ($key.Count -eq 1) {
	$key | % { 
		$packageArgs['file'] = "$($_.UninstallString)" #NOTE: You may need to split this if it contains spaces, see below
		Uninstall-ChocolateyPackage @packageArgs
	}
} elseif ($key.Count -eq 0) {
	Write-Warning "$packageName has already been uninstalled by other means."
} elseif ($key.Count -gt 1) {
	Write-Warning "$($key.Count) matches found!"
	Write-Warning "To prevent accidental data loss, no programs will be uninstalled."
	Write-Warning "Please alert package maintainer the following keys were matched:"
	$key | % {
		Write-Warning "- $($_.DisplayName)"
	}
}



# Additional instructions

# My personal variabiles
$ppath = "C:\Progra~1\createstructure"
$exepath = "$ppath\createstructure.exe"
echo "My personal path is: $ppath"
echo "My exe path id $exepath"

# Set folder
#Remove-Item -LiteralPath $ppath -Force -Recurse

# Add Path
$new_path = (Get-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH).path
if ($new_path -like "*$ppath*")
{
	echo "Delate unwanted path"
	$new_path = $new_path.Replace("$ppath", "").Replace(";;", ";")
	Set-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH -Value $new_path
}