echo "Building LSP"
cd ./lsp || exit
echo "Building Linux x86"
GOOS=linux GOARCH=amd64 CC=gcc go build -a -o lsp || exit
echo "Building Windows x86"
GOOS=windows GOARCH=amd64 CGO_ENABLED=1 CC=/usr/bin/x86_64-w64-mingw32-gcc go build -a -o lsp.exe || exit
cd .. || exit

echo "Building Generator"
cd ./generator || exit
echo "Building Linux x86"
GOOS=linux GOARCH=amd64 CC=gcc go build -a -o generator || exit
echo "Building Windows x86"
GOOS=windows GOARCH=amd64 CGO_ENABLED=1 CC=/usr/bin/x86_64-w64-mingw32-gcc go build -a -o generator.exe || exit
cd ..

echo "Building Relay"
cd ./relay || exit
echo "Building Linux x86"
GOOS=linux GOARCH=amd64 CC=gcc go build -a -o relay || exit
echo "Building Windows x86"
GOOS=windows GOARCH=amd64 CGO_ENABLED=1 CC=/usr/bin/x86_64-w64-mingw32-gcc go build -a -o relay.exe || exit
cd .. || exit

echo "Building Visual Studio Code Plugin"
echo "Coping Binaries"
cp ./lsp/lsp ./vscode-plugin/client/lsp/lsp || exit
cp ./lsp/lsp.exe ./vscode-plugin/client/lsp/lsp.exe || exit
echo "Building Typescript"
cd ./vscode-plugin || exit
npm run compile
echo "Packaging Plugin"
vsce package
cd ..
