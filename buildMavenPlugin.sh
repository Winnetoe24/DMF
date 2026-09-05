
echo "Building Maven Plugin"
cd ./Maven-Plugin || exit
mvn clean install || exit
cd .. || exit