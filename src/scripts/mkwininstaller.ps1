param (
    [Parameter(Mandatory=$true)][string]$version
)

$target="SafecoinWalletLite-v$version"

Remove-Item -Path release/wininstaller -Recurse -ErrorAction Ignore  | Out-Null
New-Item release/wininstaller -itemtype directory                    | Out-Null

Copy-Item release/$target/SafecoinWalletLite.exe     release/wininstaller/
Copy-Item release/$target/LICENSE                  release/wininstaller/

Get-Content src/scripts/safecoinwalletlite.wxs | ForEach-Object { $_ -replace "RELEASE_VERSION", "$version" } | Out-File -Encoding utf8 release/wininstaller/safecoinwalletlite.wxs

candle.exe release/wininstaller/safecoinwalletlite.wxs -o release/wininstaller/safecoinwalletlite.wixobj 
if (!$?) {
    exit 1;
}

light.exe -ext WixUIExtension -cultures:en-us release/wininstaller/SafecoinWalletLite.wixobj -out release/wininstaller/SafecoinWalletLite.msi 
if (!$?) {
    exit 1;
}

New-Item artifacts -itemtype directory -Force | Out-Null
Copy-Item release/wininstaller/SafecoinWalletLite.msi ./artifacts/Windows-installer-$target.msi
