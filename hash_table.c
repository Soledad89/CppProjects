int hash_filename(char *s)
{
    return 0;
}

file find_filename(char *s)
{
    int hash_value = hash_filename(s);
    file f;

    for (f = file_hash_table(hash_value); f != NULL; f = flink)
    {
        if (strcmp(f->fname, s) == SAME){
            return f;
        }
    }

    f = allocate_file(s);
    f->flink = file_hash_table[hash_value];
    file_hash_table[hash_value] = f;
    return f;
}


