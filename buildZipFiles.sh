mkdir "temp"

# Executables and Artefakts
echo "baue Programme.zip"
mkdir "temp/Programme"
cp ./lsp/lsp ./temp/Programme
cp ./lsp/lsp.exe ./temp/Programme
cp ./generator/generator ./temp/Programme
cp ./generator/generator.exe ./temp/Programme
cp ./relay/relay ./temp/Programme
cp ./relay/relay.exe ./temp/Programme
cp ./Maven-Plugin/target/dmf-generator-plugin-0.0.1-SNAPSHOT.jar ./temp/Programme
cp ./vscode-plugin/DMF-1.0.0.vsix ./temp/Programme
cp ./intellijPlugin/build/distributions/dmf-plugin-1.0-SNAPSHOT.zip ./temp/Programme

touch ./temp/Programme/README.md
printf "# Übersicht über die enthaltenen Programme\n" >> ./temp/Programme/README.md
printf "1. lsp => Linux Build des LSP-Servers\n" >> ./temp/Programme/README.md
printf "2. lsp.exe => Windows Build des LSP-Servers\n" >> ./temp/Programme/README.md
printf "3. generator => Linux Build des Generators\n" >> ./temp/Programme/README.md
printf "4. generator.exe => Windows Build des Generators\n" >> ./temp/Programme/README.md
printf "5. relay => Linux Build des Relays zur Nutzung eines LSP-Servers, der über TCP kommuniziert, über stdio\n" >> ./temp/Programme/README.md
printf "6. generator.exe => Windows Build des Relays zur Nutzung eines LSP-Servers, der über TCP kommuniziert, über stdio\n" >> ./temp/Programme/README.md
printf "7. dmf-generator-plugin-0.0.1-SNAPSHOT.jar => Das Maven Plugin des DMF\n" >> ./temp/Programme/README.md
printf "8. DMF-1.0.0.vsix => Visual Studio Code Plugin\n" >> ./temp/Programme/README.md
printf "9. dmf-plugin-1.0-SNAPSHOT.zip => Intellij Plugin\n" >> ./temp/Programme/README.md


cd ./temp/Programme || exit
zip -r -9 ../../Programme.zip *
cd ../../

# Beispiel Projekt
echo "baue BeispielProjekt.zip"
mkdir ./temp/BeispielProjekt
cd ./BeispielProjekt || exit
shopt -s extglob
cp -r !(.idea|BeispielProjekt.iml|JDomain.iml) ../temp/BeispielProjekt
cd .. || exit

cd ./temp/BeispielProjekt || exit
zip -r -9 ../../BeispielProjekt.zip *
cd .. || exit
cd .. || exit

# SourceCode
echo "baue SourceCode.zip"
shopt -s extglob

mkdir ./temp/SourceCode || ls .
mkdir ./temp/SourceCode/generator
cd ./generator || exit
cp -r !(generator|generator.exe) ../temp/SourceCode/generator
cd .. || exit

mkdir ./temp/SourceCode/grammar
cd ./grammar || exit
cp -r !(node_modules|build) ../temp/SourceCode/grammar
cd .. || exit

mkdir ./temp/SourceCode/intellijPlugin
cd ./intellijPlugin || exit
cp -r !(.gradle|.intellijPlatform|gradle|build|intellijPlugin.iml) ../temp/SourceCode/intellijPlugin
cd .. || exit

cp ./intellijTest/riesig.dmf ./temp/SourceCode

mkdir ./temp/SourceCode/lsp
cd ./lsp || exit
cp -r !(lsp|lsp.exe|lsp.iml) ../temp/SourceCode/lsp
cd .. || exit

mkdir ./temp/SourceCode/Maven-Plugin
cd ./Maven-Plugin || exit
cp -r !(target) ../temp/SourceCode/Maven-Plugin
cd .. || exit

mkdir ./temp/SourceCode/relay
cd ./relay || exit
cp -r !(relay|relay.exe|relay.iml) ../temp/SourceCode/relay
cd .. || exit

mkdir ./temp/SourceCode/semantic
cd ./semantic || exit
cp -r !(sem_rules.md) ../temp/SourceCode/semantic
cd .. || exit

mkdir ./temp/SourceCode/vscode-plugin
mkdir ./temp/SourceCode/vscode-plugin/client
cd ./vscode-plugin || exit
cp -r !(node_modules|client|DMF-1.0.0.vsix|.vscode) ../temp/SourceCode/vscode-plugin
cd ./client || exit
cp -r !(node_modules|dist) ../../temp/SourceCode/vscode-plugin/client
cd .. || exit
cd .. || exit

cp ./fullBuild.sh ./temp/SourceCode
cp ./go.work ./temp/SourceCode

cd ./temp/SourceCode || exit
zip -r -9 ../../SourceCode.zip *
cd .. || exit

echo "Entferne temp dir"
rm -rf ./temp
rm -rf ./temp
