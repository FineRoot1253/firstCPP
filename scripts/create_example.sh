#!/bin/sh
echo -n "파일 이름: "
read fileName
echo -n "상위 디렉토리 이름: "
read parrentsDir
upperFileName="$(tr '[:lower:]' '[:upper:]'  <<< ${fileName}) "
className="$(tr '[:lower:]' '[:upper:]' <<< ${fileName:0:1})${fileName:1}"
headerFileContents="#ifndef FIRSTCPP_${upperFileName}_H
#define FIRSTCPP_${upperFileName}_H
class $className{
};
#endif // FIRSTCPP_${upperFileName}_H
"
cmdFileContents="#include \"enthusiasm/$parrentsDir/$fileName.h\"

int main(){

    return 0;
}\n
"

echo "$headerFileContents" > ./src/enthusiasm/$parrentsDir/$fileName.h
echo "$cmdFileContents" > ./cmd/enthusiasm/$parrentsDir/$fileName.cpp
echo "add_executable(enthusiasm_${className}_run enthusiasm/${parrentsDir}/${className}.cpp)" >> ./cmd/CMakeLists.txt