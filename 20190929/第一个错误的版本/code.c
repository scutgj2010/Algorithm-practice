// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int erfenfa(left,right)
{
    long long lefttemp = (unsigned int)left;
    long long righttemp = (unsigned int)right;
    if(lefttemp>=righttemp)
    {
            if(true == isBadVersion(lefttemp))
                return left;
            return left+1;
    }
    long long  middle = (lefttemp+righttemp)/2;
    if(true == isBadVersion(middle))
    {
        return erfenfa(left,middle-1);
    }
    else
    {
        return erfenfa(middle+1,right);
    }
}
int firstBadVersion(int n) {
    return erfenfa(1,n);
}