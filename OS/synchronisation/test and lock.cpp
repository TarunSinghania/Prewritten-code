bool test_and_lock(bool *v)
{
	int temp = *v;
	*v = true;

	return temp;
}


