mkdir "temp"

# Executables and Artefakts
echo "baue Programme.zip"
mkdir "temp/Programme"
cp ./lsp/lsp ./temp/Programme
cp ./lsp/lsp.exe ./temp/Programme
cp ./generator/generator ./temp/Programme
cp ./generator/generator.exe ./temp/Programme
cp ./Maven-Plugin/target/dmf-generator-plugin-0.0.1-SNAPSHOT.jar ./temp/Programme
cp ./vscode-plugin/DMF-1.0.0.vsix ./temp/Programme
cp ./intellijPlugin/build/distributions/dmf-plugin-1.0-SNAPSHOT.zip ./temp/Programme

touch ./temp/Programme/README.md
printf "# Übersicht über die enthaltenen Programme\n" >> ./temp/Programme/README.md
printf "1. lsp => Linux Build des LSP-Servers\n" >> ./temp/Programme/README.md
printf "2. lsp.exe => Windows Build des LSP-Servers\n" >> ./temp/Programme/README.md
printf "3. generator => Linux Build des Generators\n" >> ./temp/Programme/README.md
printf "4. generator.exe => Windows Build des Generators\n" >> ./temp/Programme/README.md
printf "5. dmf-generator-plugin-0.0.1-SNAPSHOT.jar => Das Maven Plugin des DMF\n" >> ./temp/Programme/README.md
printf "6. DMF-1.0.0.vsix => Visual Studio Code Plugin\n" >> ./temp/Programme/README.md
printf "7. dmf-plugin-1.0-SNAPSHOT.zip => Intellij Plugin\n" >> ./temp/Programme/README.md


cd ./temp/Programme || exit
zip -r -9 ../../Programme.zip *
cd ../../

# Beispiel Projekt
echo "baue BeispielProjekt.zip"
mkdir ./temp/BeispielProjekt
cd ./BeispielProjekt || exit
shopt -s extglob
cp -r !(.idea | BeispielProjekt.iml | JDomain.iml) ../temp/BeispielProjekt
cd .. || exit

cd ./temp/BeispielProjekt || exit
zip -r -9 ../../BeispielProjekt.zip *
cd .. || exit

rm -rf ./temp
