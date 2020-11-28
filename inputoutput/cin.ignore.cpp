Using cin.ignore

cin.ignore( int nCount = 1, int delim = EOF );

Parameters

nCount - The maximum number of characters to extract.
delim - The delimiter character (defaults to EOF).

Remarks

Extracts and discards up to nCount characters. Extraction stops if the delimiter delim is extracted or the end of file is reached. If delim = EOF (the default), then only the end of file condition causes termination. The delimiter character is extracted.