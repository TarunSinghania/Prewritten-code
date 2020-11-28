string convertToBitString(long long value)
{
    string str(64, '0');

    for(int i = 0; i < 64; i++)
    {
        if( (1ll << i) & value)
            str[63-i] = '1';
    }

    return str;
 }