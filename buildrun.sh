rm MinecraftClone
cmake CMakeLists.txt -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

make -j8

if [ ! -f MinecraftClone ]; then
    echo "Compile failed"
else
    ./MinecraftClone
fi

