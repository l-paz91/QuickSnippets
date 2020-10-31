// implementation 1
int fac(int n)
{
  int r = 1;
  while (n > 1)
  {
    r *= n;
    --n;
  }
  return n;
}

// implementation 2
int fac(int n)
{
  return n > 1 ? n*(fac(n-1)) : 1;
}
