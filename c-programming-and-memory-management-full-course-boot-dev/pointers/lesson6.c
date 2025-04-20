int main()
{

    /*
    Syntax Review
    Declare a pointer to an integer:
    */
    int *pointer_to_something; // declares `pointer_to_something` as a pointer to an int

    /*
    New: Dereferencing Pointers
    Oftentimes we have a pointer, but we want to get access to the data that it points to. Not the address itself, but the value stored at that address.
    We can use an asterisk (*) to do it. The * operator dereferences a pointer.
    */
    int meaning_of_life = 42;
    int *pointer_to_mol = &meaning_of_life;
    int value_at_pointer = *pointer_to_mol;
    // value_at_pointer = 42
}

typedef struct CodeFile
{
    int lines;
    int filetype;
} codefile_t;

codefile_t change_filetype(codefile_t *f, int new_filetype)
{
    codefile_t new_f = *f;
    new_f.filetype = new_filetype;
    return new_f;
}
