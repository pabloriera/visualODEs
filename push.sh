echo "-------------------------------------->"
echo "CLEANING..."
make clean
make clean Debug
make clean Release
echo "-------------------------------------->"
echo "COMMITING..."
git commit -a -m $1
echo "-------------------------------------->"
echo "PUSHING..."
git push
