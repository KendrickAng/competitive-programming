# change the file that compiles into "code" or "ac" to change the input code files
# change gen.cpp to change the test case characteristics
# then just run ./script.sh
set -e
g++ -O2 -std=c++17 -Wall -Werror ./../WA1.cpp -o code
g++ -O2 -std=c++17 -Wall -Werror ./../gen.cpp -o gen
g++ -O2 -std=c++17 -Wall -Werror ./../AC.cpp -o ac
g++ -O2 -std=c++17 -Wall -Werror checker.cpp -o checker
echo "compiled."
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./ac < input_file > correctAnswer
    ./checker > checker_log || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
echo "Checker message:"
cat checker_log