kernel_release="$(uname -r)"

if [[ "$kernel_release" == *"Microsoft"* || "$kernel_release" == *"microsoft"* ]]; then
    is_windows=true
fi

# This should static link the libs with the executable file instead
if [[ $is_windows ]]; then
    cmd.exe /C "gcc -o build/sample sample/main.c src/heap/heap.c"
else
    gcc -o build/sample sample/main.c src/heap/heap.c
fi
