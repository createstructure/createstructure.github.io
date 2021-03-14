$ErrorActionPreference = 'Stop'; # stop on all errors
$toolsDir   = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"
$fileLocation = Join-Path $toolsDir 'createstructure-setup.exe'

$packageArgs = @{
  packageName   = $env:ChocolateyPackageName
  unzipLocation = $toolsDir
  fileType      = 'EXE'
  file         = $fileLocation

  softwareName  = 'createstructure*'
  validExitCodes= @(0, 3010, 1641)
  silentArgs   = 'install'
}
Install-ChocolateyInstallPackage @packageArgs



# Additional instructions

# My personal variabiles
$ppath = "C:\Progra~1\createstructure"
$exepath = "$ppath\createstructure.exe"
echo "My personal path is: $ppath"
echo "My exe path id $exepath"

# Set folder
New-Item -ItemType Directory -Force -Path $ppath
Copy-Item "$toolsDir\createstructure.exe" "$ppath\createstructure.exe"

# Add Path
$new_path = (Get-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH).path
if ($new_path -notlike "*$ppath*")
{
	$new_path += ";$ppath"
	$new_path = $new_path.Replace(";;", ";")
	Set-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name PATH -Value $new_path
}