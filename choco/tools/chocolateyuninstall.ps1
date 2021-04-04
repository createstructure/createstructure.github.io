# Variabiles
$toolsDir   = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"
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
