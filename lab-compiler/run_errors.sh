UNDEFINED="preprocessing/preprocessing_undefined.c"
UNKNOWN="preprocessing/preprocessing_unknown.c"

separator() {
    local char="${1:-=}"
    printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' "$char"
}

echo "RUNNING PREPROCESSING"

echo ">gcc -E $UNDEFINED"
gcc -E $UNDEFINED

separator "-"

echo ">gcc -E $UNKNOWN"
gcc -E $UNKNOWN

separator "="

echo "RUNNING COMPILATION"
UNDEFINED_VAR="compilation/compilation_undefined_var.c"
WRONG_TYPING="compilation/compilation_wrong_typing.c"

echo ">gcc -S $UNDEFINED_VAR"
gcc -S $UNDEFINED_VAR

separator "-"

echo ">gcc -S $WRONG_TYPING"
gcc -S $WRONG_TYPING

separator "="

echo "RUNNING ASSEMBLY"
UNKNOWN_INSTRUCTION="assembly/assembly_unknown_instruction.c"
INVALID_SYNTAX="assembly/assembly_invalid_syntax.c"

echo ">gcc -c $UNKNOWN_INSTRUCTION"
gcc -c $UNKNOWN_INSTRUCTION

separator "-"

echo ">gcc -c $INVALID_SYNTAX"
gcc -c $INVALID_SYNTAX

separator "="

echo "RUNNING LINKING"
LINKING_PATH="linking"
MULTIDEF_PATH="multidefining"
LINKING_UNDEFINED="$LINKING_PATH/linking_undefined_func.c"
MULTIDEFINING_DEF1="definition_1.c"
MULTIDEFINING_DEF2="definition_2.c"
MULTIDEFINING_MAIN="main.c"

echo ">gcc -c $LINKING_UNDEFINED"
gcc -c $LINKING_UNDEFINED -o "$LINKING_PATH/undef.o"
echo ">gcc $LINKING_PATH/undef.o"
gcc "$LINKING_PATH/undef.o"


separator "-"
cd "$LINKING_PATH/$MULTIDEF_PATH" || return

echo ">gcc -c $MULTIDEFINING_DEF1 -o def1.o"
gcc -c $MULTIDEFINING_DEF1 -o def1.o

echo ">gcc -c $MULTIDEFINING_DEF2 -o def2.o"
gcc -c $MULTIDEFINING_DEF2 -o def2.o

echo ">gcc -c $MULTIDEFINING_MAIN -o main.o"
gcc -c $MULTIDEFINING_MAIN -o main.o

echo ">gcc def1.o def2.o main.o -o main"
gcc def1.o def2.o main.o -o program

separator "="

rm -f ./*.o
cd ../..
rm -f "$LINKING_PATH"/*.o