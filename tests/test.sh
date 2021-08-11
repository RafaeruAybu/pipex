make
rm infile
rm outfile
echo "hello world" > infile
echo "<<<<<<<<<<<<<pipex<<<<<<<<<<<<"
./pipex infile "ls -l" "wc -l" outfile
cat outfile
echo ">>>>>>>>>>>>>shell>>>>>>>>>>>>"
rm infile
rm outfile
echo "hello world" > infile
< infile ls -l | wc -l > outfile
cat outfile
echo "|||||||||||||||||||||||||"
rm infile
rm outfile
echo "hello world" > infile
echo "<<<<<<<<<<<<<pipex<<<<<<<<<<<<"
./pipex infile "grep a1" "wc -w" outfile
cat outfile
echo ">>>>>>>>>>>>>shell>>>>>>>>>>>>"
rm infile
rm outfile
echo "hello world" > infile
< infile grep a1 | wc -w > outfile
cat outfile
